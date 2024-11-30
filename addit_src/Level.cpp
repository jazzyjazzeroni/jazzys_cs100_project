// #include "../addit_header/Level.h"
// #include "../addit_header/Potions.h"
// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// struct Map {
//     int width;
//     int height;
//     vector<vector<char>> layout; 
// };

// Level::Level() 
//     : gameMap({}, 0, 0), player(0), inventory(), goblinGoal(0), levelNumber(1), end(false), currentLevel(1) {
//     levelElements[1] = WATER;
//     levelElements[2] = FIRE;
//     levelElements[3] = EARTH;
//     levelElements[4] = AIR;
// }


// Level::Level(int power, const vector<vector<int>>& mapLayout, int numGoblins)
//     : gameMap(mapLayout, mapLayout[0].size(), mapLayout.size()), 
//       player(power), 
//       inventory(), 
//       goblinGoal(numGoblins), 
//       levelNumber(1), 
//       end(false) {}
      
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
//         inventory.open(player);
//     } 
//     else if (action == 's') {
//         MenuPrinter::printStatus(player);
//     } 
//     else if (action == 'w' || action == 'a' || action == 's' || action == 'd') {
//         Object encounter = player.move(action, gameMap);
//         if (encounter.getType() == "character") {
//             //todo add check for type character
//             Character *charactor = dynamic_cast<Character*>(& encounter);
//             player.attack(*charactor);
//         } else if (encounter.getType() == "sword") {
//             Sword *sword = dynamic_cast<Sword*>(& encounter);
//             //todo add check for type sword
//             player.equipSword(*sword);
//         } else if (encounter.getType() == "potion") {
//             Potion *potion = dynamic_cast<Potion*>(& encounter);
//             inventory.addPotion(*potion);
//         }
//         if (!player.isalive()) {
//             std::cout << "Game over! The player has died." << std::endl;
//             exit(0); // Terminate the game
//         }
//     }
// };

// void Level::Finalbosslevel(int power) {
//     cout << "You have reached the final boss level!" << endl;
//     cout << "You have to defeat the final boss to win the game." << endl;
//     cout << "The final boss is a dragon with 100 health points." << endl;
//     cout << "You have to defeat the dragon to win the game." << endl;
//     cout << "Good luck!" << endl;
//     cout << endl;

//     Dragon dragon(100);

//     while (player.getHealth() > 0 && dragon.getHealth() > 0) {
//         cout << "Player health: " << player.getHealth() << endl;
//         cout << "Dragon health: " << dragon.getHealth() << endl;
//         cout << endl;

//         char action;
//         cout << "Enter action: ";
//         cin >> action;
//         switch (action) {
//         case 'a':
//             player.attack(dragon);
//             break;
//         case 'd':
//             dragon.attack(player);
//             break;
//         default:
//             cout << "Invalid action" << endl;
//         }
//     }

//     if (player.getHealth() > 0) {
//         cout << "You defeated the dragon! You win!" << endl;
//     }
//     else {
//         cout << "You were defeated by the dragon. Game over." << endl;
//     }
// }

//   vector<Level> initializeLevels() { // todo call this in game manager pass it in
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