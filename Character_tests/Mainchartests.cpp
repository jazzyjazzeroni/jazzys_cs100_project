<<<<<<< HEAD
#include "gtest/gtest.h"
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Character.h"
#include "../Character_header/Goblin.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/Potions.h"
#include "../addit_header/Swords.h"

#include "../Character_header/MainCharacter.h"
#include <iostream>

using namespace std;

// // Constructor
// MainCharacter::MainCharacter(const std::string &name, int health, int damage, const std::string &element)
//     : Character(MAINCHAR, name, health, damage, element), powers(element), currentElement(powers.getPower()) {}


// // void MainCharacter::attack(Character &opponent) {
// //     cout << name << " attacks " << opponent.getType() << " with a sword, dealing " << attackAmount << " damage!" << endl;
// //     opponent.receiveDamage(attackAmount);

// //     if (!opponent.isalive()) {
// //         std::cout << "The opponent has been defeated!" << std::endl;
// //     }
// // }

// void MainCharacter::heal(int amount) {
//     health = min(health + amount, MAX_HEALTH); // Prevent exceeding MAX_HEALTH
//     cout << name << " heals for " << amount << " health points. Current health: " << health << endl;
// }

// void MainCharacter::usePowers() {
//     cout << name << " uses a special power!" << endl;
//     powers.usePower(powers.getPower(), allegiance); // Assuming `activate()` is a method in `Powers`
// }

// // void MainCharacter::usePotion(const string &potionName) {
// //     for (auto &potion : inventory.getPotions()) { // Access potions directly
// //         if (potion.getType() == potionName) {
// //             heal(potion.getHealingAmount()); // Heal the character
// //             inventory.removePotion(potionName); // Remove used potion
// //             cout << "Used potion: " << potionName << endl;
// //             return;
// //         }
// //     }
// //     cout << "Potion not found in inventory!" << endl;
// // }

// // void Character::updateElementForLevel() {
// //     currentElement = level.getElementForLevel(level.getCurrentLevel());
// // }

// Power_type Character::getCurrentElement() const {
//     return currentElement;
// }

// void MainCharacter::usePotion(const string &potionName) {
//     if (inventory.hasPotion(potionName)) {
//         Potion potion = inventory.getPotion(potionName); // Get potion from inventory
//         heal(potion.getHealingAmount());                // Apply its effect
//         inventory.removePotion(potionName);             // Remove it from inventory
//         cout << "Used potion: " << potionName << endl;
//     } else {
//         cout << "Potion not found in inventory!" << endl;
//     }
// }
// // Add sword function (pick up a sword)
//     void MainCharacter::equipSword(const Sword & newSword) {
//         //todo give o[ption to swap or replace sword]
//             // Swap or replace the sword
//             this->sword = Sword(newSword.getValue(), "New Sword");
//             inventory.addSword(newSword);
//     }
//     // Equips a sword
// //     void MainCharacter::equipSword(Object & newSword) {
// //         if (newSword.getType() == "sword") {
// //             // Swap or replace the sword
// //             this->sword = Sword(newSword.getValue(), "New Sword");

// //         }
// //     for (const auto &sword : inventory.getSwords()) { // Access swords directly
// //         if (sword.getName() == swordName) {
// //             attackAmount = sword.getPower(); // Equip and update attack strength
// //             cout << "Equipped sword: " << swordName << " (Damage: " << sword.getPower() << ")" << endl;
// //             return;
// //         }
// //     }
// //     cout << "Sword not found in inventory!" << endl;
// // }
  

//     int MainCharacter::mod(int value, int limit) {
//         return (value % limit + limit) % limit;  // Handle negative values properly
//     }

//   std::shared_ptr<Object> MainCharacter::move(char action, GameMap &gameMap) {
//     int newX = x, newY = y;
    

//     if (action == 'w') { // Move up
//         newY = mod(y - 1, gameMap.getHeight());
//     } else if (action == 's') { // Move down
//         newY = mod(y + 1, gameMap.getHeight());
//     } else if (action == 'a') { // Move left
//         newX = mod(x - 1, gameMap.getWidth());
//     } else if (action == 'd') { // Move right
//         newX = mod(x + 1, gameMap.getWidth());
//     }

//     // x = newX;
//     // y = newY;

//         setPosition(newX, newY);

//     return gameMap.getObjectAt(newX, newY); // Ensure return type matches shared_ptr<Object>
// }

//     void MainCharacter::setPosition(int newX, int newY) {
//         x = newX;
//     y = newY;
//         // this->x = x;
//         // this->y = y;
//     }


//     pair<int, int> MainCharacter::getPosition() const {
//         return {x, y};
//     }

// void MainCharacter::attack(Character &target) {
//     if (target.getType() == "Goblin") { 
//         cout << name << " attacks the Goblin fiercely with a sword, dealing " 
//              << attackAmount << " damage!" << endl;
//     } else {
//         cout << name << " attacks the opponent with a sword, dealing " 
//              << attackAmount << " damage!" << endl;
//     }
//     target.receiveDamage(attackAmount);

//     if (!target.isalive()) {
//         cout << "The opponent has been defeated!" << endl;
//     }
// }

//     // void MainCharacter::heal(int amount) {
//     //     setHealth(getHealth() + amount); // Assuming you have a setHealth method in Character
//     // }
//     void MainCharacter::print() const {
//         cout << "Main Character: " << name << ", Health: " << health << ", Attack: " << attackAmount << endl;
//     }
//     // todo Check if the character is alive
//     // bool MainCharacter::isalive() const {
//     //     return (getHealth() > 0);
//     // };


//     // todo Update the element based on the current level

class MainCharacterTest : public ::testing::Test {
protected:
    MainCharacter mc{"Theodore", 100, 15, "AIR"};
    GameMap gm;
};

TEST(MainCharacterConstrutorTest, testDefaultCase)
{
    MainCharacter mc("Theodore", 100, 5, "AIR");

    // EXPECT_EQ(mc.getName(), "Theodore");
    // EXPECT_EQ(mc.getHealth(), 100);
    // EXPECT_EQ(mc.getAttackStrength(), 15);
    // EXPECT_EQ(mc.getAllegiance(), "AIR");
    // EXPECT_EQ(mc.getPosition(), (0, 0));

}

TEST(MainCharacterAliveTest, testIsAlivePositiveFull)
{
    MainCharacter mc("Theodore", 100, 5, "AIR");
    mc.setHealth(100);
    EXPECT_EQ(mc.isalive(), 100);
}

TEST(MainCharacterAliveTest, testIsAlivePositivePartial)
{
    MainCharacter mc("Theodore", 100, 5, "AIR");
    mc.setHealth(50);   //Partial Health
    EXPECT_EQ(mc.isalive(), 50);
}

TEST(MainCharacterAliveTest, testIsAliveNegative)
{
    MainCharacter mc("Theodore", -5, 5, "AIR");
    mc.setHealth(-5);
    ASSERT_FALSE(mc.isalive());
}

TEST(MainCharacterAliveTest, testIsAliveZero)
{
    MainCharacter mc("Theodore", 0, 5, "AIR");
    mc.setHealth(0);
    EXPECT_TRUE(mc.isalive());
}
TEST(MainCharacterPotionTest, testHealBigPotion)
{
    MainCharacter mc("Theodore", 100, 5, "AIR");
    // Using 2nd potion
    mc.heal(15);    
    EXPECT_EQ(mc.getHealth(), 100);
}

TEST(MainCharacterPotionTest, testHealNegativePotion)
{
    MainCharacter mc("Theodore", -15, 5, "AIR");
    // Using 2nd potion
    mc.heal(-15);    
    EXPECT_FALSE(mc.getHealth());
}

TEST(MainCharacterPotionTest, testHealSmallPotion)
{
    MainCharacter mc("Theodore", 10, 5, "AIR");
    // Using 1st potion
    mc.heal(10);    
    EXPECT_EQ(mc.getHealth(), 100);
}

TEST(MainCharacterTest, testPowers) {
    MainCharacter mc("Theodore", 100, 5, "AIR");
    EXPECT_NO_THROW(mc.usePowers());
}


TEST(MainCharacterAttackTest, testAttackPositive) {
    MainCharacter mc("Theodore", 100, 5, "AIR");
    Goblin goblin;

    mc.attack(goblin);
    EXPECT_EQ(goblin.getHealth(), 25);

    mc.attack(goblin); // Second attack should defeat the goblin
    EXPECT_EQ(goblin.getHealth(), 0);
    EXPECT_FALSE(goblin.isalive());
}

TEST(MainCharacterAttackTest, testAttackNegative) {
    MainCharacter mc("Theodore", 100, 5, "AIR");
    Goblin goblin;

    mc.attack(goblin);
    EXPECT_EQ(goblin.getHealth(), 25);

    mc.attack(goblin); 
    EXPECT_EQ(goblin.getHealth(), 0);
    EXPECT_FALSE(goblin.isalive());

    mc.attack(goblin);  // TEST FOR NEGATIVE
    EXPECT_EQ(goblin.getHealth(), -5);
   
}

TEST(MainCharacterEdgeCaseTest, testHealNegative) {
    MainCharacter mc("Theodore", -20, 15, "Fire");
    mc.heal(-20);
    ASSERT_EQ(mc.getHealth(), 100)  << "Health should not be negative";
}

TEST(MainCharacterEdgeCaseTest, testNonExistentPotion) {
    MainCharacter mc("Theodore", 100, 15, "Fire");

    std::string output;
    testing::internal::CaptureStdout();
    mc.usePotion("Ultimate Potion");
    output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Potion not found in inventory!") != std::string::npos)
        << "Expected message for non-existent potion was not displayed.";
}

TEST(MainCharacterEdgeCaseTest, testOutOfBoundsPosition) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    GameMap gameMap(0, 0);
    int initialPosition = mc.getPosition();

    mc.setPosition(0, 0); 
    mc.move('w', gameMap); 
    EXPECT_NE(mc.getPosition(), initialPosition) << "This position is out of bounds from the map";
}

TEST(MainCharacterEdgeCaseTest, testInvalidSwordItem) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    Sword invalidSword(-21, "Mock Sword");

    mc.equipSword(invalidSword);

    EXPECT_GT(mc.getAttackAmount(), 0) << "Sword equipped is negative in attack";
}

TEST(MainCharacterEdgeCaseTest, testHealBeyondMax) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    mc.heal(500);

    ASSERT_EQ(mc.getHealth(), MainCharacter::MAX_HEALTH) << "Main Character's health should not go beyond the Max Health of 150";
}

TEST(MainCharacterEdgeCaseTest, MoveWithInvalidAction) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    GameMap gameMap(10, 10);
    auto initialPosition = mc.getPosition();

    mc.move('n', gameMap); // 
    ASSERT_EQ(mc.getPosition(), initialPosition) << "Invalid action should not change the character's position.";
}
=======
#include <gtest/gtest.h>
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Character.h"
#include "../addit_header/Potions.h"
#include "../addit_header/Object.h"
#include "../Character_header/Goblin.h"
#include "GameMap.h"

#include <iostream>

using namespace std;

TEST(MainCharacterTest, testConstructorInitialization) {
    MainCharacter character("Theodore", 100, 20, "Fire");
    EXPECT_EQ(character.getHealth(), 100);
    EXPECT_EQ(character.getType(), MAINCHAR);
    EXPECT_EQ(character.getCurrentElement(), "Fire");
}

TEST(MainCharacterTest, testHealWithinMaxHealth) {
    MainCharacter character("Theodore", 80, 20, "Water");
    character.heal(10);
    EXPECT_EQ(character.getHealth(), 90);
}

TEST(MainCharacterTest, testHealExceedingMaxHealth) {
    MainCharacter character("Theodore", 95, 20, "Water");
    character.heal(10);
    EXPECT_EQ(character.getHealth(), 100); // Assuming MAX_HEALTH = 100
}

TEST(MainCharacterTest, testUseSmallPotion) {
    MainCharacter mc("Theodore", 50, 25, "Fire");
    Potion smallPotion(50, "Small Potion");
    mc.usePotion("Small Potion");        // Use the potion
    EXPECT_EQ(mc.getHealth(), 100);      // Heals 50 points, up to MAX_HEALTH
}

TEST(MainCharacterTest, testUseLargePotion) {
    MainCharacter mc("Theodore", 20, 25, "Fire");
    Potion potion;
    Potion largePotion(100, "Large Potion");
    potion.getHealingAmount();
    mc.usePotion("Large Potion");
    EXPECT_EQ(mc.getHealth(), 100); // Heals 100 points, up to MAX_HEALTH
}

TEST(MainCharacterTest, testUsePotionNotInInventory) {
    MainCharacter mc("Theodore", 50, 25, "Fire");
    testing::internal::CaptureStdout();
    mc.usePotion("Nonexistent Potion");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Potion not found in inventory!") != std::string::npos);
}

TEST(MainCharacterTest, testAttackGoblin) {
    MainCharacter mc("Theodore", 100, 25, "Earth");
    Goblin goblin("Goblin", 50, 10, 0, "Air");

    testing::internal::CaptureStdout();
    mc.attack(goblin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(goblin.getHealth(), 25); // 50 - 25 = 25
    EXPECT_TRUE(output.find("attacks the Goblin") != std::string::npos);
}

TEST(MainCharacterTest, testAttackDefeatedOpponent) {
    MainCharacter mc("Theodore", 100, 25, "Earth");
    Goblin goblin("Goblin", 0, 10, 0, "Air");

    testing::internal::CaptureStdout();
    mc.attack(goblin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("is already defeated") != std::string::npos);
}

TEST(MainCharacterTest, testPrintDetails) {
    MainCharacter mc("Theodore", 100, 25, "Fire");

    testing::internal::CaptureStdout();
    mc.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Theodore") != std::string::npos);
    EXPECT_TRUE(output.find("Health: 100") != std::string::npos);
    EXPECT_TRUE(output.find("Attack: 25") != std::string::npos);
}

TEST(MainCharacterTest, testZeroAttackPower) {
    MainCharacter mc("Theodore", 100, 0, "Fire");
    Goblin goblin("Goblin", 50, 10, 0, "Air");
    mc.attack(goblin);
    EXPECT_EQ(goblin.getHealth(), 50); // No damage dealt
}

TEST(MainCharacterTest, testNegativeAttackPower) {
    MainCharacter mc("Theodore", 100, -10, "Earth");
    Goblin goblin("Goblin", 50, 10, 0, "Air");
    mc.attack(goblin);
    EXPECT_EQ(goblin.getHealth(), 50); // Negative attack should not affect enemy
}
>>>>>>> master
