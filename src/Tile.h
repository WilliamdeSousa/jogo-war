#ifndef JOGO_WAR_TILE_H
#define JOGO_WAR_TILE_H

#include <utility>

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Constants.h"
#include "Unit.h"

enum Tiles {GRASS, ROAD, FLOREST, MONTAIN, WATER, CITY};

class Tile : public ObjetoDeJogo {
public:
    Tile(std::string name = "", int x = 0, int y = 0, COR::Cor cor = COR::PADRAO, std::string resource = RESOURCE::WATER, Unit *unit = nullptr) : ObjetoDeJogo(std::move(name), Sprite(std::move(resource), cor), y * TILE_HEIGHT + 1, x * TILE_WIDTH + 1), unit(unit) {}

    static std::string idToString(int id) {
        switch (id) {
            case GRASS: return "Grass";
            case ROAD: return "Road";
            case FLOREST: return "Florest";
            case MONTAIN: return "Montain";
            case WATER: return "Water";
            case CITY: return "City";
            default: return "ERROR";
        }
    }

    void setUnit(Unit *unit) { this->unit = unit; }
    Unit *getUnit() { return unit; }
    bool hasUnit() { return unit != nullptr; }
private:
    Unit *unit;
};


#endif //JOGO_WAR_TILE_H
