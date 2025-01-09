#include "Mediator.h"
#include "Action.h"


Mediator::Mediator(Player& p0, Player& p1) : player0(p0), player1(p1) {}

// Mediaton Design Pattern Implementation of the mediation between
// the 2 players' actions
void Mediator::performAction(Player& self, std::string choice) {
  // self is always the player that takes the action
  // decide which one of the player0 and player1 is NOT self
  Player& opponent = (&self == &player0) ? player1 : player0;

  // Use the Strategy Design Pattern from Action to select the action
  // store the chosen action
  Action* action = nullptr;

  if (choice == "Attack" || choice == "1" ) {
    action = new AttackAction();
  } else if (choice == "Heal" || choice == "2" ) {
    action = new HealAction();
  } else {
    std::cout << "Invalid choice! Turn skipped.\n";
  }

  if (action) {
    action->execute(self, opponent);
    delete action;
  }
}