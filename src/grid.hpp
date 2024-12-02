#include <iostream>
#include <vector>

class Grid {
private:
    int width, height;
    std::vector<int> cells;
public:
    Grid(int width, int height, std::vector<int> cells): width(width), height(height), cells(cells) {};
    Grid(int width, int height) : width(width), height(height) {
        cells = std::vector<int>(width * height);
        for (int i = 0; i < width * height; i++) {
            cells[i] = 0;
        }
    }
    ~Grid();

    void set(int x, int y, int value);
    int get(int x, int y);
    void print();
};