#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
// #include "Dragon.h"
#include "../addit_header/Powers.h"
// #include "../addit_header/GameManager.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Level.h"
#include "../addit_header/Swords.h"
#include "../addit_header/Potions.h"
#include "../addit_header/Object.h"
#include "../addit_header/Inventory.h"
#include <string>
#include <utility>
#include <memory> // For shared_ptr

using namespace std; 

class MainCharacter : public Character {
private:
    string allegiance;
    Powers powers;
    Power_type currentElement;
    // Level levels;
    shared_ptr<Inventory> inventory;
    Sword sword;
    char move_action;
    int x, y; 


public:
    MainCharacter(const std::string &name, int health, int attackStrength, const std::string &element);
    MainCharacter() = default;

     void attack(Character &opponent) override;
     MainCharacter(int x = 0, int y = 0); 
     void heal(int);
     bool isalive();
     void usePowers();
     const Inventory& getInventory() const;
     void usePotion(const string &);
     void equipSword(const Sword &);
     int mod(int value, int limit);
     std::shared_ptr<Object> move(char action, GameMap &gameMap);
     pair<int, int> getPosition() const;
     void setPosition(int x, int y);
     void updateElementForLevel(); // Updates element based on current level
    // Power_type getCurrentElement() const;
        void print() const override;

     
};

#endif