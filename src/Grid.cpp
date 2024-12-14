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

void Grid::render(WindowManager& windowManager) {
    sf::RenderWindow& window = windowManager.getWindow();
    sf::Vector2u windowSize = windowManager.getWindowSize();
    sf::Vector2f tileSize = {30, 30};
    sf::Vector2f gridPosition = {(windowSize.x - tileSize.x*width)/2, (windowSize.y - tileSize.y*height)/2};

    std::unordered_map<int, sf::Color> colors = {
        {0, sf::Color::White},
        {PieceKind::LINE, sf::Color::Cyan},
        {PieceKind::J, sf::Color::Blue},
        {PieceKind::L, sf::Color(255, 165, 0)},
        {PieceKind::SQUARE, sf::Color::Yellow},
        {PieceKind::T, sf::Color::Magenta},
        {PieceKind::S, sf::Color::Green},
        {PieceKind::Z, sf::Color::Red}
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

void Grid::placePiece(Piece piece) {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (piece.isMaskFilled(x, y)) {
                sf::Vector2u position = piece.getPosition();
                PieceKind kind = piece.getKind();
                set(position.x + x, position.y + y, kind);
            }
        }
    }
}

void Grid::clearGrid(){
    for (int i = 0;i < 22 * 10; i++) {
        cells[i] = 0;
    }
}

void Grid::loadGrid(Piece &currentPiece) {
    for(Piece piece : staticPieces) {
        placePiece(piece);
    }
    placePiece(currentPiece);
}

void Grid::update(Piece &currentPiece) {
    clearGrid();
    loadGrid(currentPiece);
}
