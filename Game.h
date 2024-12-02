#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <vector>

class Game {
private:
    std::vector<Player> players;

public:
    void addPlayer(const Player& player);
    void startGame() const;
};

#endif // GAME_H