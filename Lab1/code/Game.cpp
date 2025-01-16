/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This is the main entry point for the Centipede game. It initializes the game window, sets up the game objects
such as centipedes, starship, mushrooms, and spider, and contains the main game loop that handles user input,
object updates, and drawing. The game tracks the player's score, lives, and handles collisions between the
game objects.
*/

// Include important C++ libraries here
#include <sstream>
#include <list>
#include <memory>
#include <random>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "Centipede.h"
#include "Starship.h"
#include "Laser.h"
#include "Mushroom.h"
#include "Spider.h"

const int defaultWindowWidth = 1920;
const int defaultWindowHeight = 1080;
const int headerHeight = 75;
const int mushroomFreeHeight = defaultWindowHeight * .8f;

const int starshipStartX = defaultWindowWidth / 2;
const int starshipStartY = defaultWindowHeight - 50;

// Make code easier to type with "using namespace"
using namespace sf;
// Function declaration
void generateMushrooms();
void updateBranches(int seed);
void handleHitCentipede(int& score);

const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];

// Where is the player/branch?
// Left or Right
enum class side { LEFT, RIGHT, NONE };
side branchPositions[NUM_BRANCHES];

const int NUM_CENTIPEDE_BODY = 11;
std::list<std::unique_ptr<Centipede>> centipedes;

const int NUM_MUSHROOMS = 30;
std::list<Mushroom> mushrooms;

std::list<Laser> lasers;

int main()
{
    // Create a video mode object
    VideoMode vm(defaultWindowWidth, defaultWindowHeight);

    // Create and open a window for the game
    RenderWindow window(vm, "Centipede!!!", Style::Default);

    // Create a texture to hold a graphic on the GPU
    Texture textureBackground;

    // Load a graphic into the texture
    //textureBackground.loadFromFile("graphics/Startup-Screen-BackGround.png");
    textureBackground.loadFromFile("graphics/background.png");

    // Create a sprite
    Sprite spriteBackground;

    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);

    // Set the spriteBackground to cover the screen
    spriteBackground.setPosition(0, 0);
    //spriteBackground.setScale(sf::Vector2f(2.f, 2.f));

    // Variables to control time itself
    Clock clock;

    // Track whether the game is running
    bool paused = true;

    // Game status
    int score = 0;

    sf::Text messageText;
    sf::Text scoreText;

    // We need to choose a font
    sf::Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    // Set the font to our message
    messageText.setFont(font);
    scoreText.setFont(font);

    // Assign the actual message
    messageText.setString("Press Enter to start!");
    scoreText.setString("0");

    // Make it really big
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(50);

    // Choose a color
    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);

    // Position the text
    FloatRect textRect = messageText.getLocalBounds();

    messageText.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);

    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

    scoreText.setPosition(defaultWindowWidth / 2.0f, 20);

    // Lifes
    int lives = 2;
    Texture lifeTexture;
    lifeTexture.loadFromFile("graphics/StarShip.png");

    // Create a sprite
    Sprite lifeSprites[2];

    // Attach the texture to the sprite
    lifeSprites[0].setTexture(lifeTexture);
    lifeSprites[0].setPosition(defaultWindowWidth / 2.0f + 300, 20);

    lifeSprites[1].setTexture(lifeTexture);
    lifeSprites[1].setPosition(defaultWindowWidth / 2.0f + 350, 20);

    // Control the player input
    bool acceptInput = false;

    // Init Starship
    Starship starship(starshipStartX, starshipStartY, 0, defaultWindowWidth, headerHeight, defaultWindowHeight);

    Spider spider(0, 800);
    bool spiderActive = true;

    std::unique_ptr<Centipede> centipiede;
    centipiede = std::make_unique<Centipede>(NUM_CENTIPEDE_BODY, defaultWindowWidth, headerHeight);
    centipedes.push_back(std::move(centipiede));

    while (window.isOpen())
    {
        // score ++;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyReleased && !paused)
            {
                // Listen for key presses again
                acceptInput = true;
            }

        }

        /*
        ****************************************
        Handle the players input
        ****************************************
        */

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        // Start the game
        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;

            // Reset the life and the score
            score = 0;
            lives = 2;

            // Reset centipede position
            centipedes.clear();
            centipiede = std::make_unique<Centipede>(NUM_CENTIPEDE_BODY, defaultWindowWidth, headerHeight);
            centipedes.push_back(std::move(centipiede));

            // Reset Spider
            spider.reset();

            // Reset starship position
            starship.reset();

            // Make all mushrooms disappear
            mushrooms.clear();

            // Create new mushrooms
            generateMushrooms();

            acceptInput = true;
        }

        // Wrap the player controls to
        // Make sure we are accepting input
        if (acceptInput)
        {
            // First handle pressing the right cursor key
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                starship.moveRight();

                acceptInput = false;
            }
            else
            {
                starship.stopRight();
            }


            // Handle the left cursor key
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                starship.moveLeft();

                acceptInput = false;
            }
            else
            {
                starship.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                starship.moveUp();
            }
            else
            {
                starship.stopUp();
            }

            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                starship.moveDown();
            }
            else
            {
                starship.stopDown();
            }

            // Handle the left cursor key
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                lasers.emplace_back(
                    starship.getPosition().left + starship.getPosition().width / 2,
                    starship.getPosition().top - Laser::length);

                acceptInput = false;
            }
        }


        /*
        ****************************************
        Update the scene
        ****************************************
        */
        if (!paused)
        {
            // Measure time
            Time dt = clock.restart();

            // Update the score text
            std::stringstream ss;
            ss << score;
            scoreText.setString(ss.str());

            // Handle starship
            starship.update(dt, mushrooms);

            // Handle Centipede
            for (auto& centipede : centipedes)
            {
                centipede->update(dt, mushrooms);
            }

            // Handle spider move
            if (spiderActive)
            {
                spider.update(dt);
            }
            else
            {
                spider.reset();
                spiderActive = true;
            }

            // Handle laser blast
            for (auto& laser : lasers)
            {
                laser.update(dt);
            }

            // Check for collisions with mushrooms
            for (auto it = mushrooms.begin(); it != mushrooms.end(); )
            {
                if (spider.getPosition().intersects(it->getPosition()))
                {
                    it = mushrooms.erase(it);
                }
                else
                {
                    ++it; // Move to the next mushroom
                }
            }

            // Check for collisions with lasers
            for (auto it = lasers.begin(); it != lasers.end(); )
            {
                if (spider.getPosition().intersects(it->getPosition()))
                {
                    // Collision detected, destroy the spider
                    spiderActive = false;
                    score += 10; // Increase the score
                    it = lasers.erase(it); // Remove the laser if it hits the spider
                    break;
                }
                else
                {
                    ++it; // Move to the next laser
                }
            }

            // Handle laser and mushroom collisions
            for (auto laserIt = lasers.begin(); laserIt != lasers.end();)
            {
                bool laserRemoved = false;

                for (auto mushroomIt = mushrooms.begin(); mushroomIt != mushrooms.end();)
                {
                    if (laserIt->getPosition().intersects(mushroomIt->getPosition()))
                    {
                        score++;
                        mushroomIt->reduceLife(); // Reduce life of the mushroom

                        // Check if the mushroom's life is now zero
                        if (mushroomIt->getLife() <= 0)
                        {
                            mushroomIt = mushrooms.erase(mushroomIt); // Remove the mushroom
                        }
                        else
                        {
                            ++mushroomIt; // Move to the next mushroom if not removed
                        }

                        laserIt = lasers.erase(laserIt); // Remove the laser
                        laserRemoved = true;
                        break; // Break to prevent checking other mushrooms
                    }
                    else
                    {
                        ++mushroomIt; // Move to the next mushroom if no collision
                    }
                }

                if (!laserRemoved)
                {
                    ++laserIt; // Move to the next laser if not removed
                }
            }

            // Handle laser, centipede collision
            handleHitCentipede(score);


            // starship collide with spider
            if (spiderActive && spider.getPosition().intersects(starship.getPosition()))
            {
                starship.reset(); // Reset starship to starting location
                lives--; // Use up a life
            }

            // Todo: starship collide with centipede
            for (auto& centipede : centipedes)
            {
                auto&& cc = centipede->getShape();
                for (auto& s : cc)
                {
                    if (s.getGlobalBounds().intersects(starship.getPosition()))
                    {
                        starship.reset();
                        lives--;
                    }
                }
            }

            // Win?
            if (centipedes.empty())
            {
                paused = true;
                acceptInput = false;

                // Change the text of the message
                messageText.setString("You Win!!");

                // Center it on the screen
                FloatRect textRect = messageText.getLocalBounds();

                messageText.setOrigin(textRect.left +
                    textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);

                messageText.setPosition(1920 / 2.0f,
                    1080 / 2.0f);
            }


            // Is game over?
            if (lives < 0)
            {
                // death
                paused = true;
                acceptInput = false;

                // Change the text of the message
                messageText.setString("Game Over!!");

                // Center it on the screen
                FloatRect textRect = messageText.getLocalBounds();

                messageText.setOrigin(textRect.left +
                    textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);

                messageText.setPosition(1920 / 2.0f,
                    1080 / 2.0f);
            }

        }// End if(!paused)

         /*
         ****************************************
         Draw the scene
         ****************************************
         */

         // Clear everything from the last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);

        // Draw the mushrooms
        for (auto& mushroom : mushrooms)
        {
            window.draw(mushroom.getShape());
        }

        // Draw laser blasts
        while (lasers.size()) {
            // Has the insect reached the right hand edge of the screen?
            if (lasers.front().getShape().getPosition().y < -100)
            {
                // Remove the laser
                lasers.pop_front();
            }
            else
            {
                break;
            }
        }

        for (auto& laser : lasers)
        {
            window.draw(laser.getShape());
        }

        // Draw Spider
        if (spiderActive)
        {
            window.draw(spider.getShape());
        }

        // Draw Starship
        window.draw(starship.getShape());

        // Draw centipedes
        for (auto& centipede : centipedes)
        {
            for (auto& i : centipede->getShape())
            {
                window.draw(i);
            }
        }

        // Draw the score
        window.draw(scoreText);

        for (int i = 0; i < lives; i++)
        {
            window.draw(lifeSprites[i]);
        }

        if (paused)
        {
            // Draw our message
            window.draw(messageText);
        }

        // Show everything we just drew
        window.display();


    }

    return 0;
}

// Function definition
void generateMushrooms()
{
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::uniform_int_distribution<int> distrX(1, (defaultWindowWidth - 30) / 30); // Define the range
    std::uniform_int_distribution<int> distrY((headerHeight + 60) / 30, (mushroomFreeHeight - 30) / 30);

    for (int i = 0; i < NUM_MUSHROOMS; ++i)
    {
        int x = distrX(eng) * 30;
        int y = distrY(eng) * 30;
        mushrooms.emplace_back(x, y);
    }
}

void handleHitCentipede(int& score) {
    for (auto laserIt = lasers.begin(); laserIt != lasers.end(); ) {
        bool laserRemoved = false;

        for (auto centipedeIt = centipedes.begin(); centipedeIt != centipedes.end(); ) {
            auto centipedeShapes = (*centipedeIt)->getShape();  // Centipede Components
            int centipedeLength = (*centipedeIt)->getLength();  // Centipede Length

            bool hit = false;
            int hitIndex = -1;

            // Check for collision with each segment
            int index = 0;
            for (auto& segment : centipedeShapes) {
                if (laserIt->getPosition().intersects(segment.getGlobalBounds())) {
                    hit = true;
                    hitIndex = index;
                    break;
                }
                index++;
            }

            if (hit) {
                score += 10;
                laserRemoved = true;

                std::unique_ptr<Centipede> newCentipede = (*centipedeIt)->handleHit(hitIndex);

                if (newCentipede) {
                    centipedes.push_back(std::move(newCentipede)); // Add new centipede if created
                }

                // Check if the current centipede should be removed
                if ((*centipedeIt)->getLength() < 1) {
                    centipedeIt = centipedes.erase(centipedeIt); // Remove centipede if length is less than 1
                }
                else {
                    ++centipedeIt; // Move to the next centipede
                }
                break;
            }
            else {
                ++centipedeIt; // Move to the next centipede if no hit
            }
        }

        if (laserRemoved) {
            laserIt = lasers.erase(laserIt); // Remove the laser
        }
        else {
            ++laserIt; // Move to the next laser
        }
    }
}