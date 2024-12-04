#include <gtest/gtest.h>
#include "../Character_header/Character.h"
#include "../Character_header/Goblin.h"
#include "../Character_header/MainCharacter.h"

// Constants for testing
const int MAX_HEALTH = 100;

// Test fixture for the Character class
class CharacterTest : public ::testing::Test {
protected:
    Goblin goblin{"Goblin", 50, 10, "Fire"};
    MainCharacter mainCharacter{"Theodore", 100, 20, "Water"};
};

// Test Constructor Initialization
TEST_F(CharacterTest, ConstructorInitialization) {
    EXPECT_EQ(goblin.getHealth(), 50);
    EXPECT_EQ(goblin.getType(), "Goblin");
    EXPECT_EQ(mainCharacter.getHealth(), 100);
    EXPECT_EQ(mainCharacter.getType(), "Theodore");
}

// Test setHealth with edge cases
TEST_F(CharacterTest, SetHealthEdgeCases) {
    goblin.setHealth(200); // Beyond max health
    EXPECT_EQ(goblin.getHealth(), MAX_HEALTH);

    goblin.setHealth(-10); // Negative health
    EXPECT_EQ(goblin.getHealth(), 0);

    mainCharacter.setHealth(80); // Within valid range
    EXPECT_EQ(mainCharacter.getHealth(), 80);
}

// Test receiveDamage with edge cases
TEST_F(CharacterTest, ReceiveDamageEdgeCases) {
    goblin.receiveDamage(20); // Regular damage
    EXPECT_EQ(goblin.getHealth(), 30);

    goblin.receiveDamage(40); // Damage greater than current health
    EXPECT_EQ(goblin.getHealth(), 0);

    goblin.receiveDamage(-10); // Negative damage
    EXPECT_EQ(goblin.getHealth(), 0); // Health should not change
}

// Test isalive method
TEST_F(CharacterTest, IsAlive) {
    EXPECT_TRUE(goblin.isalive());

    goblin.setHealth(0);
    EXPECT_FALSE(goblin.isalive());
}

// Test attack method
TEST_F(CharacterTest, Attack) {
    goblin.attack(mainCharacter);
    EXPECT_EQ(mainCharacter.getHealth(), 90); // Goblin does 10 damage

    mainCharacter.attack(goblin);
    EXPECT_EQ(goblin.getHealth(), 10); // MainCharacter does 20 damage
}

// Test character defeated scenario
TEST_F(CharacterTest, AttackDefeatedCharacter) {
    goblin.setHealth(0);
    EXPECT_FALSE(goblin.isalive());

    // Attempt to attack a defeated Goblin
    mainCharacter.attack(goblin);
    EXPECT_EQ(goblin.getHealth(), 0); // Health should remain 0
}

// Test heal method (MainCharacter specific)
TEST_F(CharacterTest, Heal) {
    mainCharacter.receiveDamage(50); // Reduce health to 50
    EXPECT_EQ(mainCharacter.getHealth(), 50);

    mainCharacter.heal(30); // Heal by 30
    EXPECT_EQ(mainCharacter.getHealth(), 80);

    mainCharacter.heal(50); // Heal exceeding max health
    EXPECT_EQ(mainCharacter.getHealth(), MAX_HEALTH);
}

// Test move method (MainCharacter specific)
TEST_F(CharacterTest, Movement) {
    auto position = mainCharacter.move('w', 10, 10); // Move up
    EXPECT_EQ(position, std::make_pair(0, 9));

    position = mainCharacter.move('s', 10, 10); // Move down
    EXPECT_EQ(position, std::make_pair(0, 0));

    position = mainCharacter.move('a', 10, 10); // Move left
    EXPECT_EQ(position, std::make_pair(9, 0));

    position = mainCharacter.move('d', 10, 10); // Move right
    EXPECT_EQ(position, std::make_pair(0, 0));
}

// Test invalid power type for Goblin
TEST(CharacterEdgeCases, InvalidPowerType) {
    EXPECT_THROW(Goblin("Goblin", 50, 10, "InvalidType"), std::invalid_argument);
}
