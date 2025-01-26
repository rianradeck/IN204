#include <SFML/Graphics.hpp>

#include "Grid.hpp"
#include "Network.hpp"
#include "GameState.hpp"

class Game {
private:
    Grid grid = Grid(10, 22), nextGrid = Grid(4, 4), opponentGrid = Grid(10, 22);
    unsigned int score = 0;
    PieceGenerator pieceGenerator;
    Piece currentPiece, nextPiece;
    sf::Clock clock;
    sf::Time lastTick;
    const float UPDATE_RATE = 2.0f;

public:
    Game() {
        lastTick = clock.getElapsedTime();
        opponentGrid.setTileSize({10, 10});
    };
    ~Game() {};
    void print();
    GameState update(WindowManager &windowManager, NetworkManager &networkManager);
    void render(WindowManager &windowManager);
    void calculateMovement(std::vector<sf::Event> userInput);
    void applyGravity();
    bool handlePieceChange();
    bool networkPool(NetworkManager &networkManager);

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