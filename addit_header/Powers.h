#include <string>
#include <iostream>
using namespace std;

#ifndef __POWERS_H__
#define __POWERS_H__

enum Powers{ICE, EARTH, FIRE, AIR, FUSED_POWER};

class Power_type{
protected:
Powers p_type;
int powerDamage;

public:
Power_type();
Powers getPower () const;
void setPower(const int);
int getDamage() const;
void setDamage(int);
void usePower(Powers, const string&);
void useFusedPower(); //if battle is against dragon, all powers can be used

private:
bool canUsePower(Powers, const string&);

};

#endif