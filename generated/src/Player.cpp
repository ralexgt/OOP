#include "Player.h"

Player::Player(std::string name, std::shared_ptr<Character> character)
    : name(std::move(name)), character(std::move(character)) {}

void Player::useSpecialAbility() const {
  character->specialAbility();
}
void Player::useBasicAttack() const {
  character->basicAttack();
}

const std::string& Player::getName() const {
  return name;
}

float Player::getHealth() const {
  return character->getHealth();
}
float Player::getMana() const {
  return character->getMana();
}
float Player::getCharDamage() const {
  return character->getDamage();
}

void Player::takeDamage(const float damage) {
  character->takeDamage(damage);
}

void Player::heal() {
  character->heal();
}
