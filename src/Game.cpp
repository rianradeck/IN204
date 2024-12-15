#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

void Game::print() { grid.print(); }

sf::RenderWindow& Game::getWindow() { return windowManager.getWindow(); }

void Game::calculateMovement(std::vector<sf::Event> userInput) {
    std::unordered_map<sf::Keyboard::Key, Direction> keyMap = {
        {sf::Keyboard::Left, Direction::LEFT},
        {sf::Keyboard::Right, Direction::RIGHT},
        {sf::Keyboard::Down, Direction::DOWN},
    };

    for (auto event : userInput) {
        if (event.type == sf::Event::KeyPressed) {
            if (keyMap.find(event.key.code) != keyMap.end()) {
                Direction direction = keyMap[event.key.code];
                if (grid.canChange(currentPiece, direction))
                    currentPiece.move(direction);
            }

            if (event.key.code == sf::Keyboard::Up) {
                // TODO: Wall Kicks
                if (grid.canChange(currentPiece, Direction::UP))
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