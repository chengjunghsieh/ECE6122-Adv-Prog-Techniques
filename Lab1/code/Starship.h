/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This header file defines the Starship class, which represents the player's starship in the game.
The Starship can move in all four directions, interact with game objects like mushrooms, and is constrained by screen boundaries.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <list>

#include "Mushroom.h"

using namespace sf;

class Starship
{
private:
    // Initial position of the starship
    float m_startX;
    float m_startY;

    // Movement boundaries for the starship
    float m_leftBound;
    float m_rightBound;
    float m_upBound;
    float m_downBound;

    // Current position of the starship
    Vector2f m_Position;

    // Texture and sprite of the starship
    Texture m_Texture;
    Sprite m_Sprite;

    // Speed at which the starship moves
    float m_Speed = 1001.0f;

    // Flags for determining if the starship is moving in a specific direction
    bool m_MovingRight = false;
    bool m_MovingLeft = false;
    bool m_MovingUp = false;
    bool m_MovingDown = false;

public:
    // Constructor to initialize the starship with a starting position and movement boundaries
    // @param startX The starting x-coordinate of the starship.
    // @param startY The starting y-coordinate of the starship.
    // @param leftBound The left boundary for the starship's movement.
    // @param rightBound The right boundary for the starship's movement.
    // @param upBound The upper boundary for the starship's movement.
    // @param downBound The lower boundary for the starship's movement.
    Starship(float startX, float startY, float leftBound, float rightBound, float upBound, float downBound);

    // @brief Reset the starship's position to its initial starting position.
    void reset();

    // @brief Get the global bounding box of the starship for collision detection.
    // @return A FloatRect representing the starship's global bounds.
    FloatRect getPosition();

    // @brief Get the sprite of the starship for rendering.
    // @return A Sprite object representing the starship.
    Sprite getShape();

    // @brief Set the starship to move left.
    void moveLeft();

    // @brief Set the starship to move right.
    void moveRight();

    // @brief Set the starship to move up.
    void moveUp();

    // @brief Set the starship to move down.
    void moveDown();

    // @brief Stop the starship from moving left.
    void stopLeft();

    // @brief Stop the starship from moving right.
    void stopRight();

    // @brief Stop the starship from moving up.
    void stopUp();

    // @brief Stop the starship from moving down.
    void stopDown();

    // @brief Update the starship's position based on the elapsed time, handle boundary limits, and interact with mushrooms.
    // @param dt The time elapsed since the last frame.
    // @param mushrooms A reference to a list of mushrooms that may affect the starship's movement.
    void update(Time dt, std::list<Mushroom>& mushrooms);
};
