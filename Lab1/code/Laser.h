/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This header file defines the Laser class, which represents the laser shot by the player’s starship.
The laser moves upward at a constant speed and can interact with other game objects through collisions.
*/

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Laser
{
public:
    // Constants for laser dimensions
    static const int width = 3;
    static const int length = 75;

private:
    // The position of the laser
    Vector2f m_Position;

    // The shape of the laser, represented as a RectangleShape
    RectangleShape m_Shape;

    // The speed at which the laser moves
    float m_Speed = 1000.0f;

public:
    // Constructor to initialize the laser with a starting position
    // @param startX The starting x-coordinate of the laser.
    // @param startY The starting y-coordinate of the laser.
    Laser(float startX, float startY);

    // @brief Get the global bounding box of the laser for collision detection.
    // @return A FloatRect representing the laser's global bounds.
    FloatRect getPosition();

    // @brief Get the shape of the laser for rendering.
    // @return A RectangleShape object representing the laser.
    RectangleShape getShape();

    // @brief Update the laser's position based on the elapsed time.
    // @param dt The time elapsed since the last frame.
    void update(Time dt);
};
