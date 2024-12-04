#include <gtest/gtest.h>
#include "../Levels/Levels.cpp"

// Test fixture
class LevelsTest : public ::testing::Test {
protected:
    bool isOver = false;
    Level defaultLevel;
    Level customLevel;

    void SetUp() override {
        std::vector<std::vector<int>> map = {
            {0, 1, 0},
            {1, 0, 2},
            {0, 2, 0}
        };
        customLevel = Level(10, map, 2, isOver);
    }
};

// Test default constructor
TEST_F(LevelsTest, DefaultConstructorInitialization) {
    EXPECT_EQ(defaultLevel.getCurrentLevel(), 1);
    EXPECT_THROW(defaultLevel.getElementForLevel(5), std::out_of_range);
}

// Test parameterized constructor
TEST_F(LevelsTest, ParameterizedConstructorInitialization) {
    EXPECT_EQ(customLevel.getCurrentLevel(), 1);
    EXPECT_EQ(customLevel.getElementForLevel(2), FIRE);
}

// Test setLevel
TEST_F(LevelsTest, SetLevel) {
    customLevel.setLevel(2);
    EXPECT_EQ(customLevel.getCurrentLevel(), 2);

    EXPECT_THROW(customLevel.setLevel(0), std::invalid_argument);
    EXPECT_THROW(customLevel.setLevel(10), std::invalid_argument);
}

// Test element retrieval
TEST_F(LevelsTest, GetElementForLevel) {
    EXPECT_EQ(customLevel.getElementForLevel(1), WATER);
    EXPECT_THROW(customLevel.getElementForLevel(10), std::out_of_range);
}

// Test takeAction with valid inputs
TEST_F(LevelsTest, TakeActionValidInputs) {
    std::istringstream input("i\nq\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect std::cin

    customLevel.takeAction(); // Use inventory
    EXPECT_FALSE(isOver);

    customLevel.takeAction(); // Quit
    EXPECT_TRUE(isOver);
}

// Test character movement at edges
TEST_F(LevelsTest, MainCharacterMovement) {
    MainCharacter character("Hero", 100, 10, "Fire");

    auto pos = character.move('w', 3, 3); // Wrap around up
    EXPECT_EQ(pos, std::make_pair(0, 2));

    pos = character.move('s', 3, 3); // Wrap around down
    EXPECT_EQ(pos, std::make_pair(0, 0));
}

// Test interaction with objects
TEST_F(LevelsTest, ObjectInteractions) {
    Object sword("Sword", 10);
    Object potion("Potion", 5);

    EXPECT_EQ(sword.getType(), "Sword");
    EXPECT_EQ(potion.getValue(), 5);

    MainCharacter character("Hero", 100, 10, "Fire");
    character.equipSword(sword);
    EXPECT_EQ(character.getAttack(), 20); // Assuming sword adds 10 attack
}

// Test invalid actions
TEST_F(LevelsTest, InvalidAction) {
    std::istringstream input("x\n");
    std::cin.rdbuf(input.rdbuf());

    customLevel.takeAction(); // Invalid action
    EXPECT_FALSE(isOver);
}
