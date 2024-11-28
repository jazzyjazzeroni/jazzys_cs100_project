#include "../Character_header/Character.h"
// Character::Character()
// {
//     this->health = 0;
//     this->attackAmount = 0;
//     this->damage_amount = 0;
//     this->name = " ";
//     this->type = MAINCHAR;
// }

Character::Character(CharType type, const string &name, int health, int attackAmount, int damage_amount)
{ //todo no default constructor exists for class "Powers"C/C++(291)
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackAmount = attackAmount;
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

void Character::dealtDamage(int damage_amount)
{
    if(damage_amount > 0)
    {
       this->health -= damage_amount;
        if (this->health < 0) {
            this->health = 0;
        }
    }
}

void Character::recieveDamage(int dam)
{
    std::cout << "Theodore loses " << damage_amount << '\n';
    this->dealtDamage(dam);
    std::cout << "Health Status: " << health << '\n';
}

void Character::attack(Character &enemy)
{
    if (!enemy.isalive()) {
        std::cout << enemy.name << " is already defeated! " << name << " cannot attack.\n";
        return;
    }
    std::cout << name << " attacks " << enemy.name << attackAmount << " hits!\n";
    enemy.recieveDamage(this->attackAmount);
    if (!enemy.isalive()) {
        std::cout << enemy.name << " has been defeated!\n";
    }
}

void Character::updateElementForLevel() {
    currentElement = level.getElementForLevel(level.getCurrentLevel());
}

Power_type Character::getCurrentElement() const {
    return currentElement;
}