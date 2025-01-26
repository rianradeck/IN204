#include "StateManager.hpp"

sf::RenderWindow& StateManager::getWindow() { return windowManager.getWindow(); }

bool StateManager::isRunning() {
    return windowManager.getWindow().isOpen();
}

void StateManager::changeState(GameState newState) {
    state = newState;
    if (state == GameState::PLAYING) {
        game = Game(); // Will need to build with IP
    } else if (state == GameState::WAITING_FOR_CONNECTION) {
        networkManager.listen();
    }
}

void StateManager::update() {
    switch (state) {
        case GameState::START_SCREEN:
            changeState(menu.update(windowManager));
            break;
        case GameState::PLAYING:
            game.update(windowManager);
            break;
        case GameState::GAME_OVER:
            break;
        case GameState::WAITING_FOR_CONNECTION:
            host.update(windowManager);
            networkManager.accept();
            if (networkManager.getConnectionStatus() == sf::Socket::Status::Done) {
                changeState(GameState::PLAYING);
            }
            break;
        case GameState::SEARCHING_FOR_SERVER:
            join.update(windowManager);
            if (networkManager.connectToServer(sf::IpAddress("127.0.0.1")) == 0) {
                changeState(GameState::PLAYING);
            }
            break;
    }
}

void StateManager::render(){
    switch (state) {
        case GameState::START_SCREEN:
            menu.render(windowManager);
            break;
        case GameState::PLAYING:
            game.render(windowManager);
            break;
        case GameState::GAME_OVER:
            break;
        case GameState::WAITING_FOR_CONNECTION:
            host.render(windowManager);
            break;
        case GameState::SEARCHING_FOR_SERVER:
            join.render(windowManager);
            break;
    }
}
