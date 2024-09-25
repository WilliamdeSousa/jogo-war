#ifndef JOGO_WAR_CITY_H
#define JOGO_WAR_CITY_H

#include "Tile.h"

class City : public Tile {
public:
    City(int x, int y, COR::Cor cor) : Tile("City", x, y, cor, RESOURCE::CITY){}
};


#endif //JOGO_WAR_CITY_H
