#include <gtest/gtest.h>
#include "../Character_header/Goblin.h"
#include "../Character_header/MainCharacter.h"
using namespace std;

// Test: Constructor Initialization for fire goblins
TEST(GoblinTestSuite, testFireGobDefaultConstructor) {
    Goblin gob("Fire Goblin", 100, 15, "Fire");

    EXPECT_EQ(gob.getHealth(), 100);
    EXPECT_EQ(gob.getType(), "Goblin");
    EXPECT_EQ(gob.getGoblinType(), "Fire");

}

// Test: Constructor Initialization for water goblins
TEST(GoblinTestSuite, testWaterGobDefaultConstructor) {
    Goblin gob("Water Goblin", 75, 10, "Water");

    EXPECT_EQ(gob.getHealth(), 75);
    EXPECT_EQ(gob.getType(), "Goblin");
    EXPECT_EQ(gob.getGoblinType(), "Water");

}

// Test: Constructor Initialization for air goblins
TEST(GoblinTestSuite, testAirGobDefaultConstructor) {
    Goblin gob("Air Goblin", 70, 7, "Air");

    EXPECT_EQ(gob.getHealth(), 70);
    EXPECT_EQ(gob.getType(), "Goblin");
    EXPECT_EQ(gob.getGoblinType(), "Air");

}

// Test: Constructor Initialization for earth goblins
TEST(GoblinTestSuite, testEarthGobDefaultConstructor) {
    Goblin gob("Earth Goblin", 65, 5, "Earth");

    EXPECT_EQ(gob.getHealth(), 65);
    EXPECT_EQ(gob.getType(), "Goblin");
    EXPECT_EQ(gob.getGoblinType(), "Earth");

}

// Test: Constructor Initialization for invalid element goblins
TEST(GoblinTestSuite, testInvalidGobDefaultConstructor) {

    EXPECT_THROW(Goblin gob("Goblin", 65, 5, "idk"), invalid_argument);

}

// i don't think setHealth even gets used but i made a test for it anyways
TEST(GoblinTestSuite, testSetGoblinHealth) {
    Goblin gob("Earth Goblin", 65, 5, "Earth");
    gob.setHealth(75);

    EXPECT_EQ(gob.getHealth(), 75);
}

// Test: tests if isAlive correctly returns true for an alive goblin
TEST(GoblinTestSuite, testGoblinIsAlive) {
    Goblin gob("Earth Goblin", 65, 5, "Earth");

    EXPECT_TRUE(gob.isalive());
}

// Test: tests if isAlive correctly returns false for a dead goblin
TEST(GoblinTestSuite, testGoblinIsAliveAfterSetTo0) {
    Goblin gob("Earth Goblin", 65, 5, "Earth");
    gob.setHealth(0);

    EXPECT_FALSE(gob.isalive());
}

// Test: tests if receiveDamage correctly updates goblin's health
TEST(GoblinTestSuite, testGoblinReceiveCorrectDamage) {
    Goblin gob("Earth Goblin", 65, 5, "Earth");
    gob.recieveDamage(25);

    EXPECT_EQ(gob.getHealth(), 40);
}

// Test: tests if receiveDamage correctly returns 0 for any
// attack that is inflicted on it that's more than its current health
TEST(GoblinTestSuite, testGoblinReceiveOverkillDamage) {
    Goblin gob("Earth Goblin", 65, 5, "Earth");
    gob.receiveDamage(70);

    EXPECT_EQ(gob.getHealth(), 0);
}

// Test: Goblin attacking the player
// might need tweaks
TEST(GoblinTestSuite, testAttackPlayer) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    Goblin gob("Air Goblin", 50, 50, "Air");

    gob.attack(mc);
    EXPECT_LT(mc.getHealth(), 100);
    EXPECT_TRUE(mc.isalive());

    gob.attack(mc);
    EXPECT_FALSE(mc.isalive());
}

// Test: tests that goblin of same element as mc does no damage
TEST(GoblinTestSuite, testInvalidAttack) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    Goblin gob("Fire Goblin", 50, 10, "Fire"); // Same element

    gob.attack(mc); // Should result in no damage
    EXPECT_EQ(mc.getHealth(), 100); // Health should remain the same
}