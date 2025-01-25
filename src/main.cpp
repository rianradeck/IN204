#include <iostream>
#include "StateManager.hpp"

int main() {
    

    StateManager stateManager;

    while (stateManager.isRunning()) {
        stateManager.update();
        stateManager.render();
    }
}
