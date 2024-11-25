#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include <SFML/Graphics.hpp>

class MovingObject {
protected:
    sf::Vector2f position; // Current position
    sf::Vector2f velocity; // Speed and direction
    sf::RectangleShape shape; // Visual representation

public:
    MovingObject(const sf::Vector2f& initPosition, const sf::Vector2f& initVelocity);

    void move(float deltaTime);
    void draw(sf::RenderWindow& window); // Render the object
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& newPosition);
};

#endif // MOVINGOBJECT_H