#include <iostream>
#include <Game.h>
#include <DemoGame.h>
#include <Exceptions.h>

int main() {
    try {
        const DemoGame game;
        game.displayGame();
        game.startGame();

    } catch (const InvalidGameState& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}