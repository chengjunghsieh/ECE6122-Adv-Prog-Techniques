/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This file contains the implementation of the Laser class, which represents the laser shot by the starship in the game.
It handles the laser's creation, movement, and interactions within the game (e.g., collision detection with other objects).
*/

#include "Laser.h"

// This is the constructor and it is called when we create an object
// @param startX The starting x-coordinate for the laser.
// @param startY The starting y-coordinate for the laser.
Laser::Laser(float startX, float startY)
{
    // Set the initial position of the laser
    m_Position.x = startX;
    m_Position.y = startY;

    // Set up the laser shape
    m_Shape.setSize(sf::Vector2f(width, length));
    m_Shape.setPosition(m_Position);
    m_Shape.setFillColor(Color::Red);
}

// @brief Get the global bounding box of the laser.
// @return A FloatRect representing the global bounds of the laser for collision detection.
FloatRect Laser::getPosition()
{
    return m_Shape.getGlobalBounds();
}

// @brief Get the shape of the laser for rendering.
// @return A RectangleShape object representing the laser's shape.
RectangleShape Laser::getShape()
{
    return m_Shape;
}

// @brief Update the laser's position based on the elapsed time.
// @param dt The elapsed time since the last frame, used to calculate how far the laser should move.
void Laser::update(Time dt)
{
    // Move the laser upward based on its speed and the time delta
    m_Position.y -= m_Speed * dt.asSeconds();

    // Update the laser's shape position
    m_Shape.setPosition(m_Position);
}
