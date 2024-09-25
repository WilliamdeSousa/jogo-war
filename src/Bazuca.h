#ifndef JOGO_WAR_BAZUCA_H
#define JOGO_WAR_BAZUCA_H

#include "Unit.h"

class Bazuca : public Unit {
public:
    Bazuca(int x, int y, COR::Cor cor = COR::AZUL, Tile *tile = nullptr) : Unit("Bazuca", RESOURCE::BAZUCA, x, y, cor, tile) {}
};

#endif //JOGO_WAR_BAZUCA_H
