#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// for displaying tiles and to map out
const int MAP_SIZE = 6;

// Tiles with its coordinated objects
enum Object { GOBLIN, SMALL_POTION, BIG_POTION, SWORD, EMPTY };

// MainCharacter struct
struct MainCharacter {
    int x, y;
    int health;
    int attack_power;
    bool has_sword;
};

// Make game map with random tiles
std::vector<std::vector<Object>> generateMap() {

    // From Naira's code
    std::vector<std::vector<Object>> map(MAP_SIZE, std::vector<Object>(MAP_SIZE, EMPTY));

    // Seed the random number generator with the current time
    // tbh if anyone asks i just stack overflow it
    std::srand(std::time(0));

    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            int randomValue = rand() % 15;
            if (randomValue == 3) map[i][j] = BIG_POTION;
            else if (randomValue < 7) map[i][j] = SMALL_POTION;
            else if (randomValue < 12) map[i][j] = GOBLIN;
            else if (randomValue == 14) map[i][j] = SWORD;
        }
    }

    return map;
}

// Function to display the map (hidden for unvisited tiles)
void displayMap(const std::vector<std::vector<Object>>& map, const MainCharacter& mc) {
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            if (i == mc.x && j == mc.y) 
                std::cout << "(^u^)";
            else 
                std::cout << "*  ";
        }
        std::cout << '\n';
    }
}

// Attack goblin
void attack(MainCharacter& mc) {
    std::cout << "An <insert element here> goblin appears! FIGHT!\n";
    int goblin_health{ 10 };

    // While goblin's health is greater than dead and mainchar health greater than dead
    while (goblin_health > 0 && mc.health > 0) {
        int main_character_damage{};
        int goblin_damage{ rand() % 4 + 2 };

        if (mc.has_sword)
            main_character_damage = rand() % 6 + 5;
        else
            main_character_damage = rand() % 4 + 2;

        goblin_health -= main_character_damage;
        mc.health -= goblin_damage;

        std::cout << "Goblin has been attacked for " << main_character_damage << " damage!\n";

        // If goblin is still alive
        if (goblin_health > 0) 
            std::cout << "The goblin hits you for " << goblin_damage << " damage!\n";
        
    }

    std::cout << (mc.health <= 0 ? "You died sadly!\n" : "You have slain the goblin!\n");
  
}

// movePlayer: Handles player movement
void movePlayer(MainCharacter& mc, std::vector<std::vector<Object>>& map) {
    char move;
    std::cout << "Enter move (W/A/S/D): ";
    std::cin >> move;

    int x_position = mc.x;
    int y_position = mc.y;

    switch (toupper(move)) {
        case 'W': x_position--; break;
        case 'A': y_position--; break;
        case 'S': x_position++; break;
        case 'D': y_position++; break;
        default: std::cout << "STOP RIGHT THERE! Please only select W, A, S, D to navigate the realm\n"; 
        return;
    }

    if (x_position >= 0 && x_position < MAP_SIZE && y_position >= 0 && y_position < MAP_SIZE) {
        mc.x = x_position;
        mc.y = y_position;

        Object object = map[x_position][y_position];
        map[x_position][y_position] = EMPTY;

        switch (object) {
        case GOBLIN:
            attack(mc);
            // count_kills++;
            // if (count_kills = target_amount_of_kills)
            //      proceed to next level
            // else
            //      ask if you want to quit or play again        
            break;
        case SMALL_POTION:
            mc.health += 5;
            std::cout << "You found a small potion! This gives 5 healing points. \n";
            // USE AN INVENTORY FUNCTION FOR THIS
                // Would you like to use it now? y/n
                // if (yes)
                    // jump out of condition
                //  else if (no)
                    // store in inventory
                // else
                    // INVALID CASE

            std::cout << "Your health is now " << mc.health << "hp.\n";
            break;
        case BIG_POTION:
            mc.health += 10;
            std::cout << "You found a big potion! This gives 10 healing points. \n";
            // USE AN INVENTORY FUNCTION FOR THIS
                // Would you like to use it now? y/n
                // if (yes)
                    // jump out of condition
                //  else if (no)
                    // store in inventory
                // else
                    // INVALID CASE
            std::cout << "Your health is now " << mc.health << "hp.\n";
            break;
        case SWORD:
            mc.has_sword = true;
            std::cout << "You found the Master Sword! Your attacks are 2x stronger now." << '\n';
            break;
        case EMPTY:
            std::cout << "Nothing here." << '\n';
            break;
        }
    }
    else {
        std::cout << "HALT! This is the end of the area!\n";
    }
}

// Main function
int main() {
    MainCharacter mc = { 0, 0, 20, 5, false };

    // Vector that will generate the map
    std::vector<std::vector<Object>> map = generateMap();

    std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\WELCOME TO FLAMES OF ICE\\\\\\\\\\\\\\\\\\\\\\\\\\'\n'";

    while (mc.health > 0) {
        std::cout << "\Theodore's Health: " << mc.health
            << " | Sword Equipped: " << (mc.has_sword ? "Master Sword" : "Fragile Sword") << '\n';
        displayMap(map, mc);
        movePlayer(mc, map);
    }

    std::cout << "You Died...\n";
    return 0;
}
