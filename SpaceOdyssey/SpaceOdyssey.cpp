/* Program name: SpaceOdyssey.cpp
*  Author: Anthony Harris
*  Date last updated: 25/11/2024
*  Purpose: Plays game
*/

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Odyssey");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Game rendering logic here
        window.display();
    }

    return 0;
}
