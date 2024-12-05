#include <gtest/gtest.h>
#include "../Character_header/MainCharacter.h"
#include "../addit_header/Swords.h"
#include "../Character_header/Goblin.h"
#include "../addit_header/Potions.h"

// Test: Constructor Initialization
TEST(MainCharacterTestSuite, testDefaultConstructor) {
    MainCharacter mc("Theodore", 100, 5, "Air");

    EXPECT_EQ(mc.getHealth(), 100);
    EXPECT_EQ(mc.getPosition(), std::make_pair(0, 0)); 
    EXPECT_EQ(mc.getType(), "Air");
}

// Test: Movement at boundaries (edge cases)
TEST(MainCharacterTestSuite, testCharacterMovement) {
    MainCharacter mc(0, 0);
    int width = 5, height = 5;

    auto newPosition = mc.move('w', height, width);
    EXPECT_EQ(newPosition, std::make_pair(0, 4)); // Wrap around to the bottom

    newPosition = mc.move('a', height, width);
    EXPECT_EQ(newPosition, std::make_pair(4, 4)); // Wrap around to the right

    newPosition = mc.move('s', height, width);
    EXPECT_EQ(newPosition, std::make_pair(4, 0)); // Wrap around to the top

    newPosition = mc.move('d', height, width);
    EXPECT_EQ(newPosition, std::make_pair(0, 0)); // Wrap around to the left
}

TEST(MainCharacterTestSuite, testHealingValid) {
    MainCharacter mc("Theodore", 90, 15, "Air");
    mc.heal(15); // Normal heal
    EXPECT_EQ(mc.getHealth(), 100);

    mc.heal(10); // Overheal test
    EXPECT_EQ(mc.getHealth(), 100);


}

TEST(MainCharacterTestSuite, testHealingBeyondLimit) {
    MainCharacter mc("Theodore", 90, 15, "Air");

    mc.heal(110); // Healing beyond the range
    EXPECT_EQ(mc.getHealth(), 100);
}

TEST(MainCharacterTestSuite, testHealingLowCapacity) {
    MainCharacter mc("Theodore", 90, 15, "Air");

    MainCharacter lowHealthMc("Theodore", 1, 15, "Air");
    lowHealthMc.heal(5); // Low health heal
    EXPECT_EQ(lowHealthMc.getHealth(), 6);
}

TEST(MainCharacterTestSuite, testHealingInvalidNegativeCase) {
    MainCharacter mc("Theodore", 90, 15, "Air");

    MainCharacter lowHealthMc("Theodore", 1, 15, "Air");
    lowHealthMc.heal(-5); // Low health heal
    EXPECT_FALSE(lowHealthMc.getHealth()) << "INVALID: Healing cannot be negative!";
}
// Test: Equipping a sword
TEST(MainCharacterTestSuite, EquipSword) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    Sword basicSword(10, "Basic Sword");

    mc.equipSword(basicSword);

    EXPECT_EQ(mc.getType(), "Theodore");
    EXPECT_NO_THROW(mc.equipSword(Sword(15, "Greater Sword")));
}

// Test: Attacking a Goblin
TEST(MainCharacterTestSuite, AttackGoblin) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    Goblin goblin("Air Goblin", 50, 10, "Air");

    mc.attack(goblin);
    EXPECT_LT(goblin.getHealth(), 50); 
    EXPECT_TRUE(goblin.isalive()); 

    mc.attack(goblin); 
    EXPECT_FALSE(goblin.isalive()); // Goblin is defeated
}

TEST(MainCharacterTestSuite, testInvalidAttack) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    Goblin goblin("Fire Goblin", 50, 10, "Fire"); // Same element

    mc.attack(goblin); // Should result in no damage
    EXPECT_EQ(goblin.getHealth(), 50); // Health should remain the same
}

// Test: Using a potion
TEST(MainCharacterTestSuite, testUsePotionSmall) {
    MainCharacter mc("Theodore", 50, 15, "Fire");
    Potion smallPotion(50, "Small Potion");

    smallPotion.healCharacter(mc);
    EXPECT_EQ(mc.getHealth(), 100); // Fully healed

    Potion largePotion(100, "Large Potion");
    mc.heal(-20); // Simulate health loss
    largePotion.healCharacter(mc);
    EXPECT_EQ(mc.getHealth(), 100); // Fully healed, no overheal
}

TEST(MainCharacterTestSuite, testUsePotionSmallInvalid) {
    MainCharacter mc("Theodore", 50, 15, "Fire");
    Potion smallPotion(-20, "Small Potion");

    smallPotion.healCharacter(mc);
    EXPECT_FALSE(mc.getHealth()) << "ERROR: Small potion is negative in value";
}


TEST(MainCharacterTestSuite, testUsePotionBig) {
    MainCharacter mc("Theodore", 50, 15, "Fire");
    Potion bigPotion(-50, "Big Potion");

    bigPotion.healCharacter(mc);
    EXPECT_EQ(mc.getHealth(), 100); // Fully healed

    Potion largePotion(100, "Big Potion");
    mc.heal(-20); // Simulate health loss
    largePotion.healCharacter(mc);
    EXPECT_EQ(mc.getHealth(), 100); // Fully healed, no overheal
}

TEST(MainCharacterTestSuite, testUsePotionBigInvalid) {
    MainCharacter mc("Theodore", 50, 15, "Fire");
    Potion bigPotion(-50, "Big Potion");

    bigPotion.healCharacter(mc);
    EXPECT_FALSE(mc.getHealth()) << "ERROR: Big potion is negative in value";
}


// Test: Invalid position (negative health recovery)
TEST(MainCharacterTestSuite, InvalidHealing) {
    MainCharacter mc("Theodore", 100, 15, "Fire");
    mc.heal(-10); // Invalid negative healing
    EXPECT_EQ(mc.getHealth(), 100); // No change
}

