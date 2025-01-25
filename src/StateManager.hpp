#pragma once

#include "GameState.hpp"
#include "Game.hpp"
#include "Menu.hpp"

class StateManager {
private:
    GameState state;
    Game game;
    Menu menu;
    WindowManager windowManager;
public:
    StateManager() : state(GameState::START_SCREEN) {}

    GameState getCurrentState() const { return state; }
    void changeState(GameState newState);

    sf::RenderWindow& getWindow();
    bool isRunning();

    void update();
    void render();
};