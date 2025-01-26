/**
 * @file main.cpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Main file to start and keep the game looping
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include "StateManager.hpp"

int main() {
    

    StateManager stateManager;

    while (stateManager.isRunning()) {
        stateManager.update();
        stateManager.render();
    }
}
