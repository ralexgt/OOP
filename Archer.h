#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"

class Archer final : public Character {
public:
    explicit Archer(std::string name);
    void specialAbility() const override;
};

#endif // ARCHER_H
