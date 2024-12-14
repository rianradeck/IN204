#include "Piece.hpp"

void Piece::move(Direction direction) {
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
}

bool Piece::isMaskFilled(int x, int y) {
    return mask[x + y * 4];
}