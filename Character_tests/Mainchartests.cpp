#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MainCharacter.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::Mock;
using ::testing::InSequence;
using ::testing::Ref;

class MockMainChararacter : public MainCharacter{
    public:
    MockMainCharacter(const string &name, double health, double attackStrength, const string &allegiance)
        : MainCharacter(name, health, attackStrength, allegiance) {}
    MOCK_METHOD(void, attack, (Character &opponent), (override));
    MOCK_METHOD(void, WitchInteraction, (), (override));
    MOCK_METHOD(double, getHealth, (), (const, override));
    MOCK_METHOD(bool, isalive, (), (const, override));
    MOCK_METHOD(void, damage, (double), (override));
    MOCK_METHOD(void, takeDamage, (double), (override));
    MOCK_METHOD(void, attack, (Character&), (override));
    MOCK_METHOD(CharType, getType, (), (override));

};

TEST(MainCharacter, attack){
    MockMainChar mockMainChar;
    MockCharacter mockChar;
    InSequence seq;
    EXPECT_CALL(mockMainChar, attack(Ref(mockChar))).Times(1);
    mockMainChar.attack(mockChar);
}