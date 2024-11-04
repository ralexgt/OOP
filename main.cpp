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

    float getHealth() const {
        return health;
    }
    void setHealth(const float offset) {
        health += offset;
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
        : name(std::move(name)), character(character), weapon(weapon), wins(wins) {};

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

    void startGame() {
        while(players[0].getCharacter().getHealth() > 0 && players[1].getCharacter().getHealth() > 0) {
            players[0].basicAttack(players[1]);
            std::this_thread::sleep_for(0.5s);
            if (players[1].getCharacter().getHealth() <= 0) {
                break;
            }
            players[1].basicAttack(players[0]);
            std::this_thread::sleep_for(1.5s);
            std::cout << "------------- Turn end -------------\n\n";
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
    std::array<Character, 2> characters{Character{"Warrior", 100, 20},
                             Character{"Mage", 80, 50}};
    std::array<Weapon, 4> weapons{Weapon{"Sword", 10, 0.2},
                          Weapon{"Bow", 5, 0.8},
                          Weapon{"Staff", 2, 1},
                          Weapon{"Daggers", 8, 0.5}};

    std::array<Player, 2> players{Player{"Tik", characters[0], weapons[0]},
                                  Player{"Tok", characters[1], weapons[2]}};

    Game game{players, roundsToWin};
    game.startGame();
    return 0;
}
