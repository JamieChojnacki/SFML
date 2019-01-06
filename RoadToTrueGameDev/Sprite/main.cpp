#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(1280, 960), "Using sprite");

    /* prepare sprite */
    sf::Texture skiTexture;
    skiTexture.loadFromFile("image/skier.jpg");
    sf::Sprite skier(skiTexture);

    sf::Vector2u size = skiTexture.getSize();
    skier.setOrigin(size.x / 2, size.y / 2);
    sf::Vector2f increment(0.4f, 0.4f);  /* move sprite sequence */


    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                /* close window button clicked */
                window.close();
        }
        if( (skier.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) ||
                (skier.getPosition().x - (size.x / 2) < 0 && increment.x < 0)){
            /* reverse the direction on X axis */
            increment.x = -increment.x;
        }

        if( (skier.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) ||
            (skier.getPosition().y - (size.y / 2) < 0 && increment.y < 0)){
            /* reverse the direction on Y axis */
            increment.y = -increment.y;
        }

        skier.setPosition(skier.getPosition() + increment);

        window.clear(sf::Color::Black);
        window.draw(skier);  // drawing rectangle shape
        window.display();
    }

    return 0;
}