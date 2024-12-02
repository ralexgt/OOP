#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <memory>

class Player {
private:
    std::string name;
    std::shared_ptr<Character> character;

public:
    Player(std::string name, std::shared_ptr<Character> character);
    void useSpecialAbility() const;
    void useBasicAttack() const;

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] float getHealth() const;
};

#endif // PLAYER_H