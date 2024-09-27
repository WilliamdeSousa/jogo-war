#ifndef JOGO_WAR_HELICOPTER_H
#define JOGO_WAR_HELICOPTER_H

#include "Unit.h"

class Helicopter : public Unit {
public:
    Helicopter(int x, int y, COR::Cor cor = COR::AZUL, Tile *tile = nullptr, int team = 1) : Unit("Helicopter", RESOURCE::HELICOPTER, x, y, cor, tile, team, unitAttributes[3]) {}
};

#endif //JOGO_WAR_HELICOPTER_H
