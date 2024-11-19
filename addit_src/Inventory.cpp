#include "Inventory.h"

string Inventory::getMushroom() const
{
    return mushroom;
}

void Inventory::setMushroom(string mushroom)
{
    this->mushroom = mushroom;
}

vector<std::string> Inventory::getSword() const
{
    return swords;
}

void Inventory::setSword(vector<string> swords)
{
    this->swords = swords; 
}

vector<std::string> Inventory::getPotion() const
{
    return potions;
}

void Inventory::setPotion(vector<string> potions) 
{
    this->potions = potions;
}

void Inventory::removePotion()
{
    //PSEUDOCODE
    /*
    * if potion is not empty
        potion--
      else
        display "You don't have potion in the first place...Find some on your journey"  
    */
}

void Inventory::removeSword()
{
     //PSEUDOCODE
    /*
    * if sword is not empty
        sword--
      else
        display "Seems to be you do not have a sword. You need one along the way..."  
    */
}

double Inventory::getswordDam() const
{
    //PSEUDOCODE
    /*
        After every 
    */
}

// double getswordDam() const;
// void setswordDam(double);
// double getHealAmount() const;
// void setHealAmount(double);
// void displayInventory();