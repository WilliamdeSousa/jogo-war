#ifndef JOGO_WAR_HELICOPTER_H
#define JOGO_WAR_HELICOPTER_H

#include "Unit.h"

class Helicopter : public Unit {
public:
    Helicopter(int x, int y, COR::Cor cor = COR::AZUL, Tile *tile = nullptr) : Unit("Helicopter", RESOURCE::HELICOPTER, x, y, cor, tile) {}
};

#endif //JOGO_WAR_HELICOPTER_H
