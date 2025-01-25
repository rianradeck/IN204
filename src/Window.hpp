#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


class WindowManager {
private:
    const sf::Vector2u WINDOW_SIZE{1080u, 720u};
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode{WINDOW_SIZE.x,WINDOW_SIZE.y}, "Tetris");
    sf::Texture backgroundTexture;

public:

    WindowManager() {
        window.setFramerateLimit(60);
        backgroundTexture.loadFromFile("src/tetris.png");
    };
    ~WindowManager() {};

    sf::RenderWindow& getWindow() { return window; }
    void clear() { 
        window.clear(); 
        sf::Sprite background(backgroundTexture);
        window.draw(background);
    };
    void display() { window.display(); };
    std::vector<sf::Event> updateInput();
    sf::Vector2u getWindowSize() { return WINDOW_SIZE; };
};
