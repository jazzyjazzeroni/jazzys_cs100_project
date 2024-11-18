#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
using namespace std; 

class Enemy : public Character {
private:
    string allegiance;
    char move;

public:
    Enemy(const string &name, double health, double attackStrength, const string &allegiance);

    void attack(Character &opponent) override;
    void WitchInteraction();
    char getMovement();
   void setMovement(char);

};

#endif