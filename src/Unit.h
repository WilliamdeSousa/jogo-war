#ifndef JOGO_WAR_UNIT_H
#define JOGO_WAR_UNIT_H

class Tile;

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Constants.h"

enum Units {SOLDIER, BAZUCA, TANK, HELICOPTER};

class Unit : public ObjetoDeJogo {
public:
    Unit(std::string name, std::string resource, int x, int y, COR::Cor cor = COR::PADRAO, Tile *tile = nullptr) : ObjetoDeJogo(name, Sprite(resource, cor), y * TILE_HEIGHT + 1, x * TILE_WIDTH + 1), tile(tile) { }
    virtual ~Unit() = default;

    static std::string idToString(int id) {
        switch (id) {
            case SOLDIER: return "Soldier";
            case BAZUCA: return "Bazuca";
            case TANK: return "Tank";
            case HELICOPTER: return "Helicopter";
            default: return "ERROR";
        }
    }

protected:
    int life, attack, moviment, defense;
    bool fly, walk;
    Tile *tile;
};


#endif //JOGO_WAR_UNIT_H
