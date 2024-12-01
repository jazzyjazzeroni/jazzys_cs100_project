#include "../Character_header/Goblin.h"
#include <iostream>

using namespace std;
// the goblin constructor i believe
Goblin::Goblin(const string &name, int health, int attackStrength, int specialPower, const string &allegiance) {
    this->name = name;
    this->health = health;
    this->attackAmount = attackStrength;
    this->specialPower = specialPower;

}

// returns goblin's current health
int Goblin::getHealth() const {
    return health;
}

// returns goblin's type of element maybe?
CharType Goblin::getType() {
    return type;
}

// set's goblin's health
void Goblin::setHealth(int health) {
    this->health = health;
}

// returns true if goblin is still alive
bool Goblin::isalive() const {
    return (getHealth() > 0);
}

// sets attackAmount to however much damage
// the goblin deals to the player i think
void Goblin::dealtDamage(int dam) {
    this->attackAmount = dam;
}

// decreases goblin's health by however much damage the player does
void Goblin::recieveDamage(int dam) {
    this->health -= dam;
}

// probably used when the goblin goes to attack the player
void Goblin::attack(Character &player) {
    player.recieveDamage(attackAmount);
}
