#include "../Character_header/Character.h"

Character::Character()
{
    health = 0;
    attack_amount = 0;
    damage_amount = 0;
    name = " ";
    type = MAINCHAR;
}

Character::Character(CharType type, const string &name, double health, double amount)
{
    this->type = type;
    this->name = name;
    this->health = health;
    this->amount = amount;
}