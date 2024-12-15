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

void Grid::render(WindowManager& windowManager, sf::Vector2f gridPosition) {
    sf::RenderWindow& window = windowManager.getWindow();
    sf::Vector2u windowSize = windowManager.getWindowSize();
    if (gridPosition == sf::Vector2f(0, 0)) 
        gridPosition = {(windowSize.x - tileSize.x*width)/2, (windowSize.y - tileSize.y*height)/2};

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
                sf::Vector2i position = piece.getPosition();
                PieceKind kind = piece.getKind();
                set(position.x + x, position.y + y, kind);
            }
        }
    }
}

void Grid::freezePiece(Piece piece) {
    staticPieces.push_back(piece);
}

void Grid::clearGrid(){
    for (int i = 0;i < width * height; i++) {
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
    if (currentPiece.getKind() == PieceKind::NONE) return;
    clearGrid();
    loadGrid(currentPiece);
}

std::vector<sf::Vector2i> getNewPositions(Piece currentPiece, Direction direction){
    std::vector<sf::Vector2i> newPositions;
    if (direction == Direction::UP) {
        currentPiece.rotate();
        for (sf::Vector2u newPos : currentPiece.getGridPositions())
            newPositions.push_back((sf::Vector2i)newPos);
    }
    else {
        for (sf::Vector2u pos : currentPiece.getGridPositions()) 
            newPositions.push_back((sf::Vector2i)pos + sf::Vector2i(
                static_cast<int>((direction == Direction::RIGHT) - (direction == Direction::LEFT)),
                static_cast<int>(direction == Direction::DOWN)
            ));
    }
    return newPositions;
}

bool Grid::canChange(Piece &currentPiece, Direction direction) {
    std::vector<sf::Vector2i> newPositions = getNewPositions(currentPiece, direction);
    std::cout << "New positions: " << std::endl;
    for (sf::Vector2i &newPosition : newPositions) {
        std::cout << "(" << newPosition.x << ", " << newPosition.y << ") ";
    }
    std::cout << std::endl;
    
    for (Piece staticPiece : staticPieces) {
        std::vector<sf::Vector2u> staticPositions = staticPiece.getGridPositions();
        for (sf::Vector2u &pos : staticPositions) {
            for (sf::Vector2i &newPosition : newPositions) {
                if ((sf::Vector2i)pos == newPosition) return false;
            }
        }
    }

    for (sf::Vector2i &newPosition : newPositions) 
        if (newPosition.x < 0 || newPosition.x >= width || newPosition.y >= height) return false;
    
    return true;
}