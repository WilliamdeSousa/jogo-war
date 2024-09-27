#ifndef JOGO_WAR_CURSOR_H
#define JOGO_WAR_CURSOR_H


#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Constants.h"
#include "Tile.h"
#include "Menu.h"

class Cursor : public ObjetoDeJogo {
public:
    Cursor(Tile *(map[TILES_VERTICALLY][TILES_HORIZONTALLY]), Menu *menu, int x = 0, int y = 0) : ObjetoDeJogo("cursor", Sprite(RESOURCE::CURSOR, COR::BRANCA, true), y * TILE_HEIGHT, x * TILE_WIDTH), x(x), y(y), menu(menu) {
        for (int i = 0; i < TILES_VERTICALLY; i++)
            for (int j = 0; j < TILES_HORIZONTALLY; j++) {
                this->map[i][j] = map[i][j];
            }
    }

    void moveToRight();
    void moveToLeft();
    void moveToDown();
    void moveToUp();

    Tile *getSelected() { return map[y][x]; }
    int getX() const { return x; }
    int getY() const { return y; }

    Menu *getMenu() { return menu; }

    void update() override {
        ObjetoDeJogo::update();
        std::string tile = getSelected()->getName();

        COR::Cor tileColor = COR::BRANCA;
        if (tile == "City") {
            tileColor = COR::CINZA;
            if (getSelected()->getTeam() == 1) {
                tileColor = COR::AZUL;
            }
            else if (getSelected()->getTeam() == 2) {
                tileColor = COR::VERMELHA;
            }
        }

        int n = (TILE_WIDTH - tile.length() + 1) / 2 - 1;

        TextSprite line = TextSprite(std::string(TILE_WIDTH - 1, '-'), COR::BRANCA);
        TextSprite(tile, tileColor).draw(line, 0, n);
        line.draw(*pSprite, 0, 1);
//
//        line = TextSprite(std::string(TILE_WIDTH - 1, '-'), COR::BRANCA);
//
//        if (getSelected()->hasUnit() && getSelected()->getUnit()->isActive()) {
//            std::string unit = getSelected()->getUnit()->getName();
//            COR::Cor unitColor = (getSelected()->getUnit()->getTeam() == 1 ? COR::AZUL : COR::VERMELHA);
//
//            n = (TILE_WIDTH - unit.length() + 1) / 2 - 1;
//
//            TextSprite(unit, unitColor).draw(line, 0, n);
//        }

//        line.draw(*pSprite, TILE_HEIGHT, 1);
    }

private:
    int x, y;
    Tile *(map[TILES_VERTICALLY][TILES_HORIZONTALLY]);
    Menu *menu;
};


#endif //JOGO_WAR_CURSOR_H
