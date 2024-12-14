#include "PieceGenerator.hpp"
#include "Pieces.hpp"

Piece PieceGenerator::generatePiece(){
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 7);
    int random = dist(randomGenerator);
    switch (random) {
        case 0:
            return LinePiece(defaultPosition);
        case 1:
            return JPiece(defaultPosition);
        case 2:
            return LPiece(defaultPosition);
        case 3:
            return SquarePiece(defaultPosition);
        case 4:
            return SPiece(defaultPosition);
        case 5:
            return TPiece(defaultPosition);
        case 6:
            return ZPiece(defaultPosition);
    }
    return Piece();
}