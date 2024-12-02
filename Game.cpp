#include "Game.h"
#include "Player.h"
#include <iostream>
#include <exception>

void Game::addPlayer(const Player& player) {
    players.push_back(player);
}

void Game::startGame() {
    if (players.size() < 2)
        throw std::runtime_error("Not enough players to start the game.");

    std::cout << "Starting the game with " << players.size() << " players.\n";
    for (const auto& player : players) {
        std::cout << player.getName() << "'s health: " << player.getHealth() << "\n";
    }

    players[0].useSpecialAbility();
    players[1].useSpecialAbility();
}