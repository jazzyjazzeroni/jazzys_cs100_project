#include <string>
#include <iostream>
using namespace std;
#ifndef __POWERS_H__
#define __POWERS_H__

enum Powers{WATER, EARTH, FIRE, AIR};

class Power_type{
protected:
Powers p_type;

public:
Powers getPower () const;
void setPower();
void usePower(Powers);
bool canUsePower(Powers);

};
#endif