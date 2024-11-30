#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
// #include "Dragon.h"
#include "../addit_header/Powers.h"
#include "../addit_header/Inventory.h"
// #include "../addit_header/GameManager.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Level.h"
#include "../addit_header/Swords.h"
#include "../addit_header/Potions.h"
#include "../addit_header/Object.h"
#include <string>
#include <utility>
using namespace std; 

class MainCharacter : public Character {
private:
    string allegiance;
    Powers powers;
    Power_type currentElement;
    Inventory inventory;
    // Level levels;
    Sword sword;
    char move;
    int x, y; 

public:
     MainCharacter(const string &name, int health, int attackStrength, const string &allegiance);
         MainCharacter(int x = 0, int y = 0);

     void attack(Character &opponent) override;
     MainCharacter(int x = 0, int y = 0); 
     void heal(int);
     bool isalive();
     void usePowers();
     const Inventory& getInventory() const;
     void usePotion(const string &);
     void equipSword(const Sword &);
     int mod(int value, int limit);
     Object move(char action, GameMap &gameMap);
     pair<int, int> getPosition() const;
     void setPosition(int x, int y);
     void updateElementForLevel(); // Updates element based on current level
    Power_type getCurrentElement() const;
     
};

#endif