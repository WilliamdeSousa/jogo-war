#ifndef JOGO_WAR_ROAD_H
#define JOGO_WAR_ROAD_H

#include "Tile.h"
#include "Constants.h"

std::string resource;

class Road : public Tile {
public:
    Road(int x, int y, bool nesw[4]) : Tile("Road", x, y, COR::CINZA, (resource = nlsoToResource(nesw))) {
        if (DEBUG_MODE)
            std::cout << "Road (" << x << ", " << y << ") N=" << nesw[0] << " L=" << nesw[1] << " S=" << nesw[2] << " O=" << nesw[3] << std::endl;
    }
private:
    static std::string nlsoToResource(const bool nesw[4]) {
        std::string arquivo = RESOURCE::ROAD;
        if (nesw[0]) arquivo += "n";
        if (nesw[1]) arquivo += "l";
        if (nesw[2]) arquivo += "s";
        if (nesw[3]) arquivo += "o";
        return arquivo + ".img";
    }
};

#endif //JOGO_WAR_ROAD_H
