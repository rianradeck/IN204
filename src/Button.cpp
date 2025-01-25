#include "Button.hpp"

void Button::render(WindowManager &windowManager) {
    sf::RenderWindow &window = windowManager.getWindow();
    window.draw(button);
    sf::Font font;
    if(!font.loadFromFile("src/arial.ttf")){
        std::cout << "Font not loaded" << std::endl;
    }
    text.setFont(font);
    window.draw(text);
}

bool Button::isClicked(sf::Vector2i mousePosition) {
    return button.getGlobalBounds().contains(mousePosition.x, mousePosition.y);
}
