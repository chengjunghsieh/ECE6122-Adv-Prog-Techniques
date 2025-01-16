/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This file contains the implementation of the Mushroom class, representing a mushroom object in the game.
Mushrooms have a life value and can be hit and reduced in life, with a change in texture when damaged.
*/

#include "Mushroom.h"

// This the constructor function
// @param startX The starting x-coordinate for the mushroom.
// @param startY The starting y-coordinate for the mushroom.
Mushroom::Mushroom(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Life = MAX_LIFE;

    // Load the textures for the mushroom
    m_Texture0.loadFromFile("graphics/Mushroom0.png");
    m_Texture1.loadFromFile("graphics/Mushroom1.png");

    // Set the texture and position of the mushroom
    m_Shape.setTexture(m_Texture0);
    m_Shape.setPosition(m_Position);
}

// @brief Get the global bounding box of the mushroom for collision detection.
// @return A FloatRect representing the mushroom's global bounds.
FloatRect Mushroom::getPosition()
{
    return m_Shape.getGlobalBounds();
}

// @brief Get the current life of the mushroom.
// @return The current life of the mushroom.
int Mushroom::getLife()
{
    return m_Life;
}

// @brief Get the shape of the mushroom for rendering.
// @return A Sprite object representing the mushroom.
Sprite Mushroom::getShape()
{
    return m_Shape;
}

// @brief Reduce the mushroom's life and change its texture if damaged.
void Mushroom::reduceLife()
{
    // Change texture if the mushroom is at full life and is hit
    if (m_Life == MAX_LIFE)
    {
        m_Shape.setTexture(m_Texture1);
    }

    // Decrease the life of the mushroom
    m_Life--;
}
