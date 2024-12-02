#include "Character.h"

Character::Character(std::string name, float health)
    : name(std::move(name)), health(health), maxHealth(health) {}

void Character::takeDamage(float damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Character::heal(float amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
}

float Character::getHealth() const {
    return health;
}

const std::string& Character::getName() const {
    return name;
}
