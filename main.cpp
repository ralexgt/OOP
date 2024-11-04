#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include <string>
//#include "generated/include/Helper.h"

// TODO: implement consumables
//class Consumable {
//private:
//    std::string name{"unknown_consumable"};
//};

// TODO: Select a weapon from a selection given to the user
class Weapon {
private:
    std::string name{"unknown_weapon"};
    float damage{10.f};
    float hitChance{1.f};

public:
    Weapon() = default;
    Weapon(std::string name, float damage, float hitChance) : name(std::move(name)), damage(damage), hitChance(hitChance) {}


    ~Weapon() = default;
};

// TODO: Select a character from a selection given to the user
class Character {
private:
    std::string name{"unknown_character"};
    float health{100.f};
    float mana{100.f};

public:
    Character() = default;
    Character(std::string name, float health, float mana)
        : name(std::move(name)), health(health), mana(mana) {}


    ~Character() = default;
};

class Player {
private:
    std::string name{"unknown_player"};
    Character character{};
    Weapon weapon{};
    // no. of wins in a duel
    int wins{0};

public:
    Player() = default;
    Player(std::string name, const Character &character, const Weapon &weapon, int wins = 0)
        : name(std::move(name)), character(character), weapon(weapon) {}

    ~Player() = default;
};

class Game {
private:
    // players in game
    std::array<Player, 2> players{};
    // no. of wins to win a duel
    int minWins{3};

public:
    Game() = default;
    Game(std::array<Player, 2> players, int minWins = 3)
        : players(players), minWins(minWins) {}

    ~Game() = default;
};

int main() {

    return 0;
}
