#include "gtest/gtest.h"
#include "../Character_header/Goblin.h"
#include "../Character_header/Character.h" // Assuming Character is a base class
#include "../Character_header/MainCharacter.h"

// Test Case 1: Test Goblin Constructor Air
TEST(GoblinConstructorTest, testAirTypeGoblin) {
    Goblin goblin("Air Goblin", 100, 5, "AIR"); // Assuming Goblin is a derived class of Character
    
    EXPECT_EQ(goblin.getHealth(), 100);  // Check initial health
    EXPECT_EQ(goblin.getType(), GOBLIN);  // Assuming GOBLIN is a valid CharType

}

// Test Case 2: Test Goblin Constructor Earth Type
TEST(GoblinConstructorTest, testEarthTypeGoblin) {
    Goblin goblin("Earth Goblin", 100, 10, "EARTH"); // Assuming Goblin is a derived class of Character

    EXPECT_EQ(goblin.getHealth(), 100);  // Check initial health
    EXPECT_EQ(goblin.getType(), GOBLIN);  // Assuming GOBLIN is a valid CharType

}

// Test Case 2: Test Goblin Constructor Water Type
TEST(GoblinConstructorTest, testWaterTypeGoblin) {
    Goblin goblin("Water Goblin", 100, 15, "WATER"); // Assuming Goblin is a derived class of Character

    EXPECT_EQ(goblin.getHealth(), 100);  // Check initial health
    EXPECT_EQ(goblin.getType(), GOBLIN);  // Assuming GOBLIN is a valid CharType

}

// Test Case 2: Test Goblin Constructor Fire Type
TEST(GoblinConstructorTest, testFireTypeGoblin) {
    Goblin goblin("Fire Goblin", 100, 20, "FIRE"); // Assuming Goblin is a derived class of Character

    EXPECT_EQ(goblin.getHealth(), 100);  // Check initial health
    EXPECT_EQ(goblin.getType(), GOBLIN);  // Assuming GOBLIN is a valid CharType

}

////////////////////// SET HEALTH TESTING//////////////////////////////////
// Test Case 2: Test setHealth
TEST(GoblinSetHealthTest, TestSetHealthAirGoblin) {
    Goblin goblin("Air Goblin", 100, 5, "AIR"); // Assuming Goblin is a derived class of Character

    goblin.setHealth(100);
    EXPECT_EQ(goblin.getHealth(), 100);  // Check updated health
}

// Test Case 2: Test setHealth
TEST(GoblinSetHealthTest, TestSetHealthEarthGoblin) {
    Goblin goblin("Earth Goblin", 100, 10, "EARTH"); // Assuming Goblin is a derived class of Character

    goblin.setHealth(100);
    EXPECT_EQ(goblin.getHealth(), 100);  // Check updated health
}

TEST(GoblinSetHealthTest, TestSetHealthWaterGoblin) {
    Goblin goblin("Water Goblin", 100, 5, "WATER"); // Assuming Goblin is a derived class of Character

    goblin.setHealth(100);
    EXPECT_EQ(goblin.getHealth(), 100);  // Check updated health
}

TEST(GoblinSetHealthTest, TestSetHealthFireGoblin) {
    Goblin goblin("Fire Goblin", 100, 5, "FIRE"); // Assuming Goblin is a derived class of Character

    goblin.setHealth(100);
    EXPECT_EQ(goblin.getHealth(), 100);  // Check updated health
}

// Test Case 3: Test isAlive when health > 0
TEST(GoblinTest, TestIsAlivePositiveHealth) {
    Goblin goblin("Air Goblin", 100, 5, "AIR"); // Assuming Goblin is a derived class of Character

    EXPECT_TRUE(goblin.isalive());  // Goblin should be alive
}

// Test Case 4: Test isAlive when health <= 0
TEST(GoblinTest, TestIsAliveZeroHealth) {
    Goblin goblin("Air Goblin", 0, 20, "AIR");

    EXPECT_FALSE(goblin.isalive());  // Goblin should be dead
}

// // Test Case 5: Test dealtDamage sets the correct attackAmount
// TEST(GoblinTest, TestDealtDamage) {
//     Goblin goblin("Air Goblin", 100, 5, "AIR"); // Assuming Goblin is a derived class of Character

//     goblin.dealtDamage(50);  // Set damage
//     EXPECT_EQ(goblin.attackAmount, 50);  // Check updated attackAmount
// }

// Test Case 6: Test receiveDamage reduces health correctly
TEST(GoblinTest, TestReceiveDamage) {
    Goblin goblin("Air Type", 100, 5, "AIR");

    goblin.recieveDamage(30);  // Apply damage
    EXPECT_EQ(goblin.getHealth(), 70);  // Health should decrease by 30
}

// Test Case 7: Test receiveDamage with overkill
TEST(GoblinTest, TestReceiveDamageOverkill) {
    Goblin goblin("Air Type", 100, 5, "AIR");

    goblin.recieveDamage(100);  // Apply damage greater than health
    EXPECT_EQ(goblin.getHealth(), -50);  // Health decreases even below zero
}

//////////// TODO: FIX BUG
// //MainCharacter::MainCharacter(const std::string &name, int health, int attackStrength, const std::string &allegiance)
//     : allegiance(allegiance), x(0), y(0), powers("FUSED_POWER") { // Default power as "FUSED_POWER"
//     this->name = name;
//     this->health = health;
//     this->attackAmount = attackStrength;
//     this->type = MAINCHAR;
// }

// void MainCharacter::attack(Character &opponent) {
//     cout << name << " attacks " << opponent.getType() << " with a sword, dealing " << attackAmount << " damage!" << endl;
//     opponent.recieveDamage(attackAmount);

//     if (!opponent.isalive()) {
//         std::cout << "The opponent has been defeated!" << std::endl;
//     }
// }

// Test Case 8: Test attack decreases player's health
// TEST(GoblinTest, TestAttack) {
//     Goblin goblin("Air Type", 100, 5, "AIR");
//     Character player("Theodore", 100, 10,"EARTH"); // Create a player character of type Goblin

//     goblin.attack(mc);  // Goblin attacks player
//     EXPECT_EQ(player.getHealth(), 100);  // Player's health should decrease by goblin's attackAmount (20)
// }

// // Test Case 9: Test attack on a dead player
// TEST(GoblinTest, TestAttackDeadPlayer) {
//     Goblin goblin("Air Type", 100, 5, "AIR");
//     Character player(MAINCHAR, "Player", 0, 15, 10);  // Dead player

//     goblin.attack(player);  // Goblin attacks player
//     EXPECT_EQ(player.getHealth(), -20);  // Player's health decreases even further
// }

// Test Case 10: Test getType returns correct type
TEST(GoblinTest, TestGetType) {
    Goblin goblin("Air Type", 100, 5, "AIR");

    EXPECT_EQ(goblin.getType(), GOBLIN);  // Assuming GOBLIN is the correct type
}
