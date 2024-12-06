#include "../Character_header/Goblin.h"

using namespace std;
// the goblin constructor i believe
Goblin::Goblin(const std::string &name, int health, int damage, const std::string &element)
    : Character(GOBLIN, name, health, damage, element), powers(element), currentElement(element) {
    if (element != "Fire" && element != "Water" && element != "Earth" && element != "Air") {
        throw std::invalid_argument("Unknown power type: " + element);
    }
}


// returns goblin's current health
int Goblin::getHealth() const {
    return health;
}

 std::string Goblin::getGoblinType() const {
        return currentElement;  
    }

// returns goblin's type of element maybe?
string Goblin::getType() const{
    return "Goblin";
}

// set's goblin's health
void Goblin::setHealth(int health) {
    this->health = health;
}

// returns true if goblin is still alive
bool Goblin::isalive() const {
    return (getHealth() > 0);
}


void Goblin::recieveDamage(int dam) {
    this->health -= dam;
    if (health < 0) {
        health = 0;
    }
}



// // probably used when the goblin goes to attack the player
void Goblin::attack(Character &target) {
    cout << getType() << " attacks " << target.getType() << "!" << endl << endl;

    int targetHealth = target.getHealth();
    target.setHealth(targetHealth - powers.calculateDamage());
    cout << target.getType() << "'s health after attack: " << target.getHealth() << endl << endl;
}

void Goblin::print() const {
    cout << "Goblin: " << name << ", Health: " << health << ", Attack: " << attackAmount << endl;
}