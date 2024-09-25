#include "BattleFase.h"
#include "Road.h"

int frame = 0;

enum TEAM {NEUTRAL, MY_TEAM, ENEMY_TEAM};

BattleFase::BattleFase() : Fase("Fase de Batalha", SpriteBuffer(WIDTH, HEIGHT)), cursor(nullptr), unitColor(COR::CINZA, COR::AZUL, COR::VERMELHA), cityColor(COR::CINZA, COR::AZUL, COR::VERMELHA) {
    readLevel(LEVELS_DIR + "l001");

    cursor = new Cursor(map);
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
            else if (input == 10) cursor->select();
            else if (input == 27) cursor->unselect();
        }

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
                case Tiles::MONTAIN:
                    tile = new Tile("Montain", j, i, COR::VERDE, RESOURCE::MONTAIN);
                    break;
                case Tiles::FLOREST:
                    tile = new Tile("Florest", j, i, COR::VERDE, RESOURCE::FLOREST);
                    break;
                case Tiles::CITY:
                    arquivo >> team;
                    tile = new City(j, i, cityColor[team]);
                    break;
                default:
                    tile = new City(j, i, COR::AMARELA);
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
                unit = new Tank(x, y, unitColor[team], map[y][x]);
                map[y][x]->setUnit(unit);
                break;
            case Units::SOLDIER:
                unit = new Soldier(x, y, unitColor[team], map[y][x]);
                map[y][x]->setUnit(unit);
                break;
            case Units::BAZUCA:
                unit = new Bazuca(x, y, unitColor[team], map[y][x]);
                map[y][x]->setUnit(unit);
                break;
            case Units::HELICOPTER:
                unit = new Helicopter(x, y, unitColor[team], map[y][x]);
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
