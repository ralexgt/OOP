#include <iostream>
#include <array>
#include <utility>
#include <string>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

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
    float getDamage() const {
        return damage;
    }

    ~Weapon() = default;
};


class Character {
private:
    std::string name{"unknown_character"};
    float health{100.f};
    float mana{100.f};
    float maxHealth{100.f};
    float maxMana{100.f};

public:
    Character() = default;
    Character(std::string name, float health, float mana)
        : name(std::move(name)), health(health), mana(mana) {
        this->maxHealth = health;
        this->maxMana = mana;
    };
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

    float getHealth() const {
        return health;
    }
    void setHealth(const float offset) {
        health += offset;
        if (health > maxHealth) {
            health = maxHealth;
        }
    }
    void setMana(const float offset) {
        mana += offset;
        if (mana > maxMana) {
            mana = maxMana;
        }
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
    const float restingGain{10};

public:
    Player() = default;
    Player(std::string name, const Character &character, const Weapon &weapon, int wins = 0, float restingGain = 10)
        : name(std::move(name)), character(character), weapon(weapon), wins(wins), restingGain(restingGain) {};

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
    const Character &getCharacter() const {
        return character;
    }

    void basicAttack(Player &target) {
        target.character.setHealth(-this->weapon.getDamage());
        std::cout << this->name << " used basic attack on " << target.getName() << " and dealt "
            << this->weapon.getDamage() << " damage.\n" << this->name << " health: " << this->character.getHealth()
            << ".\n" << target.name << " health: " << target.character.getHealth() << ".\n\n";
    }

    void rest() {
        this->character.setHealth(+restingGain);
        std::cout << this->name << " rested.\nNew health: " << this->character.getHealth() << "\n";
        this->character.setMana(+restingGain);
        std::cout << "New mana: " << this->character.getHealth() << "\n\n";
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
        out << "Game type: Best of " << game.minWins * 2 - 1 << "\n";
        out << game.players[0];
        out << "\t\t VS.\n";
        out << game.players[1];
        out << "\n" << "\t\tFIGHT!\n\n";

        return out;
    }

    // simulate a simple playing style with only basic attacks and rarely
    void startGame() {
        int turn = 0;
        // starting message
        std::cout << *this;
        while(players[0].getCharacter().getHealth() > 0 && players[1].getCharacter().getHealth() > 0) {
            std::this_thread::sleep_for(0.5s);
            turn++;
            if (turn % 6 == 5) {
                players[0].rest();
                std::this_thread::sleep_for(0.5s);
                players[1].rest();
                std::cout << "------------- Turn end " << turn <<"-------------\n\n";
                continue;
            }
            players[0].basicAttack(players[1]);
            std::this_thread::sleep_for(0.5s);
            if (players[1].getCharacter().getHealth() <= 0) {
                break;
            }
            players[1].basicAttack(players[0]);
            std::this_thread::sleep_for(1.2s);
            std::cout << "------------- Turn end " << turn <<"-------------\n\n";
        }
        if (players[0].getCharacter().getHealth() <= 0 && players[1].getCharacter().getHealth() <= 0) {
            std::cout << "Draw\n";
        }
        if (players[0].getCharacter().getHealth() <= 0) {
            std::cout << players[1].getName() << " won with " << players[1].getCharacter().getHealth() << " health left.\n";
        }
        if (players[1].getCharacter().getHealth() <= 0) {
            std::cout << players[0].getName() << " won with " << players[0].getCharacter().getHealth() << " health left.\n";
        }
    }

    ~Game() = default;
};

int main() {
    const int roundsToWin = 1;
    std::array<Character, 2> characters{Character{"Warrior", 100.f, 20.f},
                             Character{"Mage", 80.f, 50.f}};
    std::array<Weapon, 4> weapons{Weapon{"Sword", 10.f, 0.2f},
                          Weapon{"Bow", 5.f, 0.8f},
                          Weapon{"Staff", 2.f, 1.f},
                          Weapon{"Daggers", 8.f, 0.5f}};

    std::array<Player, 2> players{Player{"Tik", characters[0], weapons[0]},
                                  Player{"Tok", characters[1], weapons[2]}};

    Game game{players, roundsToWin};
    game.startGame();
    return 0;
}
