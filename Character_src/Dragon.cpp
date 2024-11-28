#include "../Character_header/Dragon.h"
#include "../Character_header/MainCharacter.h"

Dragon::Dragon(MainCharacter& mc, const string &name, int pHealth, int pBreatheFire, int pFireBall)
    : mc(mc), breathe_fire(pBreatheFire), fire_ball(pFireBall) {
    this->name = name;
    health = pHealth;
}

void Dragon::setfireAttack(int breatheFire){
    this->breathe_fire = breatheFire;
}

// Dragon::Dragon()
// {
//     this->name = " ";
//     this->health = 0;
//     this->fire_ball = 0;
//     this->breathe_fire = 0;
// }

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
void Dragon::attack(MainCharacter &mc)
{
    if(this->fire_ball > 0)
    {
        // this->attack_amount = this->fire_ball;
        mc.recieveDamage(this->fire_ball);
    }

    if(this->breathe_fire > 0)
    {
        // this->attack_amount = this->breathe_fire;
        mc.recieveDamage(this->breathe_fire);
    }
}
void Dragon::startBattle()
    {
        std::cout << "You have made it to the dragon's lair\n";
        std::cout << "Will you be able to defeat Ignus?\n";
        std::cout << "FINAL ROUND:\n";

        while(mc.isalive() && this->isalive())
        {
            // MainCharacter move
            std::cout << "Theodore attacks Ignus!\n";
            mc.attack(*this); //maybe not should be okay bc this pointer
            if(!this->isalive())
            {
                std::cout << "IGNUS HAS BEEN DEFEATED!\n";
                break;
            }

            // MainCharacter move
            std::cout<< "Theodore attacks Ignus!\n";
            this->attack(mc);
            if(!mc.isalive())
            {
                std::cout << "You have died...\n";
                break;
            }

            std::cout<< "Theodore's health status: " << mc.getHealth() << '\n';
            std::cout<< "Ignus' health status: " << this->getHealth() << '\n';
        }

        declareWinner();
    }

void Dragon::declareWinner()
    {
        if(mc.isalive() && !this->isalive())
        {
            std::cout << "You have slained Ignus! YOU WON THE GAME\n";
        }
        else if(!mc.isalive() && this->isalive())
        {
            std::cout << "Ignus has won. Try again? y/n \n"; 
        }
        else
            std::cout << "Both characters have been defeated. DRAW!\n";
    }