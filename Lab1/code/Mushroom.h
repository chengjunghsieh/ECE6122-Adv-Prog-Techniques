/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024


Description:
This header file defines the Mushroom class, representing a mushroom object in the game.
Mushrooms have a life value and change appearance when hit. They can be destroyed after a certain number of hits.
*/

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Mushroom
{
public:
    // Maximum life of a mushroom before it gets destroyed
    static const int MAX_LIFE = 2;

private:
    // The life of the mushroom (decreases when hit)
    int m_Life;

    // The position of the mushroom
    Vector2f m_Position;

    // Textures for different states of the mushroom (healthy and damaged)
    Texture m_Texture0;
    Texture m_Texture1;

    // The sprite representing the mushroom
    Sprite m_Shape;

public:
    // Constructor to initialize the mushroom with a starting position
    // @param startX The starting x-coordinate of the mushroom.
    // @param startY The starting y-coordinate of the mushroom.
    Mushroom(float startX, float startY);

    // @brief Get the global bounding box of the mushroom for collision detection.
    // @return A FloatRect representing the mushroom's global bounds.
    FloatRect getPosition();

    // @brief Get the sprite of the mushroom for rendering.
    // @return A Sprite object representing the mushroom.
    Sprite getShape();

    // @brief Get the current life of the mushroom.
    // @return An integer representing the current life of the mushroom.
    int getLife();

    // @brief Reduce the mushroom's life and change its texture if necessary.
    void reduceLife();
};
