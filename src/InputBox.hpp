#include <SFML/Graphics.hpp>
#include <string>

class InputBox {
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    bool isActive;
    std::string input;
public:
    InputBox(sf::Vector2f position, sf::Vector2f size) {
        box.setPosition(position);
        box.setSize(size);
        box.setFillColor(sf::Color::White);
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(1);

        if (!font.loadFromFile("src/arial.ttf")) {
            // Handle error
        }

        text.setFont(font);
        text.setPosition(position);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);

        isActive = false;
        input = "";
    }

    void render(sf::RenderWindow &window) {
        window.draw(box);
        window.draw(text);
    }

    void handleEvent(sf::Event event) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (box.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                isActive = true;
            } else {
                isActive = false;
            }
        }

        if (isActive && event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b' && !input.empty()) {
                input.pop_back();
            } else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                input += static_cast<char>(event.text.unicode);
            }
            text.setString(input);
        }
    }

    std::string getInput() const {
        return input;
    }

    bool isFilled() const {
        return !input.empty();
    }
};