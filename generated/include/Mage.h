#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage final : public Character {
public:
    explicit Mage(std::string name);
    void specialAbility() const override;
    void basicAttack() const override;
    void heals() const override;

    std::shared_ptr<Character> clone() const override;
};

#endif // MAGE_H
