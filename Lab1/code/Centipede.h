/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This header file defines the Centipede class, which manages a centipede composed of multiple CentipedeComponent segments.
The Centipede can move, handle collisions with mushrooms, split into two upon being hit, and update its position.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include "Mushroom.h"
#include "CentipedeComponent.h"

using namespace sf;

class Centipede
{
private:
    // A list of unique pointers to CentipedeComponent, representing the segments of the centipede.
    std::list<std::unique_ptr<CentipedeComponent>> m_C;

public:
    // Constructor that initializes the centipede with a specified length and starting position.
    // @param length The number of body segments of the centipede.
    // @param startX The starting x-coordinate of the centipede's head.
    // @param startY The starting y-coordinate of the centipede's head.
    Centipede(int length, float startX, float startY);

    // Constructor that initializes the centipede with a pre-defined list of centipede components.
    // @param length The length of the centipede.
    // @param components The list of centipede components to be used.
    Centipede(int length, std::list<std::unique_ptr<CentipedeComponent>> components);

    // @brief Get the current length of the centipede.
    // @return The number of segments in the centipede.
    int getLength();

    // @brief Retrieve the sprites representing the centipede components for rendering.
    // @return A list of Sprite objects corresponding to the centipede's segments.
    std::list<Sprite> getShape();

    // @brief Update the centipede's position and handle collisions with mushrooms.
    // @param dt The time elapsed since the last update.
    // @param mushrooms A reference to a list of mushrooms for collision detection.
    void update(Time dt, std::list<Mushroom>& mushrooms);

    // @brief Handle a hit on a specific centipede segment.
    // @param hitIndex The index of the segment that was hit.
    // @return A new centipede if the hit causes a split, or nullptr if the centipede is not split.
    std::unique_ptr<Centipede> handleHit(int hitIndex);

    // @brief Split the centipede into two at the specified index.
    // @param index The index at which the centipede is split.
    // @return A new Centipede object representing the split portion of the centipede.
    std::unique_ptr<Centipede> split(int index);
};
