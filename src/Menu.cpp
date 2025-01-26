#include "Menu.hpp"
#include <iostream>

void Menu::render(WindowManager &windowManager) {
    windowManager.clear();
    
    hostButton.render(windowManager);
    joinButton.render(windowManager);

    windowManager.display();
}

GameState Menu::update(WindowManager &windowManager) {
    std::vector<sf::Event> userInput = windowManager.updateInput();
    sf::RenderWindow &window = windowManager.getWindow();
    for (auto event : userInput) {
        if (event.type == sf::Event::MouseButtonPressed) {
            std::cout << "Mouse button pressed" << std::endl;
            if (hostButton.isClicked(sf::Mouse::getPosition(window))) {
                std::cout << "Host button clicked" << std::endl;
                return GameState::WAITING_FOR_CONNECTION;
            }
            if (joinButton.isClicked(sf::Mouse::getPosition(window))) {
                std::cout << "Join button clicked" << std::endl;
                return GameState::SEARCHING_FOR_SERVER;
            }
        }
    }
    return GameState::START_SCREEN;
}