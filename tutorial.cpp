#include <iostream>
#include <fstream>

using namespace std;

int tutorial() {
    cout << "Would you like to play the tutorial first?" << endl;
    cout << "       1. Yes              2. No          " << endl;
    cout << endl;

    int choice;
    cin >> choice;

    // if the player chooses anything other than Yes and No
    while ((choice != 1) && (choice != 0)) {
        // get input again until they do
        cout << "Would you like to play the tutorial first?" << endl;
        cout << "       1. Yes              2. No          " << endl;
        cout << endl;
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
        cout << "Please choose a direction:" << endl;
        cout << "UP: press 'w'             " << endl;
        cout << "LEFT: press 'a'           " << endl;
        cout << "RIGHT: press 'd'          " << endl;
        cout << "DOWN: press 's'           " << endl;
        cout << endl;
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
    cout << "              UP: press 'w'                " << endl;
    cout << "              LEFT: press 'a'              " << endl;
    cout << "              RIGHT: press 'd'             " << endl;
    cout << "              DOWN: press 's'              " << endl;
    cout << endl;

    cin >> step;

    // if the player doesn't choose a direction
    while ((step != 'w') && (step != 'a') && (step != 'd') && (step != 's')) {
        // get input again until they do
        cout << "Please choose a direction:" << endl;
        cout << "UP: press 'w'             " << endl;
        cout << "LEFT: press 'a'           " << endl;
        cout << "RIGHT: press 'd'          " << endl;
        cout << "DOWN: press 's'           " << endl;
        cout << endl;
        cin.clear();
        cin >> step;
    }

    cout << "       YOU ENCOUNTERED A GOBLIN!           " << endl;
    cout << "            STARTING BATTLE                " << endl;
    cout << endl;

    cout << "               YOUR TURN                  " << endl;
    cout << endl;
    cout << "           Your Health: 100               " << endl;
    cout << endl;
    cout << "          Choose your action:             " << endl;
    cout << "            k: Sword Attack               " << endl;
    cout << endl;
    cout << "          Goblin's Health: 50             " << endl;
    cout << endl;

    char action;
    cin >> action;
    // if the player doesn't choose to sword attack
    while (action != 'k') {
        // get input again until they do
        cout << "Please press 'k' to Sword Attack." << endl;
        cout << endl;
        cin.clear();
        cin >> action;
    }

    cout << "       YOUR ATTACK DID 15 DAMAGE!         " << endl;
    cout << endl;
    cout << "           GOBLIN ATTACKED!               " << endl;
    cout << "       THEIR ATTACK DID 5 DAMAGE!         " << endl;
    cout << endl;

    cout << "               YOUR TURN                  " << endl;
    cout << endl;
    cout << "            Your Health: 95               " << endl;
    cout << endl;
    cout << "          Goblin's Health: 35             " << endl;
    cout << endl;
    cout << "  Your sword broke from that last attack, " << endl;
    cout << "           but that's okay!!!             " << endl;
    cout << "  In every level, you will be given an    " << endl;
    cout << "elemental power that you can use against  " << endl;
    cout << "goblins with their own elemental powers.  " << endl;
    cout << "For now, you can use the Wind element to  " << endl;
    cout << "attack. Press 'p' to use the Power Attack." << endl;
    cout << endl;

    cin >> action;
    // if the player doesn't choose to power attack
    while (action != 'p') {
        // get input again until they do
        cout << "Please press 'p' to Power Attack." << endl;
        cout << endl;
        cin.clear();
        cin >> action;
    }   

    cout << "       YOUR ATTACK DID 35 DAMAGE!         " << endl;
    cout << endl;
    cout << "        GOBLIN HAS BEEN DEFEATED          " << endl;
    cout << endl;

    cout << "         Choose your next step:           " << endl;
    cout << "             UP: press 'w'                " << endl;
    cout << "             LEFT: press 'a'              " << endl;
    cout << "             RIGHT: press 'd'             " << endl;
    cout << "             DOWN: press 's'              " << endl;
    cout << endl;

    cin >> step;

    // if the player doesn't choose a direction
    while ((step != 'w') && (step != 'a') && (step != 'd') && (step != 's')) {
        // get input again until they do
        cout << "Please choose a direction:" << endl;
        cout << "UP: press 'w'             " << endl;
        cout << "LEFT: press 'a'           " << endl;
        cout << "RIGHT: press 'd'          " << endl;
        cout << "DOWN: press 's'           " << endl;
        cout << endl;
        cin.clear();
        cin >> step;
    }

    cout << "        YOU FOUND A SMALL POTION!         " << endl;
    cout << endl;
    cout << "You took some damage in that last battle. " << endl;
    cout << "   Open your inventory by pressing 'i'.   " << endl;
    cout << endl;
    
    cin >> action;
    // if the player doesn't choose to open inventory
    while (action != 'i') {
        // get input again until they do
        cout << "Please press 'i' to open inventory." << endl;
        cout << endl;
        cin.clear();
        cin >> action;
    }

    cout << "                INVENTORY                 " << endl;
    cout << "                No Sword                  " << endl;
    cout << "           1. Small Potions x1            " << endl;
    cout << "           2. Medium Potions x0           " << endl;
    cout << "           3. Large Potions x0            " << endl;

    cout << "      Press 1 to use a Small Potion.      " << endl;
    cout << endl;

    int choice2;
    cin >> choice2;

    // if the player doesn't choose to use a small potion
    while (choice2 != 1) {
        // get input again until they do
        cout << "Please press 1 to use a Small Potion. " << endl;
        cout << endl;
        cin.clear();
        cin >> choice2;
    }

    cout << "     You are now back to full health!     " << endl;
    cout << endl;
    cout << "            TUTORIAL COMPLETE             " << endl;
    cout << "          MOVING ON TO LEVEL 1            " << endl;
    cout << endl;
    
    }

    // if the player didn't want to play the tutorial
    // simply return

    return 0;
}