/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Define design aspects of the initial menu
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <SFML/Graphics.hpp>
#include <string>

#include "Window.hpp"
#include "Button.hpp"
#include "GameState.hpp"
#include "InputBox.hpp"

class Menu {
private:
    Button singleButton = Button({100, 100}, {100, 50}, sf::Color::Green, "Single");
    Button hostButton = Button({100, 200}, {100, 50}, sf::Color::Green, "Host");
    Button joinButton = Button({100,300}, {100, 50}, sf::Color::Green, "Join");
    InputBox ipInputBox = InputBox({100, 400}, {200, 50});
public:
    Menu() {}
    ~Menu() {}
    void render(WindowManager &windowManager);
    GameState update(WindowManager &windowManager);
    std::string getIp() { return ipInputBox.getInput(); }
};