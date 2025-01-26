/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Handles the randomic generation of pieces throughout the game
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "PieceGenerator.hpp"
#include "Pieces.hpp"

Piece PieceGenerator::generatePiece(){
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 6);
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