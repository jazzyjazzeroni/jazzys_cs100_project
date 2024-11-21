//Pseudocode
#include "../addit_header/Battle.h"
#include <iostream>

Battle::Battle(Character& player, Character& goblin, int num_of_rounds)
{
    this->player = player;
    this->goblin = goblin;
    this->num_of_rounds = num_of_rounds;
}