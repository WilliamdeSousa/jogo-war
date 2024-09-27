#ifndef JOGO_WAR_MENU_H
#define JOGO_WAR_MENU_H

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Constants.h"

class Menu : public ObjetoDeJogo {
public:
    Menu(int x = 0, int y = 0) : ObjetoDeJogo("Menu de Ação", Sprite(RESOURCE::MENU, COR::BRANCA), y, x), selectedOption(0), MAX(2) { close(); }

    void update() override;

    void moveDown() { selectedOption = (selectedOption + 1) % 2; }
    void moveUp() { selectedOption = (selectedOption + 1) % 2; }

    bool isOpen() const { return active; }
    void open(int x, int y) {
        selectedOption = 0;
        ativarObj();
        moveTo(y * TILE_HEIGHT + 4, x * TILE_WIDTH);
    }

    void close() {
        desativarObj();
    }

    int getSelectedOption() const { return selectedOption; }

private:
    int selectedOption, MAX;
};

#endif //JOGO_WAR_MENU_H
