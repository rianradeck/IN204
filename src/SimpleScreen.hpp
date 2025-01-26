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
    void update(WindowManager &windowManager) {
        windowManager.updateInput();
    }
};