#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character {
protected:
    std::string name;
    float health;
    float maxHealth;

public:
    Character(std::string name, float health);
    virtual ~Character() = default;

    void takeDamage(float damage);
    void heal(float amount);

    [[nodiscard]] float getHealth() const;
    [[nodiscard]] const std::string& getName() const;

    virtual void specialAbility() const = 0;
    virtual void basicAttack() const = 0;
};

#endif // CHARACTER_H
