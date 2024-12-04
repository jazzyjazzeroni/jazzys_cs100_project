#include <gtest/gtest.h>
#include "../Character_header/Goblin.h"

class MockPlayer : public Character {
public:
    MockPlayer(const string &name, int health)
        : Character(MAINCHAR, name, health, 0, 0) {}

    void attack(Character &) override {
        // Mock attack implementation
    }
};

TEST(GoblinTest, ConstructorInitializesProperly) {
    Goblin goblin("GOBLIN", 100, 20, 5, "AIR");
    EXPECT_EQ(goblin.getHealth(), 100);
    EXPECT_EQ(goblin.isalive(), true);
}

TEST(GoblinTest, HealthManipulation) {
    Goblin goblin("GOBLIN", 100, 20, 5, "AIR");
    goblin.setHealth(80);
    EXPECT_EQ(goblin.getHealth(), 80);

    goblin.recieveDamage(30);
    EXPECT_EQ(goblin.getHealth(), 50);

    goblin.recieveDamage(60);
    EXPECT_EQ(goblin.getHealth(), -10);
    EXPECT_FALSE(goblin.isalive());
}

TEST(GoblinTest, AttackDecreasesHealthOfOpponent) {
    Goblin goblin("GOBLIN", 100, 20, 5, "AIR");
    MockPlayer player("Theodore", 150);

    goblin.attack(player);
    EXPECT_EQ(player.getHealth(), 130); // Assuming attackAmount is set to 20
}

TEST(GoblinTest, DealtDamageChangesAttackAmount) {
    Goblin goblin("GOBLIN", 100, 20, 5, "AIR");

    goblin.dealtDamage(40);
    MockPlayer player("Theodore", 150);

    goblin.attack(player);
    EXPECT_EQ(player.getHealth(), 110); // Assuming attackAmount is updated to 40
}

TEST(GoblinTest, NegativeHealthInitialization) {
    Goblin goblin("GOBLIN", -50, 20, 5, "AIR");
    EXPECT_EQ(goblin.getHealth(), -50);
    EXPECT_FALSE(goblin.isalive());
}

TEST(GoblinTest, NegativeDamageInReceiveDamage) {
    Goblin goblin("GOBLIN", 100, 20, 5, "AIR");
    goblin.recieveDamage(-30);
    EXPECT_EQ(goblin.getHealth(), 130); // If health increases with negative damage
}

TEST(GoblinTest, NegativeAttackDamage) {
    Goblin goblin("GOBLIN", 100, 20, 5, "AIR");
    MockPlayer player("Hero", 150);

    goblin.dealtDamage(-10);
    goblin.attack(player);

    EXPECT_EQ(player.getHealth(), 150); // Assuming negative attack damage does nothing
}

TEST(GoblinTest, NegativeHealthUpdate) {
    Goblin goblin("GOBLIN", 100, 20, 5, "AIR");

    goblin.setHealth(-100);
    EXPECT_EQ(goblin.getHealth(), -100);
    EXPECT_FALSE(goblin.isalive());
}

