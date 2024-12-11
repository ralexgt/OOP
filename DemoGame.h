//
// Created by rares on 12/11/24.
//

#ifndef DEMOGAME_H
#define DEMOGAME_H

#include "Game.h"

class DemoGame final : public Game {
public:
  void display() const override {
    std::cout << "Demo game started!\n";
  }
};


#endif //DEMOGAME_H
