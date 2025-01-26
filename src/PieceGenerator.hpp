/**
 * @file Menu.hpp
 * @author Rian Radeck and Henrique Gundlach
 * @brief Class' definition for piece generator handler
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <random>
#include <vector>
#include <memory>

#include "Piece.hpp"

class PieceGenerator {
private:
    int seed;
    std::mt19937 randomGenerator;
    const sf::Vector2u defaultPosition = {4, 0};

public:
    PieceGenerator(int seed) : seed(seed) { randomGenerator = std::mt19937(seed); };
    PieceGenerator() {
        seed = 42;
        randomGenerator = std::mt19937(seed);
    };
    ~PieceGenerator() {};
    std::unique_ptr<Piece> generatePiece();

    // PieceGenerator& operator=(const PieceGenerator& other) {
    //     if (this == &other) {
    //         return *this;
    //     }
    //     this->seed = other.seed;
    //     this->randomGenerator = other.randomGenerator;
    //     return *this;
    // }
};