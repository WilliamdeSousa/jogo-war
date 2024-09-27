#ifndef JOGO_WAR_SELECTION_H
#define JOGO_WAR_SELECTION_H

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Selection : public ObjetoDeJogo {
public:
    Selection(int x, int y, COR::Cor color) : ObjetoDeJogo("Selection", Sprite(RESOURCE::SELECTION, color), y * TILE_HEIGHT, x * TILE_WIDTH) {}
};

#endif //JOGO_WAR_SELECTION_H
