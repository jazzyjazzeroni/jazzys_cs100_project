#include <string>
#ifndef SWORD_H
#define SWORD_H

using namespace std;

class Sword {
private:
    int power;
    string name;

public:
    Sword();
    Sword(int pwr, const string& nm);

    int getPower() const;
    string getName() const;
    void setPower(int pwr);
    void setName(const string& nm);
};

#endif