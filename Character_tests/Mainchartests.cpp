#include "gtest/gtest.h"
#include "../Character_header/MainCharacter.h"
#include "../Character_header/Character.h"
#include "../Character_header/Goblin.h"
#include "../addit_header/GameMap.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/Potions.h"
#include "../addit_header/Swords.h"

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
    MainCharacter mc;
    mc.setHealth(100);
    EXPECT_EQ(mc.isalive(), 100);
}

TEST(MainCharacterAliveTest, testIsAlivePositivePartial)
{
    MainCharacter mc;
    mc.setHealth(50);   //Partial Health
    EXPECT_EQ(mc.isalive(), 50);
}

TEST(MainCharacterAliveTest, testIsAliveNegative)
{
    MainCharacter mc;
    mc.setHealth(-5);
    ASSERT_FALSE(mc.isalive());
}

TEST(MainCharacterAliveTest, testIsAliveZero)
{
    MainCharacter mc;
    mc.setHealth(0);
    EXPECT_TRUE(mc.isalive());
}
TEST(MainCharacterPotionTest, testHealBigPotion)
{
    MainCharacter mc;
    // Using 2nd potion
    mc.heal(15);    
    EXPECT_EQ(mc.getHealth(), 100);
}

TEST(MainCharacterPotionTest, testHealNegativePotion)
{
    MainCharacter mc;
    // Using 2nd potion
    mc.heal(-15);    
    EXPECT_FALSE(mc.getHealth());
}

TEST(MainCharacterPotionTest, testHealSmallPotion)
{
    MainCharacter mc;
    // Using 1st potion
    mc.heal(10);    
    EXPECT_EQ(mc.getHealth(), 100);
}

TEST(MainCharacterTest, testPowers) {
    MainCharacter mc;
    EXPECT_NO_THROW(mc.usePowers());
}


TEST(MainCharacterAttackTest, testAttackPositive) {
    MainCharacter mc;
    Goblin goblin;

    mc.attack(goblin);
    EXPECT_EQ(goblin.getHealth(), 25);

    mc.attack(goblin); // Second attack should defeat the goblin
    EXPECT_EQ(goblin.getHealth(), 0);
    EXPECT_FALSE(goblin.isalive());
}

TEST(MainCharacterAttackTest, testAttackNegative) {
    MainCharacter mc;
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
    MainCharacter mainCharacter("Theodore", 100, 15, "Fire");
    mainCharacter.heal(-20);
    ASSERT_EQ(mainCharacter.getHealth(), 100)  << "Health should not be negative";
}

TEST(MainCharacterEdgeCaseTest, testNonExistentPotion) {
    MainCharacter mainCharacter("Theodore", 100, 15, "Fire");

    std::string output;
    testing::internal::CaptureStdout();
    mainCharacter.usePotion("Ultra Potion");
    output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Potion not found in inventory!") != std::string::npos)
        << "Expected message for non-existent potion was not displayed.";
}

TEST(MainCharacterEdgeCaseTest, testOutOfBoundsPosition) {
    MainCharacter mainCharacter("Theodore", 100, 15, "Fire");
    MockGameMap gameMap(10, 10);
    int initialPosition = mainCharacter.getPosition();

    mainCharacter.setPosition(0, 0); 
    mainCharacter.move('w', gameMap); 
    EXPECT_NE(mainCharacter.getPosition(), initialPosition) << "This position is out of bounds from the map";
}

TEST(MainCharacterEdgeCaseTest, testInvalidSwordItem) {
    MainCharacter mainCharacter("Theodore", 100, 15, "Fire");
    Sword invalidSword(-21, "Mock Sword");

    mainCharacter.equipSword(invalidSword);

    EXPECT_GT(mainCharacter.getAttackAmount(), 0) << "Sword equipped is negative in attack";
}

TEST(MainCharacterEdgeCaseTest, testHealBeyondMax) {
    MainCharacter mainCharacter("Theodore", 100, 15, "Fire");
    mainCharacter.heal(500);

    ASSERT_EQ(mainCharacter.getHealth(), MainCharacter::MAX_HEALTH) << "Main Character's health should not go beyond the Max Health of 150";
}

TEST(MainCharacterTest, MoveWithInvalidAction) {
    MainCharacter mainCharacter("Theodore", 100, 15, "Fire");
    MockGameMap gameMap(10, 10);
    auto initialPosition = mainCharacter.getPosition();

    mainCharacter.move('n', gameMap); // 
    ASSERT_EQ(mainCharacter.getPosition(), initialPosition) << "Invalid action should not change the character's position.";
}