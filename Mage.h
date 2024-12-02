#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage final : public Character {
public:
    explicit Mage(std::string name);
    void specialAbility() const override;
    void basicAttack() const override;
};

#endif // MAGE_H
