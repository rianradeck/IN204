#include <random>
#include <vector>

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