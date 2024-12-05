#include "gtest/gtest.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/Potions.h"

class InventoryTestSuite : public ::testing::Test {
protected:
    Inventory inventory;
    Potion smallPotion{50, "Small Potion"};
    Potion largePotion{100, "Large Potion"};
    MainCharacter character; // Assuming MainCharacter has `heal` and related methods
};

TEST_F(InventoryTestSuite, testRemovePotionValid) {
    inventory.addPotion(smallPotion);
    inventory.addPotion(largePotion);
    inventory.removePotion("Small Potion");
    EXPECT_FALSE(inventory.hasPotion("Small Potion"));
    EXPECT_TRUE(inventory.hasPotion("Large Potion"));

    // Edge case: removing non-existent potion
    EXPECT_TRUE(inventory.hasPotion("Null Potion"));
}
TEST_F(InventoryTestSuite, testRemovePotionInalid) {
    inventory.addPotion(smallPotion);
    inventory.addPotion(largePotion);

    inventory.removePotion("Mysterious Potion");    // this potion does not exist in our program
    EXPECT_TRUE(inventory.hasPotion("Large Potion"));
}

TEST_F(InventoryTestSuite, testGetPotion) {
    inventory.addPotion(smallPotion);
    Potion retrieved = inventory.getPotion("Small Potion");
    EXPECT_EQ(retrieved.getType(), "Small Potion");
    EXPECT_EQ(retrieved.getHealingAmount(), 25);

    // Edge case: potion not found
    EXPECT_THROW(inventory.getPotion("Mysterious Potion"), std::runtime_error);
}

TEST_F(InventoryTestSuite, testUsePotionValid) {
    inventory.addPotion(smallPotion);
    inventory.addPotion(largePotion);
    
    inventory.usePotion(character);
    
    EXPECT_FALSE(inventory.hasPotion("Small Potion"));
    EXPECT_TRUE(inventory.hasPotion("Large Potion"));
}

TEST_F(InventoryTestSuite, testUsePotionInvalid) {

    // Edge case: inventory empty
    EXPECT_NO_THROW(inventory.usePotion(character));
}

TEST_F(InventoryTestSuite, PrintInventory) {
    inventory.addPotion(smallPotion);
    inventory.addPotion(largePotion);

    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());
    inventory.print();

    std::string expectedOutput = 
        "Potions in inventory:\n"
        "Name: Small Potion, Value: 50\n"
        "Name: Large Potion, Value: 100\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
