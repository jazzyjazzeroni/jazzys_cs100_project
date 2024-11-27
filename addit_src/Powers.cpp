#include "../addit_header/Powers.h"
#include "../Character_header/Character.h"


using namespace std;
//Water vs Fire, Wind vs Earth 

Powers::Powers() {
    p_type = AIR; //why air?
    powerDamage = 80; //why 80?
}

Power_type Powers::getPower () const {
    return p_type;
}
void Powers::setPower(const int option) { //why are we giving character option they dont get one
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

int Powers::getDamage() const {
    return powerDamage;
}
void Powers::setDamage(int damage) {
    powerDamage = damage;
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

//confused about this function

void Powers::useFusedPower () {
    cout << "Ultimate ability used!" << endl;
    damage(powerDamage);
    cout << "Dealt "<< powerDamage << " damage to Ignus!" << endl;
}


//why so many if statements?

bool Powers::canUsePower(Power_type element, const string& enemyAllegiance) {
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