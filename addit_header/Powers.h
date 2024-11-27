#include <string>
#include <iostream>
using namespace std;

#ifndef __Power_type_H__
#define __Power_type_H__

enum Power_type{ICE, EARTH, FIRE, AIR, FUSED_POWER};

class Powers{
protected:
Power_type p_type;
int powerDamage;

public:
Power_type();
Power_type getPower () const;
void setPower(const int);
int getDamage() const;
void setDamage(int);
void usePower(Power_type, const string&);
void handleAttack(const string &goblinElement, int &health) const;
void useFusedPower(); //if battle is against dragon, all Power_type can be used

// private:
bool canUsePower(Power_type, const string&);

};

#endif