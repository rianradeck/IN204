/**
 * @file StateManager.cpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Handles the current state of the game and leads the appropriated modifications
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <chrono>
#include <memory>

#include "StateManager.hpp"

sf::RenderWindow& StateManager::getWindow() { return windowManager.getWindow(); }

bool StateManager::isRunning() {
    return windowManager.getWindow().isOpen();
}

void StateManager::changeState(GameState newState, int seed) {
    if (newState == GameState::NO_CHANGE) return;
    bool isOnlineGame = (state == GameState::WAITING_FOR_CONNECTION || state == GameState::SEARCHING_FOR_SERVER);

    state = newState;
    if (state == GameState::PLAYING) {
        std::cout << "Starting new game with seed: " << seed << std::endl;
        game = std::make_unique<Game>(seed, isOnlineGame);
    } else if (state == GameState::WAITING_FOR_CONNECTION) {
        if(networkManager.listen() == -1) {
            changeState(GameState::START_SCREEN);
        }
    }
}

void StateManager::update() {
    switch (state) {
        case GameState::START_SCREEN:
            networkManager.disconnect();
            changeState(menu.update(windowManager));
            break;
        case GameState::PLAYING:
            changeState(game->update(windowManager, networkManager));
            break;
        case GameState::GAME_OVER:
            networkManager.disconnect();
            changeState(gameover.update(windowManager));
            break;
        case GameState::WAITING_FOR_CONNECTION:
            changeState(host.update(windowManager));
            networkManager.accept();
            if (networkManager.getConnectionStatus() == sf::Socket::Status::Done) {
                // Get seed from current time
                auto now = std::chrono::system_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
                int seed = static_cast<int>(duration.count() % 10000);
                
                networkManager.send_data(seed);
                changeState(GameState::PLAYING, seed);
            }
            break;
        case GameState::SEARCHING_FOR_SERVER:
            changeState(join.update(windowManager));
            if (networkManager.connectToServer(sf::IpAddress((menu.getIp() != "") ? menu.getIp() : "127.0.0.1")) == 0) {
                int seed;
                networkManager.receive_data(seed);
                changeState(GameState::PLAYING, seed);
            }
            break;
        case GameState::YOU_WON:
            networkManager.disconnect();
            changeState(youWon.update(windowManager));
            break;
        case GameState::EXIT:
            networkManager.disconnect();
            break;
    }
}

void StateManager::render(){
    switch (state) {
        case GameState::START_SCREEN:
            menu.render(windowManager);
            break;
        case GameState::PLAYING:
            game->render(windowManager);
            break;
        case GameState::GAME_OVER:
            gameover.render(windowManager);
            break;
        case GameState::WAITING_FOR_CONNECTION:
            host.render(windowManager);
            break;
        case GameState::SEARCHING_FOR_SERVER:
            join.render(windowManager);
            break;
        case GameState::YOU_WON:
            youWon.render(windowManager);
            break;
    }
}
