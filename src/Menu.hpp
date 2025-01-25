#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Button.hpp"
#include "GameState.hpp"

class Menu {
private:
    Button playButton = Button({100, 100}, {100, 50}, sf::Color::Green, "Play");
public:
    Menu() {}
    ~Menu() {}
    void render(WindowManager &windowManager);
    GameState update(WindowManager &windowManager);
};