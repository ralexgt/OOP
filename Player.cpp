#include "Player.h"

Player::Player(std::string name, std::shared_ptr<Character> character)
    : name(std::move(name)), character(std::move(character)) {}

void Player::useSpecialAbility() const {
    character->specialAbility();
}

const std::string& Player::getName() const {
    return name;
}

float Player::getHealth() const {
    return character->getHealth();
}