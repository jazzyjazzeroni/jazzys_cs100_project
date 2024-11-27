#include "../addit_header/Powers.h"
#include "../Character_header/Character.h"


using namespace std;
//Water vs Fire, Wind vs Earth 

Powers::Powers(const string &element) : currentElement(element) {}

Power_type Powers::getPower () const {
    return p_type;
}
void Powers::setPower(const int powerTypeIndex) { 
        p_type = static_cast<Power_type>(powerTypeIndex);
//tbh not sure if static cast or dynamic
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

int Powers::calculateDamage() const {
    switch (p_type) {
        case ICE: return 15;         // ICE does 15 damage
        case FIRE: return 20;        // FIRE does 20 damage
        case EARTH: return 10;       // EARTH does 10 damage
        case AIR: return 12;         // AIR does 12 damage
        case FUSED_POWER: return 50; // FUSED_POWER does 50 damage
        default: return 0;           // Default is no damage
    }
}

//where is damage defined?

void Powers::usePower(Power_type element, const string &enemyAllegiance) {
    if (canUsePower(element, enemyAllegiance)) {
        cout << "Elemental Power used!" << endl;
        damage(powerDamage);
        cout << "Dealt " << powerDamage << " damage!" << endl;
    }
    else {
        cout << "This Elemental Power cannot be used against " << enemyAllegiance << " enemy type!" << endl;
        damage(powerDamage);
        cout << "Dealt no damage!" << endl;
    }
}



void Powers::handleAttack(const string &goblinElement, int &health) const {
        int currentDamage = calculateDamage();
    if (canUsePower(p_type, goblinElement)) {
        cout << "Your " << p_type << " power easily defeats the " << goblinElement << " goblin!" << endl;
    } else if (p_type == static_cast<Power_type>(goblinElement)) {
        cout << "You tried attacking a " << goblinElement << " goblin with the same power type! You take massive damage!" << endl;
        health -= 50; // Massive damage for same power type
        if (health <= 0) {
            cout << "You have died due to your poor elemental choice!" << endl;
            throw runtime_error("Game Over");
        }
    } else {
        cout << "Your " << p_type << " power is not effective against the " << goblinElement << " goblin. The goblin fights back!" << endl;
        health -= 20; // Moderate damage for ineffective attacks
        if (health <= 0) {
            cout << "You have died in the battle with the goblin!" << endl;
            throw runtime_error("Game Over");
        }
    }
}


//confused about this function

void Powers::useFusedPower () {
    cout << "Ultimate ability used!" << endl;
    int currentDamage = calculateDamage();
    cout << "Dealt "<< powerDamage << " damage to Ignus!" << endl;
}



bool Powers::canUsePower(Power_type opponentPower, const string& opponentType) {
    if ((p_type == ICE && opponentPower == FIRE) || 
        (p_type == FIRE && opponentPower == ICE) ||
        (p_type == EARTH && opponentPower == AIR) || 
        (p_type == AIR && opponentPower == EARTH)) {
        return true; // Elemental advantage
    }
    
    if (p_type == opponentPower) {
        cout << "Warning: Using the same element against a " << opponentType 
             << " will result in high damage to yourself!" << endl;
        return false;
    }
    
    // If no match, assume ineffective
    return false;

}