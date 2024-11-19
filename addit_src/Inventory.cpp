#include "Inventory.h"

string Inventory::getMushroom() const
{
    return mushroom;
}

void Inventory::setMushroom(string pMushroom)
{
    mushroom = pMushroom;
}

vector<std::string> Inventory::getSword() const
{
    return swords;
}

void Inventory::setSword(vector<string> pSwords)
{
    swords = pSwords; 
}

vector<std::string> Inventory::getPotion() const
{
    return potions;
}

void Inventory::setPotion(vector<string> pPotions) 
{
    potions = pPotions;
}

void Inventory::removePotion() {
    if (!potions.empty()) {
        potions.pop_back();
    } else {
        std::cout << "There are no potions in your inventory to remove. You will find some along the way...\n";
    }
}

void Inventory::removeSword() {
    if (!swords.empty()) {
        swords.pop_back();
    } else {
        std::cout << "You are not holding a sword.\n";
    }
}

double Inventory::getswordDam() const {
    return sword_dam;
}

void Inventory::setswordDam(double pSwordDamage) {
    sword_dam = pSwordDamage;
}

double Inventory::getHealAmount() const {
    return heal_num;
}

void Inventory::setHealAmount(double pHealNum) {
    heal_num = pHealNum;
}

void Inventory::displayInventory() {
    std::cout << "Mushroom: " << mushroom << '\n';
    std::cout << "Swords: ";
    for (const string& sword : swords) {
        std::cout << sword << " ";
    }
    std::cout << '\n';

    std::cout << "Potions: ";
    for (const string& potion : potions) {
        std::cout << potion << " ";
    }
    std::cout << '\n';

    std::cout << "Sword Damage: " << sword_dam << '\n';
    std::cout << "Heal Amount: " << heal_num << '\n';
}