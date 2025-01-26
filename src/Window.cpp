/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Handles the window configuration
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Window.hpp"
#include <iostream>


std::vector<sf::Event> WindowManager::updateInput() {
    sf::RenderWindow& window = this->getWindow();
    std::vector<sf::Event> events;
    for (auto event = sf::Event(); window.pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        events.push_back(event);
        // std::cout << event.key.code << " ";
    }
    return events;
    
    // std::cout << "\n";
}