#ifndef JOGO_WAR_BATTLEFASE_H
#define JOGO_WAR_BATTLEFASE_H

#include "ASCII_Engine/Fase.hpp"
#include "KeyBoard.h"
#include "Constants.h"
#include "Cursor.h"

#include "Unit.h"
#include "Tile.h"
#include "Tank.h"
#include "Soldier.h"
#include "Helicopter.h"
#include "Bazuca.h"
#include "City.h"
#include "Menu.h"
#include "Selection.h"

#include <fstream>
#include <string>

class BattleFase : public Fase {
public:
    BattleFase();

    void init() override {}
    unsigned int run(SpriteBuffer &screen) override;

    void update(SpriteBuffer &screen);

    void showAttackRange();
    void showMovimentRange();

    void select();
    void unselect();

private:
    Cursor *cursor;
    Menu *menu;
    std::list<Unit*> myUnits;
    std::list<Unit*> enemyUnits;
    Unit *lastSelectedUnit;
    Tile *(map[TILES_VERTICALLY][TILES_HORIZONTALLY]);
    bool selection;
    bool moviment;

    COR::Cor unitColor[3];
    COR::Cor cityColor[3];

    void readLevel(const std::string &level);
    void readUnits(std::ifstream &arquivo);
    void readTiles(std::ifstream &arquivo);

    void selectTile(int x, int y, COR::Cor selectionColor);
    void removeSelection();
    void showRange(int range, COR::Cor selectionColor);
    void moveUnit(Unit *unit, int x, int y);

    bool checkVictory();
};

#endif //JOGO_WAR_BATTLEFASE_H
