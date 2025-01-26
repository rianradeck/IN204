#include <SFML/Graphics.hpp>

#include "Grid.hpp"
#include "Network.hpp"
#include "GameState.hpp"

class Game {
private:
    // Variables
    unsigned int score = 0; // Deprecated
    const float UPDATE_RATE = 2.0f;
    bool isOnline = false;

    // Objects
    std::unique_ptr<Grid> grid, nextGrid, opponentGrid;
    std::unique_ptr<PieceGenerator> pieceGenerator;
    std::unique_ptr<Piece> currentPiece, nextPiece;

    sf::Clock clock;
    sf::Time lastTick;
public:
    Game(int seed) : Game(seed, false) {}
    Game(int seed, int isOnline) : isOnline(isOnline) {
        grid = std::make_unique<Grid>(10, 22);
        nextGrid = std::make_unique<Grid>(4, 4);
        lastTick = clock.getElapsedTime();
        if (isOnline) {
            opponentGrid = std::make_unique<Grid>(10, 22);
            opponentGrid->setTileSize({10, 10});
        }
        pieceGenerator = std::make_unique<PieceGenerator>(seed);
    };
    ~Game() {};
    void print();
    GameState update(WindowManager &windowManager, NetworkManager &networkManager);
    void render(WindowManager &windowManager);
    int calculateMovement(std::vector<sf::Event> userInput);
    void applyGravity();
    bool handlePieceChange();
    bool networkPool(NetworkManager &networkManager);

};