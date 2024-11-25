/* Program name: SpaceOdyssey.cpp
*  Author: Anthony Harris
*  Date last updated: 25/11/2024
*  Purpose: Plays game
*/

#include <SFML/Graphics.hpp>
#include "Rocket.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Odyssey");

    // Create a Rocket object
    Rocket player({ 400, 500 });

    sf::Clock clock; // Clock to manage deltaTime
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.moveRocket(clock.restart().asSeconds(), event.key.code);
        }

        // Update logic
        window.clear();
        player.draw(window); // Draw the player
        window.display();
    }

    return 0;
}



//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Odyssey");
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        // Game rendering logic here
//        window.display();
//    }
//
//    return 0;
//}
