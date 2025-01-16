/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This header file defines the CentipedeComponent class, which represents a single segment of the centipede.
Each CentipedeComponent can be either a head or a body segment, and it manages movement, direction changes,
and collisions with other game objects.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

class CentipedeComponent
{
private:
    // Textures for the head and body segments of the centipede.
    Texture headTexture;
    Texture bodyTexture;

    // Boolean to indicate if the component is the head.
    bool m_IsHead;

    // The sprite and position of the centipede segment.
    Sprite m_Sprite;
    Vector2f m_Position;

    // Speed of the centipede segment.
    float m_Speed = 1000.0f;

    // Flags and timers for handling direction changes.
    bool m_MovingX = true;
    float m_DirectionChangeInterval = 0.1f;
    float m_ChangeDirectionTimer = 0;

    // Direction vectors for movement.
    float m_DirectionX = -.4f;
    float m_DirectionY = .4f;

public:
    // Default constructor for CentipedeComponent.
    CentipedeComponent();

    // Constructor to initialize the centipede component as a head or body segment.
    // @param isHead Boolean indicating whether this component is the head.
    // @param x Initial x-coordinate of the component.
    // @param y Initial y-coordinate of the component.
    CentipedeComponent(bool isHead, float x, float y);

    // @brief Get the global bounding box of the centipede component for collision detection.
    // @return A FloatRect representing the component's global bounds.
    FloatRect getPosition();

    // @brief Get the sprite of the centipede component for rendering.
    // @return A Sprite object representing the component.
    Sprite getShape();

    // @brief Rotate the centipede component to face left.
    void faceLeft();

    // @brief Rotate the centipede component to face right.
    void faceRight();

    // @brief Rotate the centipede component to face up.
    void faceUp();

    // @brief Rotate the centipede component to face down.
    void faceDown();

    // @brief Change the direction of movement based on current movement direction.
    void changeDirection();

    // @brief Move the centipede component based on the elapsed time and its speed.
    // @param dt The time elapsed since the last frame.
    void movePosition(Time dt);

    // @brief Set the current centipede component as the head.
    void setHead();

    // @brief Set the position of the centipede component.
    // @param position The new position of the component.
    void setPosition(Vector2f position);

    // @brief Handle collisions with other objects and adjust position accordingly.
    // @param position The position of the object collided with.
    void handleCollision(Vector2f position);
};
