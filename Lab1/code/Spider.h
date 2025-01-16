/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This header file defines the Spider class, which represents a spider enemy in the game.
The Spider moves randomly within the game area and changes direction after a certain interval.
It can reset its position, update its movement based on time, and interact with other game objects.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace sf;

class Spider
{
private:
    // Starting position of the spider
    Vector2f m_startPosition;

    // Current position of the spider
    Vector2f m_Position;

    // Texture and sprite of the spider
    Texture m_Texture;
    Sprite m_Shape;

    // Speed and direction of the spider's movement
    float m_Speed;
    float m_DirectionX;
    float m_DirectionY;

    // Timers for changing direction at intervals
    float m_ChangeDirectionTimer;
    float m_DirectionChangeInterval;

public:
    // Constructor to initialize the spider with a starting position
    // @param startX The starting x-coordinate of the spider.
    // @param startY The starting y-coordinate of the spider.
    Spider(float startX, float startY);

    // @brief Get the global bounding box of the spider for collision detection.
    // @return A FloatRect representing the spider's global bounds.
    FloatRect getPosition();

    // @brief Get the sprite of the spider for rendering.
    // @return A Sprite object representing the spider.
    Sprite getShape();

    // @brief Reset the spider's position to its initial starting position.
    void reset();

    // @brief Update the spider's position and movement based on the elapsed time.
    // @param dt The time elapsed since the last frame.
    void update(Time dt);

    // @brief Set a random movement direction for the spider.
    void randomMove();
};
