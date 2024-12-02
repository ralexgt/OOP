#include "Archer.h"

Archer::Archer(std::string name) : Character(std::move(name), 80.0f) {}

void Archer::specialAbility() const {
    std::cout << name << " uses Precision Shot! Deals 20 damage and consumes 15 mana.\n";
}
void Archer::basicAttack() const {
    std::cout << name << " attacks! Deals 10 damage and consumes no mana.\n";
}
