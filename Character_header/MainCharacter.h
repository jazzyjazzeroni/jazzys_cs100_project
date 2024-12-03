#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
#include "../addit_header/Swords.h"
#include <string>
#include <utility>


using namespace std; 

class MainCharacter : public Character {
private:
    string allegiance;
    Powers powers;
    Power_type currentElement;

    Sword sword;
    char move_action;
    int x, y; 


public:
    MainCharacter(const std::string &name, int health, int attackStrength, const std::string &element);
    MainCharacter() = default;

     void attack(Character &opponent) override;
     MainCharacter(int x = 0, int y = 0); 
     void heal(int);
     void usePowers();
     void equipSword(const Sword &);
     int mod(int value, int limit);
     pair<int, int> move(char action, int height, int width);
     pair<int, int> getPosition() const;
     void setPosition(int x, int y);
     void updateElementForLevel(); // Updates element based on current level
  
        void print() const override;

     
};

#endif