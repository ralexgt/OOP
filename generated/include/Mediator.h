#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Player.h"
#include <iostream>

// Implementing the Mediator Design Pattern
// Restricts direct communications between the objects and
// forces them to collaborate only via a mediator object (refactoring.guru)
class Mediator {
private:
  Player& player0;
  Player& player1;

public:
  Mediator(Player& p0, Player& p1);

  void performAction(Player& self, std::string choice);
};

#endif // MEDIATOR_H