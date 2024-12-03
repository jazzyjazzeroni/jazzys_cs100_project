#include "gtest/gtest.h"
#include "../Character_header/Character.h"
#include "../addit_header/Object.h"

TEST(CharacterTest, TestCharacterInitialization) {
    Character character(MAINCHAR, "TestCharacter", 100, 10, 5);

    // Test the initial health, attack amount, and type
    EXPECT_EQ(character.getHealth(), 100);
    EXPECT_EQ(character.getType(), MAINCHAR);
}

// Test Case 2: Test setting health to a valid value
TEST(CharacterTest, TestSetHealthValid) {
    Character character(MAINCHAR, "TestCharacter", 100, 10, 5);

    character.setHealth(50);
    EXPECT_EQ(character.getHealth(), 50);
}

// Test Case 3: Test setting health to a value greater than MAX_HEALTH
TEST(CharacterTest, TestSetHealthAboveMax) {
    Character character(MAINCHAR, "TestCharacter", 100, 10, 5);

    character.setHealth(200);  // Assuming MAX_HEALTH is 100
    EXPECT_EQ(character.getHealth(), MAX_HEALTH);
}

// Test Case 4: Test setting health to a value less than or equal to zero
TEST(CharacterTest, TestSetHealthBelowZero) {
    Character character(MAINCHAR, "TestCharacter", 100, 10, 5);

    character.setHealth(-10);
    EXPECT_EQ(character.getHealth(), 0);  // Health should not be negative
}

// Test Case 5: Test isAlive when health is greater than zero
TEST(CharacterTest, TestIsAlive) {
    Character character(MAINCHAR, "TestCharacter", 100, 10, 5);

    EXPECT_TRUE(character.isalive());  // Should be alive with positive health
}

// Test Case 6: Test isAlive when health is zero
TEST(CharacterTest, TestIsAliveWhenDead) {
    Character character(MAINCHAR, "TestCharacter", 0, 10, 5);

    EXPECT_FALSE(character.isalive());  // Should be dead with zero health
}

// Test Case 7: Test dealtDamage function
TEST(CharacterTest, TestDealtDamage) {
    Character character(MAINCHAR, "TestCharacter", 100, 10, 5);

    character.dealtDamage(30);
    EXPECT_EQ(character.getHealth(), 70);  // Health should decrease by 30
}

// Test Case 8: Test dealtDamage with overkill (damage more than current health)
TEST(CharacterTest, TestDealtDamageOverkill) {
    Character character(MAINCHAR, "TestCharacter", 50, 10, 5);

    character.dealtDamage(100);
    EXPECT_EQ(character.getHealth(), 0);  // Health should not go below 0
}

// Test Case 9: Test receiveDamage function, which indirectly tests dealtDamage
TEST(CharacterTest, TestReceiveDamage) {
    Character character(MAINCHAR, "TestCharacter", 100, 10, 5);

    character.recieveDamage(20);
    EXPECT_EQ(character.getHealth(), 80);  // Health should decrease by 20
}

// Test Case 10: Test attack function with a living enemy
TEST(CharacterTest, TestAttackAliveEnemy) {
    Character attacker(MAINCHAR, "Attacker", 100, 20, 5);
    Character defender(MAINCHAR, "Defender", 100, 10, 5);

    attacker.attack(defender);
    EXPECT_EQ(defender.getHealth(), 80);  // Defender should lose health (attacker's attackAmount)
}

// Test Case 11: Test attack function on a dead enemy
TEST(CharacterTest, TestAttackDeadEnemy) {
    Character attacker(MAINCHAR, "Attacker", 100, 20, 5);
    Character defender(MAINCHAR, "Defender", 0, 10, 5);  // Defender is dead

    attacker.attack(defender);
    EXPECT_EQ(defender.getHealth(), 0);  // Defender should remain dead
}

// Test Case 12: Test health is correctly printed in receiveDamage
TEST(CharacterTest, TestHealthPrintInReceiveDamage) {
    // Test if health status message is printed correctly (requires capturing stdout)
    // We may use a redirect of std::cout if necessary, but this is generally
    // outside the unit test scope.
    testing::internal::CaptureStdout();
    Character character(MAINCHAR, "TestCharacter", 100, 10, 5);
    character.recieveDamage(30);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Health Status: 70") != std::string::npos);  // Check if health status is printed
}

