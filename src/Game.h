#ifndef GAME_H
#define GAME_H

#include "ASCII_Engine/SpriteBuffer.hpp"

#include "Constants.h"
#include "BattleFase.h"

class Game {
public:
    static void run() {
        SpriteBuffer screen = SpriteBuffer(WIDTH, HEIGHT);

        BattleFase battleFase;

        battleFase.init();
        battleFase.run(screen);
    }
};

#endif //GAME_H
