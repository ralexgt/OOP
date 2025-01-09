#include "Game.h"
#include "Exceptions.h"
#include "Player.h"
#include "Swordsman.h"
#include "Archer.h"
#include "Mage.h"
#include "Action.h"
#include "Mediator.h"
#include "Character.h"

#include <iostream>

std::vector<Player<Character>> Game::players;

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
  players.clear();

  for (int i = 0; i < 2; i++) {
    try {
      std::cout << "\n Player " << i << " choose your name: \n";
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
      if (character_choice == "Swordsman" || character_choice == "swordsman" || character_choice == "1") {
        const auto swordsman = std::make_shared<Swordsman>(name);
        players.push_back(Player(name, swordsman->clone()));

      } else if (character_choice == "Archer" || character_choice == "archer" || character_choice == "2") {
        const auto archer = std::make_shared<Archer>(name);
        players.push_back(Player(name, archer->clone()));
      } else if (character_choice == "Mage" || character_choice == "mage" || character_choice == "3") {
        const auto archer = std::make_shared<Mage>(name);
        players.push_back(Player(name, archer->clone()));
      } else {
        throw InvalidCharacterException();
      }
    } catch (const BaseGameException& e) {
      std::cerr << e.what() << '\n';
      players.clear();
      exit(0);
    }
  }
}

void Game::startGame() {
    // setting up the game
    gameStatus();

    // Select players[0] and players[1]
    characterSelection();
    gameStatus();

    // Mediator to deal with actions between players
    Mediator mediator(players[0], players[1]);

    // main gameplay of the players
    while (players[0].getHealth() >= 0 && players[1].getHealth() >= 0) {
      // Taking turns, player[0] first, then player[1], choose their action
      for (int i = 0; i < 2; ++i) {
        std::cout << players[i].getName() << ", choose your action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Heal\n";
        std::cout << "Choose your action: ";

        std::string choice = "";
        std::cin >> choice;

        mediator.performAction(players[i], choice);
	  }
    // at the end of each turn, the current game state is displayed
    gameStatus();
    }
  // resolution of the game
  if (players[0].getHealth() > players[1].getHealth()) {
    std::cout << "THE WINNER IS " << players[0].getName() << "! Congratulations!\n";
  } else if (players[0].getHealth() == players[1].getHealth()) {
    std::cout << "THAT'S A DRAW! GOOD GAME TO BOTH OF YOU!\n";
  } else {
    std::cout << "THE WINNER IS " << players[1].getName() << "! Congratulations!\n";
  }
}
