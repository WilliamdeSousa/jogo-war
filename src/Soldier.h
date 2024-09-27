#ifndef JOGO_WAR_SOLDIER_H
#define JOGO_WAR_SOLDIER_H


#include "Unit.h"

class Soldier : public Unit {
public:
    Soldier(int x, int y, COR::Cor cor = COR::AZUL, Tile *tile = nullptr, int team = 1) : Unit("Soldier", RESOURCE::SOLDIER, x, y, cor, tile, team, unitAttributes[0]) {}
};

#endif //JOGO_WAR_SOLDIER_H
