#include "Archer.h"
#include "Mage.h"
#include "Swordsman.h"
#include "Player.h"
#include "Game.h"
#include "Exceptions.h"
#include <memory>
#include <iostream>

int main() {
    try {
        const auto archer = std::make_shared<Archer>("Tik the Archer");
        const auto mage = std::make_shared<Mage>("Tok the Mage");

        const Player player1("Player 1", archer);
        const Player player2("Player 2", mage);

        Game game;
        game.addPlayer(player1);
        game.addPlayer(player2);

        game.startGame();

    } catch (const GameException& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}