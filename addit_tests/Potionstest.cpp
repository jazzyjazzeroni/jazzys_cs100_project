#include "gtest/gtest.h"
#include "../addit_header/Potions.h"

#include "gtest/gtest.h"
#include "../addit_header/Potions.h"

TEST(PotionTest, PotionConstructorGetHealingAmount){
    Potion miniPotion;
    EXPECT_EQ(miniPotion.getHealingAmount(), 1);
};

TEST(PotionTest, PotionConstructorSetHealingAmount){
    Potion miniPotion;
    miniPotion.setHealingAmount(50);
    EXPECT_EQ(miniPotion.getHealingAmount(), 50);
};

TEST(PotionTest, InvalidPotionHealing) {
    Potion miniPotion;
    miniPotion.setHealingAmount(-50);
    EXPECT_EQ(miniPotion.getHealingAmount(), 0);
};

TEST(PotionTest, PotionConstructorGetType){
    Potion miniPotion;
    EXPECT_EQ(miniPotion.getType(), "");
};

TEST(PotionTest, SwordConstructorSetType) {
    Potion miniPotion;
    miniPotion.setType("Mini Potion");
    EXPECT_EQ(miniPotion.getType(), "Mini Potion");
};

TEST(PotionTest, InvalidPotionType) {
    Potion miniPotion;
    miniPotion.setType("Insane Potion");
    EXPECT_EQ(miniPotion.getType(), "");
};

TEST(PotionTest, InvalidPotionConstructorParameters) {
    Potion miniPotion;
    miniPotion.setHealingAmount(-1);
    EXPECT_EQ(miniPotion.getHealingAmount(), 0);
};

TEST(PotionTest, PotionFullConstructorGetHealingAmount){
    Potion smallPotion (50, "Small Potion");
    EXPECT_EQ(smallPotion.getHealingAmount(), 50);
};

TEST(PotionTest, PotionFullConstructorSetHealingAmount){
    Potion smallPotion (50, "Small Potion");
    smallPotion.setHealingAmount(100);
    EXPECT_EQ(smallPotion.getHealingAmount(), 100);
};

TEST(PotionTest, PotionFullConstructorGetType){
    Potion smallPotion (50, "Small Potion");
    EXPECT_EQ(smallPotion.getType(), "Small Potion");
};

TEST(PotionTest, PotionFullConstructorSetType) {
    Potion smallPotion (50, "Small Potion");
    smallPotion.setType("Smaller Potion");
    EXPECT_EQ(smallPotion.getType(), "Smaller Potion");
};

TEST(PotionTest, InvalidPotionFullConstructorParameters) {
    Potion miniPotion(-1, "Not a Potion");
    EXPECT_EQ(miniPotion.getHealingAmount(), 0);
    EXPECT_EQ(miniPotion.getType(), "");
};

