/**
 * @file Button.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Definition of the class Button
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <SFML/Graphics.hpp>

#include <string>
#include "Window.hpp"
#include <iostream>

class Button {
private:
    sf::RectangleShape button;
    sf::Text text;
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string _text) {
        button.setSize(size);
        button.setFillColor(color);
        button.setPosition(position);
        button.setOutlineColor(sf::Color::Black);
        button.setOutlineThickness(1);
        
        text.setString(_text);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(position);
    }
    ~Button() {}
    void render(WindowManager &windowManager);
    bool isClicked(sf::Vector2i mousePosition);
};