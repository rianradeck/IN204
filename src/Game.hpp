#include <SFML/Graphics.hpp>

#include "Grid.hpp"

class Game {
private:
    Grid grid = Grid(10, 22);
    unsigned int score = 0;
    WindowManager windowManager;
    PieceGenerator pieceGenerator;
    Piece currentPiece;

public:
    Game() {
        currentPiece = pieceGenerator.generatePiece();
    };
    ~Game() {};
    void print();
    void update();
    void render();
    sf::RenderWindow& getWindow();
    void calculateMovement(std::vector<sf::Event> userInput);
};