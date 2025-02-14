/**
 * @file Grid.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Definition of main grid's controller class
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <tuple>
#include <vector>

#include "PieceGenerator.hpp"
#include "Window.hpp"

class Grid {
private:
    int width, height;
    sf::Vector2f tileSize = {30, 30};
    std::vector<int> cells;
    std::vector<std::tuple<int, int, int>> staticTiles;

public:
    Grid(int width, int height, std::vector<int> cells) : width(width), height(height), cells(cells), staticTiles({}) {};
    Grid(int width, int height) : width(width), height(height), staticTiles({}) {
        cells = std::vector<int>(width * height);
        for (int i = 0; i < width * height; i++) {
            cells[i] = 0;
        }
    }
    ~Grid() {};

    void set(int x, int y, int value);
    int get(int x, int y);
    int getWidth() { return width; }
    int getHeight() { return height; }
    std::vector<int> getCells() { return cells; }
    sf::Vector2f getTileSize() { return tileSize; }
    void setTileSize(sf::Vector2f tileSize) { this->tileSize = tileSize; }
    void print();
    void render(WindowManager &windowManager, sf::Vector2f gridPosition);

    void clearGrid();
    void drawGrid(std::unique_ptr<Piece>& currentPiece);
    void update(std::unique_ptr<Piece>& currentPiece);
    void drawPiece(std::unique_ptr<Piece>& piece);
    void freezePiece(std::unique_ptr<Piece>& piece);
    void drawTile(std::tuple<int, int, int> tile);
    bool canChange(std::unique_ptr<Piece>& currentPiece, Direction direction);
    int clearFullLines();
    void BlockLines(int n_lines);
};