#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Character.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::Mock;

class MockCharacter : public Character{
    public:
    MockCharacter()
        : Character(MAINCHAR, "MockCharacter", 100.0, 10.0) {}
    MOCK_METHOD(void, displayStats, (), (override));
    MOCK_METHOD(void, setHealth, (double), (override));
    MOCK_METHOD(double, getHealth, (), (const, override));
    MOCK_METHOD(bool, isalive, (), (const, override));
    MOCK_METHOD(void, damage, (double), (override));
    MOCK_METHOD(void, takeDamage, (double), (override));
    MOCK_METHOD(void, attack, (Character&), (override));

};

TEST(Charactertest, TestobtainingHealth){
MockCharacter _char;
EXPECT_EQ(_char.getHealth(), 90.0);
 _char.setHealth(140.0);
 EXPECT_EQ(_char.getHealth(), 140.0); 
};

TEST(Charactertest, TestdefaultHealth){
MockCharacter _char;
EXPECT_EQ(_char.getHealth(), 90.0);
 _char.setHealth(140.0);
 EXPECT_EQ(_char.getHealth(), 140.0); 
};




TEST(Charactertest, TakesDamagetimes){
MockCharacter _char;
EXPECT_CALL(_char, damage(40.0))
    .Times(1);
_char.damage(40.0);
};

TEST(Charactertest, TakesDamageNonZero){
MockCharacter _char;
_char.setHealth(15.0);
EXPECT_CALL(_char, damage(40.0))
    .Times(1);
EXPECT_CALL(_char, setHealth(testing::Ge(0)))
    .Times(1);
_char.damage(40.0);
EXPECT_DOUBLE_EQ(_char.getHealth(),0.0);
};

TEST(Charactertest, TakesDamagelowerHealth){
MockCharacter _char;
_char.setHealth(200.0);
EXPECT_CALL(_char, setHealth(testing::_)).Times(1);
EXPECT_CALL(_char, damage(50.0))
    .Times(1);
EXPECT_DOUBLE_EQ(_char.getHealth(), 150.0);
};

TEST(Charactertest, TakesZeroDamage){
MockCharacter _char;
_char.setHealth(200.0);
_char.damage(0.0);
EXPECT_DOUBLE_EQ(_char.getHealth(), 200.0);
};