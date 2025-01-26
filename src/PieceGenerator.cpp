#include "PieceGenerator.hpp"
#include "Pieces.hpp"

std::unique_ptr<Piece> PieceGenerator::generatePiece() {
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 6);
    int random = dist(randomGenerator);
    switch (random) {
        case 0:
            return std::make_unique<LinePiece>(defaultPosition);
        case 1:
            return std::make_unique<JPiece>(defaultPosition);
        case 2:
            return std::make_unique<LPiece>(defaultPosition);
        case 3:
            return std::make_unique<SquarePiece>(defaultPosition);
        case 4:
            return std::make_unique<SPiece>(defaultPosition);
        case 5:
            return std::make_unique<TPiece>(defaultPosition);
        case 6:
            return std::make_unique<ZPiece>(defaultPosition);
    }
    return std::make_unique<Piece>();
}