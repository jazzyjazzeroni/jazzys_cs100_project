#include "../Character_header/Character.h"
#include "../addit_header/Powers.h" // Include the header file for Powers class

Character::Character(CharType type, const string &name, int health, int attackAmount, int damage_amount){ 
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackAmount = attackAmount;
    this->damage_amount = damage_amount;
}

string Character::charTypeToString(CharType type) {
    switch (type) {
        case MAINCHAR: return "Theodore";
        case GOBLIN: return "Goblin";
        case DRAGON: return "Dragon";
        default: return "Unknown";
    }
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

// void Character::updateElementForLevel() {
//     currentElement = level.getElementForLevel(level.getCurrentLevel());
// }

Power_type Character::getCurrentElement() const {
    return currentElement;
}