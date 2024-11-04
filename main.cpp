#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include <string>
//#include "generated/include/Helper.h"

// TODO: Select a weapon from a selection given to the user
class Weapon {
private:
    std::string name{"unknown_weapon"};
    float damage{10.f};
    float hitChance{1.f};

public:
    Weapon() = default;
    Weapon(std::string name, float damage, float hitChance) : name(std::move(name)), damage(damage), hitChance(hitChance) {}
    Weapon& operator=(const Weapon& weapon) = default;

    friend std::ostream& operator<<(std::ostream &out, const Weapon& weapon) {
        out << "Weapon name: " << weapon.name << "\n";
        out << "Weapon damage: " << weapon.damage << "\n";
        out << "Weapon hitChance: " << weapon.hitChance << "\n";
        return out;
    }

    const std::string &getName() const {
        return name;
    }

    ~Weapon() = default;
};


class Character {
private:
    std::string name{"unknown_character"};
    float health{100.f};
    float mana{100.f};

public:
    Character() = default;
    Character(std::string name, float health, float mana)
        : name(std::move(name)), health(health), mana(mana) {};
    Character& operator=(const Character& character) = default;

    friend std::ostream&  operator<<(std::ostream &out, const Character& character) {
        out << "Character name: " << character.name << "\n";
        out << "Character health: " << character.health << "\n";
        out << "Character mana:: " << character.mana << "\n";
        return out;
    }

    const std::string &getName() const {
        return name;
    }

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
        : name(std::move(name)), character(character), weapon(weapon) {};

    Player(const Player& player) {
        this->name = player.name;
        this->character = player.character;
        this->weapon = player.weapon;
        this->wins = player.wins;
    }
    Player& operator=(const Player& player) {
        this->name = player.name;
        this->character = player.character;
        this->weapon = player.weapon;
        this->wins = player.wins;
        return *this;
    }

    friend std::ostream&  operator<<(std::ostream &out, const Player& player) {
        out << "Player's name: " << player.name << "\n";
        out << "Player's character: " << player.character.getName() << "\n";
        out << "Player's weapon:: " << player.weapon.getName() << "\n";
        return out;
    }

    const std::string &getName() const {
        return name;
    }

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
    Game(std::array<Player, 2> players, int minWins)
        : players(std::move(players)), minWins(minWins) {};

    friend std::ostream&  operator<<(std::ostream &out, const Game& game) {
        out << "Player 1: " << game.players[0].getName() << "\n";
        out << "Player 2: " << game.players[1].getName() << "\n";
        out << "Rounds to win game: " << game.minWins << "\n";
        return out;
    }

    ~Game() = default;
};

int main() {

    return 0;
}
