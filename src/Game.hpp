#include <SFML/Graphics.hpp>

#include "Grid.hpp"

class Game {
private:
    Grid grid = Grid(10, 22), nextGrid = Grid(4, 4);
    unsigned int score = 0;
    WindowManager windowManager;
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
    void update();
    void render();
    sf::RenderWindow& getWindow();
    void calculateMovement(std::vector<sf::Event> userInput);
    void applyGravity();
};