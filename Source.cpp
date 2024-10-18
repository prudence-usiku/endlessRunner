#include <iostream>
#include <vector>
#include <random>


#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Obstacle.h"
#include "ParallaxBackground.h"

int main() {
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Endless Runner");
    window.setFramerateLimit(60); 

    // Random number generation setup
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::uniform_real_distribution<float> distr(1.0f, 3.0f); // Define the range for spawnInterval


    Player player;
    std::vector<Obstacle> obstacles; // Vector to hold obstacles
    float spawnTimer = 0.0f; // Timer for obstacle spawning
    float spawnInterval = distr(eng); // Time between spawns
    float obstacleSpeed = 5.0f;

    // Create parallax background
    std::vector<std::string> textures = { "1.png", "2.png", "3.png", "4.png", "5.png" };
    std::vector<float> speeds = { 1, 2, 3, 4, 5 };
    ParallaxBackground parallax(textures, speeds);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.jump();
        }

        // Update spawn timer and spawn obstacles
        spawnTimer += clock.restart().asSeconds();
        if (spawnTimer >= spawnInterval) {
            obstacles.emplace_back(); // Create a new obstacle
            spawnTimer = 0.0f; // Reset the spawn timer

            spawnInterval = distr(eng);
        }

        player.update();
        parallax.update(obstacleSpeed * 5);
        // Update obstacles
        for (auto& obstacle : obstacles) {
            obstacle.update(obstacleSpeed);
        }

        // Remove off-screen obstacles
        obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(), [](const Obstacle& o) {
            return o.getPosition().x < -o.getWidth(); // Assuming Obstacle has a method to get its width
            }), obstacles.end());

        window.clear();

        player.render(window);
        parallax.render(window);

// Render obstacles
        for (const auto& obstacle : obstacles) {
            obstacle.render(window);
        }
        for (auto& obstacle : obstacles) {
            if (player.getBounds().intersects(obstacle.getBounds())) {
               
                std::cout << "Collision detected! Player flies up!" << std::endl;
                break; // Exit loop to prevent multiple collisions in one frame
            }
        }

        window.display();
    }

    return 0;
}
