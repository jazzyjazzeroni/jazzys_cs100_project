#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Character.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::Mock;
using ::testing::InSequence;

class MockCharacter : public Character{
    public:
    MockCharacter()
        : Character(MAINCHAR, "MockCharacter", 200.0, 10.0) {}
    MOCK_METHOD(void, setHealth, (double), (override));
    MOCK_METHOD(double, getHealth, (), (const, override));
    MOCK_METHOD(bool, isalive, (), (const, override));
    MOCK_METHOD(void, damage, (double), (override));
    MOCK_METHOD(void, takeDamage, (double), (override));
    MOCK_METHOD(void, attack, (Character&), (override));
    MOCK_METHOD(CharType, getType, (), (override));

};

//start health tests
TEST(Charactertest, TestobtainingHealth){
MockCharacter _char;
EXPECT_EQ(_char.getHealth(), 90.0);
 _char.setHealth(140.0);
 EXPECT_EQ(_char.getHealth(), 140.0); 
};

TEST(Charactertest, TestdefaultHealth){
MockCharacter _char;
 EXPECT_CALL(_char, getHealth())
    .WillOnce(Return(200.0));
    EXPECT_DOUBLE_EQ(_char.getHealth(), 200.0); 
};

TEST(Charactertest, TestSETValidHealth){
MockCharacter _char;
 EXPECT_CALL(_char, setHealth(70.0))
    .Times(1);
    EXPECT_DOUBLE_EQ(_char.getHealth(), 70.0); 
};

TEST(Charactertest, invalidNegHealthTest){
MockCharacter _char;
 EXPECT_CALL(_char, setHealth(-30.0))
    .Times(1);
EXPECT_CALL(_char, getHealth())
.WillOnce(Return(0.0));
    EXPECT_DOUBLE_EQ(_char.getHealth(), 0.0); 
};

TEST(Charactertest, MaxHealthTest){
MockCharacter _char;
 EXPECT_CALL(_char, setHealth(300.0))
    .Times(1);
EXPECT_CALL(_char, getHealth())
.WillOnce(Return(MAX_HEALTH));
_char.setHealth(250.0);
EXPECT_DOUBLE_EQ(_char.getHealth(), MAX_HEALTH); 
};

TEST(Charactertest, HealthAfterdamageTest){
MockCharacter _char;
 EXPECT_CALL(_char, setHealth(200.0))
    .Times(1);
EXPECT_CALL(_char, damage(20.0))
    .Times(1);
EXPECT_CALL(_char, getHealth())
.WillOnce(Return(180.0));
_char.setHealth(200.0);
_char.damage(20.0);
    EXPECT_DOUBLE_EQ(_char.getHealth(), 180.0); 
};

TEST(Charactertest, HealthwithAliveTest){
MockCharacter _char;
 EXPECT_CALL(_char, setHealth(200.0))
    .Times(1);
EXPECT_CALL(_char, isalive())
    .WillOnce(Return(true));
_char.setHealth(200.0);
EXPECT_TRUE(_char.isalive());
EXPECT_CALL(_char, setHealth(0.0))
    .Times(1);
EXPECT_CALL(_char, isalive())
    .WillOnce(Return(false));
    _char.setHealth(0.0);
    EXPECT_FALSE(_char.isalive()); 
};

//end health tests

//start alive testss
TEST(Charactertest, CharAlive){
MockCharacter _char;
EXPECT_CALL(_char, isalive())
    .WillOnce(Return(true));
EXPECT_TRUE(_char.isalive());
};

TEST(Charactertest, CharNotAlive){
MockCharacter _char;
EXPECT_CALL(_char, getHealth())
.WillOnce(Return(0.0));
EXPECT_CALL(_char, isalive())
    .WillOnce(Return(false));
EXPECT_FALSE(_char.isalive());
};

TEST(Charactertest, CharAlivelittleHealth){
MockCharacter _char;
EXPECT_CALL(_char, getHealth())
.WillOnce(Return(0.1));
EXPECT_CALL(_char, isalive())
    .WillOnce(Return(true));
EXPECT_TRUE(_char.isalive());
};

TEST(Charactertest, CharAliveafterDam){
MockCharacter _char;
EXPECT_CALL(_char, damage(20.0));
EXPECT_CALL(_char, getHealth())
    .WillOnce(Return(180.0));
EXPECT_CALL(_char, isalive())
    .WillOnce(Return(true));
_char.damage(20.0);
EXPECT_DOUBLE_EQ(_char.getHealth(), 180.0);
EXPECT_TRUE(_char.isalive());
};

TEST(Charactertest, CharNotAliveafterDam){
MockCharacter _char;
EXPECT_CALL(_char, damage(300.0));
EXPECT_CALL(_char, getHealth())
    .WillOnce(Return(0.0));
EXPECT_CALL(_char, isalive())
    .WillOnce(Return(false));
_char.damage(300.0);
EXPECT_DOUBLE_EQ(_char.getHealth(), 0.0);
EXPECT_FALSE(_char.isalive());
};

//end alive tests

//start take damage tests
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

TEST(Charactertest, OverkillDamage) {
    MockCharacter _char;
    _char.setHealth(50.0);
    EXPECT_CALL(_char, damage(100.0));
    EXPECT_CALL(_char, getHealth())
        .WillOnce(Return(0.0));
    _char.damage(100.0);
    EXPECT_DOUBLE_EQ(_char.getHealth(), 0.0);
};
//end take damage tests

//start damage tests
TEST(Charactertest, OpptakesZeroDamage){
MockCharacter _char;
MockCharacter opp;
EXPECT_CALL(opp, getHealth())
        .WillOnce(Return(150.0));
    EXPECT_CALL(opp, setHealth(150.0))
        .Times(1);
    _char.damage(0.0);
    opp.setHealth(150.0);
    EXPECT_DOUBLE_EQ(opp.getHealth(), 150.0);
};

TEST(Charactertest, OpptakesFullDamage){
MockCharacter _char;
MockCharacter opp;
EXPECT_CALL(opp, getHealth())
        .WillOnce(Return(150.0));
    EXPECT_CALL(opp, setHealth(0.0))
        .Times(1);
    _char.damage(150.0);
    opp.setHealth(0.0);
    EXPECT_DOUBLE_EQ(opp.getHealth(),0.0);
};

TEST(Charactertest, BelowZeroOpptest){
MockCharacter _char;
MockCharacter opp;
EXPECT_CALL(opp, getHealth())
        .WillOnce(Return(10.0));
    EXPECT_CALL(opp, setHealth(0.0))
        .Times(1);
    _char.damage(30.0);
    opp.setHealth(0.0);
    EXPECT_DOUBLE_EQ(opp.getHealth(),0.0);
};

TEST(Charactertest, OpptakesDamage){
MockCharacter _char;
MockCharacter opp;
EXPECT_CALL(opp, getHealth())
        .WillOnce(Return(150.0));
    EXPECT_CALL(opp, setHealth(100.0))
        .Times(1);
    _char.damage(50.0);
    opp.setHealth(100.0);
    EXPECT_DOUBLE_EQ(opp.getHealth(),100.0);
};

TEST(Charactertest, NegativeDamage){
MockCharacter _char;
MockCharacter opp;
EXPECT_CALL(opp, getHealth())
        .WillOnce(Return(150.0));
    EXPECT_CALL(opp, setHealth(150.0))
        .Times(1);
    _char.damage(-50.0);
    opp.setHealth(150.0);
    EXPECT_DOUBLE_EQ(opp.getHealth(),150.0);
};

TEST(Charactertest, VeryLargeDamage){
MockCharacter _char;
MockCharacter opp;
EXPECT_CALL(opp, getHealth())
        .WillOnce(Return(150.0));
    EXPECT_CALL(opp, setHealth(0.0))
        .Times(1);
    _char.damage(1000.0);
    opp.setHealth(0.0);
    EXPECT_DOUBLE_EQ(opp.getHealth(),0.0);
};

//end damage tests


//start attack tests

TEST(Charactertest, SuccessfulattackOpp){
MockCharacter _char;
MockCharacter opp;
EXPECT_CALL(_char, attack(::testing::Ref(opp)))
        .Times(1);
    EXPECT_CALL(opp, takeDamage(40.0))
        .Times(1);
    _char.attack(opp);
};

TEST(Charactertest, SuccessfullattackEnemy){
MockCharacter _char;
MockCharacter opp;
EXPECT_CALL(_char, getType())
        .WillOnce(Return(MAINCHAR));
    EXPECT_CALL(opp, getType())
        .WillOnce(Return(GOBLIN));
        if (_char.getType() != opp.getType()) {
        EXPECT_CALL(opp, takeDamage(testing::_))
            .Times(1); 
    }
    _char.attack(opp);
};

TEST(Charactertest, testAlly){
MockCharacter _char;
MockCharacter ally;
EXPECT_CALL(_char, getType())
        .WillOnce(Return(MAINCHAR));
    EXPECT_CALL(ally, getType())
        .WillOnce(Return(NPC));
        EXPECT_CALL(ally, takeDamage(testing::_))
        .Times(0); 
    _char.attack(ally);
};



//end attack tests