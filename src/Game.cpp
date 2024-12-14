#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

void Game::print() { grid.print(); }

sf::RenderWindow& Game::getWindow() { return windowManager.getWindow(); }

void Game::calculateMovement(std::vector<sf::Event> userInput) {
    for (auto event : userInput) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                currentPiece.move(Direction::LEFT);
            } else if (event.key.code == sf::Keyboard::Right) {
                currentPiece.move(Direction::RIGHT);
            } else if (event.key.code == sf::Keyboard::Down) {
                currentPiece.move(Direction::DOWN);
            } else if (event.key.code == sf::Keyboard::Up) {
                currentPiece.rotate();
            }
        }
    }
}

void Game::update() {
    std::vector<sf::Event> userInput = windowManager.updateInput();

    // Calculate movement
    calculateMovement(userInput);
    // Calculate gravity TODO

    grid.update(currentPiece);
}

void Game::render() {
    windowManager.clear();
    grid.render(windowManager);
    windowManager.display();
}