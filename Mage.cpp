#include "Mage.h"

Mage::Mage(std::string name) : Character(std::move(name), 70.0f) {}

void Mage::specialAbility() const {
    std::cout << name << " casts Fireball! Deals 30 damage.\n";
}