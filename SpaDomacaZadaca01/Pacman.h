#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Pacman {
public:
    Pacman(sf::RenderWindow* window);

    void draw();   // Draws Pac-Man and dots

private:
    sf::RenderWindow* window;
    sf::CircleShape pacMan; // Pac-Man character
    float xPosition; // Pac-Man's x position
    float yPosition; // Pac-Man's y position
    float movementSpeed; // Pac-Man's movement speed
    float mouthAngle; // Angle for Pac-Man's mouth animation
    bool opening; // Flag indicating whether Pac-Man's mouth is opening or closing

    std::vector<sf::CircleShape> dots; // Vector to hold dots
};
