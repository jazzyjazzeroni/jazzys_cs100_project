#include "gtest/gtest.h"
#include "../addit_header/Swords.h"

TEST(SwordsTestSuite, testDefaultSwordConstructor){
    Sword sword_test;
    EXPECT_EQ(sword_test.getType(), " ");
    EXPECT_EQ(sword_test.getPower(), 0);
    EXPECT_EQ(sword_test.getName(), " ");
};

TEST(SwordsTestSuite, testOverloadedSwordConstructor){
    Sword sword_test(50, "Small Sword");
    sword_test.setPower(50);
    EXPECT_EQ(sword_test.getPower(), 50);
};

TEST(SwordsTestSuite, testInvalidSwordPowerParameters) {
    Sword sword_test;
    sword_test.setPower(-20);
    EXPECT_EQ(sword_test.getPower(), 0);
};

TEST(SwordsTestSuite, testSwordGetName){
    Sword sword_test;
    EXPECT_EQ(sword_test.getName(), "");
};

TEST(SwordsTestSuite, testSwordSetName) {
    Sword sword_test;
    sword_test.setName("Large Sword");
    EXPECT_EQ(sword_test.getName(), "Lame Sword");
};

TEST(SwordsTestSuite, testSwordNameParametersInvalid) {
    Sword sword_test;
    sword_test.setName("No Sword");
    EXPECT_EQ(sword_test.getName(), "");
};

TEST(SwordsTestSuite, SwordFullConstructorGetName) {
    Sword sword_test (50, "Large Sword");
    EXPECT_EQ(sword_test.getName(), "Large Sword");
};

TEST(SwordsTestSuite, SwordFullConstructorSetName){
    Sword sword_test(50, "Large Sword");
    sword_test.setName("Large Sword");
    EXPECT_EQ(sword_test.getName(), "Large Sword");
};

TEST(SwordsTestSuite, SwordFullConstructorGetPower){
    Sword sword_test(50, "Small Sword");
    EXPECT_EQ(sword_test.getPower(), 50);
};

TEST(SwordsTestSuite, SwordFullConstructorSetPower){
    Sword sword_test(50, "Small Sword");
    sword_test.setPower(100);
    EXPECT_EQ(sword_test.getPower(), 100);
};

