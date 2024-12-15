#include "Piece.hpp"

#include <iostream>

void Piece::move(Direction direction) {
    std::cout << "Old Anchor Position: " << anchorPosition.x << ", " << anchorPosition.y << std::endl;
    std::cout << "Direction: " << direction << std::endl;
    anchorPosition.x += (direction == Direction::RIGHT) - (direction == Direction::LEFT);
    anchorPosition.y += (direction == Direction::DOWN) - (direction == Direction::UP);
    std::cout << "New Anchor Position: " << anchorPosition.x << ", " << anchorPosition.y << std::endl;
}

void Piece::rotate() {
    currentMask = (currentMask + 1) % masks.size();
    std::cout << "Rotating to mask " << currentMask << std::endl;
    mask = masks[currentMask];
}

bool Piece::isMaskFilled(int x, int y) {
    return mask[x + y * 4];
}

std::vector<sf::Vector2u> Piece::getGridPositions() {
    std::vector<sf::Vector2u> positions;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (isMaskFilled(x, y)) {
                positions.push_back({(unsigned)(anchorPosition.x + x), (unsigned)(anchorPosition.y + y)});
            }
        }
    }

    // std::cout << "Piece anchorPosition: " << anchorPosition.x << ", " << anchorPosition.y << std::endl;
    // std::cout << "Positions: " << std::endl;
    // for (auto pos : positions) {
    //     std::cout << pos.x << ", " << pos.y << std::endl;
    // }
    return positions;
}