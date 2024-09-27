//
// Created by william on 9/26/24.
//
#include "Menu.h"

void Menu::update() {
    if (active) {
        TextSprite(">", COR::BRANCA).draw(*pSprite, 1 + selectedOption, 2);
        TextSprite(" ").draw(*pSprite, 1 + ((selectedOption + 1) % 2), 2);
    }
}

