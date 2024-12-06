
#include "../addit_header/Inventory.h"

using namespace std;

void Inventory::addPotion(const Potion& potion) {
    potions.push_back(potion);
}

void Inventory::removePotion(const std::string& name) {
    potions.erase(
        remove_if(potions.begin(), potions.end(), [&name](const Potion& potion) {
            return potion.getType() == name;
        }),
        potions.end()
    );
}

bool Inventory::hasPotion(const std::string& name) const {
    return any_of(potions.begin(), potions.end(), [&name](const Potion& potion) {
        return potion.getType() == name;
    });
}

Potion Inventory::getPotion(const std::string& name) const {
    auto it = find_if(potions.begin(), potions.end(), [&name](const Potion& potion) {
        return potion.getType() == name;
    });
    if (it != potions.end()) {
        return *it;
    }
    throw runtime_error("Potion not found");
}

// Print inventory contents
void Inventory::print() const {
    cout << "Potions in inventory:" << endl;
    for (const auto& potion : potions) {
        potion.print();
    }
}

void Inventory::usePotion(MainCharacter& mainCharacter) {
    if (potions.empty()) {
        cout << "No potions in inventory" << endl;
        return;
    }

    cout << "Would you like to use one of your potions?" << endl;
    for (size_t i = 0; i < potions.size(); i++) {
        cout << i + 1 << ". ";
        potions[i].print();
    }
    cout << endl;
    cout << "Press (y) to use a potion or any other key to cancel: ";

    char choose;
    cin >> choose;
    if (choose != 'y') {
        return;
    }

    else{

    int choice;
    cout << endl;
    cout << "Enter number on list to use that potion: ";
    while (!(cin >> choice) || choice < 1 || choice > potions.size()) {
        cout << "Invalid choice. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    mainCharacter.heal(potions[choice - 1].getHealingAmount());
    removePotion(potions[choice - 1].getType());
    }
}