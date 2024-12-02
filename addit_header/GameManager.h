#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <vector>
#include "Level.h"
#include "MenuPrinter.h"
#include "../addit_header/GameMap.h"
#include "../Character_header/MainCharacter.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/Swords.h"
#include "../addit_header/Potions.h"
#include "../Character_header/Character.h"
#include "../Character_header/Dragon.h"

////////////////////////LEVELS/////////////////////////
// struct Map {
//     int width;
//     int height;
//     vector<vector<char>> layout; 
// };

// // Level::Level() 
// //     : gameMap({}, 0, 0), player(0), inventory(), goblinGoal(0), levelNumber(1), end(false), currentLevel(1) {
// //     levelElements[1] = WATER;
// //     levelElements[2] = FIRE;
// //     levelElements[3] = EARTH;
// //     levelElements[4] = AIR;
// // }


// Level::Level(int power, const vector<vector<int>>& mapLayout, int goblinGoal)
//     : gameMap(mapLayout, mapLayout[0].size(), mapLayout.size()), 
//       player(power), 
//       inventory(), 
//       goblinGoal(goblinGoal), 
//       levelNumber(1), 
//       end(false), 
//       currentLevel(1) {
//     levelElements[1] = WATER;
//     levelElements[2] = FIRE;
//     levelElements[3] = EARTH;
//     levelElements[4] = AIR;
// }

      
// void Level::start() {
//     while (!end) {
//       //   gameMap.printMap(player.getX(), player.getY());
//         takeAction();
//        // end = (gameMap.getGoblinsKilled() >= goblinGoal || !player.isAlive());
//     }
// }


// Power_type Level::getElementForLevel(int level) const {
//     auto it = levelElements.find(level);
//     if (it != levelElements.end()) {
//         return it->second;
//     } else {
//         throw std::out_of_range("Level not defined in levelElements.");
//     }
// }

// void Level::setLevel(int level) {
//     if (level > 0 && level <= static_cast<int>(levelElements.size())) {
//         currentLevel = level;
//     } else {
//         throw std::invalid_argument("Invalid level number.");
//     }
// }

// int Level::getCurrentLevel() const {
//     return currentLevel;
// }

// void Level::takeAction() {
//     char action;
//     cout << "Enter action: ";
//     MenuPrinter::printGoblinStatus(
//             gameMap.getNumGoblins() - gameMap.getGoblinsKilled(), 
//             gameMap.getGoblinsKilled()
//         );
//     cin >> action;
//     if (action == 'i') {
//         // inventory.open(player);
//                 player.openInventory();
//     } 
//     else if (action == 's') {
//         MenuPrinter::printStatus(player);
//     } 
//     else if (action == 'w' || action == 'a' || action == 's' || action == 'd') {
//         shared_ptr<Object> encounter = player.move(action, gameMap);

//         // if (encounter.getType() == "character") {
//         //     //todo add check for type character
//         //     Character *charactor = dynamic_cast<Character*>(& encounter);
//         //     player.attack(*charactor);
//         // } 
//         if (encounter) {
//             string type = encounter->getType();
//         if (type == "Goblin") {
//                 cout << "A goblin appeared!" << endl;
//                 Goblin* goblin = dynamic_cast<Goblin*>(encounter.get());
//                 if (goblin) {
//                     player.attack(*goblin);
//                     if (!goblin->isalive()) {
//                         gameMap.killGoblin(player.getPosition().first, player.getPosition().second);
//                         cout << "Goblin defeated!" << endl;
//                     }
//                 }
//         }
//         // else if (encounter.getType() == "sword") {
//         //     Sword *sword = dynamic_cast<Sword*>(& encounter);
//         //     //todo add check for type sword
//         //     player.equipSword(*sword);
//         // } 
//         else if (type == "Potion") {
//                 Potion* potion = dynamic_cast<Potion*>(encounter.get());
//                 if (potion) {
//                     player.getInventory().addPotion(*potion);
//                     cout << "You picked up a potion: " << potion->getName() << endl;
//                 }
//         }
//         // else if (encounter.getType() == "potion") {
//         //     Potion *potion = dynamic_cast<Potion*>(& encounter);
//         //     inventory.addPotion(*potion);
//         // }
//         else if (type == "Sword") {
//                 Sword* sword = dynamic_cast<Sword*>(encounter.get());
//                 if (sword) {
//                     player.equipSword(*sword);
//                     cout << "You equipped a sword: " << sword->getName() << endl;
//                 }
//                 else{
//                  cout << "Nothing interesting here." << endl;

//                 }

//         if (!player.isalive()) {
//             std::cout << "Game over! The player has died." << std::endl;
//             exit(0); // Terminate the game
//         }
//     }
//     else {
//         cout << "Invalid action. Please try again." << endl;
//     }
// }

// // void Level::Finalbosslevel(int power) {
// //     cout << "You have reached the final boss level!" << endl;
// //     cout << "You have to defeat the final boss to win the game." << endl;
// //     cout << "The final boss is a dragon with 100 health points." << endl;
// //     cout << "You have to defeat the dragon to win the game." << endl;
// //     cout << "Good luck!" << endl;
// //     cout << endl;

// //     Dragon dragon(100);

// //     while (player.getHealth() > 0 && dragon.getHealth() > 0) {
// //         cout << "Player health: " << player.getHealth() << endl;
// //         cout << "Dragon health: " << dragon.getHealth() << endl;
// //         cout << endl;

// //         char action;
// //         cout << "Enter action: ";
// //         cin >> action;
// //         switch (action) {
// //         case 'a':
// //             player.attack(dragon);
// //             break;
// //         case 'd':
// //             dragon.attack(player);
// //             break;
// //         default:
// //             cout << "Invalid action" << endl;
// //         }
// //     }

// //     if (player.getHealth() > 0) {
// //         cout << "You defeated the dragon! You win!" << endl;
// //     }
// //     else {
// //         cout << "You were defeated by the dragon. Game over." << endl;
// //     }
// // }

//   vector<Level> Level::initialize_level() { // todo call this in game manager pass it in
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
//     levels = level.initialize_level(); // Load all levels
//     currentLevel = 0; // Start with the first level
//     levels[currentLevel].start(); // Begin the game
// }
//////////////////////////////////////////////////////////////////////

////////////////////////GAME MAP///////////////////////////////////////
// #include <vector>
// #include "../addit_header/GameMap.h"
// #include <memory> // For shared_ptr

// using namespace std;

// GameMap::GameMap() : height(0), width(0), numGoblin(0), goblinKilled(0) {
//     mapMatrix.resize(0, vector<shared_ptr<Object>>(0));
// }

// GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h) : height(h), width(w), numGoblin(0), goblinKilled(0) {
//     mapMatrix.resize(h, vector<shared_ptr<Object>>(w));

//     for (int y = 0; y < height; y++) {
//         for (int x = 0; x < width; x++) {
//             switch (initMatrix[y][x]) {
//             case 1:
//                 mapMatrix[y][x] = make_shared<Goblin>("Goblin", 100, 15, "Fire");
//                 numGoblin++;
//                 break;
//             case 2:
//                 mapMatrix[y][x] = make_shared<Goblin>("Goblin", 75, 10, "Water");
//                 numGoblin++;
//                 break;
//             case 4:
//                 mapMatrix[y][x] = make_shared<Goblin>("Goblin", 70, 7, "Air");
//                 numGoblin++;
//                 break;
//             case 5:
//                 mapMatrix[y][x] = make_shared<Goblin>("Goblin", 65, 5, "Earth");
//                 numGoblin++;
//                 break;
//             case 6:
//                 mapMatrix[y][x] = make_shared<Sword>(10, "Basic Sword");
//                 break;
//             case 7:
//                 mapMatrix[y][x] = make_shared<Sword>(15, "Greater Sword");
//                 break;
//             case 8:
//                 mapMatrix[y][x] = make_shared<Potion>(5, "Small Potion");
//                 break;
//             case 9:
//                 mapMatrix[y][x] = make_shared<Potion>(10, "Large Potion");
//                 break;
//             default:
//                 mapMatrix[y][x] = make_shared<Object>();  // Empty object
//                 break;
//             }
//         }
//     }
// }

// void GameMap::killGoblin(int x, int y) {
//     if (x < 0 || x >= width || y < 0 || y >= height) {
//         throw out_of_range("Invalid map coordinates");
//     }

//     shared_ptr<Object>& obj = mapMatrix[y][x];
//     if (obj->getType() == "Goblin") {
//         obj = make_shared<Object>();  // Replace with an empty object
//         goblinKilled++;
//     } else {
//         cerr << "No goblin at the specified coordinates" << endl;
//     }
// }

// shared_ptr<Object> GameMap::getObjectAt(int x, int y) {
//     if (x < 0 || x >= width || y < 0 || y >= height) {
//         throw out_of_range("Invalid map coordinates");
//     }
//     return mapMatrix[y][x];
// }

// void GameMap::setObjectAt(int x, int y, const shared_ptr<Object>& obj) {
//     if (x < 0 || x >= width || y < 0 || y >= height) {
//         throw out_of_range("Invalid map coordinates");
//     }
//     mapMatrix[y][x] = obj;
// }

// int GameMap::getNumGoblins() const {
//     return numGoblin;
// }

// int GameMap::getGoblinsKilled() const {
//     int count = 0;
//     for (const auto& row : mapMatrix) {
//         for (const auto& obj : row) {
//             if (obj->getType() == "Goblin") {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int GameMap::getWidth() const {
//     return width;
// }

// int GameMap::getHeight() const {
//     return height;
// }
///////////////////////////////////////////////////////////////////////////

class GameManager: public MenuPrinter {
private:
    int currLevel;
    vector<Level> levels;
    int current_level;
public:
    GameManager() 
    : levels(initialize_level()), current_level(0) {}
    ~GameManager();

    //Initializes the starting room, player, and levels
    void gameStart();

    // Gets user input (hit w, hit a, hit s, hit d, "take sword", "take potion", "fight goblin")
    // This function parses the input and determines the approporiate action
    void nextLevel();


    void update();
    //updates inventory
    // will trigger the event with goblin
    // 

    // will start the level against the final boss
    void finalBoss();
    void pause();
    void quit();
};

#endif