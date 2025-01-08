#include "Archer.h"

Archer::Archer(std::string name) : Character(std::move(name), 40.0f, 50.0f, 13.0f, 8.0f) {}

void Archer::specialAbility() const {
  std::cout << name << " uses Precision Shot! Deals 35 damage and consumes 15 mana.\n";
}
void Archer::basicAttack() const {
  std::cout << name << " attacks! Deals 13 damage and consumes no mana.\n";
}

void Archer::heals() const {
  std::cout << name << " heals for 8 health.\n";
}

// Implement the clone function
std::shared_ptr<Character> Archer::clone() const {
  return std::make_shared<Archer>(*this);
}