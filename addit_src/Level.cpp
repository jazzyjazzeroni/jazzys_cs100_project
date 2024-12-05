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
    cout << "debug: start" << endl;
        while (!end && !*isOver) {
        pair<int, int> playerPos = player.getPosition();
        gameMap.printMap(playerPos.first, playerPos.second); // Print the map
        takeAction();
;
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
    cout << "debug: takeAction" << endl;
    char action;
    cout << "Enter action: ";
    // // MenuPrinter::printGoblinStatus(
    // //         gameMap.getNumGoblins() - gameMap.getGoblinsKilled(), 
    // //         gameMap.getGoblinsKilled()
    //     );
    cin >> action;
    cout << "debug: action is " << action << endl;

    if (action == 'i') {
        inventory.usePotion(player);
               
                // player.openInventory();
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
        cout << "debug: move" << endl;
        pair<int, int> pos = player.move(action, gameMap.getHeight(), gameMap.getWidth());
        shared_ptr<Object> encounter = gameMap.getObjectAt(pos.first, pos.second);
        // if (encounter.getType() == "character") {
        //     //todo add check for type character
        //     Character *charactor = dynamic_cast<Character*>(& encounter);
        //     player.attack(*charactor);
        // } 
        if (encounter) {
            string type = encounter->getType();
        if (type == "Goblin") {
                cout << "A goblin appeared!" << endl;
                Goblin* goblin = dynamic_cast<Goblin*>(encounter.get());
                if (goblin) {
                    player.attack(*goblin);
                    if (!goblin->isalive()) {
                        gameMap.killGoblin(player.getPosition().first, player.getPosition().second);
                        cout << "Goblin defeated!" << endl;
                    }
                }
        }
        // else if (encounter.getType() == "sword") {
        //     Sword *sword = dynamic_cast<Sword*>(& encounter);
        //     //todo add check for type sword
        //     player.equipSword(*sword);
        // } 
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
                    cout << "You equipped a sword: " << sword->getName() << endl;
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




//   vector<Level> Level::initializeLevels() { // todo call this in game manager pass it in
//     vector<Level> levels;

//     // Level 1: Small map
//     vector<vector<int>> level1Map = {
//         {0, 1, 0, 5, 0},  
//         {0, 0, 2, 0, 6},  
//         {4, 0, 0, 1, 0},  
//         {0, 5, 0, 4, 0}, 
//         {2, 0, 4, 0, 0} 
//     };
//     levels.push_back(Level(1, level1Map, 2)); //goal: 2 goblins

//     // Level 2: Medium map
//     vector<vector<int>> level2Map = {
//         {0, 1, 0, 5, 4},  
//         {1, 0, 2, 0, 6},  
//         {4, 0, 0, 0, 2},  
//         {0, 5, 0, 4, 0},  
//         {0, 4, 0, 0, 0},
//         {1, 0, 2, 4, 6},  
//         {4, 0, 4, 0, 2}
//     };
//     levels.push_back(Level(2, level2Map, 3)); // goal: 3 goblins

//     // Level 3: Even larger map for the final boss
//     vector<vector<int>> level3Map = {
//         {0, 1, 0, 5, 4, 0},  
//         {1, 0, 2, 0, 6, 0},  
//         {4, 0, 0, 0, 2, 3},  
//         {0, 5, 3, 4, 0, 0},  
//         {0, 4, 0, 0, 0, 5},
//         {6, 4, 0, 4, 0, 4},
//         {1, 0, 2, 4, 6, 1},  
//         {4, 0, 4, 0, 2, 2}
//     };
// levels.push_back(Level(3, level3Map, 4)); 

//     vector<vector<int>> level4Map = {
//         {0, 1, 0, 5, 4, 0},  
//         {1, 0, 2, 0, 6, 4},  
//         {4, 0, 0, 0, 2, 3},  
//         {0, 5, 3, 4, 0, 0},  
//         {0, 4, 0, 0, 0, 5},
//         {6, 4, 0, 4, 0, 4},
//         {6, 4, 0, 4, 0, 4},
//         {1, 0, 2, 4, 6, 1},  
//         {4, 0, 4, 0, 2, 2},
//         {1, 0, 2, 0, 6, 0},  
//         {4, 0, 0, 0, 2, 3}

//     };
//     levels.push_back(Level(4, level4Map, 5)); 


//     return levels;
// }

// void GameManager::initializeGame() {
//     levels = level.initializeLevels(); // Load all levels
//     currentLevel = 0; // Start with the first level
//     levels[currentLevel].start(); // Begin the game
// }