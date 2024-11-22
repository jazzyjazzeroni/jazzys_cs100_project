#include <string>
using namespace std;
#ifndef POTIONS_H
#define POTIONS_H

class Potion {
private:
    int healingAmount; 
    string type;  
    string type; // "character" | "sword" | "potion" | "empty"
    int value; // 0 | 5 | 10 | 15

public:
    Potion();
    Potion(int healAmount, const string& potionType);

    int getHealingAmount() const;
    void setHealingAmount(int amount);

    string getType() const;
    void setType(const string& type);

    Potion(const string& type, int value);
    string getType() const;
    void setType(const string& newType);
    int getValue() const;
    void setValue(int newValue);
    void print() const;
};

#endif