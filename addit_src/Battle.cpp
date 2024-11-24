#include "../addit_header/Battle.h"
#include <iostream>

Battle::Battle(MainCharacter& mc, Dragon& dragon)
    :mc(this->mc), dragon(this->dragon){}

void Battle::startBattle()
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

void Battle::declareWinner()
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