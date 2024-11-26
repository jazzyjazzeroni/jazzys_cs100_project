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


Dragon::Dragon(const string &name, int health, int attackStrength)
{
   this->name = "Ignus";
   this->health = health;
   this->attack_amount = attackStrength;

}

Dragon::Dragon()
{
    this->name = " ";
    this->health = 0;
    this->fire_ball = 0;
    this->breathe_fire = 0;
}

int Dragon::getfireAttack() 
{
    return this->breathe_fire;
}

void Dragon::setfireAttack(int breatheFire)
{
    this->breathe_fire = this->damage_amount;
}

int Dragon::getfireBall()
{
    return this->fire_ball;
}

void Dragon::attack(Character &player)
{
    int attack_amount = breathe_fire;
    if(fire_ball > 0)
    {
        attack_amount = fire_ball;
    }
}


