#include "Swordsman.h"

Swordsman::Swordsman(std::string name) : Character(std::move(name), 100.0f) {}

void Swordsman::specialAbility() const {
    std::cout << name << " uses Shield Bash! Stuns the enemy.\n";
}
void Swordsman::basicAttack() const {
    std::cout << name << " attacks! Deals 10 damage and consumes no mana.\n";
}