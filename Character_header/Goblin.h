#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"

using namespace std; 

class Goblin : public Character{
    private:
        Powers powers;
        string currentElement;
        

public:
    Goblin(const std::string &name, int health, int damage, const std::string &element);
    Goblin(){};
    int getHealth() const;
    string getType() const override ;
    string getGoblinType() const;
    void setHealth(int);
    bool isalive() const;
    void recieveDamage(int);
    void attack(Character &player) override;
    void print() const override;
};

#endif