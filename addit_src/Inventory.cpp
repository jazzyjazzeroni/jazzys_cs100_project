#include "Inventory.h"

// class Item {
// public:
//     string name;
//     int value;

//     Item(string name, int value) : name(name), value(value) {}
// };

// class Inventory {
// private:
//     vector<Item> swords;
//     vector<Item> potions;

// public:
//     void addSword(const string &name, int damage);
//     void addPotion(const string &name, int healAmount);

//     void removeSword(const string &name);
//     void removePotion(const string &name);

//     Item* getSword(const string &name);
//     Item* getPotion(const string &name);
void Inventory::addSword(const string &name, int damage)
{
    swords.emplace_back(name, damage);
}

void Inventory::addPotion(const string &name, int healAmount)
{
    swords.emplace_back(name, healAmount);
}

void Inventory::removeSword(const string &name) {
    for (auto i = swords.begin(); i != swords.end(); i++) {
        if (i->name == name) {
            swords.erase(i);
            return;
        }
        else 
            std::cout << "No sword equipped. Continue your journey to find one!\n";
    }
}

void Inventory::removePotion(const string &name) {
    for (auto i = swords.begin(); i != swords.end(); i++) {
        if (i->name == name) {
            swords.erase(i);
            return;
        }
        else 
            std::cout << "No potion is in your inventory. Continue your journey to find one!\n";
    }
}


// I do need someone to take a look at the two Item* implemented
Item* Inventory::getSword(const string &name)
{

    for(auto &sword : swords)
    {
        if(sword.name == name) return &sword;
    }
    std::cout << "No sword found in your inventory.\n";
}

Item* Inventory::getPotion(const string &name)
{
    for(auto &potion : potions)
    {
        if(potion.name == name) return &potion;
    }
    std::cout << "No potion found in your inventory.\n";
}