/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Defines the class for the state management
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "GameState.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "SimpleScreen.hpp"
#include <memory>

class StateManager {
private:
    // Managers
    NetworkManager networkManager;
    WindowManager windowManager;

    // Tetris
    GameState state;
    std::unique_ptr<Game> game;
    
    // Screens
    Menu menu;
    SimpleScreen host = SimpleScreen("Waiting for connection", windowManager);
    SimpleScreen join = SimpleScreen("Searching for server", windowManager);
    SimpleScreen gameover = SimpleScreen("Game Over", windowManager);
    SimpleScreen youWon = SimpleScreen("You Won", windowManager);
public:
    StateManager() : state(GameState::START_SCREEN) {}

    GameState getCurrentState() const { return state; }
    void changeState(GameState newState, int seed = 42);

    sf::RenderWindow& getWindow();
    bool isRunning();

    void update();
    void render();
};