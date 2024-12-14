#include "Piece.hpp"
#include <iostream>

void Piece::move(Direction direction) {
    std::cout << "Old position: " << position.x << ", " << position.y << std::endl;
    std::cout << "Direction: " << direction << std::endl;
    switch (direction) {
        case Direction::LEFT:
            position.x--;
            break;
        case Direction::RIGHT:
            position.x++;
            break;
        case Direction::DOWN:
            position.y++;
            break;
        case Direction::UP:
            position.y--;
            break;
    }
    std::cout << "New position: " << position.x << ", " << position.y << std::endl; 
}

void Piece::rotate() {
    std::cout << "Masks size: " << masks.size() << std::endl;
    std::cout << "Rotating to mask " << currentMask << std::endl;
    currentMask = (currentMask + 1) % masks.size();
    mask = masks[currentMask];
}

bool Piece::isMaskFilled(int x, int y) {
    return mask[x + y * 4];
}