#include "Action.h"
#include <iostream>

// Strategy Design Pattern Implementation of specific actions
void AttackAction::execute(Player<Character>& self, Player<Character>& opponent) {
  self.useBasicAttack();
  opponent.takeDamage(self.getCharDamage());
}

// Implementation of HealAction
void HealAction::execute(Player<Character>& self, Player<Character>& opponent) {
  self.heal();
  std::cout << opponent.getName() << " turn is next!\n";
}