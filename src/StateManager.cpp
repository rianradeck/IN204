#include "StateManager.hpp"

sf::RenderWindow& StateManager::getWindow() { return windowManager.getWindow(); }

bool StateManager::isRunning() {
    return windowManager.getWindow().isOpen();
}

void StateManager::changeState(GameState newState) {
    if (newState == GameState::NO_CHANGE) return;

    state = newState;
    if (state == GameState::PLAYING) {
        game = new Game();
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
                changeState(GameState::PLAYING);
            }
            break;
        case GameState::SEARCHING_FOR_SERVER:
            changeState(join.update(windowManager));
            if (networkManager.connectToServer(sf::IpAddress(menu.getIp())) == 0) {
                changeState(GameState::PLAYING);
            }
            break;
        case GameState::YOU_WON:
            networkManager.disconnect();
            changeState(youWon.update(windowManager));
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
