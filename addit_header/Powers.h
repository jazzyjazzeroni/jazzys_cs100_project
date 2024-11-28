#include <string>
#include <iostream>
using namespace std;

#ifndef __Power_type_H__
#define __Power_type_H__

enum Power_type{ICE, EARTH, FIRE, AIR, FUSED_POWER};

class Powers{
protected:
Power_type powers;
int powerDamage;
string currentElement;

public:
Powers(){};
Powers(const std::string& element); 
Power_type getPower () const;
void setPower(const int);
int getDamage() const;
void setDamage(int);
void usePower(Power_type, const string&);
void handleAttack(const string &goblinElement, int &health) const;
int calculateDamage() const;
bool canUsePower(Power_type) const;

};

#endif