#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"
#include "../addit_header/Powers.h"
using namespace std; 

class Goblin : public Character {
    private:
        Powers powers;
        Power_type currentElement;


public:
    Goblin(const std::string &name, int health, int damage, const std::string &element);
    Goblin(){};
    int getHealth() const;
    string getType();
    void setHealth(int);
    bool isalive() const;
    void recieveDamage(int);
    void attack(Character &player) override;
    void usePowers();
};

#endif