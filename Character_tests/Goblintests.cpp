#include "gtest/gtest.h"
#include "../Character_header/Goblin.h"
#include "../Character_header/Character.h" // Assuming Character is a base class

// Test Case 1: Test Goblin Initialization
TEST(GoblinTest, TestInitialization) {
    Goblin goblin("Gobbo", 100, 20, 15, "Evil Clan"); // Assuming Goblin is a derived class of Character

    EXPECT_EQ(goblin.getHealth(), 100);  // Check initial health
    EXPECT_EQ(goblin.getType(), GOBLIN);  // Assuming GOBLIN is a valid CharType
}

// Test Case 2: Test setHealth
TEST(GoblinTest, TestSetHealth) {
    Goblin goblin("Gobbo", 100, 20, 15, "Evil Clan"); // Assuming Goblin is a derived class of Character

    goblin.setHealth(80);
    EXPECT_EQ(goblin.getHealth(), 80);  // Check updated health
}

// Test Case 3: Test isAlive when health > 0
TEST(GoblinTest, TestIsAlivePositiveHealth) {
    Goblin goblin("Gobbo", 100, 20, 15, "Evil Clan"); // Assuming Goblin is a derived class of Character

    EXPECT_TRUE(goblin.isalive());  // Goblin should be alive
}

// Test Case 4: Test isAlive when health <= 0
TEST(GoblinTest, TestIsAliveZeroHealth) {
    Goblin goblin("Gobbo", 0, 20, 15, "Evil Clan");

    EXPECT_FALSE(goblin.isalive());  // Goblin should be dead
}

// Test Case 5: Test dealtDamage sets the correct attackAmount
TEST(GoblinTest, TestDealtDamage) {
    Goblin goblin("Gobbo", 100, 20, 15, "Evil Clan"); // Assuming Goblin is a derived class of Character

    goblin.dealtDamage(50);  // Set damage
    EXPECT_EQ(goblin.attackAmount, 50);  // Check updated attackAmount
}

// Test Case 6: Test receiveDamage reduces health correctly
TEST(GoblinTest, TestReceiveDamage) {
    Goblin goblin("Gobbo", 100, 20, 15, "Evil Clan");

    goblin.recieveDamage(30);  // Apply damage
    EXPECT_EQ(goblin.getHealth(), 70);  // Health should decrease by 30
}

// Test Case 7: Test receiveDamage with overkill
TEST(GoblinTest, TestReceiveDamageOverkill) {
    Goblin goblin("Gobbo", 50, 20, 15, "Evil Clan");

    goblin.recieveDamage(100);  // Apply damage greater than health
    EXPECT_EQ(goblin.getHealth(), -50);  // Health decreases even below zero
}

// Test Case 8: Test attack decreases player's health
TEST(GoblinTest, TestAttack) {
    Goblin goblin("Gobbo", 100, 20, 15, "Evil Clan");
    Goblin player("Player", 100, 15, 10, "Evil Clan");  // Create a player character of type Goblin

    goblin.attack(player);  // Goblin attacks player
    EXPECT_EQ(player.getHealth(), 80);  // Player's health should decrease by goblin's attackAmount (20)
}

// Test Case 9: Test attack on a dead player
TEST(GoblinTest, TestAttackDeadPlayer) {
    Goblin goblin("Gobbo", 100, 20, 15, "Evil Clan");
    Character player(MAINCHAR, "Player", 0, 15, 10);  // Dead player

    goblin.attack(player);  // Goblin attacks player
    EXPECT_EQ(player.getHealth(), -20);  // Player's health decreases even further
}

// Test Case 10: Test getType returns correct type
TEST(GoblinTest, TestGetType) {
    Goblin goblin("Gobbo", 100, 20, 15, "Evil Clan");

    EXPECT_EQ(goblin.getType(), GOBLIN);  // Assuming GOBLIN is the correct type
}
