#include "../addit_header/Powers.h"
#include "../Character_header/Character.h"


using namespace std;
//Water vs Fire, Wind vs Earth 

Power_type::Power_type() {
    p_type = AIR;
    powerDamage = 80;
}

Powers Power_type::getPower () const {
    return p_type;
}
void Power_type::setPower(const int option) {
    if (option == 0) {
        p_type = ICE;
    }
    else if (option == 1) {
        p_type = EARTH;
    }
    else if (option == 2) {
        p_type = FIRE;
    }
    else if (option == 3) {
        p_type = AIR;
    }
}

int Power_type::getDamage() const {
    return powerDamage;
}
void Power_type::setDamage(int damage) {
    powerDamage = damage;
}

void Power_type::usePower(Powers element, const string &enemyAllegiance) {
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

void Power_type::useFusedPower () {
    cout << "Ultimate ability used!" << endl;
    damage(powerDamage);
    cout << "Dealt "<< powerDamage << " damage to Ignus!" << endl;
}

bool Power_type::canUsePower(Powers element, const string& enemyAllegiance) {
    if (element == ICE) {
        if (enemyAllegiance == "ICE") {
            return false;
        }
        else {
            return true;
        }
    }
    else if (element == EARTH) {
        if (enemyAllegiance == "EARTH") {
            return false;
        }
        else {
            return true;
        }
    }
    else if (element == FIRE) {
        if (enemyAllegiance == "FIRE") {
            return false;
        }
        else {
            return true;
        }
    }
    else if (element == AIR) {
        if (enemyAllegiance == "AIR") {
            return false;
        }
        else {
            return true;
        }
    }
    return false;

}