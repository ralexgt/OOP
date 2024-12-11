#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <vector>


class Game {
private:
    static std::vector<Player> players;

public:
    // non virtual destructor for proper cleanup
    virtual ~Game() = default;

    void addPlayer(const Player& player);
    static void characterSelection();
    static void startGame();
    static void gameStatus();

    // virtual displaying function
    virtual void display() const = 0;

    // non-virtual interface
    void displayGame() const {
        display();
    }

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif // GAME_H