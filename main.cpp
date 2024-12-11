#include "Archer.h"
#include "Mage.h"
#include "Swordsman.h"
#include "Player.h"
#include "Game.h"
#include "DemoGame.h"
#include "Exceptions.h"
#include <memory>
#include <iostream>

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