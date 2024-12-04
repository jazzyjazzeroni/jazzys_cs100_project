#include <gtest/gtest.h>
#include "../Character_header/Character.h"

// Define test fixture for Character class
class CharacterTest : public ::testing::Test {
protected:
    Character *mainChar;
    Character *goblin;

    void TearDown() override {
        delete mainChar;
        delete goblin;
    }
};

// Test charTypeToString()
TEST(CharacterTest, CharTypeToString) {
    EXPECT_EQ(mainChar->getType(), "Theodore");
    EXPECT_EQ(goblin->getType(), "Goblin");
}

// Test getHealth()
TEST(CharacterTest, GetHealth) {
    EXPECT_EQ(mainChar->getHealth(), 100);
    EXPECT_EQ(goblin->getHealth(), 50);
}

// Test setHealth()
TEST(CharacterTest, SetHealth) {
    mainChar->setHealth(80);
    EXPECT_EQ(mainChar->getHealth(), 80);

    mainChar->setHealth(120); // Above MAX_HEALTH
    EXPECT_EQ(mainChar->getHealth(), MAX_HEALTH);

    mainChar->setHealth(-10); // Negative health
    EXPECT_EQ(mainChar->getHealth(), 0);
}

// Test isalive()
TEST(CharacterTest, IsAlive) {
    EXPECT_TRUE(mainChar->isalive());
    mainChar->setHealth(0);
    EXPECT_FALSE(mainChar->isalive());
}

// Test receiveDamage()
TEST(CharacterTest, ReceiveDamage) {
    goblin->receiveDamage(20);
    EXPECT_EQ(goblin->getHealth(), 30);

    goblin->receiveDamage(40); // More than remaining health
    EXPECT_EQ(goblin->getHealth(), 0);
}

// Test attack()
TEST(CharacterTest, Attack) {
    mainChar->attack(*goblin);
    EXPECT_EQ(goblin->getHealth(), 30);

    mainChar->attack(*goblin);
    mainChar->attack(*goblin); // Goblin should now be at 0 health
    EXPECT_EQ(goblin->getHealth(), 0);
    EXPECT_FALSE(goblin->isalive());
}

// Test getPower()
TEST(CharacterTest, GetPower) {
    EXPECT_EQ(mainChar->getPower(), "Fire");
    EXPECT_EQ(goblin->getPower(), "Earth");
}
TEST(CharacterTest, ZeroHealthInitialization) {
    Character deadChar(MAINCHAR, "DeadCharacter", 0, 15, "Dark");
    EXPECT_EQ(deadChar.getHealth(), 0);
    EXPECT_FALSE(deadChar.isalive());
}

// Test setHealth with zero
TEST(CharacterTest, SetHealthToZero) {
    goblin->setHealth(0);
    EXPECT_EQ(goblin->getHealth(), 0);
    EXPECT_FALSE(goblin->isalive());
}

// Test negative health initialization
TEST(CharacterTest, NegativeHealthInitialization) {
    Character woundedChar(GOBLIN, "WoundedGoblin", -10, 15, "Earth");
    EXPECT_EQ(woundedChar.getHealth(), 0); // Should be corrected to 0
    EXPECT_FALSE(woundedChar.isalive());
}

// Test overkill damage
TEST(CharacterTest, OverkillDamage) {
    goblin->receiveDamage(100); // Damage exceeds current health
    EXPECT_EQ(goblin->getHealth(), 0);
    EXPECT_FALSE(goblin->isalive());
}

// Test attack on a dead character
TEST(CharacterTest, AttackDeadCharacter) {
    goblin->setHealth(0); // Goblin is dead
    mainChar->attack(*goblin); // Should not change goblin's health
    EXPECT_EQ(goblin->getHealth(), 0);
    EXPECT_FALSE(goblin->isalive());
}

// Test self-attack
TEST(CharacterTest, SelfAttack) {
    mainChar->attack(*mainChar);
    EXPECT_EQ(mainChar->getHealth(), 80); // Health reduced by attack amount
    EXPECT_TRUE(mainChar->isalive());
}

// Test extreme health values
TEST(CharacterTest, SetExtremeHealthValues) {
    mainChar->setHealth(9999); // Set health to a value much larger than MAX_HEALTH
    EXPECT_EQ(mainChar->getHealth(), MAX_HEALTH);

    mainChar->setHealth(-9999); // Set health to a value much less than 0
    EXPECT_EQ(mainChar->getHealth(), 0);
}

// Test minimal non-zero damage
TEST(CharacterTest, MinimalNonZeroDamage) {
    goblin->receiveDamage(1); // Minimal non-zero damage
    EXPECT_EQ(goblin->getHealth(), 49);
    EXPECT_TRUE(goblin->isalive());
}

// Test attack with zero damage
TEST(CharacterTest, ZeroDamageAttack) {
    Character weakChar(MAINCHAR, "WeakTheodore", 100, 0, "Fire");
    weakChar.attack(*goblin); // Should not reduce goblin's health
    EXPECT_EQ(goblin->getHealth(), 50);
    EXPECT_TRUE(goblin->isalive());
}

// Test simultaneous death in battle
TEST(CharacterTest, SimultaneousDeath) {
    mainChar->setHealth(20); // Reduce health so both characters can die in one attack
    goblin->attack(*mainChar);
    mainChar->attack(*goblin);

    EXPECT_EQ(mainChar->getHealth(), 0);
    EXPECT_FALSE(mainChar->isalive());

    EXPECT_EQ(goblin->getHealth(), 0);
    EXPECT_FALSE(goblin->isalive());
}

// Test multiple consecutive attacks
TEST(CharacterTest, MultipleConsecutiveAttacks) {
    for (int i = 0; i < 3; ++i) {
        mainChar->attack(*goblin);
    }
    EXPECT_EQ(goblin->getHealth(), 0);
    EXPECT_FALSE(goblin->isalive());
}

// Test attack when attacker is dead
TEST(CharacterTest, DeadCharacterAttack) {
    mainChar->setHealth(0); // Attacker is dead
    mainChar->attack(*goblin);
    EXPECT_EQ(goblin->getHealth(), 50); // Goblin's health remains unchanged
    EXPECT_TRUE(goblin->isalive());
}