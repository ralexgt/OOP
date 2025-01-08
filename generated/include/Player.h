#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <memory>

class Player final {
private:
    std::string name;
    std::shared_ptr<Character> character;

public:
    virtual ~Player() = default;
    Player(std::string name, std::shared_ptr<Character> character);
    void useSpecialAbility() const;
    void useBasicAttack() const;

    void takeDamage(float damage);
    void heal();

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] float getHealth() const;
    [[nodiscard]] float getMana() const;
    [[nodiscard]] float getCharDamage() const;
};

#endif // PLAYER_H