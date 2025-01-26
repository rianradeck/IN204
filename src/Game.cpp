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
            }

            if (event.key.code == sf::Keyboard::Up) {
                // TODO: Wall Kicks https://tetris.wiki/Super_Rotation_System
                if (grid.canChange(currentPiece, Direction::UP))
                    currentPiece.rotate();
            }

            if (event.key.code == sf::Keyboard::Space) {
                while (grid.canChange(currentPiece, Direction::DOWN))
                    currentPiece.move(Direction::DOWN);
                grid.freezePiece(currentPiece);
                currentPiece = Piece();
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

void Game::handlePieceChange() {
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
    }
}

void Game::update(WindowManager &windowManager) {
    handlePieceChange();

    std::vector<sf::Event> userInput = windowManager.updateInput();

    calculateMovement(userInput);

    if ((clock.getElapsedTime() - lastTick).asSeconds() > 1.0 / UPDATE_RATE) {
        lastTick = clock.getElapsedTime();
        // Rate dependant code
        applyGravity();
    }

    grid.update(currentPiece);

    // TODO: Add score properly
    score += grid.clearFullLines();
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
            windowSize.x / 2 - grid.getWidth() / 2 * tileSize.x - 50 - opponentGrid.getWidth() * tileSize.x,
            windowSize.y / 2 - opponentGrid.getHeight() / 2 * tileSize.y
        )
    );
    windowManager.display();
}
