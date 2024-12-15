#include <iostream>
#include <vector>

#include "PieceGenerator.hpp"
#include "Window.hpp"

class Grid {
private:
    int width, height;
    std::vector<int> cells;
    std::vector<Piece> staticPieces;

public:
    Grid(int width, int height, std::vector<int> cells) : width(width), height(height), cells(cells), staticPieces({}) {};
    Grid(int width, int height) : width(width), height(height), staticPieces({}) {
        cells = std::vector<int>(width * height);
        for (int i = 0; i < width * height; i++) {
            cells[i] = 0;
        }
    }
    ~Grid() {};

    void set(int x, int y, int value);
    int get(int x, int y);
    void print();
    void render(WindowManager &windowManager);
    void clearGrid();
    void loadGrid(Piece &currentPiece);
    void update(Piece &currentPiece);
    void placePiece(Piece piece);
    bool canChange(Piece &currentPiece, Direction direction);
};