#ifndef JOGO_WAR_CONSTANTS_H
#define JOGO_WAR_CONSTANTS_H

const int TILE_WIDTH = 12, TILE_HEIGHT = 7;
const int TILES_HORIZONTALLY = 19, TILES_VERTICALLY = 7;
const int WIDTH = TILES_HORIZONTALLY * TILE_WIDTH + 1, HEIGHT = TILES_VERTICALLY * TILE_HEIGHT + 1;

const bool DEBUG_MODE = true;

namespace RESOURCE {
    const std::string RESOURCE_DIR = "../rsc/";
    const std::string TANK = RESOURCE_DIR + "tank.img";
    const std::string SOLDIER = RESOURCE_DIR + "soldier.img";
    const std::string HELICOPTER = RESOURCE_DIR + "helicopter.img";
    const std::string BAZUCA = RESOURCE_DIR + "bazuca.img";
    const std::string FLOREST = RESOURCE_DIR + "florest.img";
    const std::string CITY = RESOURCE_DIR + "city.img";
    const std::string WATER = RESOURCE_DIR + "water.img";
    const std::string GRASS = RESOURCE_DIR + "grass.img";
    const std::string ROAD = RESOURCE_DIR + "road/";
    const std::string MOUNTAIN = RESOURCE_DIR + "mountain.img";
    const std::string CURSOR = RESOURCE_DIR + "cursor.img";
    const std::string MENU = RESOURCE_DIR + "menu.img";
    const std::string SELECTION = RESOURCE_DIR + "selection.img";
}

const std::string LEVELS_DIR = "../levels/";
const std::string LEVEL_1 = LEVELS_DIR + "l001/";


#endif //JOGO_WAR_CONSTANTS_H
