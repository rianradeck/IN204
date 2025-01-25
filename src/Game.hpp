#include <SFML/Graphics.hpp>

#include "Grid.hpp"

class Game {
private:
    Grid grid = Grid(10, 22), nextGrid = Grid(4, 4);
    unsigned int score = 0;
    PieceGenerator pieceGenerator;
    Piece currentPiece, nextPiece;
    sf::Clock clock;
    sf::Time lastTick;
    const float UPDATE_RATE = 1.0f;

public:
    Game() {
        lastTick = clock.getElapsedTime();
    };
    ~Game() {};
    void print();
    void update(WindowManager &windowManager);
    void render(WindowManager &windowManager);
    void calculateMovement(std::vector<sf::Event> userInput);
    void applyGravity();
    void handlePieceChange();

    Game& operator=(const Game& other) {
        if (this == &other) {
            return *this;
        }
        this->grid = other.grid;
        this->nextGrid = other.nextGrid;
        this->score = other.score;
        this->pieceGenerator = other.pieceGenerator;
        this->currentPiece = other.currentPiece;
        this->nextPiece = other.nextPiece;
        this->clock = other.clock;
        this->lastTick = other.lastTick;
        return *this;
    }
};