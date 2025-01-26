#include "Menu.hpp"
#include <iostream>

void Menu::render(WindowManager &windowManager) {
    windowManager.clear();
    
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
        }
    }
    return GameState::NO_CHANGE;
}