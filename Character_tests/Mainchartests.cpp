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

// Test moving the character within boundaries and wrapping around
// TEST(MainCharacterTest, testMapMove) {
//     MainCharacter mc;
//     mc.setPosition(5, 5);
//     auto obj = mc.move('w', gameMap); // Move up
//     EXPECT_EQ(mc.getPosition(), std::make_pair(5, 4));
//     EXPECT_EQ(obj.getType(), "Goblin");

//     mc.move('d', gameMap); // Move right
//     EXPECT_EQ(mc.getPosition(), std::make_pair(6, 4));

//     mc.move('a', gameMap); // Move left
//     EXPECT_EQ(mc.getPosition(), std::make_pair(5, 4));

//     mc.move('s', gameMap); // Move down
//     EXPECT_EQ(mainChar.getPosition(), std::make_pair(5, 5));
// }

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