#ifndef JOGO_WAR_UNIT_H
#define JOGO_WAR_UNIT_H

class Tile;

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Constants.h"
#include <string>

enum Units {SOLDIER, BAZUCA, TANK, HELICOPTER};

typedef struct {
    int attack, defense, movimentRange, attackRange;
    bool climp, fly;
} UnitAttributes;

const UnitAttributes unitAttributes[] = {
        {20, 1, 4, 3, true, false},
        {25, 1, 3, 2, true, false},
        {35, 5, 4, 2, false, false},
        {30, 1, 6, 4, true, true}
};

class Unit : public ObjetoDeJogo {
public:
    Unit(std::string name, std::string resource, int x, int y, COR::Cor cor = COR::PADRAO, Tile *tile = nullptr, int team = 1, UnitAttributes unitAttribute = unitAttributes[0]) : ObjetoDeJogo(name, Sprite(resource, cor), y * TILE_HEIGHT + 1, x * TILE_WIDTH + 1), tile(tile), team(team), attackPower(unitAttribute.attack), defense(unitAttribute.defense), movimentRange(unitAttribute.movimentRange), attackRange(unitAttribute.attackRange), climb(unitAttribute.climp), fly(unitAttribute.fly), life(100.0) {}
    virtual ~Unit() = default;

    static std::string idToString(int id) {
        switch (id) {
            case SOLDIER: return "Soldier";
            case BAZUCA: return "Bazuca";
            case TANK: return "Tank";
            case HELICOPTER: return "Helicopter";
            default: return "ERROR";
        }
    }

    int getTeam() const { return team; }
    int getAttackRange() const { return attackRange; }
    int getMovimentRange() const { return movimentRange; }

    bool canFly() const { return fly; }
    bool canClimb() const { return climb; }

    bool canAttack(Unit *unit) {
        int unitX = (unit->getPosC() - 1) / TILE_WIDTH, unitY = (unit->getPosL() - 1) / TILE_HEIGHT;
        int thisX = (this->getPosC() - 1) / TILE_WIDTH, thisY = (this->getPosL() - 1) / TILE_HEIGHT;
        return attackRange >= ((thisX > unitX) ? thisX - unitX : unitX - thisX) + ((thisY > unitY) ? thisY - unitY : unitY - thisY);
    }

    virtual void attack(Unit *unit) {
        double receivedDamage = 0, causedDamage = (this->attackPower - unit->defense) * (this->life/100.0) * 1.5;
        unit->life -= causedDamage;

        if (unit->canAttack(this)) {
            receivedDamage = (unit->attackPower - this->defense) * (unit->life/100.0);
            this->life -= receivedDamage;
        }
        if (unit->life < 10)
            unit->desativarObj();

        if (life < 10)
            desativarObj();

        if (DEBUG_MODE) {
            std::cout << getName() << " is attacking " << unit->getName() << std::endl;
            std::cout << "Caused damage: " << causedDamage << std::endl;
            std::cout << "Received damage: " << receivedDamage << std::endl;
        }
    }

    void draw(SpriteBase &screen, int x, int y) override {
        int intLife = static_cast<int> (life / 10);
        if (intLife > 0) {
            ObjetoDeJogo::draw(screen, x, y);
            if (intLife < 10 && active) {
                TextSprite textLife("[" + std::to_string(intLife) + "]", COR::BRANCA);
                textLife.draw(screen, x + TILE_HEIGHT - 2, y + TILE_WIDTH - 4);
            }
        }
    }

    Tile *getTile() { return tile; }
    void setTile(Tile *tile) { this->tile = tile; }

protected:
    double life;
    int attackPower, movimentRange, defense, attackRange, team;
    bool fly, climb;
    Tile *tile;
};


#endif //JOGO_WAR_UNIT_H
