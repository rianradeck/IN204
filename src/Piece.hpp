#include <SFML/Graphics.hpp>
#include <vector>

#include "enums.hpp"

class Piece {
private:
    sf::Vector2u position;
    Direction rotation;
    PieceKind kind;
protected:
    std::vector<bool> mask;
public:
    Piece(sf::Vector2u position, Direction rotation, PieceKind kind) : position(position), rotation(rotation), kind(kind), mask(16, false) {};
    Piece(sf::Vector2u position, PieceKind kind) : position(position), rotation(Direction::UP), kind(kind), mask(16, false) {};
    Piece() {};
    virtual ~Piece() {};
    void move(Direction direction);
    bool isMaskFilled(int x, int y);

    PieceKind getKind() { return kind; }
    sf::Vector2u getPosition() { return position; }
};