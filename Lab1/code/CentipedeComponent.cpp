/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024


Description:
This file implements the CentipedeComponent class, which represents a segment of the centipede in the game.
It handles segment movement, direction changes, collision detection, and drawing of the segment.
*/

#include "CentipedeComponent.h"

/**
 * @class CentipedeComponent
 * @brief Represents a segment of a centipede, which can be either a head or a body segment.
 *        Handles movement, direction changes, and collision detection.
 */

/**
 * @brief Default constructor for CentipedeComponent.
 */
CentipedeComponent::CentipedeComponent() {}

/**
 * @brief Constructor for CentipedeComponent. Initializes a segment with its position and type (head or body).
 * @param isHead Boolean value indicating whether the segment is the head.
 * @param x The x-coordinate of the segment's position.
 * @param y The y-coordinate of the segment's position.
 */
CentipedeComponent::CentipedeComponent(bool isHead, float x, float y)
{
    headTexture.loadFromFile("graphics/CentipedeHead.png");
    bodyTexture.loadFromFile("graphics/CentipedeBody.png");

    m_IsHead = isHead;

    // Set the origin to the center for proper rotation
    m_Position.x = x;
    m_Position.y = y + 20;

    m_Sprite.setTexture(isHead ? headTexture : bodyTexture);
    m_Sprite.setPosition(m_Position);

    FloatRect rect = m_Sprite.getLocalBounds();
    m_Sprite.setOrigin(rect.width / 2, rect.height / 2);

    // Initially facing left
    faceLeft();
}

/**
 * @brief Get the global bounds of the sprite for collision detection.
 * @return A FloatRect representing the bounds of the sprite.
 */
FloatRect CentipedeComponent::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

/**
 * @brief Get the sprite of the current centipede segment.
 * @return A Sprite object representing the segment.
 */
Sprite CentipedeComponent::getShape()
{
    return m_Sprite;
}

/**
 * @brief Rotate the segment to face left.
 */
void CentipedeComponent::faceLeft()
{
    m_Sprite.setRotation(180);
}

/**
 * @brief Rotate the segment to face right.
 */
void CentipedeComponent::faceRight()
{
    m_Sprite.setRotation(0);
}

/**
 * @brief Rotate the segment to face down.
 */
void CentipedeComponent::faceDown()
{
    m_Sprite.setRotation(90);
}

/**
 * @brief Rotate the segment to face up.
 */
void CentipedeComponent::faceUp()
{
    m_Sprite.setRotation(270);
}

/**
 * @brief Change the direction the centipede is facing based on its movement direction.
 */
void CentipedeComponent::changeDirection()
{
    if (m_MovingX)
    {
        if (m_DirectionX > 0)
        {
            faceRight();
        }
        else
        {
            faceLeft();
        }
    }
    else
    {
        if (m_DirectionY > 0)
        {
            faceDown();
        }
        else
        {
            faceUp();
        }
    }
}

/**
 * @brief Move the centipede segment's position based on its direction and speed.
 * @param dt The elapsed time since the last frame, used to compute movement distance.
 */
void CentipedeComponent::movePosition(Time dt)
{
    Vector2f position = m_Position;

    // Update position based on direction
    if (m_MovingX)
    {
        position.x += m_DirectionX * m_Speed * dt.asSeconds();
    }
    else
    {
        m_ChangeDirectionTimer += dt.asSeconds();
        position.y += m_DirectionY * m_Speed * dt.asSeconds();

        // Change direction based on the timer
        if (m_ChangeDirectionTimer >= m_DirectionChangeInterval)
        {
            m_ChangeDirectionTimer = 0.f; // Reset timer
            m_MovingX = true; // Change to moving in X direction
            changeDirection();
        }
    }

    // Boundary checks
    if (position.x < 20)
    {
        position.x = 20; // Clamp position to left bound
        m_MovingX = false; // Change direction to down
        m_DirectionX = -m_DirectionX;
        changeDirection();
    }
    else if (position.x > 1900)
    {
        position.x = 1900; // Clamp position to right bound
        m_MovingX = false; // Change direction to down
        m_DirectionX = -m_DirectionX;
        changeDirection();
    }

    if (position.y < 80)
    {
        position.y = 80;
        m_MovingX = true;
        m_DirectionY = -m_DirectionY;
        changeDirection();
    }
    else if (position.y > 1070)
    {
        position.y = 1070; // Clamp position to bottom bound
        m_MovingX = true; // Change direction to horizontal movement
        m_DirectionY = -m_DirectionY;
        changeDirection();
    }

    // Update the position and sprite
    m_Position = position;
    m_Sprite.setPosition(m_Position);
}

/**
 * @brief Set the current segment to be the head of the centipede.
 */
void CentipedeComponent::setHead()
{
    m_IsHead = true;
    m_Sprite.setTexture(headTexture);
}

/**
 * @brief Set the position of the centipede segment.
 * @param position The new position of the segment.
 */
void CentipedeComponent::setPosition(Vector2f position)
{
    m_Position = position;
    m_Sprite.setPosition(m_Position);
}

/**
 * @brief Handle collision with another object by adjusting the centipede's position and changing direction.
 * @param position The position of the object collided with.
 */
void CentipedeComponent::handleCollision(Vector2f position)
{
    // Calculate the direction vector from the centipede's current position to the collision position
    Vector2f direction = position - m_Position;

    // Normalize the direction vector to determine the collision side
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length > 0)
    {
        direction /= length; // Normalize the vector

        // Move the centipede slightly away from the collision position
        const float adjustmentDistance = 5.0f; // Adjust this value as needed
        m_Position -= direction * adjustmentDistance; // Move away from the collision

        // Update the sprite position
        m_Sprite.setPosition(m_Position);
    }

    // Flip movement direction upon collision
    if (m_MovingX)
    {
        m_MovingX = false;
        m_DirectionX = -m_DirectionX;
    }
    else
    {
        m_MovingX = true;
    }

    // Change the direction of the sprite to reflect the new movement direction
    changeDirection();
}
