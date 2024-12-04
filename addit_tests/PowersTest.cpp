#include <gtest/gtest.h>
#include "../addit_header/Powers.h"

// Test fixture for the Powers class
class PowersTest : public ::testing::Test {
protected:
    Powers firePower{"Fire"};
    Powers waterPower{"Water"};
    Powers earthPower{"Earth"};
    Powers airPower{"Air"};
};

// Test Constructor Initialization
TEST_F(PowersTest, ConstructorInitialization) {
    EXPECT_EQ(firePower.getPower(), FIRE);
    EXPECT_EQ(waterPower.getPower(), WATER);
    EXPECT_EQ(earthPower.getPower(), EARTH);
    EXPECT_EQ(airPower.getPower(), AIR);
}

// Test invalid power type
TEST(PowersEdgeCases, InvalidPowerType) {
    EXPECT_THROW(Powers("Invalid"), std::invalid_argument);
}

// Test calculateDamage method
TEST_F(PowersTest, CalculateDamage) {
    EXPECT_EQ(firePower.calculateDamage(), 20);
    EXPECT_EQ(waterPower.calculateDamage(), 15);
    EXPECT_EQ(earthPower.calculateDamage(), 10);
    EXPECT_EQ(airPower.calculateDamage(), 12);
}

// Test setPower and getPower methods
TEST_F(PowersTest, SetAndGetPower) {
    firePower.setPower(WATER);
    EXPECT_EQ(firePower.getPower(), WATER);

    firePower.setPower(EARTH);
    EXPECT_EQ(firePower.getPower(), EARTH);
}

// Test getDamage and setDamage methods
TEST_F(PowersTest, GetAndSetDamage) {
    firePower.setDamage(25);
    EXPECT_EQ(firePower.getDamage(), 25);

    firePower.setDamage(-5); // Invalid damage
    EXPECT_EQ(firePower.getDamage(), 25); // Damage should remain unchanged
}

// Test canUsePower method
TEST_F(PowersTest, CanUsePower) {
    EXPECT_TRUE(waterPower.canUsePower(firePower)); // Water > Fire
    EXPECT_TRUE(firePower.canUsePower(waterPower)); // Fire > Water
    EXPECT_TRUE(earthPower.canUsePower(airPower));  // Earth > Air
    EXPECT_TRUE(airPower.canUsePower(earthPower));  // Air > Earth

    EXPECT_FALSE(firePower.canUsePower(airPower));  // Fire not effective against Air
    EXPECT_FALSE(earthPower.canUsePower(waterPower)); // Earth not effective against Water
}

// Test calculateDamage with invalid states
TEST_F(PowersTest, CalculateDamageEdgeCases) {
    firePower.setDamage(-10); // Invalid damage
    EXPECT_EQ(firePower.calculateDamage(), 20); // Should still use default FIRE damage

    waterPower.setDamage(30); // Manually set damage
    EXPECT_EQ(waterPower.getDamage(), 30); // Should reflect the updated damage
}
