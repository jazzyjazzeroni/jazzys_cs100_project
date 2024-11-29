#include "../Character_header/Goblin.h"

using namespace std;
// the goblin constructor i believe
Goblin::Goblin(const std::string &name, int health, int damage, const std::string &element)
    : Character(GOBLIN, name, health, damage, element), powers(element) {}


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

void Goblin::usePowers() {
    cout << name << " uses a special power!" << endl;
    powers.usePower(powers.getPower(), "The enemy"); // Assuming `activate()` is a method in `Powers`
}

// probably used when the goblin goes to attack the player
void Goblin::attack(Character &target) {
    cout << getType() << " attacks " << target.getType() << "!" << endl;
    
    // Assuming target has an element or you can pass some identifier
    powers.usePower(target.getPower(), target.getType());

    // Subtract damage (assuming target's `getHealth()` and `setHealth()` exist)
    int targetHealth = target.getHealth();
    target.setHealth(targetHealth - powers.calculateDamage());
    cout << target.getType() << "'s health after attack: " << target.getHealth() << endl;
}
