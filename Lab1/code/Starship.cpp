/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This file contains the implementation of the Starship class, representing the player's controllable spaceship in the game.
The Starship can move in all four directions within predefined screen boundaries and interact with other game objects such as mushrooms.
*/

#include <list>

#include "Starship.h"

// This the constructor and it is called when we create an object
// @param startX The starting x-coordinate for the starship.
// @param startY The starting y-coordinate for the starship.
// @param leftBound The left boundary for the starship's movement.
// @param rightBound The right boundary for the starship's movement.
// @param upBound The upper boundary for the starship's movement.
// @param downBound The lower boundary for the starship's movement.
Starship::Starship(float startX, float startY, float leftBound, float rightBound, float upBound, float downBound)
{
    // Initialize position and boundaries
    m_startX = startX;
    m_startY = startY;
    m_leftBound = leftBound;
    m_rightBound = rightBound;
    m_upBound = upBound;
    m_downBound = downBound;

    // Set the initial position of the starship
    m_Position.x = startX;
    m_Position.y = startY;

    // Load the starship texture and set its sprite
    m_Texture.loadFromFile("graphics/StarShip.png");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(m_Position);
}

// @brief Reset the starship's position to its starting position.
void Starship::reset()
{
    m_Position.x = m_startX;
    m_Position.y = m_startY;
}

// @brief Get the global bounding box of the starship for collision detection.
// @return A FloatRect representing the starship's global bounds.
FloatRect Starship::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

// @brief Get the shape of the starship for rendering.
// @return A Sprite object representing the starship.
Sprite Starship::getShape()
{
    return m_Sprite;
}

// @brief Set the starship to move left.
void Starship::moveLeft()
{
    m_MovingLeft = true;
}

// @brief Set the starship to move right.
void Starship::moveRight()
{
    m_MovingRight = true;
}

// @brief Set the starship to move up.
void Starship::moveUp()
{
    m_MovingUp = true;
}

// @brief Set the starship to move down.
void Starship::moveDown()
{
    m_MovingDown = true;
}

// @brief Stop the starship from moving left.
void Starship::stopLeft()
{
    m_MovingLeft = false;
}

// @brief Stop the starship from moving right.
void Starship::stopRight()
{
    m_MovingRight = false;
}

// @brief Stop the starship from moving up.
void Starship::stopUp()
{
    m_MovingUp = false;
}

// @brief Stop the starship from moving down.
void Starship::stopDown()
{
    m_MovingDown = false;
}

// @brief Update the starship's position and handle movement within screen boundaries and mushroom collisions.
// @param dt The elapsed time since the last frame, used to calculate how far the starship should move.
// @param mushrooms A list of mushrooms that the starship may collide with.
void Starship::update(Time dt, std::list<Mushroom>& mushrooms)
{
    // Move up and check boundary
    if (m_MovingUp)
    {
        m_Position.y -= m_Speed * dt.asSeconds();
        if (m_Position.y <= m_upBound + .5f)
        {
            m_Position.y = m_upBound;
        }
    }

    // Move down and check boundary
    if (m_MovingDown)
    {
        m_Position.y += m_Speed * dt.asSeconds();
        if (m_Position.y + getPosition().height >= m_downBound)
        {
            m_Position.y = m_downBound - getPosition().height;
        }
    }

    // Move left and check boundary
    if (m_MovingLeft)
    {
        m_Position.x -= m_Speed * dt.asSeconds();
        if (m_Position.x <= m_leftBound + .5f)
        {
            m_Position.x = m_leftBound;
        }
    }

    // Move right and check boundary
    if (m_MovingRight)
    {
        m_Position.x += m_Speed * dt.asSeconds();
        if (m_Position.x + getPosition().width >= m_rightBound)
        {
            m_Position.x = m_rightBound - getPosition().width;
        }
    }

    // Check for collisions with mushrooms
    for (auto& mushroom : mushrooms)
    {
        if (m_Sprite.getGlobalBounds().intersects(mushroom.getPosition()))
        {
            // Adjust position if colliding with a mushroom
            if (m_MovingUp) m_Position.y = mushroom.getPosition().top + mushroom.getPosition().height;
            if (m_MovingDown) m_Position.y = mushroom.getPosition().top - getPosition().height;
            if (m_MovingLeft) m_Position.x = mushroom.getPosition().left + mushroom.getPosition().width;
            if (m_MovingRight) m_Position.x = mushroom.getPosition().left - getPosition().width;
            break;
        }
    }

    // Update the sprite's position to the new calculated position
    m_Sprite.setPosition(m_Position);
}
