#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class ParallaxBackground {
public:
    ParallaxBackground(const std::vector<std::string>& textures, const std::vector<float>& speeds);
    void update(float playerSpeed);
    void render(sf::RenderWindow& window) const;

private:
    std::vector<sf::Sprite> layers;
    std::vector<float> speeds;
    float windowWidth;
};
