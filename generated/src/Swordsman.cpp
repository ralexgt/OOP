#include "Swordsman.h"

Swordsman::Swordsman(std::string name) : Character(std::move(name), 45.0f, 20.0f, 15.0f, 5.0f) {}

void Swordsman::specialAbility() const {
  std::cout << name << " used Sword slash and dealt 20 health points\n";
}
void Swordsman::basicAttack() const {
  std::cout << name << " attacks! Deals 15 damage and consumes no mana.\n";
}

void Swordsman::heals() const {
  std::cout << name << " heals for 5 health.\n";
}

// Implement the clone function
std::shared_ptr<Character> Swordsman::clone() const {
  return std::make_shared<Swordsman>(*this);
}