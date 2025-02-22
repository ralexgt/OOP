#ifndef SWORDSMAN_H
#define SWORDSMAN_H

#include "Character.h"

class Swordsman final : public Character {
public:
    explicit Swordsman(std::string name);
    void specialAbility() const override;
    void basicAttack() const override;
    void heals() const override;

    std::shared_ptr<Character> clone() const override;
};

#endif // SWORDSMAN_H
