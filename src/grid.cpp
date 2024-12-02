#include "grid.hpp"

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

Grid::~Grid() {
    
}