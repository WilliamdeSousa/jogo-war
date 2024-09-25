#ifndef JOGO_WAR_TANK_H
#define JOGO_WAR_TANK_H


#include "Unit.h"

class Tank : public Unit {
public:
    Tank(int x, int y, COR::Cor cor = COR::AZUL, Tile *tile = nullptr) : Unit("Tank", RESOURCE::TANK, x, y, cor, tile) {}
};


#endif //JOGO_WAR_TANK_H
