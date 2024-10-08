#ifndef JOGO_WAR_TILE_H
#define JOGO_WAR_TILE_H

#include <utility>

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Constants.h"
#include "Unit.h"
#include "Selection.h"

enum Tiles {GRASS, ROAD, FLOREST, MOUNTAIN, WATER, CITY};

class Tile : public ObjetoDeJogo {
public:
    Tile(std::string name = "", int x = 0, int y = 0, COR::Cor cor = COR::PADRAO, std::string resource = RESOURCE::WATER, Unit *unit = nullptr, int team = 0) : ObjetoDeJogo(std::move(name), Sprite(std::move(resource), cor), y * TILE_HEIGHT + 1, x * TILE_WIDTH + 1), unit(unit), team(team) {
        movimentDifficulty = 5;
    }

    static std::string idToString(int id) {
        switch (id) {
            case GRASS: return "Grass";
            case ROAD: return "Road";
            case FLOREST: return "Florest";
            case MOUNTAIN: return "Mountain";
            case WATER: return "Water";
            case CITY: return "City";
            default: return "ERROR";
        }
    }

    void setUnit(Unit *unit) { this->unit = unit; }
    Unit *getUnit() { return unit; }
    bool hasUnit() const { return unit != nullptr; }

    int getMovimentDifficulty() const { return movimentDifficulty; }
    int getProtection() const { return protection; }

    bool isSelected() const { return selected; }
    void select() { selected = true; }
    void unselect() { selected = false; }

    int getTeam() const { return team; }

    void update() override {
        if (hasUnit() && !unit->isActive()) {
            unit = nullptr;
        }
    }

private:
    int team, movimentDifficulty, protection;
    bool selected;
    Unit *unit;
};


#endif //JOGO_WAR_TILE_H
