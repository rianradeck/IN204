#include <SFML/Graphics.hpp>
#include <vector>

#include "enums.hpp"

class Piece {
private:
    sf::Vector2i anchorPosition;
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
    Piece(sf::Vector2u anchorPosition, Direction rotation, PieceKind kind) : anchorPosition(anchorPosition), rotation(rotation), kind(kind), mask(16, false) {};
    Piece(sf::Vector2u anchorPosition, PieceKind kind) : anchorPosition(anchorPosition), rotation(Direction::UP), kind(kind), mask(16, false) {};
    Piece() : kind(PieceKind::NONE) {};
    virtual ~Piece() {};
    void move(Direction direction);
    void rotate();
    bool isMaskFilled(int x, int y);
    void setPosition(sf::Vector2i position) { anchorPosition = position; }

    PieceKind getKind() { return kind; }
    sf::Vector2i getPosition() { return anchorPosition; }
    std::vector<sf::Vector2u> getGridPositions();
};