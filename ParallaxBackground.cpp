#include "ParallaxBackground.h"

ParallaxBackground::ParallaxBackground(const std::vector<std::string>& textures, const std::vector<float>& speeds)
    : speeds(speeds) {
    // Load textures and create sprites
    for (const auto& textureFile : textures) {
        sf::Texture texture;
        if (!texture.loadFromFile(textureFile)) {
            // Handle error
        }
        layers.emplace_back(texture); // Create sprite with the loaded texture
        layers.back().setPosition(layers.size() * 1280, 300); // Set initial position (adjust based on texture width)
    }
    windowWidth = 1280;
}

void ParallaxBackground::update(float playerSpeed) {
    for (size_t i = 0; i < layers.size(); ++i) {
        // Move each layer based on the player's speed and its specific parallax speed
        layers[i].move(-playerSpeed * speeds[i] * (1.0f / 60.0f), 0);

        // Reset position if the layer moves off-screen
        if (layers[i].getPosition().x < -layers[i].getGlobalBounds().width) {
            layers[i].setPosition(layers[(i + 1) % layers.size()].getPosition().x + layers[(i + 1) % layers.size()].getGlobalBounds().width, 0);
        }
    }
}

void ParallaxBackground::render(sf::RenderWindow& window) const {
    for (const auto& layer : layers) {
        window.draw(layer);
    }
}
