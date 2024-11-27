#include "Dragon.h"
#include "MainCharacter.h"
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


Dragon::Dragon(const string &name, int pHealth, int pBreatheFire, int pFireBall)
{
   this->name = "Ignus";
   this->health = health;
   this->breathe_fire = pBreatheFire;
   this->fire_ball = pFireBall;
}

Dragon::Dragon()
{
    this->name = " ";
    this->health = 0;
    this->fire_ball = 0;
    this->breathe_fire = 0;
}

Dragon::~Dragon()
{

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

void Dragon::setfireBall(int damage)
{
    this->fire_ball = damage;
}
void Dragon::attack(Character &player)
{
    if(this->fire_ball > 0)
    {
        this->attack_amount = this->fire_ball;
    }

    if(this->breathe_fire > 0)
    {
        this->attack_amount = this->breathe_fire;
    }
}
void Dragon::startBattle()
    {
        std::cout << "You have made it to the dragon's lair\n";
        std::cout << "Will you be able to defeat Ignus?\n";
        std::cout << "FINAL ROUND:\n";

        while(mc.isalive() && dragon.isalive())
        {
            // MainCharacter move
            std::cout << "Theodore attacks Ignus!\n";
            mc.attack(dragon);
            if(!dragon.isalive())
            {
                std::cout << "IGNUS HAS BEEN DEFEATED!\n";
                break;
            }

            // MainCharacter move
            std::cout << "Theodore attacks Ignus!\n";
            dragon.attack(mc);
            if(!mc.isalive())
            {
                std::cout << "You have died...\n";
                break;
            }

            std::cout << "Theodore's health status: " << mc.getHealth() << '\n';
            std::cout << "Ignus' health status: " << dragon.getHealth() << '\n';
        }

        declareWinner();
    }

void Dragon::declareWinner()
    {
        if(mc.isalive() && !dragon.isalive())
        {
            std::cout << "You have slained Ignus! YOU WON THE GAME\n";
        }
        else if(!mc.isalive() && dragon.isalive())
        {
            std::cout << "Ignus has won. Try again? y/n \n"; 
        }
        else
            std::cout << "Both characters have been defeated. DRAW!\n";
    }

