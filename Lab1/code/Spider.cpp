/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This file contains the implementation of the Spider class, representing the spider object in the game.
The spider moves randomly on the screen and changes direction periodically.
The spider's position is updated each frame, and it is constrained to the screen boundaries.
*/

#include "Spider.h"

// This the constructor function
// @param startX The starting x-coordinate for the spider.
// @param startY The starting y-coordinate for the spider.
Spider::Spider(float startX, float startY)
{
    // Initialize the direction change timer and interval
    m_ChangeDirectionTimer = 0.f;
    m_DirectionChangeInterval = static_cast<float>(std::rand() % 200 + 100) / 100.0f;

    // Set the starting position of the spider
    m_startPosition.x = startX;
    m_startPosition.y = startY;
    m_Position = m_startPosition;

    // Load the spider texture
    m_Texture.loadFromFile("graphics/spider.png");
    m_Shape.setTexture(m_Texture);
    m_Shape.setPosition(m_Position);

    // Seed random number generator and generate an initial random movement direction
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    randomMove();
}

// @brief Get the global bounding box of the spider for collision detection.
// @return A FloatRect representing the spider's global bounds.
FloatRect Spider::getPosition()
{
    return m_Shape.getGlobalBounds();
}

// @brief Get the shape of the spider for rendering.
// @return A Sprite object representing the spider.
Sprite Spider::getShape()
{
    return m_Shape;
}

// @brief Reset the spider's position to its starting position.
void Spider::reset()
{
    m_Position = m_startPosition;
}

// @brief Update the spider's position and movement based on the elapsed time.
// @param dt The elapsed time since the last frame, used to calculate how far the spider should move.
void Spider::update(Time dt)
{
    // Update the change direction timer
    m_ChangeDirectionTimer += dt.asSeconds();
    if (m_ChangeDirectionTimer >= m_DirectionChangeInterval)
    {
        randomMove();
        m_DirectionChangeInterval = static_cast<float>(std::rand() % 200 + 100) / 100.0f;
        m_ChangeDirectionTimer = 0.f; // Reset timer after changing direction
    }

    // Randomly set the spider's speed
    m_Speed = static_cast<float>(std::rand() % 200 + 400);

    // Update position based on speed and direction
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

    // Ensure the spider stays within the screen boundaries
    if (m_Position.x < 0)
    {
        m_Position.x = 0; // Prevent moving left out of bounds
        m_DirectionX = -m_DirectionX; // Reverse direction
    }
    else if (m_Position.x > 1080 - m_Shape.getGlobalBounds().width)
    { // Subtract width of sprite to stay fully on screen
        m_Position.x = 1080 - m_Shape.getGlobalBounds().width; // Prevent moving right out of bounds
        m_DirectionX = -m_DirectionX; // Reverse direction
    }

    if (m_Position.y < 75)
    {
        m_Position.y = 75; // Prevent moving up out of bounds
        m_DirectionY = -m_DirectionY; // Reverse direction
    }
    else if (m_Position.y > 1060 - m_Shape.getGlobalBounds().height)
    { // Subtract height of sprite to stay fully on screen
        m_Position.y = 1060 - m_Shape.getGlobalBounds().height; // Prevent moving down out of bounds
        m_DirectionY = -m_DirectionY; // Reverse direction
    }

    // Move the spider sprite
    m_Shape.setPosition(m_Position);
}

// @brief Randomly set a new direction for the spider to move in.
void Spider::randomMove()
{
    // Generate a random angle in radians
    float angle = static_cast<float>(std::rand()) / RAND_MAX * 2 * acos(-1);

    // Calculate new direction based on the angle
    m_DirectionX = std::cos(angle);
    m_DirectionY = std::sin(angle);
}
