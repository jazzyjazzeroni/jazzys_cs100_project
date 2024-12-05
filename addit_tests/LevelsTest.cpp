#include <gtest/gtest.h>
#include "../addit_header/GameMap.h"
#include "../addit_header/Level.h"
#include "../addit_header/Swords.h"
#include "../addit_header/Inventory.h"

class LevelTestSuite : public ::testing::Test {
protected:
    bool isOver = false;
    Level initialLevel;
    Level level;

    void SetUp() override {
        std::vector<std::vector<int>> map = {
            {0, 1, 0},
            {1, 0, 2},
            {0, 2, 0}
        };
        level = Level(10, map, 2, isOver);
    }
};

TEST_F(LevelTestSuite, testDefaultConstructor) {
    EXPECT_EQ(initialLevel.getCurrentLevel(), 1);
    EXPECT_THROW(initialLevel.getElementForLevel(5), std::out_of_range);
}

TEST_F(LevelTestSuite, testOverloadedConstructor) {
    EXPECT_EQ(level.getCurrentLevel(), 1);
    EXPECT_EQ(level.getElementForLevel(2), FIRE);
}

TEST_F(LevelTestSuite, testSetLevelValid) {
    level.setLevel(2);
    EXPECT_EQ(level.getCurrentLevel(), 2);

    EXPECT_THROW(level.setLevel(0), std::invalid_argument);
    EXPECT_THROW(level.setLevel(10), std::invalid_argument);
}

// Test element retrieval
TEST_F(LevelTestSuite, testGetElementLevel) {
    EXPECT_EQ(level.getElementForLevel(1), AIR);
    EXPECT_THROW(level.getElementForLevel(10), std::out_of_range);
}

// Test takeAction with valid inputs
TEST_F(LevelTestSuite, testTakeActionInventoryChoiceValid) {
    std::istringstream input("i\nq\n");
    std::cin.rdbuf(input.rdbuf());  // Saw this on stack overflow to test cin test fixturess

    level.takeAction(); // Use inventory
    EXPECT_FALSE(isOver);

    level.takeAction(); // Quit
    EXPECT_TRUE(isOver);
}

TEST_F(LevelTestSuite, testTakeActionInventoryChoiceInvalid) {
    std::istringstream input("i\n");
    std::cin.rdbuf(input.rdbuf()); // Saw this on stack overflow to test cin test fixtures

    level.takeAction(); // Use inventory
    EXPECT_FALSE(isOver);   // uses quit action instead of inventory action
}


// Test character movement at edges
TEST_F(LevelTestSuite, testKeyboardMovementsAtEndOfMap) {
    MainCharacter character("Theodore", 100, 10, "Water");

    auto pos = character.move('w', 3, 3); // Wrap around up
    EXPECT_EQ(pos, std::make_pair(0, 2));

    pos = character.move('s', 3, 3); // Wrap around down
    EXPECT_EQ(pos, std::make_pair(0, 0));
}

// Test interaction with objects
TEST_F(LevelTestSuite, testInventoryObjectsValid) {
    Object sword("Sword", 10);
    Object potion("Potion", 5);

    EXPECT_EQ(sword.getType(), "Sword");
    EXPECT_EQ(potion.getValue(), 5);
}

TEST_F(LevelTestSuite, testInventoryObjectsInvalid) {
    Object sword("Sword", -10);
    Object potion("Potion", -5);

    ASSERT_EQ(sword.getType(), "Sword") << "INVALID: Sword cannot be negative";
    ASSERT_EQ(potion.getValue(), -5) << "INVALID: Potion cannot be negative";

}