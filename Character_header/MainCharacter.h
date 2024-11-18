#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
using namespace std; 

class MainCharacter : public Character {
private:
    string allegiance;
    char move;

public:
    MainCharacter(const string &name, double health, double attackStrength, const string &allegiance);

    void attack(Character &opponent) override;
    void WitchInteraction();
    char getMovement();
   void setMovement(char);

};

#endif