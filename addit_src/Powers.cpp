#include "../addit_header/Powers.h"

using namespace std;

Powers::Powers(const string &element) : currentElement(element) {
    if (element == "ICE") powers = ICE;
    else if (element == "FIRE") powers = FIRE;
    else if (element == "EARTH") powers = EARTH;
    else if (element == "AIR") powers = AIR;
    else if (element == "FUSED_POWER") powers = FUSED_POWER;
    else throw invalid_argument("Unknown power type: " + element);
}

int Powers::calculateDamage() const {
    switch (powers) {
        case ICE: return 15;         // ICE does 15 damage
        case FIRE: return 20;        // FIRE does 20 damage
        case EARTH: return 10;       // EARTH does 10 damage
        case AIR: return 12;         // AIR does 12 damage
        case FUSED_POWER: return 50; // FUSED_POWER does 50 damage
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

bool Powers::canUsePower(Power_type opponentPower) const {
    if ((powers == ICE && opponentPower == FIRE) || 
        (powers == FIRE && opponentPower == ICE) ||
        (powers == EARTH && opponentPower == AIR) || 
        (powers == AIR && opponentPower == EARTH)) {
        return true; // Elemental advantage
    }
    return false; // Default: Ineffective power
}
void Powers::usePower(Power_type opponentPower, const string &enemyAllegiance) {
    powerDamage = calculateDamage(); // Update power damage

    if (canUsePower(opponentPower)) {
        cout << "Elemental Power used against " << enemyAllegiance << "!" << endl;
        cout << "Dealt " << powerDamage << " damage!" << endl;
    } else if (powers == opponentPower) {
        cout << "Warning: Using the same element against " << enemyAllegiance 
             << " results in self-damage!" << endl;
        cout << "Dealt no damage!" << endl;
    } else {
        cout << "This Elemental Power is ineffective against " << enemyAllegiance << "!" << endl;
        cout << "Dealt no damage!" << endl;
    }
}

void Powers::handleAttack(const string &goblinElement, int &health) const {
    Power_type goblinPower;

    if (goblinElement == "ICE") goblinPower = ICE;
    else if (goblinElement == "FIRE") goblinPower = FIRE;
    else if (goblinElement == "EARTH") goblinPower = EARTH;
    else if (goblinElement == "AIR") goblinPower = AIR;
    else throw invalid_argument("Unknown goblin element: " + goblinElement);

    if (canUsePower(goblinPower)) {
        cout << "Your " << currentElement << " power easily defeats the " 
             << goblinElement << " goblin!" << endl;
    } else if (powers == goblinPower) {
        cout << "Using the same power type against the " << goblinElement 
             << " goblin! You take self-damage!" << endl;
        health -= 50; // Self-damage
    } else {
        cout << "Ineffective power! Goblin fights back!" << endl;
        health -= 20; // Goblin damage
    }

    if (health <= 0) {
        cout << "You have died!" << endl;
        throw runtime_error("Game Over");
    }
}
// int main() {
//     try {
//         Powers firePower("FIRE");
//         cout << "Using FIRE power:" << endl;

//         firePower.usePower(ICE, "ICE");

//         int health = 100;
//         firePower.handleAttack("ICE", health);
//         cout << "Remaining health: " << health << endl;
//     } catch (const runtime_error &e) {
//         cout << e.what() << endl;
//     }
//     return 0;
// }


