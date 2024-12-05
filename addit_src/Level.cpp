#include "../addit_header/Level.h"
using namespace std;

struct Map {
    int width;
    int height;
    vector<vector<char>> layout; 
};

Level::Level() 
    : gameMap({}, 0, 0), player(0), inventory(), goblinGoal(0), levelNumber(1), end(false), currentLevel(1) {
    levelElements[1] = WATER;
    levelElements[2] = FIRE;
    levelElements[3] = EARTH;
    levelElements[4] = AIR;
}


Level::Level(int power, const vector<vector<int>>& mapLayout, int goblinGoal, bool &isOver)
    : gameMap(mapLayout, mapLayout[0].size(), mapLayout.size()), 
      player("Hero", 100, power, "Fire"), 
      inventory(), 
      goblinGoal(goblinGoal), 
      levelNumber(1), 
      end(false), 
      currentLevel(1) {
    levelElements[1] = WATER;
    levelElements[2] = FIRE;
    levelElements[3] = EARTH;
    levelElements[4] = AIR;
    this->isOver = &isOver;
}

      
void Level::start() {
    while (!end && !*isOver) {
      //   gameMap.printMap(player.getX(), player.getY());
        takeAction();
       // end = (gameMap.getGoblinsKilled() >= goblinGoal || !player.isAlive());
    }
}


Power_type Level::getElementForLevel(int level) const {
    auto it = levelElements.find(level);
    if (it != levelElements.end()) {
        return it->second;
    } else {
        throw std::out_of_range("Level not defined in levelElements.");
    }
}

void Level::setLevel(int level) {
    if (level > 0 && level <= static_cast<int>(levelElements.size())) {
        currentLevel = level;
    } else {
        throw std::invalid_argument("Invalid level number.");
    }
}

int Level::getCurrentLevel() const {
    return currentLevel;
}

void Level::takeAction() {
    char action;
    cout << "Enter action: ";
    // // MenuPrinter::printGoblinStatus(
    // //         gameMap.getNumGoblins() - gameMap.getGoblinsKilled(), 
    // //         gameMap.getGoblinsKilled()
    //     );
    cin >> action;
    if (action == 'i') {
        inventory.usePotion(player);
    } 
    else if (action == 'm'){
        MenuPrinter::movementMenu();
    }
    else if(action == 'q'){
        cout << "You have quit the game." << endl;
        *isOver = true;
    }
    else if(action == 'g'){
        MenuPrinter::printGoblinStatus(
            gameMap.getNumGoblins() - gameMap.getGoblinsKilled(), 
            gameMap.getGoblinsKilled()
        );
    }
    else if (action == 't') {
        MenuPrinter::printStatus(player);
    } 
    else if (action == 'w' || action == 'a' || action == 's' || action == 'd') {
        pair<int, int> pos = player.move(action, gameMap.getHeight(), gameMap.getWidth());
        shared_ptr<Object> encounter = gameMap.getObjectAt(pos.first, pos.second);
        if (encounter) {
            string type = encounter->getType();
        if (type == "Goblin") {
                cout << "A goblin appeared!" << endl;
                Goblin* goblin = dynamic_cast<Goblin*>(encounter.get());
                if (goblin) {
                    MenuPrinter::GoblinEncounterMenu(*goblin); // Show goblin info and ask for fight choice
                    char choice;
                    cin >> choice;
                    if (choice == '1') {  // Player chooses to fight
                        bool inCombat = true;
                        while (inCombat) {
                            // Player's turn to attack
                            cout << "It's your turn. Press 'k' to attack!" << endl;
                            cout << "Press 'r' to run away." << endl;
                            char attackChoice;
                            cin >> attackChoice;
                            if (attackChoice == 'k') {
                                player.attack(*goblin);  // Perform attack
                                if (!goblin->isalive()) {
                                    cout << "The goblin has been defeated!" << endl;
                                    gameMap.killGoblin(player.getPosition().first, player.getPosition().second);
                                    inCombat = false;
                                }
                            }
                            else if (attackChoice == 'r') {
                                cout << "You ran away from the goblin." << endl;
                                inCombat = false;
                            }
                            
                            if (!goblin->isalive()) break; // Goblin defeated, exit combat

                            // Goblin's turn to attack
                            if (goblin->isalive()) {
                                goblin->attack(player);
                                if (!player.isalive()) {
                                    cout << "You have been defeated by the goblin!" << endl;
                                    MenuPrinter::deathScreen();
                                    *isOver = true;
                                    inCombat = false;  // End the game if the player dies
                                }
                            }
                            else {
                                cout << "Invalid action. Please try again." << endl;
                            }
                        }
                    } else if (choice == '2') {
                        cout << "You chose not to fight the goblin." << endl;
                    }
                    else {
                        cout << "Invalid action. Please try again." << endl;
                    }
                }
        }
        else if (type == "Potion") {
                Potion* potion = dynamic_cast<Potion*>(encounter.get());
                if (potion) {
                   inventory.addPotion(*potion);
                    cout << "You picked up a potion: " << potion->getType() << endl;
                }
        }
        else if (type == "Sword") {
                Sword* sword = dynamic_cast<Sword*>(encounter.get());
                if (sword) {
                    player.equipSword(*sword);
                }
                else{
                 cout << "Nothing interesting here." << endl;

                }

        if (!player.isalive()) {
            std::cout << "Game over! The player has died." << std::endl;
            exit(0); // Terminate the game
        }
    }
   
        }
    }
 else {
        cout << "Invalid action. Please try again." << endl;
    }
}
