#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>


void Game::print() { grid.print(); }

sf::RenderWindow& Game::getWindow() { return windowManager.getWindow(); }

void Game::update() {
    std::vector<sf::Event> userInput = windowManager.updateInput();

    grid.update(userInput);
}

void Game::render() {
    
    windowManager.clear();
    grid.render(windowManager);
    windowManager.display();
}