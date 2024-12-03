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
