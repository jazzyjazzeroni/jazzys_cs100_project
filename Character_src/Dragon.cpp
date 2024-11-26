#include "Dragon.h"
// private:
//     int breatheFire;
//     int fireBall;

// public:
//     Dragon(const string &name, double health, double attackStrength, const string &allegiance);
//     int getfireAttack();
//     int getfireBall();
//     void setfireBall();
//     void setfireAttack();
//     void attack(Character &opponent);

Dragon::Dragon()
{
    this->name = " ";
    this->health = 0;
    this->fireBall = 0;
    this->breatheFire = 0;

}

int Dragon::getfireAttack() 
{
    return this->breatheFire;
}

void Dragon::setfireAttack(int breatheFire)
{
    this->breatheFire = this->damage_amount;
}

int Dragon::getfireBall()
{
    return this->fireBall;
}



