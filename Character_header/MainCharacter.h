#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
#include "../addit_header/Powers.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/GameManager.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Level.h"
#include "../addit_header/Swords.h"
#include "../addit_header/Potions.h"
#include "../addit_header/Object.h"
using namespace std; 

class MainCharacter : public Character {
private:
    string allegiance;
    Power_type powers;
    Power_type currentElement;
    Inventory inventory;
    Levels levels;
    Sword sword;
    char move;
    int x, y; 

public:
     MainCharacter(const string &name, int health, int attackStrength, const string &allegiance);

     void attack(Character &opponent) override;
     MainCharacter(int x = 0, int y = 0); 
     void WitchInteraction();
     void heal(int);
     bool isalive();
     void usePowers();
     const Inventory& getInventory() const;
     void usePotion(const string &);
     void equipSword(Sword &);
     int mod(int value, int limit);
     Object move(char action, GameMap &gameMap);
     pair<int, int> getPosition() const;
     void setPosition(int x, int y);
     void updateElementForLevel(); // Updates element based on current level
    Power_type getCurrentElement() const;
     
};

#endif