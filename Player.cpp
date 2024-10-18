#include "Player.h"

Player::Player() {
    if (!texture.loadFromFile("player.png")) {
        // Handle error
    }
    sprite.setTexture(texture);
    sprite.setScale(1.9f, 1.9f);
    sprite.setPosition(100, 600);// Initial position
    velocity = sf::Vector2f(0.0f, 0.0f);
}

void Player::update() {
    if (isJumping) {
        velocity.y += gravity; // Apply gravity
        sprite.move(0, velocity.y);
        if (sprite.getPosition().y >= groundLevel) {
            sprite.setPosition(sprite.getPosition().x, groundLevel);
            isJumping = false;
            velocity.y = 0;
        }
    }
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::jump() {
    if (!isJumping) {
        velocity.y = jumpForce;
        isJumping = true;
    }
}
sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds(); // Return the global bounds of the sprite
}
