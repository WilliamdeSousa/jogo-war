#ifndef JOGO_WAR_CITY_H
#define JOGO_WAR_CITY_H

#include "Tile.h"

const COR::Cor cityColors[] = {COR::CINZA, COR::AZUL, COR::VERMELHA};

class City : public Tile {
public:
    City(int x, int y, int team) : Tile("City", x, y, cityColors[team], RESOURCE::CITY, nullptr, team){}
};


#endif //JOGO_WAR_CITY_H
