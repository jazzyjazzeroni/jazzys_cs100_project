#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
using namespace std; 

class Enemy : public Character {
private:
    string allegiance;
    string enemy_type;
    double damage;

public:
    Enemy(const string &name, double health, double attackStrength, const string &allegiance, const string &enemy_type);

    void attack(Character &opponent) override;
    void takeDamage(int);

};

#endif