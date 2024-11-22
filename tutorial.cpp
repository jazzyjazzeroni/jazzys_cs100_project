#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Would you like to play the tutorial first?" << endl;
    cout << "       1. Yes              2. No          " << endl;
    cout << endl;

    int choice;
    cin >> choice;

    // if the player chooses anything other than Yes and No
    while ((choice != 1) && (choice != 0)) {
        // get input again until they do
        cin.clear();
        cin >> choice;
    }

    if (choice == 1) {
    
    cout << "          To complete a level:             " << endl;
    cout << "Defeat the specified number of enemies at" << endl;
    cout << "each level. You will randomly encounter   " << endl;
    cout << "these enemies as you traverse each level. " << endl;
    cout << endl;
    cout << "                 To move:                 " << endl;
    cout << "              UP: press 'w'               " << endl;
    cout << "              LEFT: press 'a'             " << endl;
    cout << "              RIGHT: press 'd'            " << endl;
    cout << "              DOWN: press 's'             " << endl;
    cout << endl;

    char step;
    cin >> step;

    // if the player doesn't choose a direction
    while ((step != 'w') && (step != 'a') && (step != 'd') && (step != 's')) {
        // get input again until they do
        cin.clear();
        cin >> step;
    }

    // the tutorial is scripted so regardless of where the player
    // moves they'll always follow this order

    cout << "        YOU FOUND A FRAGILE SWORD!         " << endl;
    cout << "You can use swords to attack during battle " << endl;
    cout << "   But you may only carry one at a time    " << endl;
    cout << endl;
    cout << "          Choose your next step:           " << endl;
    cout << endl;

    cin >> step;

    // if the player doesn't choose a direction
    while ((step != 'w') && (step != 'a') && (step != 'd') && (step != 's')) {
        // get input again until they do
        cin.clear();
        cin >> step;
    }

    cout << "       YOU ENCOUNTERED A GOBLIN!           " << endl;
    cout << ""

    return 0;
}