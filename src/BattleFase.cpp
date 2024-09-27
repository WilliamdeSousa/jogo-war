#include "BattleFase.h"
#include "Road.h"

int frame = 0;

enum TEAM {NEUTRAL, MY_TEAM, ENEMY_TEAM};

BattleFase::BattleFase() : Fase("Fase de Batalha", SpriteBuffer(WIDTH, HEIGHT)), cursor(nullptr), selection(false) {
    unitColor[0] = COR::CINZA;
    unitColor[1] = COR::AZUL;
    unitColor[2] = COR::VERMELHA;
    cityColor[0] = COR::CINZA;
    cityColor[1] = COR::AZUL;
    cityColor[2] = COR::VERMELHA;

    readLevel(LEVELS_DIR + "l001");


    menu = new Menu;
    objs.push_back(menu);

    cursor = new Cursor(map, menu, 10, 4);
    objs.push_front(cursor);
}

unsigned int BattleFase::run(SpriteBuffer &screen) {
    KeyBoard::setInputMode(); // modificar comportamento da entrada de dados

    char input;
    do {
        update(screen);

        if (KeyBoard::readInput(input)) {
            // processar entradas
            if (input == 'd') cursor->moveToRight();
            else if (input == 'a') cursor->moveToLeft();
            else if (input == 'w') cursor->moveToUp();
            else if (input == 's') cursor->moveToDown();
            else if (input == 10) select();
            else if (input == 27) unselect();
        }
        if (checkVictory())
            return LEVEL_COMPLETE;
    } while (input != 'q');

    KeyBoard::setInputMode(false); // retorna as configurações padrões da entrada de dados

    return END_GAME;
}

void BattleFase::update(SpriteBuffer &screen) {
    if (DEBUG_MODE)
        std::cout << "Frame " << frame++ << std::endl;
    else
        system("clear"); // limpa o terminal
    screen.clear(); // limpa o buffer
    Fase::update(); // atualiza os objetos
    draw(screen); // desenha os objetos na screen
    show(screen); // mostra os objetos no terminal
}

void BattleFase::readLevel(const std::string &level) {
    std::ifstream arquivo(level);

    readTiles(arquivo);
    readUnits(arquivo);
}
void BattleFase::readTiles(std::ifstream &arquivo) {
    int type, team;
    Tile *tile;
    if (DEBUG_MODE)
        std::cout << "Reanding Tiles:" << std::endl;
    for (int i = 0; i < TILES_VERTICALLY; i++)
        for (int j = 0; j < TILES_HORIZONTALLY; j++) {
            arquivo >> type;
            switch (type) {
                case Tiles::GRASS:
                    tile = new Tile("Grass", j, i, COR::VERDE, RESOURCE::GRASS);
                    break;
                case Tiles::ROAD:
                    bool nesw[4];
                    arquivo >> nesw[0] >> nesw[1] >> nesw[2] >> nesw[3];
                    tile = new Road(j, i, nesw);
                    break;
                case Tiles::WATER:
                    tile = new Tile("Water", j, i, COR::CIANO, RESOURCE::WATER);
                    break;
                case Tiles::MOUNTAIN:
                    tile = new Tile("Mountain", j, i, COR::VERDE, RESOURCE::MOUNTAIN);
                    break;
                case Tiles::FLOREST:
                    tile = new Tile("Florest", j, i, COR::VERDE, RESOURCE::FLOREST);
                    break;
                case Tiles::CITY:
                    arquivo >> team;
                    tile = new City(j, i, team);
                    break;
                default:
                    tile = new City(j, i, 0 );
                    break;
            }
            map[i][j] = tile;
            objs.push_front(tile);
            if (DEBUG_MODE)
                std::cout << "Adding Tile " << Tile::idToString(type) << " at (" << j << ", " << i << ")" << std::endl;
        }
}

void BattleFase::readUnits(std::ifstream &arquivo) {
    int x, y, team, type;
    Unit *unit;


    if (DEBUG_MODE)
        std::cout << "Reading Units:" << std::endl;
    while (arquivo >> type) {
        arquivo >> x >> y >> team;
        switch (type) {
            case Units::TANK:
                unit = new Tank(x, y, unitColor[team], map[y][x], team);
                map[y][x]->setUnit(unit);
                break;
            case Units::SOLDIER:
                unit = new Soldier(x, y, unitColor[team], map[y][x], team);
                map[y][x]->setUnit(unit);
                break;
            case Units::BAZUCA:
                unit = new Bazuca(x, y, unitColor[team], map[y][x], team);
                map[y][x]->setUnit(unit);
                break;
            case Units::HELICOPTER:
                unit = new Helicopter(x, y, unitColor[team], map[y][x], team);
                map[y][x]->setUnit(unit);
                break;
        }
        if (team == 1)
            myUnits.push_back(unit);
        else
            enemyUnits.push_back(unit);

        objs.push_back(unit);

        if (DEBUG_MODE)
            std::cout << "Adding " << ((team == 2) ? "Enemy" : "Ally") << " Unit " << Unit::idToString(type) << " at (" << x << ", " << y << ")" << std::endl;
    }
}

void BattleFase::selectTile(int x, int y, COR::Cor selectionColor = COR::AMARELA) {
    Unit *selected = cursor->getSelected()->getUnit();
    if (moviment) {
        if (map[y][x]->hasUnit())
            return;
        if (map[y][x]->getName() == "Water" && !selected->canFly())
            return;
        if (map[y][x]->getName() == "Mountain" && !selected->canClimb())
            return;
    }
    if (!moviment) {
        if (map[y][x]->hasUnit() && map[y][x]->getUnit()->getTeam() == selected->getTeam())
            return;
    }

    objs.push_front(new Selection(x, y, selectionColor));
    map[y][x]->select();
}

void BattleFase::showRange(int range, COR::Cor selectionColor) {
    selection = true;

    int x = cursor->getX();
    int y = cursor->getY();

    // esquerda
    int x1 = x - 1, i = 1;
    while (x1 >= 0 && x1 >= x - range) {
        selectTile(x1, y, selectionColor);

        // esquerda-cima
        int y1 = y - 1;
        while (y1 >= 0 && y1 >= y - range + i)
            selectTile(x1, y1--, selectionColor);

        // esquerda-baixo
        y1 = y + 1;
        while (y1 < TILES_VERTICALLY && y1 <= y + range - i)
            selectTile(x1, y1++, selectionColor);

        x1--; i++;
    }

    // direita
    x1 = x + 1, i = 1;
    while (x1 < TILES_HORIZONTALLY && x1 <= x + range) {
        selectTile(x1, y, selectionColor);

        // direita-cima
        int y1 = y - 1;
        while (y1 >= 0 && y1 >= y - range + i)
            selectTile(x1, y1--, selectionColor);

        // direita-baixo
        y1 = y + 1;
        while (y1 < TILES_VERTICALLY && y1 <= y + range - i)
            selectTile(x1, y1++, selectionColor);

        x1++; i++;
    }

    // cima
    int y1 = y - 1;
    while (y1 >= 0 && y1 >= y - range + 1)
        selectTile(x, y1--, selectionColor);

    // baixo
    y1 = y + 1;
    while (y1 < TILES_VERTICALLY && y1 <= y + range - 1)
        selectTile(x, y1++, selectionColor);
}

void BattleFase::showMovimentRange() {
    moviment = true;
    showRange(cursor->getSelected()->getUnit()->getMovimentRange(), COR::AMARELA);
}

void BattleFase::showAttackRange() {
    moviment = false;
    showRange(cursor->getSelected()->getUnit()->getAttackRange(), COR::VERMELHA);
}

void BattleFase::select() {
    Tile *tileSelected = cursor->getSelected();
    bool hasUnit = tileSelected->hasUnit();
    Unit *unitSelected = tileSelected->getUnit();

    if (selection) {
        if (!tileSelected->isSelected())
            removeSelection();
        else if (moviment) {
            moveUnit(lastSelectedUnit, cursor->getX(), cursor->getY());
            removeSelection();
        } else {
            if (cursor->getSelected()->hasUnit()) {
                lastSelectedUnit->attack(cursor->getSelected()->getUnit());
                if (!unitSelected->isActive())
                    tileSelected->setUnit(nullptr);
            }
            else {
                if (DEBUG_MODE) {
                    std::cout << "Empty tile" << std::endl;
                }
            }
            removeSelection();
        }
    }

    if (DEBUG_MODE) {
        std::cout << "Select (x=" << cursor->getX() << ", y=" << cursor->getY() << "): " << tileSelected->getName() << (hasUnit ? " -> " + unitSelected->getName() : "") << std::endl;
    }

    if (!menu->isOpen()) {
        if (hasUnit && unitSelected->getTeam() == 1) {
            menu->open(cursor->getX(), cursor->getY());
            lastSelectedUnit = cursor->getSelected()->getUnit();
        }
    } else {
        switch (menu->getSelectedOption()) {
            case 0:
                showMovimentRange();
                break;
            case 1:
                showAttackRange();
                break;
        }
        menu->close();
    }
}

void BattleFase::unselect() {
    if (DEBUG_MODE) {
        Tile *selected = cursor->getSelected();
        std::cout << "Unselect (x=" << cursor->getX() << ", y=" << cursor->getY() << "): " << selected->getName() << std::endl;
    }
    removeSelection();
    menu->close();
}

void BattleFase::removeSelection() {
    if (DEBUG_MODE)
        std::cout << "removendo seleção\n";
    while (objs.front()->getName() == "Selection") {
        ObjetoDeJogo *obj = objs.front();
        map[(obj->getPosL() - 1) / TILE_HEIGHT][(obj->getPosC() - 1) / TILE_WIDTH]->unselect();
        objs.pop_front();
        delete obj;
    }
    selection = false;
}

void BattleFase::moveUnit(Unit *unit, int x, int y) {
    unit->getTile()->setUnit(nullptr);
    unit->setTile(map[y][x]);
    map[y][x]->setUnit(unit);
    unit->moveTo(y * TILE_HEIGHT + 1, x * TILE_WIDTH + 1);
}

bool BattleFase::checkVictory() {
    if (enemyUnits.empty())
        return true;
    return false;
}