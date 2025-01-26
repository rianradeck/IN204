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
            if (hostButton.isClicked(sf::Mouse::getPosition(window))) {
                return GameState::WAITING_FOR_CONNECTION;
            }
            if (joinButton.isClicked(sf::Mouse::getPosition(window))) {
                if (ipInputBox.getInput().empty()) 
                    std::cout << "IP Address is empty, defaulting to localhost" << std::endl;
                else
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