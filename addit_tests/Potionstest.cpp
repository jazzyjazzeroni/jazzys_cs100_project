#include "gtest/gtest.h"
#include "../addit_header/Potions.h"

TEST(PotionTestSuite, testDefaultPotionConstructor){
    Potion smallPotion;
    EXPECT_EQ(smallPotion.getHealingAmount(), 1);
};

TEST(PotionTestSuite, testOverloadedConstructorInvalidPotion) {
    Potion smallPotion(-1, "Not a Potion");
    EXPECT_EQ(smallPotion.getHealingAmount(), 0);
    EXPECT_EQ(smallPotion.getType(), "");
};

TEST(PotionTestSuite, testSmallPotionInvalid) {
    Potion smallPotion;
    smallPotion.setHealingAmount(-1);
    EXPECT_EQ(smallPotion.getHealingAmount(), 0);
};

TEST(PotionTestSuite, testSmallPotionValid){
    Potion smallPotion;
    smallPotion.setHealingAmount(50);
    EXPECT_EQ(smallPotion.getHealingAmount(), 50);
};

TEST(PotionTestSuite, testLargePotionInvalid) {
    Potion largePotion;
    largePotion.setHealingAmount(-50);
    EXPECT_EQ(largePotion.getHealingAmount(), 0);
};

TEST(PotionTestSuite, testPotionGetType){
    Potion smallPotion;
    EXPECT_EQ(smallPotion.getType(), "");
};

TEST(PotionTestSuite, testPotionSetTypeValid) {
    Potion smallPotion;
    smallPotion.setType("Small Potion");
    EXPECT_EQ(smallPotion.getType(), "Small Potion");
};

TEST(PotionTestSuite, testPotionSetTypeInvalid) {
    Potion smallPotion;
    smallPotion.setType("Null Potion");
    EXPECT_EQ(smallPotion.getType(), "");
};


TEST(PotionTestSuite, testSmallPotionFullGetHealingAmount){
    Potion smallPotion (50, "Small Potion");
    EXPECT_EQ(smallPotion.getHealingAmount(), 50);
};

TEST(PotionTestSuite, PotionSmallPotionHalfSetHealingAmount){
    Potion smallPotion (50, "Small Potion");
    smallPotion.setHealingAmount(100);
    EXPECT_EQ(smallPotion.getHealingAmount(), 100);
};

TEST(PotionTestSuite, testSmallPotionFullConstructorGetType){
    Potion smallPotion (50, "Small Potion");
    EXPECT_EQ(smallPotion.getType(), "Small Potion");
};

TEST(PotionTestSuite, testSmallPotionFullConstructorSetType) {
    Potion smallPotion (50, "Small Potion");
    smallPotion.setType("Smaller Potion");
    EXPECT_EQ(smallPotion.getType(), "Smaller Potion");
};



