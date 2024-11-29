#include "../Character_header/Goblin.h"

using namespace std;
// the goblin constructor i believe
Goblin::Goblin(const string &name, int health, int attackStrength, const string &allegiance)
    : Character(GOBLIN, name, health, attackStrength, 0) { // Initialize base class
}

// returns goblin's current health
int Goblin::getHealth() const {
    return health;
}

// returns goblin's type of element maybe?
string Goblin::getType() {
    return charTypeToString(type);
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

// decreases goblin's health by however much damage the player does
void Goblin::recieveDamage(int dam) {
    this->health -= dam;
    if (health < 0) {
        health = 0;
    }
}

// void Goblin::usePowers() {
//     cout << name << " uses a special power!" << endl;
//     powers.usePower(powers.getPower(), allegiance); // Assuming `activate()` is a method in `Powers`
// }

// probably used when the goblin goes to attack the player
void Goblin::attack(Character &player) {
    player.receiveDamage(attackAmount);
}