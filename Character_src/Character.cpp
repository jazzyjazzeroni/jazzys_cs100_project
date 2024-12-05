#include "../Character_header/Character.h"


Character::Character(CharType type, const string &name, int health, int damage, const string &element)
    : name(name), health(health), type(type), attackAmount(damage), powers(element) {}

string Character::charTypeToString(CharType type) {
    switch (type) {
        case MAINCHAR: return "Theodore";
        case GOBLIN: return "Goblin";
        default: return "Unknown";
    }
}

Powers Character::getPower() const {
        return powers;
    }

int Character::getHealth() const
{
    return this->health;
}

string Character::getType() const {
    return Character::charTypeToString(type);
}

void Character::setHealth(int health)
{
    if (health > 0)
    {
        if (health <= MAX_HEALTH)
            this->health = health;
        else
            this->health = MAX_HEALTH;
    } 
   else 
        this->health = 0;   
}

bool Character::isalive() const
{
    return this->health > 0;
}

void Character::receiveDamage(int damage)
{
    if (damage > 0) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }
}

void Character::attack(Character &enemy)
{
    if (!enemy.isalive()) {
        std::cout << name << " is already defeated! " << enemy.getType() << " cannot attack.\n";
        return;
    }
    std::cout << name << " attacks " << enemy.getType() << attackAmount << " hits!\n";
    enemy.receiveDamage(attackAmount);
    if (!enemy.isalive()) {
        std::cout << enemy.getType()<< " has been defeated!\n";
    }
}