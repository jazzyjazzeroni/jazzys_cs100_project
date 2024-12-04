#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "Character.h"
<<<<<<< HEAD
// #include "Dragon.h"
#include "../addit_header/Powers.h"
#include "../addit_header/Inventory.h"
// #include "../addit_header/GameManager.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Level.h"
=======
>>>>>>> master
#include "../addit_header/Swords.h"
#include <string>
#include <utility>
<<<<<<< HEAD
#include <memory> // For shared_ptr
=======

>>>>>>> master

using namespace std; 

class MainCharacter : public Character {
private:
    string allegiance;
    Powers powers;
    Power_type currentElement;
<<<<<<< HEAD
    Inventory inventory;
    // Level levels;
=======

>>>>>>> master
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
<<<<<<< HEAD
     std::shared_ptr<Object> move(char action, GameMap &gameMap);
     pair<int, int> getPosition() const;
     void setPosition(int x, int y);
     void updateElementForLevel(); // Updates element based on current level
    // Power_type getCurrentElement() const;
=======
     pair<int, int> move(char action, int height, int width);
     pair<int, int> getPosition() const;
     void setPosition(int x, int y);
     void updateElementForLevel(); // Updates element based on current level
  
>>>>>>> master
        void print() const override;

     
};

#endif