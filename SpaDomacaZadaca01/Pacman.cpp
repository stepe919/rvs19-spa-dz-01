#include "Pacman.h"
#include <cmath>

Pacman::Pacman(sf::RenderWindow* window) : window(window), xPosition(400.f), yPosition(300.f), movementSpeed(1.f), mouthAngle(45.f), opening(true) {
    // Initialize Pac-Man
    pacMan.setRadius(20.f);
    pacMan.setFillColor(sf::Color::Yellow);
    pacMan.setPointCount(30);
    pacMan.setOrigin(20.f, 20.f);

    // Initialize dots along the same axis as Pac-Man
    for (int i = 0; i < 10; ++i) {
        sf::CircleShape dot(5.f);
        dot.setFillColor(sf::Color::White);
        dot.setPosition(50.f * i, yPosition); // Align dots with Pac-Man's y-position
        dots.push_back(dot);
    }
}

void Pacman::draw() {
    // Update Pac-Man's mouth animation
    if (opening) {
        mouthAngle -= 1.5f;
        if (mouthAngle <= 0.f)
            opening = false;
    }
    else {
        mouthAngle += 1.5f;
        if (mouthAngle >= 45.f)
            opening = true;
    }

    // Update Pac-Man's position
    xPosition += movementSpeed;
    if (xPosition > 800.f) // Wrap around the screen
        xPosition = 0.f;

    // Set Pac-Man's position and rotation
    pacMan.setPosition(xPosition, yPosition);
    pacMan.setRotation(0.f); // Reset rotation

    // Draw Pac-Man
    window->draw(pacMan);

    // Draw Pac-Man's mouth
    sf::CircleShape mouth;
    mouth.setRadius(20.f);
    mouth.setPointCount(30);
    mouth.setFillColor(sf::Color::Black);
    mouth.setOrigin(0.f, 20.f);
    mouth.setPosition(pacMan.getPosition());
    mouth.setRotation(-mouthAngle);
    window->draw(mouth);

    // Check for collision with dots
    for (auto it = dots.begin(); it != dots.end(); ++it) {
        if (pacMan.getGlobalBounds().intersects(it->getGlobalBounds())) {
            // Pac-Man ate the dot, remove it
            it = dots.erase(it);
            if (it == dots.end()) break; // Check if it reached the end
        }
    }

    // Draw dots
    for (const auto& dot : dots) {
        window->draw(dot);
    }
}
