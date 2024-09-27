#ifndef JOGO_WAR_TANK_H
#define JOGO_WAR_TANK_H


#include "Unit.h"

class Tank : public Unit {
public:
    Tank(int x, int y, COR::Cor cor = COR::AZUL, Tile *tile = nullptr, int team = 1) : Unit("Tank", RESOURCE::TANK, x, y, cor, tile, team, unitAttributes[2]) {}
};


#endif //JOGO_WAR_TANK_H
