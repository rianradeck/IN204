/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Defines a simple screen with a text to inform the user of the current status of the game
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Window.hpp"

class SimpleScreen {
private:
    sf::Text text;
    sf::Font font;
public:
    SimpleScreen(std::string text, WindowManager &windowManager) {
        font.loadFromFile("src/arial.ttf");
        this->text.setFont(font);
        this->text.setString(text);
        this->text.setCharacterSize(24);
        this->text.setFillColor(sf::Color::White);
        sf::Vector2u windowSize = windowManager.getWindow().getSize();
        this->text.setPosition(
            windowSize.x / 2 - this->text.getGlobalBounds().width / 2,
            windowSize.y / 2 - this->text.getGlobalBounds().height / 2
        );
    }
    ~SimpleScreen() {}
    void render(WindowManager &windowManager) {
        windowManager.clear();
        sf::RenderWindow &window = windowManager.getWindow();
        window.draw(text);
        window.display();
    }
    GameState update(WindowManager &windowManager) {
        sf::RenderWindow& window = windowManager.getWindow();
        std::vector<sf::Event> events = windowManager.updateInput();
        for (sf::Event event : events) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return GameState::START_SCREEN;
            }
        }
        return GameState::NO_CHANGE;
    }
};