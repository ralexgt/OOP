#include "Swordsman.h"

Swordsman::Swordsman(std::string name) : Character(std::move(name), 100.0f, 20.0f) {}

void Swordsman::specialAbility() const {
    std::cout << name << " used Sword slash and dealt 20 health points\n";
}
void Swordsman::basicAttack() const {
    std::cout << name << " attacks! Deals 10 damage and consumes no mana.\n";
}

// Implement the clone function
std::shared_ptr<Character> Swordsman::clone() const {
    return std::make_shared<Swordsman>(*this);
}