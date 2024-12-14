#include <SFML/Graphics.hpp>
#include <vector>

#include "enums.hpp"

class Piece {
private:
    sf::Vector2u position;
    Direction rotation;
    PieceKind kind;
protected:
    std::vector<std::vector<bool>> masks;
    std::vector<bool> mask;
    int currentMask = 0;
    void setMasks(const std::vector<std::vector<bool>>& newMasks) {
        masks = newMasks;
        if (!masks.empty()) {
            mask = masks[0];
            currentMask = 0;
        }
    }
public:
    Piece(sf::Vector2u position, Direction rotation, PieceKind kind) : position(position), rotation(rotation), kind(kind), mask(16, false) {};
    Piece(sf::Vector2u position, PieceKind kind) : position(position), rotation(Direction::UP), kind(kind), mask(16, false) {};
    Piece() {};
    virtual ~Piece() {};
    void move(Direction direction);
    void rotate();
    bool isMaskFilled(int x, int y);

    PieceKind getKind() { return kind; }
    sf::Vector2u getPosition() { return position; }
};