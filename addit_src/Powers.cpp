#include "../addit_header/Powers.h"

using namespace std;

Powers::Powers(const string &element) : currentElement(element) {
    if (element == "Fire") powers = FIRE;
    else if (element == "Water") powers = WATER;
    else if (element == "Earth") powers = EARTH;
    else if (element == "Air") powers = AIR;
    else throw invalid_argument("Unknown power type: " + element);
}
int Powers::calculateDamage() const {
    switch (powers) {
        case FIRE: return 20;        // FIRE does 20 damage
        case WATER: return 15;       // WATER does 15 damage
        case EARTH: return 10;       // EARTH does 10 damage
        case AIR: return 12;         // AIR does 12 damage
        default: return 0;           // Default is no damage
    }
}
Power_type Powers::getPower() const {
    return powers;
}
void Powers::setPower(const int powerTypeIndex) { 
    powers = static_cast<Power_type>(powerTypeIndex);
}
int Powers::getDamage() const {
    return powerDamage;
}
void Powers::setDamage(int damage) {
    if (damage >= 0) {
        powerDamage = damage;
    } else {
        cout << "Invalid damage value. Damage cannot be negative." << endl;
    }
}
bool Powers::canUsePower(Powers opponentPower) const {
    if ((powers == WATER && opponentPower.powers == FIRE) || 
        (powers == FIRE && opponentPower.powers == WATER) ||
        (powers == EARTH && opponentPower.powers == AIR) || 
        (powers == AIR && opponentPower.powers == EARTH)) {
        return true; // Elemental advantage
    }
    return false; // Default: Ineffective power
}




