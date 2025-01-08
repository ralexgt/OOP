#include "Character.h"

Character::Character(std::string name, const float health, const float mana, const float damage, const float healingPow)
    : name(std::move(name)), health(health), mana(mana), maxHealth(health), maxMana(mana), basicDamage(damage), healingPow(healingPow) {}

void Character::takeDamage(const float damage) {
    health -= damage;
}

void Character::heal() {
  heals();
  health += healingPow;
  if (health > maxHealth) health = maxHealth;
}

float Character::getHealth() const {
  return health;
}
float Character::getMana() const {
  return mana;
}
float Character::getDamage() const {
  return basicDamage;
}

const std::string& Character::getName() const {
  return name;
}

std::ostream& operator<<(std::ostream& os, const Character& character) {
  std::cout << character.getName() << " health: " << character.getHealth()
            << std::endl;
  return os;
}