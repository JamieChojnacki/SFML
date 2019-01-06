#include <iostream>
#include "Window.h"

int main() {

    sf::RenderWindow newWindow(sf::VideoMode(1280, 960), "Window");

    while(newWindow.isOpen()) {
        sf::Event event;
        while (newWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                /* close window button clicked */
                newWindow.close();
        }
        newWindow.clear(sf::Color::Black);

        newWindow.display();
    }



    return 0;
}