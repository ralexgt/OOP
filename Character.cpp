#include "Character.h"

Character::Character(std::string name, const float health, const float mana)
    : name(std::move(name)), health(health), mana(mana), maxHealth(health), maxMana(mana) {}

//void Character::takeDamage(const float damage) {
//    health -= damage;
//    if (health < 0) health = 0;
//}
//
//void Character::heal(const float amount) {
//    health += amount;
//    if (health > maxHealth) health = maxHealth;
//}

float Character::getHealth() const {
    return health;
}
float Character::getMana() const {
    return mana;
}

const std::string& Character::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Character& character) {
    std::cout << character.getName() << " health: " << character.getHealth()
            << std::endl;
  return os;
}