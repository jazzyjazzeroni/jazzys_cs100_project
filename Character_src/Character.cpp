#include "../Character_header/Character.h"

Character::Character()
{
    this->health = 0;
    this->attack_amount = 0;
    this->damage_amount = 0;
    this->name = " ";
    this->type = MAINCHAR;
}

Character::Character(CharType type, const string &name, int health, int attack_amount, int damage_amount)
{
    this->type = type;
    this->name = name;
    this->health = health;
    this->attack_amount = attack_amount;
    this->damage_amount = damage_amount;
}

int Character::getHealth() const
{
    return this->health;
}


