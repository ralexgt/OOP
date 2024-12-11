#include "Game.h"
#include "Exceptions.h"
#include "Player.h"
#include "Swordsman.h"
#include "Archer.h"
#include "Mage.h"

#include <iostream>

std::vector<Player> Game::players;

Game& Game::operator=(Game& other) {
  swap(*this, other);
  return *this;
}
void swap(Game& first, Game& second) noexcept {
  using std::swap;
  for (int i = 0; i < 2; ++i) {
    swap(first.players[i], second.players[i]);
  }
}

void Game::gameStatus() {
    std::cout << "Game status: \n";
    if (players.size() == 0) {
        std::cout << "Clean state\n";
    }
    for (unsigned long i = 0; i < players.size(); i++) {
      std::cout << players[i].getName() << ": " << players[i].getHealth() << " heath, "
    << players[i].getMana() << " mana\n";
    }
    std::cout << "--------------\n";
}

void Game::characterSelection() {
  std::string name = "";
  std::string character_choice = "";
  int player_count = 0;
  players.clear();

  do {
    try {
      std::cout << "\n Player " << player_count + 1 << " choose your name: \n";
      std::cout << "Name: ";
      std::cin >> name;
      if (name == "") {
        throw NonNullNameException();
      }
      std::cout << name << " choose your character: \n";
      std::cout << "1. Swordsman\n";
      std::cout << "2. Archer\n";
      std::cout << "3. Mage\n";
      std::cin >> character_choice;
      if (character_choice == "Swordsman") {
        const auto swordsman = std::make_shared<Swordsman>(name);
        players.push_back(Player(name, swordsman->clone()));
      } else if (character_choice == "Archer") {
        const auto archer = std::make_shared<Archer>(name);
        players.push_back(Player(name, archer->clone()));
      } else if (character_choice == "Mage") {
        const auto archer = std::make_shared<Mage>(name);
        players.push_back(Player(name, archer->clone()));
      } else {
        throw InvalidCharacterException();
      }
      player_count++;
    } catch (const BaseGameException& e) {
      std::cerr << e.what() << '\n';
      players.clear();
      player_count = 0;
      exit(0);
    }
  } while (player_count < 2);
}

void Game::startGame() {
    std::cout << "Booting up the game.\n";
    gameStatus();
    characterSelection();


    players[0].useSpecialAbility();
    players[1].useSpecialAbility();
    gameStatus();
    players[0].useBasicAttack();
    players[1].useBasicAttack();
    gameStatus();
}
