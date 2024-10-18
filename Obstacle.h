#pragma once

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

class Obstacle
{
public:
	Obstacle();
	void update(float speed);
	void render(sf::RenderWindow& window) const;
	sf::Vector2f getPosition() const { return sprite.getPosition(); }
	float getWidth() const { return sprite.getGlobalBounds().width;
	}
	sf::FloatRect getBounds();
	float rotationSpeed;

private:
	sf::Sprite sprite;
	sf::Texture texture;
	float x;
	float y;
};

#endif 