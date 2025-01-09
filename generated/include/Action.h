#ifndef ACION_H
#define ACION_H

#include <Player.h>

// Implementing the Strategy Design Pattern
// Turn a set of behaviors into objects and make them
// interchangeable inside original context object. (refactoring.guru)
// Abstract base class for actions
class Action {
public:
  virtual void execute(Player<Character>& self, Player<Character>& opponent) = 0;
  virtual ~Action() = default;
};

// Concrete class for attack action
class AttackAction : public Action {
public:
  void execute(Player<Character>& self, Player<Character>& opponent) override;
};

// Concrete class for heal action
class HealAction : public Action {
public:
  void execute(Player<Character>& self, Player<Character>& opponent) override;
};

#endif //ACION_H
