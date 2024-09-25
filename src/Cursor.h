#ifndef JOGO_WAR_CURSOR_H
#define JOGO_WAR_CURSOR_H


#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Constants.h"
#include "Tile.h"

class Cursor : public ObjetoDeJogo {
public:
    Cursor(Tile *(map[TILES_VERTICALLY][TILES_HORIZONTALLY])) : ObjetoDeJogo("cursor", Sprite(RESOURCE::CURSOR, COR::BRANCA, true), 0, 0), x(0), y(0) {
        for (int i = 0; i < TILES_VERTICALLY; i++)
            for (int j = 0; j < TILES_HORIZONTALLY; j++) {
                this->map[i][j] = map[i][j];
            }
    }

    void moveToRight() { if (x < TILES_HORIZONTALLY - 1) { moveRight(TILE_WIDTH); x++; } };
    void moveToLeft() { if (x > 0) { moveLeft(TILE_WIDTH); x--; } };
    void moveToDown() { if (y < TILES_VERTICALLY - 1) { moveDown(TILE_HEIGHT); y++; } };
    void moveToUp() { if (y > 0) { moveUp(TILE_HEIGHT); y--; } };

    void select() {
        if (DEBUG_MODE) {
            Tile *tileSelected = getSelected();
            bool hasUnit = tileSelected->hasUnit();
            Unit *unitSelected = tileSelected->getUnit();

            std::cout << "Select (x=" << x << ", y=" << y << "): " << tileSelected->getName() << (hasUnit ? " -> " + unitSelected->getName() : "") << std::endl;
        }
    }
    void unselect() {
        if (DEBUG_MODE) {
            Tile *selected = getSelected();
            std::cout << "Unselect (x=" << x << ", y=" << y << "): " << selected->getName() << std::endl;
        }
    }

    Tile *getSelected() {
        return map[y][x];
    }
private:
    int x, y;
    Tile *(map[TILES_VERTICALLY][TILES_HORIZONTALLY]);
};


#endif //JOGO_WAR_CURSOR_H
