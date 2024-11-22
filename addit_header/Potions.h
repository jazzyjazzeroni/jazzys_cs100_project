#include <string>
using namespace std;
#ifndef POTIONS_H
#define POTIONS_H

class Potion {
private:
    int healingAmount; 
    string type;  

public:
    Potion();
    Potion(int healAmount, const string& potionType);

    int getHealingAmount() const;
    void setHealingAmount(int amount);

    string getType() const;
    void setType(const string& type);
};

#endif