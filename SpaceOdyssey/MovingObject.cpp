#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2f& initPosition, const sf::Vector2f& initVelocity)
    : position(initPosition), velocity(initVelocity) {
    shape.setSize({ 50.f, 50.f }); // Default size
    shape.setFillColor(sf::Color::White); // Default color
    shape.setPosition(position);
}

void MovingObject::move(float deltaTime) {
    position += velocity * deltaTime; // Update position based on velocity
    shape.setPosition(position); // Update shape position
}

void MovingObject::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f MovingObject::getPosition() const {
    return position;
}

void MovingObject::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;
    shape.setPosition(position);
}