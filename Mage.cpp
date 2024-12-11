#include "Mage.h"

Mage::Mage(std::string name) : Character(std::move(name), 50.0f, 120.0f) {}

void Mage::specialAbility() const {
    std::cout << name << " casts Fireball! Deals 55 damage and consumes 75 mana.\n";
}
void Mage::basicAttack() const {
    std::cout << name << " attacks! Deals 18 damage and consumes no mana.\n";
}

// Implement the clone function
std::shared_ptr<Character> Mage::clone() const {
    return std::make_shared<Mage>(*this);
}