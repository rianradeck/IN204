#include "Menu.hpp"
#include <iostream>

void Menu::render(WindowManager &windowManager) {
    windowManager.clear();
    
    playButton.render(windowManager);

    windowManager.display();
}

GameState Menu::update(WindowManager &windowManager) {
    std::vector<sf::Event> userInput = windowManager.updateInput();
    sf::RenderWindow &window = windowManager.getWindow();
    for (auto event : userInput) {
        if (event.type == sf::Event::MouseButtonPressed) {
            std::cout << "Mouse button pressed" << std::endl;
            if (playButton.isClicked(sf::Mouse::getPosition(window))) {
                std::cout << "Play button clicked" << std::endl;
                return GameState::PLAYING;
            }
        }
    }
    return GameState::START_SCREEN;
}