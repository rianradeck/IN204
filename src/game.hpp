#include "grid.hpp"

class Game {
private:
    Grid grid = Grid(10, 22);
    int score = 0;
public:
    Game() {};
    ~Game();

    void print();
};