#include "GameMap.h"
#include "Inventory.h"
#include "MenuPrinter.h"
#include <vector>
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Character.h"
#ifndef BATTLE_H
#define BATTLE_H

// enum CharType{MAINCHAR, GOBLIN, DRAGON, NPC};
// const double MAX_HEALTH = 200.0;

// class Character{
// protected:
// double health;
// double attackAmount;
// double damage_amount;
// string name;
// CharType type;

// public:
// Character::Character();
// virtual double getHealth () const =0;
// virtual CharType getType() =0;
// virtual void setHealth(double) =0;
// virtual bool isalive() const =0;
// Character(CharType, const string &, double, double);
// virtual void damage(double dam) = 0;
// virtual void takeDamage(double) = 0 ;
// virtual void attack(Character &) = 0;

// };

class Battle {
private:
    Character& maincharacter;
    Character& goblin;
    int num_of_rounds = 5;

public: 
    // THIS IS ONLY FOR TESTING 
    Battle(Character& mc, Character& g, int num_of_rounds);
    void round();
};
#endif 