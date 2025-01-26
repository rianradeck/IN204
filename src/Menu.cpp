/**
 * @file Menu.cpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Handles the user's menu choice and leads him to the right path
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Menu.hpp"
#include <iostream>

void Menu::render(WindowManager &windowManager) {
    windowManager.clear();
    
    singleButton.render(windowManager);
    hostButton.render(windowManager);
    joinButton.render(windowManager);
    ipInputBox.render(windowManager.getWindow());


    windowManager.display();
}

GameState Menu::update(WindowManager &windowManager) {
    std::vector<sf::Event> userInput = windowManager.updateInput();
    sf::RenderWindow &window = windowManager.getWindow();
    for (auto event : userInput) {
        ipInputBox.handleEvent(event);

        if (event.type == sf::Event::MouseButtonPressed) {
            std::cout << "Mouse button pressed" << std::endl;
            if (hostButton.isClicked(sf::Mouse::getPosition(window))) {
                std::cout << "Host button clicked" << std::endl;
                return GameState::WAITING_FOR_CONNECTION;
            }
            if (joinButton.isClicked(sf::Mouse::getPosition(window)) && ipInputBox.isFilled()) {
                std::cout << "Join button clicked" << std::endl;
                std::cout << "IP Address: " << ipInputBox.getInput() << std::endl;
                return GameState::SEARCHING_FOR_SERVER;
            }
            if (singleButton.isClicked(sf::Mouse::getPosition(window))) {
                std::cout << "Single button clicked" << std::endl;
                return GameState::PLAYING;
            }
        }
    }
    return GameState::NO_CHANGE;
}