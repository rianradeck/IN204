#pragma once

#include "GameState.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "Network.hpp"
#include "SimpleScreen.hpp"

class StateManager {
private:
    GameState state;
    NetworkManager networkManager;
    Game game;
    Menu menu;
    WindowManager windowManager;
    SimpleScreen host = SimpleScreen("Waiting for connection", windowManager);
    SimpleScreen join = SimpleScreen("Searching for server", windowManager);
public:
    StateManager() : state(GameState::START_SCREEN) {}

    GameState getCurrentState() const { return state; }
    void changeState(GameState newState);

    sf::RenderWindow& getWindow();
    bool isRunning();

    void update();
    void render();
};