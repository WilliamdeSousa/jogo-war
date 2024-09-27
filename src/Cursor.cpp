#include "Cursor.h"

void Cursor::moveToRight() {
    if (menu->isOpen())
        menu->close();
    if (x < TILES_HORIZONTALLY - 1) {
        moveRight(TILE_WIDTH);
        x++;
    }
}

void Cursor::moveToLeft() {
    if (menu->isOpen())
        menu->close();
    if (x > 0) {
        moveLeft(TILE_WIDTH);
        x--;
    }
}

void Cursor::moveToDown() {
    if (menu->isOpen())
        menu->moveDown();
    else if (y < TILES_VERTICALLY - 1) {
        moveDown(TILE_HEIGHT);
        y++;
    }
}
void Cursor::moveToUp() {
    if (menu->isOpen())
        menu->moveUp();
    else if (y > 0) {
        moveUp(TILE_HEIGHT);
        y--;
    }
}
