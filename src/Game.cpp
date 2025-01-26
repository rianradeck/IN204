/**
 * @file Game.cpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Main game's file, handles all the steps of the game
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

void Game::print() { grid.print(); }

void Game::calculateMovement(std::vector<sf::Event> userInput) {
    std::unordered_map<sf::Keyboard::Key, Direction> keyMap = {
        {sf::Keyboard::Left, Direction::LEFT},
        {sf::Keyboard::Right, Direction::RIGHT},
        {sf::Keyboard::Down, Direction::DOWN},
    };

    for (auto event : userInput) {
        if (event.type == sf::Event::KeyPressed) {
            if (keyMap.find(event.key.code) != keyMap.end()) {
                Direction direction = keyMap[event.key.code];
                if (grid.canChange(currentPiece, direction))
                    currentPiece.move(direction);
                return;
            }

            if (event.key.code == sf::Keyboard::Up) {
                // TODO: Wall Kicks https://tetris.wiki/Super_Rotation_System
                if (grid.canChange(currentPiece, Direction::UP))
                    currentPiece.rotate();
                return;
            }

            if (event.key.code == sf::Keyboard::Space) {
                while (grid.canChange(currentPiece, Direction::DOWN))
                    currentPiece.move(Direction::DOWN);
                grid.freezePiece(currentPiece);
                currentPiece = Piece();
                return;
            }
        }
    }
}

void Game::applyGravity() {
    if (currentPiece.getKind() == PieceKind::NONE) return;
    if (!grid.canChange(currentPiece, Direction::DOWN)) {
        grid.freezePiece(currentPiece);
        currentPiece = Piece();
    } else if (grid.canChange(currentPiece, Direction::DOWN))
        currentPiece.move(Direction::DOWN);
}

bool Game::handlePieceChange() {
    if (nextPiece.getKind() == PieceKind::NONE) {
        nextPiece = pieceGenerator.generatePiece();
        nextGrid.update(nextPiece);
    }
    if (currentPiece.getKind() == PieceKind::NONE) {
        currentPiece = nextPiece;
        nextPiece = pieceGenerator.generatePiece();
        nextPiece.setPosition({0, 0});
        nextGrid.update(nextPiece);
        currentPiece.setPosition({4, 0});
        return grid.canChange(currentPiece, Direction::DOWN);    
    }
    return true;
}

bool Game::networkPool(NetworkManager &networkManager) {
    sf::Packet packet;
    networkManager.receive(packet);
    std::string data = "";
    for(int i = 0; i < packet.getDataSize(); i++) {
        data += ((char*)packet.getData())[i];
    }
    // std::cout << "Received: " << data << std::endl;
    if (data.find("Game Over") != std::string::npos)
        return false;
    if (data.find("LINES") != std::string::npos) {
        int linesCleared = std::stoi(std::string(1, data[data.find("LINES") + 5]));
        grid.BlockLines(linesCleared);
    }

    for(int i = 0; i < opponentGrid.getCells().size(); i++) {
        int cell;
        packet >> cell;
        opponentGrid.set(i % opponentGrid.getWidth(), i / opponentGrid.getWidth(), cell);
    }

    packet = sf::Packet();
    for (int cell : grid.getCells())
        packet << cell;
    networkManager.send(packet);

    return true;
}

GameState Game::update(WindowManager &windowManager, NetworkManager &networkManager) {
    if (!handlePieceChange()){
        sf::Packet packet;
        packet << "Game Over";
        networkManager.send(packet);
        sf::sleep(sf::seconds(1));
        return GameState::GAME_OVER;
    }

    std::vector<sf::Event> userInput = windowManager.updateInput();

    calculateMovement(userInput);

    if ((clock.getElapsedTime() - lastTick).asSeconds() > 1.0 / UPDATE_RATE) {
        lastTick = clock.getElapsedTime();
        // Rate dependant code
        applyGravity();
    }

    grid.update(currentPiece);

    int linesCleared = grid.clearFullLines();
    if (linesCleared > 0){
        sf::Packet packet;
        packet << ("LINES" + std::to_string(linesCleared));
        networkManager.send(packet);
    }
    // score += grid.clearFullLines();
    
    if (networkPool(networkManager) == false)
        return GameState::YOU_WON;

    return GameState::NO_CHANGE;
}

void Game::render(WindowManager &windowManager) {
    windowManager.clear();
    sf::Vector2u windowSize = windowManager.getWindowSize();
    sf::Vector2f tileSize = grid.getTileSize();
    grid.render(
        windowManager,
        sf::Vector2f(
            (windowSize.x - tileSize.x * grid.getWidth()) / 2,
            (windowSize.y - tileSize.y * grid.getHeight()) / 2
        )
    );
    nextGrid.render(
        windowManager,
        sf::Vector2f(
            windowSize.x / 2 + grid.getWidth() / 2 * tileSize.x + 50,
            windowSize.y / 2 - nextGrid.getHeight() / 2 * tileSize.y
        )
    );

    tileSize = opponentGrid.getTileSize();
    opponentGrid.render(
        windowManager,
        sf::Vector2f(
            windowSize.x / 2 - grid.getWidth() / 2 * tileSize.x - 150 - opponentGrid.getWidth() * tileSize.x,
            windowSize.y / 2 - opponentGrid.getHeight() / 2 * tileSize.y
        )
    );
    windowManager.display();
}
