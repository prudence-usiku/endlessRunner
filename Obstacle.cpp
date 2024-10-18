#include "Obstacle.h"

Obstacle::Obstacle() {
        if (!texture.loadFromFile("obstacle.png")) {
            // Handle error
        }
        sprite.setTexture(texture);
        x = 1280; // Start off-screen
        y = 600;
        sprite.setPosition(x, y);
        rotationSpeed = 90.0f;
}


    void Obstacle::update(float speed) {
        // Move the obstacle to the left
        sprite.move(-speed, 0);
        sprite.rotate(-rotationSpeed * (1.0f / 60.0f));
    }

    void Obstacle::render(sf::RenderWindow& window) const {
        window.draw(sprite);
    }
    sf::FloatRect Obstacle::getBounds() {
        return sprite.getGlobalBounds();
    }
