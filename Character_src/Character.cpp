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

CharType Character::getType() 
{
    return this->type;
}

void Character::setHealth(int health)
{
    if (health > 0) // Character still has health
    {
        if (health <= MAX_HEALTH)
            this->health = health;
        else
            this->health = MAX_HEALTH;
    } 
   else // Character has no more health
        this->health = 0;   
}

bool Character::isalive() const
{
    return this->health > 0;
}

void Character::damage(int damage_amount)
{
    if(damage_amount > 0)
    {
       this->health -= damage_amount;
        if (this->health < 0) {
            this->health = 0;
        }
    }
}

void Character::takeDamage(int dam)
{
    std::cout << "Theodore loses " << damage_amount << '\n';
    this->damage(dam);
    std::cout << "Health Status: " << health << '\n';
}

void Character::attack(Character &enemy)
{
    if (!enemy.isalive()) {
        std::cout << enemy.name << " is already defeated! " << name << " cannot attack.\n";
        return;
    }
    std::cout << name << " attacks " << enemy.name << attack_amount << " hits!\n";
    enemy.takeDamage(this->attack_amount);
    if (!enemy.isalive()) {
        std::cout << enemy.name << " has been defeated!\n";
    }
}