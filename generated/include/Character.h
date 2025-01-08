#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <memory>

class Character {
protected:
    std::string name;
    float health;
    float mana;
    float maxHealth;
    float maxMana;
    float basicDamage;
    float healingPow;

public:
    Character(std::string name, float health, float mana, float basicDamage, float healingPower);
    virtual ~Character() = default;

    void takeDamage(float damage);
    void heal();

    [[nodiscard]] float getHealth() const;
    [[nodiscard]] float getDamage() const;
    [[nodiscard]] float getMana() const;
    [[nodiscard]] const std::string& getName() const;

    virtual void specialAbility() const = 0;
    virtual void basicAttack() const = 0;
    virtual void heals() const = 0;

    // virtual cloning contructor
    virtual std::shared_ptr<Character> clone() const = 0;
    // << overload
    friend std::ostream& operator<<(std::ostream& os, const Character& character);
};

#endif // CHARACTER_H
