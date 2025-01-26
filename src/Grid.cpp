/**
 * @file Grid.cpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Defines all the functions concerning the game's grid, as full lines, block enemy's lines and the possibilities of moves for the pieces
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Grid.hpp"

#include <unordered_map>

void Grid::set(int x, int y, int value) {
    cells[y * width + x] = value;
}

int Grid::get(int x, int y) {
    return cells[y * width + x];
}

void Grid::print() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << get(x, y) << " ";
        }
        std::cout << "\n";
    }
}

void Grid::render(WindowManager &windowManager, sf::Vector2f gridPosition) {
    sf::RenderWindow &window = windowManager.getWindow();
    sf::Vector2u windowSize = windowManager.getWindowSize();
    if (gridPosition == sf::Vector2f(0, 0))
        gridPosition = {(windowSize.x - tileSize.x * width) / 2, (windowSize.y - tileSize.y * height) / 2};

    std::unordered_map<int, sf::Color> colors = {
        {0, sf::Color::White},
        {PieceKind::LINE, sf::Color::Cyan},
        {PieceKind::J, sf::Color::Blue},
        {PieceKind::L, sf::Color(255, 165, 0)},
        {PieceKind::SQUARE, sf::Color::Yellow},
        {PieceKind::T, sf::Color::Magenta},
        {PieceKind::S, sf::Color::Green},
        {PieceKind::Z, sf::Color::Red},
        {PieceKind::BLOCKED, sf::Color(128, 128, 128)}
    };

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int cellValue = get(x, y);
            sf::Color color = colors[cellValue];
            sf::RectangleShape rect;
            rect.setSize(tileSize);
            rect.setPosition(gridPosition.x + x * tileSize.x, gridPosition.y + y * tileSize.y);
            rect.setFillColor(color);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1);

            window.draw(rect);
        }
    }
}

void Grid::drawPiece(Piece piece) {
    if (piece.getKind() == PieceKind::NONE) return;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (piece.isMaskFilled(x, y)) {
                sf::Vector2i position = piece.getPosition();
                PieceKind kind = piece.getKind();
                set(position.x + x, position.y + y, kind);
            }
        }
    }
}

void Grid::drawTile(std::tuple<int, int, int> tile) {
    int tileX, tileY, tileKind;
    std::tie(tileX, tileY, tileKind) = tile;
    set(tileX, tileY, tileKind);
}

void Grid::freezePiece(Piece piece) {
    for (sf::Vector2 tile : piece.getGridPositions()) {
        staticTiles.push_back({tile.x, tile.y, piece.getKind()});
    }
}

void Grid::clearGrid() {
    for (int i = 0; i < width * height; i++) {
        cells[i] = 0;
    }
}

void Grid::drawGrid(Piece &currentPiece) {
    for (std::tuple<int, int, int> tile : staticTiles) {
        drawTile(tile);
    }
    if (currentPiece.getKind() != PieceKind::NONE)
        drawPiece(currentPiece);
}

void Grid::update(Piece &currentPiece) {
    clearGrid();
    drawGrid(currentPiece);
}

std::vector<sf::Vector2i> getNewPositions(Piece currentPiece, Direction direction) {
    std::vector<sf::Vector2i> newPositions;
    if (direction == Direction::UP) {
        currentPiece.rotate();
        for (sf::Vector2u newPos : currentPiece.getGridPositions())
            newPositions.push_back((sf::Vector2i)newPos);
    } else {
        for (sf::Vector2u pos : currentPiece.getGridPositions())
            newPositions.push_back((sf::Vector2i)pos + sf::Vector2i((int)((direction == Direction::RIGHT) - (direction == Direction::LEFT)), (int)(direction == Direction::DOWN)));
    }
    return newPositions;
}

bool Grid::canChange(Piece &currentPiece, Direction direction) {
    std::vector<sf::Vector2i> newPositions = getNewPositions(currentPiece, direction);
    // std::cout << "New positions: " << std::endl;
    // for (sf::Vector2i &newPosition : newPositions) {
    //     std::cout << "(" << newPosition.x << ", " << newPosition.y << ") ";
    // }
    // std::cout << std::endl;

    for (auto [tileX, tileY, _] : staticTiles)
        for (sf::Vector2i &newPosition : newPositions)
            if (newPosition == sf::Vector2i(tileX, tileY)) return false;

    for (sf::Vector2i &newPosition : newPositions)
        if (newPosition.x < 0 || newPosition.x >= width || newPosition.y >= height) return false;

    return true;
}

int Grid::clearFullLines() {
    int linesCleared = 0;
    for (int y = height - 1; y >= 0; y--) {
        bool fullLine = true;
        for (int x = 0; x < width; x++)
            if (get(x, y) == PieceKind::NONE || get(x, y) == PieceKind::BLOCKED) fullLine = false;
        if (fullLine) {
            std::cout << "Line " << y << " is full" << std::endl;
            // print();
            linesCleared++;
            for (int _y = y; _y > 1; _y--) {
                for (int x = 0; x < width; x++) {
                    if (!get(x, _y)) continue;

                    staticTiles.erase(std::remove(staticTiles.begin(), staticTiles.end(), std::make_tuple(x, _y, get(x, _y))), staticTiles.end());
                    if (get(x, _y - 1)) {
                        staticTiles.erase(std::remove(staticTiles.begin(), staticTiles.end(), std::make_tuple(x, _y - 1, get(x, _y - 1))), staticTiles.end());
                        staticTiles.push_back({x, _y, get(x, _y - 1)});
                    }

                    set(x, _y, get(x, _y - 1));
                }
            }
            y++;
        }
    }

    return linesCleared;
}

void Grid::BlockLines(int n_lines){
    std::cout << "Blocking " << n_lines << " lines" << std::endl;
    for (int i = 0, y = height-1; i < n_lines; i++, y--){
        for (int j = 0; j < width; j++){
            if (get(j, y) == PieceKind::BLOCKED){
                i--;
                break;
            }
            set(j, i, PieceKind::BLOCKED);
            staticTiles.push_back({j, y, PieceKind::BLOCKED});
        }
    }
}