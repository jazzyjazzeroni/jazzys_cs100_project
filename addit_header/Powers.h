#include <string>
#include <iostream>
using namespace std;
#ifndef __POWERS_H__
#define __POWERS_H__

enum Powers{WATER, EARTH, FIRE, AIR};


class Power_type{
protected:
double health;
double attackAmount;
string name;
Powers p_type;

public:
string getPower () const;
void setPower();
Power_type(Powers, const string &, double, double);

};
#endif