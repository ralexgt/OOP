#include "Action.h"
#include <iostream>

// Strategy Design Pattern Implementation of specific actions
void AttackAction::execute(Player& self, Player& opponent) {
  self.useBasicAttack();
  opponent.takeDamage(self.getCharDamage());
}

// Implementation of HealAction
void HealAction::execute(Player& self, Player& opponent) {
  self.heal();
  std::cout << opponent.getName() << " turn is next!\n";
}