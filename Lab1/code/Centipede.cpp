/*
Author: Cheng-Jung Hsieh
Class: ECE6122 A
Last Date Modified: Mon Sep 23 11:24:03 EDT 2024

Description:
This class represents a centipede entity composed of multiple CentipedeComponent segments.
The Centipede class handles movement, collision, and interactions such as splitting when hit.
*/

#include "Centipede.h"

/**
 * @brief Constructor for the Centipede class. Initializes the centipede with a given body length and starting position.
 * @param bodyLength The number of body segments (excluding the head).
 * @param startX The starting x-coordinate for the centipede's head.
 * @param startY The starting y-coordinate for the centipede's head.
 */
Centipede::Centipede(int bodyLength, float startX, float startY)
{
    Vector2f p;
    // Create the head of the centipede
    CentipedeComponent c = CentipedeComponent(false, startX, startY);
    std::unique_ptr<CentipedeComponent> ptr;

    // Initialize head position based on the starting point and body length
    p.x = startX - c.getPosition().width * (bodyLength + 1);
    p.y = startY;
    ptr = std::make_unique<CentipedeComponent>(true, p.x, p.y);
    m_C.push_back(std::move(ptr));

    // Create the rest of the centipede body segments
    for (int i = bodyLength; i > 0; i--)
    {
        p.x = startX - c.getPosition().width * i;
        p.y = startY;
        ptr = std::make_unique<CentipedeComponent>(false, p.x, p.y);
        m_C.push_back(std::move(ptr));
    }
}

/**
 * @brief Constructor for the Centipede class, allowing the creation of a centipede with pre-existing components.
 * @param length The length of the centipede.
 * @param components The list of centipede components to be used for this centipede.
 */
Centipede::Centipede(int length, std::list<std::unique_ptr<CentipedeComponent>> components)
    : m_C(std::move(components)) {}

/**
 * @brief Get the current length of the centipede.
 * @return The number of segments in the centipede.
 */
int Centipede::getLength()
{
    return m_C.size();
}

/**
 * @brief Retrieve the shapes of all the centipede components.
 * @return A list of Sprite objects representing the shape of each centipede component.
 */
std::list<Sprite> Centipede::getShape()
{
    std::list<Sprite> result;
    // Iterate over each component and get its shape
    for (auto& c : m_C)
    {
        result.push_back(c->getShape());
    }
    return result;
}

/**
 * @brief Update the centipede's position and handle potential collisions with mushrooms.
 * @param dt The time elapsed since the last update.
 * @param mushrooms A reference to a list of mushrooms to check for collisions.
 */
void Centipede::update(Time dt, std::list<Mushroom>& mushrooms)
{
    auto it = std::prev(m_C.end()); // Start from the second-to-last segment

    // Move each body segment to the position of the segment in front
    while (it != m_C.begin())
    {
        auto prv = std::prev(it);  // Get the segment in front
        auto sx = prv->get()->getShape().getPosition().x;
        auto sy = prv->get()->getShape().getPosition().y;
        auto tx = it->get()->getShape().getPosition().x;
        auto ty = it->get()->getShape().getPosition().y;

        Vector2f position;
        // Update the current segment's position relative to the previous segment
        position.x = tx + (sx - tx) * 18.f * dt.asSeconds();
        position.y = ty + (sy - ty) * 18.f * dt.asSeconds();
        it->get()->setPosition(position);
        --it;
    }

    // Move the head segment
    FloatRect headRect = m_C.front()->getPosition();
    m_C.front()->movePosition(dt);

    // Check for collision between the head and mushrooms
    for (auto& mushroom : mushrooms)
    {
        if (headRect.intersects(mushroom.getPosition()))
        {
            // Handle the collision and adjust head's position
            m_C.front()->handleCollision(mushroom.getShape().getPosition());
            return;
        }
    }
}

/**
 * @brief Handles the event when the centipede is hit. If the centipede is split by the hit, returns a new centipede.
 * @param hitIndex The index of the segment that was hit.
 * @return A new centipede if the centipede is split, or nullptr if the centipede is not split or the index is invalid.
 */
std::unique_ptr<Centipede> Centipede::handleHit(int hitIndex)
{
    if (hitIndex < 0 || hitIndex >= getLength())
    {
        return nullptr; // Invalid index
    }

    if (hitIndex == 0)
    { // Head is hit
        m_C.pop_front();
        if (getLength() > 0)
        {
            // If there are remaining segments, designate the new head
            m_C.front()->setHead();
        }
        return nullptr;
    }
    else if (hitIndex == getLength() - 1)
    {
        // Tail is hit, remove the last segment
        m_C.pop_back();
        return nullptr;
    }

    // If hit in the middle, split the centipede at the hit index
    return split(hitIndex);
}

/**
 * @brief Splits the centipede into two at the specified index.
 *        The original centipede will be shortened, and a new centipede will be returned from the split segment.
 * @param index The index at which to split the centipede.
 * @return A new Centipede object starting from the hit index onward.
 */
std::unique_ptr<Centipede> Centipede::split(int index)
{
    std::list<std::unique_ptr<CentipedeComponent>> newComponents;

    // Move components from the current centipede to the new centipede
    for (auto it = std::next(m_C.begin(), index + 1); it != m_C.end(); ++it)
    {
        newComponents.push_back(std::move(*it));
    }

    // Erase the moved components from the original centipede
    m_C.erase(std::next(m_C.begin(), index), m_C.end());

    // Set the new head for the split centipede
    newComponents.front()->setHead();
    // Return the new centipede
    return std::make_unique<Centipede>(getLength() - index - 1, std::move(newComponents));
}
