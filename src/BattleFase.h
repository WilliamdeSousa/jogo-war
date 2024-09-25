#ifndef JOGO_WAR_BATTLEFASE_H
#define JOGO_WAR_BATTLEFASE_H

#include "ASCII_Engine/Fase.hpp"
#include "KeyBoard.h"
#include "Constants.h"
#include "Cursor.h"

#include "Unit.h"
#include "Tile.h"
#include "Tank.h"
#include "Soldier.h"
#include "Helicopter.h"
#include "Bazuca.h"
#include "City.h"

#include <fstream>
#include <string>

class BattleFase : public Fase {
public:
    BattleFase();

    void init() override {}
    unsigned int run(SpriteBuffer &screen) override;

    void update(SpriteBuffer &screen);

private:
    Cursor *cursor;
    std::list<Unit*> myUnits;
    std::list<Unit*> enemyUnits;
    Tile *(map[TILES_VERTICALLY][TILES_HORIZONTALLY]);

    COR::Cor unitColor[3];
    COR::Cor cityColor[3];

    void readLevel(const std::string &level);
    void readUnits(std::ifstream &arquivo);
    void readTiles(std::ifstream &arquivo);
};

#endif //JOGO_WAR_BATTLEFASE_H
