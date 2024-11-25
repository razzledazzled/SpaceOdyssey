#ifndef ROCKET_H
#define ROCKET_H

#include "MovingObject.h"

class Rocket : public MovingObject {
private:
    int health;
    int energy;

public:
    Rocket(const sf::Vector2f& initPosition);

    void moveRocket(float deltaTime, const sf::Keyboard::Key& key);
    void takeDamage(int damage);
    void rechargeEnergy(int amount);

    int getHealth() const;
    int getEnergy() const;
};

#endif // ROCKET_H