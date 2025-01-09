#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <vector>


class Game {
private:
    static std::vector<Player<Character>> players;


public:
    // non virtual destructor for proper cleanup
    virtual ~Game() = default;

    void addPlayer(const Player<Character>& player);
    static void characterSelection();
    static void startGame();
    static void gameStatus();

    // virtual displaying function
    virtual void display() const = 0;

    // non-virtual interface
    void displayGame() const {
        display();
    }

    // Assignment operator using copy-and-swap idiom
    Game& operator=(Game& other);
    // Swap
    friend void swap(Game& first, Game& second) noexcept;
    // << operator
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif // GAME_H