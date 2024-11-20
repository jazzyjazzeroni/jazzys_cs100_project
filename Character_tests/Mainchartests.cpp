#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MainCharacter.h"
#include "Character_tests.cpp"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::Mock;
using ::testing::InSequence;
using ::testing::Ref;

class MockMainChar : public MainCharacter {
public:
    MockMainChar(const string &name, double health, double attackStrength, const string &allegiance)
        : MainCharacter(name, health, attackStrength, allegiance) {}

    MOCK_METHOD(void, attack, (Character &opponent), (override));
    MOCK_METHOD(void, WitchInteraction, (), (override));
    MOCK_METHOD(char, getMovement, (), (override));
    MOCK_METHOD(void, usePowers, (), (override));
    MOCK_METHOD(const Inventory&, getInventory, (), (const, override));
    MOCK_METHOD(void, usePotion, (), (override));
    MOCK_METHOD(void, equipSword, (), (override));
};

//start attack tests

TEST(MainCharacter, attack) {
    MockMainChar mmc("Hero", 150, 10, "Good");
    MockMainChar mockMainChar2("Jane", 100, 10, "Evil");

    InSequence s;

    EXPECT_CALL(mockMainChar, attack(Ref(mockMainChar2)))
        .Times(1);

    mockMainChar.attack(mockMainChar2);
}

TEST(MainCharacter, SuccessfulAttack) {
    MockMainChar mmc("Hero", 150, 10, "Good");

    MockCharacter enemy;

    EXPECT_CALL(mockMainChar, attack(Ref(mockMainChar2)))
        .Times(1);

    mockMainChar.attack(mockMainChar2);
}

