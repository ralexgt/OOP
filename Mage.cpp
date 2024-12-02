#include "Mage.h"

Mage::Mage(std::string name) : Character(std::move(name), 70.0f) {}

void Mage::specialAbility() const {
    std::cout << name << " casts Fireball! Deals 30 damage.\n";
}
void Mage::basicAttack() const {
    std::cout << name << " attacks! Deals 10 damage and consumes no mana.\n";
}