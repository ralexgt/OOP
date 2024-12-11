#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"

class Archer final : public Character {
public:
    explicit Archer(std::string name);
    void specialAbility() const override;
    void basicAttack() const override;

    std::shared_ptr<Character> clone() const override;
};

#endif // ARCHER_H
