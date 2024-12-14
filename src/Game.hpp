#include <SFML/Graphics.hpp>

#include "Grid.hpp"

class Game {
private:
    Grid grid = Grid(10, 22);
    unsigned int score = 0;
    WindowManager windowManager;
    PieceGenerator pieceGenerator;

public:
    Game() {
        grid.placePiece(pieceGenerator.generatePiece());
    };
    ~Game() {};
    void print();
    void update();
    void render();
    sf::RenderWindow& getWindow();
};