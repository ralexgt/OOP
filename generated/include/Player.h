#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <memory>

// Defining a template so a player object can also take Swordsman, Archer, Mage
// not only Character class.
template <typename CharacterType>
class Player final {
private:
    std::string name;
    std::shared_ptr<CharacterType> character;

public:
    ~Player() = default;
    Player(std::string name, std::shared_ptr<CharacterType> character)
        : name(std::move(name)), character(std::move(character)) {}
    void useSpecialAbility() const {
        character->specialAbility();
    }
    void useBasicAttack() const {
        character->basicAttack();
    }

    void takeDamage(float damage) {
        character->takeDamage(damage);
    }
    void heal() {
        character->heal();
    }

    [[nodiscard]] const std::string& getName() const {
        return name;
    }
    [[nodiscard]] float getHealth() const {
        return character->getHealth();
    }
    [[nodiscard]] float getMana() const {
        return character->getMana();
    }
    [[nodiscard]] float getCharDamage() const {
        return character->getDamage();
    }
};

#endif // PLAYER_H