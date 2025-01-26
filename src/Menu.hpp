#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Button.hpp"
#include "GameState.hpp"

class Menu {
private:
    Button hostButton = Button({100, 100}, {100, 50}, sf::Color::Green, "Host");
    Button joinButton = Button({100, 200}, {100, 50}, sf::Color::Green, "Join");
public:
    Menu() {}
    ~Menu() {}
    void render(WindowManager &windowManager);
    GameState update(WindowManager &windowManager);
};