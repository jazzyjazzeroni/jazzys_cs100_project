#include "gtest/gtest.h"
#include "../addit_header/Swords.h"

TEST(SwordTests, SwordConstructorGetPower){
    Sword greySword;
    EXPECT_EQ(greySword.getPower(), 1);
};

TEST(SwordTests, SwordConstructorSetPower){
    Sword greySword;
    greySword.setPower(50);
    EXPECT_EQ(greySword.getPower(), 50);
};

TEST(SwordTests, InvalidSwordPowerParameters) {
    Sword greySword;
    greySword.setPower(-20);
    EXPECT_EQ(greySword.getPower(), 0);
};

TEST(SwordTests, SwordConstructorGetName){
    Sword greySword;
    EXPECT_EQ(greySword.getName(), "");
};

TEST(SwordTests, SwordConstructorSetName) {
    Sword greySword;
    greySword.setName("Lame Sword");
    EXPECT_EQ(greySword.getName(), "Lame Sword");
};

TEST(SwordTests, InvalidSwordNameParameters) {
    Sword greySword;
    greySword.setName("No Sword");
    EXPECT_EQ(greySword.getName(), "");
};

TEST(SwordTests, SwordFullConstructorGetName) {
    Sword greySword (50, "Happy Sword");
    EXPECT_EQ(greySword.getName(), "Happy Sword");
};

TEST(SwordTests, SwordFullConstructorSetName){
    Sword greySword(50, "Lame Sword");
    greySword.setName("Sad Sword");
    EXPECT_EQ(greySword.getName(), "Sad Sword");
};

TEST(SwordTests, SwordFullConstructorGetPower){
    Sword greySword(50, "Lame Sword");
    EXPECT_EQ(greySword.getPower(), 50);
};

TEST(SwordTests, SwordFullConstructorSetPower){
    Sword greySword(50, "Lame Sword");
    greySword.setPower(100);
    EXPECT_EQ(greySword.getPower(), 100);
};

TEST(SwordTests, SwordDealDamage) {
    Sword normalSword(5, "Normal Sword");
    normalSword.dealDamage();
    EXPECT_EQ(cout, "You used your Normal Sword!");
};

TEST(SwordTests, InvalidSwordTypeDealDamage) {
     Sword normalSword(5, "Norm Sword");
    normalSword.dealDamage();
    EXPECT_EQ(cout, "");
}
