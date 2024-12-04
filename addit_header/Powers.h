#include <string>
#include <iostream>
using namespace std;

#ifndef __Power_type_H__
#define __Power_type_H__

enum Power_type{WATER, EARTH, FIRE, AIR};

class Powers{
protected:
Power_type powers{};
int powerDamage{};
string currentElement{};

public:
Powers(){};
Powers(const std::string& element); 
Power_type getPower () const;
void setPower(const int);
int getDamage() const;
void setDamage(int);
void usePower(Powers, const string&);
void handleAttack(const string &goblinElement, int &health) const;
int calculateDamage() const;
<<<<<<< HEAD
bool canUsePower(Power_type) const;
=======
bool canUsePower(Powers) const;
string getcurrentElement() const {return currentElement;}
>>>>>>> master

};

#endif