#include "StateManager.hpp"

sf::RenderWindow& StateManager::getWindow() { return windowManager.getWindow(); }

bool StateManager::isRunning() {
    return windowManager.getWindow().isOpen();
}

void StateManager::changeState(GameState newState) {
    state = newState;
    if (state == GameState::PLAYING) {
        game = Game(); // Will need to build with IP
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
    }
}
