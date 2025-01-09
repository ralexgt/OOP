#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Player.h"
#include "Character.h"
#include <iostream>

// Implementing the Mediator Design Pattern
// Restricts direct communications between the objects and
// forces them to collaborate only via a mediator object (refactoring.guru)
class Mediator {
private:
  Player<Character>& player0;
  Player<Character>& player1;

public:
  Mediator(Player<Character>& p0, Player<Character>& p1);

  void performAction(Player<Character>& self, std::string choice);
};

#endif // MEDIATOR_H