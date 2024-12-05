#include <gtest/gtest.h>
#include "../Character_header/Goblin.h"

// Test: Constructor Initialization for fire goblins
TEST(GoblinTestSuite, testFireGobDefaultConstructor) {
    Goblin gob("Goblin", 100, 15, "Fire");

    EXPECT_EQ(gob.getHealth(), 100);
    EXPECT_EQ(gob.getType(), "Goblin");
    EXPECT_EQ(gob.getGoblinType(), "Fire");

}

// Test: Constructor Initialization for water goblins
TEST(GoblinTestSuite, testWaterGobDefaultConstructor) {
    Goblin gob("Goblin", 75, 10, "Water");

    EXPECT_EQ(gob.getHealth(), 75);
    EXPECT_EQ(gob.getType(), "Goblin");
    EXPECT_EQ(gob.getGoblinType(), "Water");

}

// Test: Constructor Initialization for air goblins
TEST(GoblinTestSuite, testAirGobDefaultConstructor) {
    Goblin gob("Goblin", 70, 7, "Air");

    EXPECT_EQ(gob.getHealth(), 70);
    EXPECT_EQ(gob.getType(), "Goblin");
    EXPECT_EQ(gob.getGoblinType(), "Air");

}

// Test: Constructor Initialization for earth goblins
TEST(GoblinTestSuite, testEarthGobDefaultConstructor) {
    Goblin gob("Goblin", 65, 5, "Earth");

    EXPECT_EQ(gob.getHealth(), 65);
    EXPECT_EQ(gob.getType(), "Goblin");
    EXPECT_EQ(gob.getGoblinType(), "Earth");

}

