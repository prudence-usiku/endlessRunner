#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void update();
	void render(sf::RenderWindow& window);
	void jump();
	sf::FloatRect getBounds() const;

private:
	sf::Sprite sprite;
	sf::Texture texture;
	bool isJumping = false;
	sf::Vector2f velocity;
	const float gravity = 0.5f;
	const float jumpForce = -10.0f;
	const float groundLevel = 600.0f;
	
};


#endif 