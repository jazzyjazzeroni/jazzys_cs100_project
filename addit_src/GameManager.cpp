#include "../addit_header/GameManager.h"
#include "../addit_header/MenuPrinter.h"
#include "../addit_header/Level.h"
#include "../Character_header/Character.h"
#include "../Character_header/MainCharacter.h"
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

// Constructor to initialize levels
GameManager::GameManager() : current_level(0), player("Theodore", 100, 5, "AIR") {
        levels = initializer_levels(initialize_levels); // Initialize levels using provided function
    }
// Start the game
void GameManager::gameStart() {
    std::cout << "Your Journey Begins...\n";
    MenuPrinter::movementMenu(); // Will display keys and keys for attack
     while (current_level < levels.size()) {
            cout << "Starting Level " << current_level + 1 << endl;
            // Start level level[current_lev].start()

      
            } else {
                cout << "You have been defeated! Game over." << endl;
                return;
            }
        }
}

// Progress to the next level
void GameManager::nextLevel() {
    
    if (currLevel + 1 < levels.size()) {
        currLevel++;
        levels[currLevel].setLevel(currLevel + 1);
        cout << "Proceeding to  the next level " << currLevel + 1 << "..." << endl;
    } else {
        cout << "This is the last level." << endl;
    }
}

// Handle user input for global actions outside levels
void GameManager::handleInput() {
    char input;
    cout << "Enter 'q' to quit or 'c' to continue: ";
    cin >> input;

    if (input == 'q') {
        cout << "Thanks for playing!" << endl;
        exit(0);
    }
}

// Update the game state
void GameManager::update() {
    if (currLevel < levels.size()) {
        levels[currLevel].start();
    } else {
        cout << "Game Over!" << endl;
    }
}

// EMMANS CODE
void GameManager::pause()
{
    // since the player chose to pause, output pause menu
    MenuPrinter::pauseMenu();
    char choice{};
    int quit_choice{};
    while (true)
    {

        // get input from player
        cin >> choice;

        // if the user input anything other than 'r' and 'q'
        while ((choice != 'r') && (choice != 'q')) {
            // keep getting input from them
            cin.clear();
            cout << "Please select 'r' to resume or 'q' to quit\n";
            cin >> choice;
        }
        
        // atp user should have input either 'r' or 'q'

        // if player input 'r' (to resume the game)
        if (choice == 'r')
        {
            // resume the game
            cout << "Resuming...\n";
            break;
        }
        
        // if the user input 'q' (to quit the game)
        else if (choice == 'q')
        {
            // output quit reassurance prompt
            MenuPrinter::quitReassuranceMenu();
            
            // get quit choice from user
            cin >> quit_choice;

            // while the user inputs something other than 1 and 2
            while ((quit_choice != 1) && (quit_choice != 2)) {
                // keep getting input from them
                cin.clear();
                cout << "Please select 1 or 2.\n";
                cin >> quit_choice;
            }

            // atp user should have input either 1 or 2
            
            // if user chose '1' (Yes)
            if (quit_choice == 1) { quit(); }

            // if user chose '2' (No)
            else if (quit_choice == 2) { break; }
        }
    }
}
void GameManager::quit()
{
    std::cout << "You ended the journey. See you again!\n"; // updated to an exclamation point....
    exit(0);
}


