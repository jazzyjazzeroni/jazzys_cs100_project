#include <gtest/gtest.h>
#include "../Character_header/MainCharacter.h"
#include "../addit_header/Swords.h"
#include "../Character_header/Goblin.h"
#include "../addit_header/Potions.h"

// Test: Constructor Initialization
TEST(MainCharacterTest, ConstructorInitialization) {
    MainCharacter mc("Hero", 100, 15, "Fire");

    EXPECT_EQ(mc.getHealth(), 100);
    EXPECT_EQ(mc.getPosition(), std::make_pair(0, 0)); // Default position
    EXPECT_EQ(mc.getType(), "Theodore");
}

// Test: Movement at boundaries (edge cases)
TEST(MainCharacterTest, MovementBoundaries) {
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

// Test: Healing (normal and edge cases)
TEST(MainCharacterTest, Healing) {
    MainCharacter mc("Hero", 90, 15, "Fire");
    mc.heal(15); // Normal heal
    EXPECT_EQ(mc.getHealth(), 100);

    mc.heal(10); // Overheal test
    EXPECT_EQ(mc.getHealth(), 100);

    MainCharacter lowHealthMc("Hero", 1, 15, "Water");
    lowHealthMc.heal(5); // Low health heal
    EXPECT_EQ(lowHealthMc.getHealth(), 6);
}

// Test: Equipping a sword
TEST(MainCharacterTest, EquipSword) {
    MainCharacter mc("Hero", 100, 15, "Fire");
    Sword basicSword(10, "Basic Sword");

    mc.equipSword(basicSword);

    EXPECT_EQ(mc.getType(), "Theodore");
    EXPECT_NO_THROW(mc.equipSword(Sword(15, "Greater Sword")));
}

// Test: Attacking a Goblin
TEST(MainCharacterTest, AttackGoblin) {
    MainCharacter mc("Hero", 100, 15, "Fire");
    Goblin goblin("Enemy Goblin", 50, 10, "Water");

    mc.attack(goblin);
    EXPECT_LT(goblin.getHealth(), 50); // Goblin should lose health
    EXPECT_TRUE(goblin.isalive()); // Goblin is still alive

    mc.attack(goblin); // Continue attacking
    EXPECT_FALSE(goblin.isalive()); // Goblin is defeated
}

// Test: Attacking with Elemental Mismatch
TEST(MainCharacterTest, AttackElementMismatch) {
    MainCharacter mc("Hero", 100, 15, "Fire");
    Goblin goblin("Enemy Goblin", 50, 10, "Fire"); // Same element

    mc.attack(goblin); // Should result in no damage
    EXPECT_EQ(goblin.getHealth(), 50); // Health should remain the same
}

// Test: Using a potion
TEST(MainCharacterTest, UsePotion) {
    MainCharacter mc("Hero", 50, 15, "Fire");
    Potion smallPotion(50, "Small Potion");

    smallPotion.healCharacter(mc);
    EXPECT_EQ(mc.getHealth(), 100); // Fully healed

    Potion largePotion(100, "Large Potion");
    mc.heal(-20); // Simulate health loss
    largePotion.healCharacter(mc);
    EXPECT_EQ(mc.getHealth(), 100); // Fully healed, no overheal
}

// Test: Invalid position (negative health recovery)
TEST(MainCharacterTest, InvalidHealing) {
    MainCharacter mc("Hero", 100, 15, "Fire");
    mc.heal(-10); // Invalid negative healing
    EXPECT_EQ(mc.getHealth(), 100); // No change
}

// Test: Circular movement
TEST(MainCharacterTest, CircularMovement) {
    MainCharacter mc(0, 0);
    int width = 10, height = 10;

    for (int i = 0; i < 11; ++i) {
        mc.move('d', height, width); // Move right in a loop
    }
    EXPECT_EQ(mc.getPosition(), std::make_pair(1, 0));
}
