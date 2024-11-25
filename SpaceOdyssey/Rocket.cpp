#include "Rocket.h"

Rocket::Rocket(const sf::Vector2f& initPosition)
    : MovingObject(initPosition, { 0, 0 }), health(100), energy(100) {
    shape.setFillColor(sf::Color::Green); // Rocket-specific color
}

void Rocket::moveRocket(float deltaTime, const sf::Keyboard::Key& key) {
    if (key == sf::Keyboard::Left) velocity.x = -200;
    else if (key == sf::Keyboard::Right) velocity.x = 200;
    else if (key == sf::Keyboard::Up) velocity.y = -200;
    else if (key == sf::Keyboard::Down) velocity.y = 200;
    else velocity = { 0, 0 }; // Stop moving if no keys are pressed

    move(deltaTime);
}

void Rocket::takeDamage(int damage) {
    health -= damage;
}

void Rocket::rechargeEnergy(int amount) {
    energy += amount;
}

int Rocket::getHealth() const {
    return health;
}

int Rocket::getEnergy() const {
    return energy;
}