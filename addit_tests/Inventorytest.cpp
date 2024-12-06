#include "gtest/gtest.h"
#include "../addit_header/Inventory.h"
#include "../addit_header/Potions.h"
#include "../Character_header/MainCharacter.h"


TEST(InventoryTestSuite, testRemovePotionValid) {
     Inventory inventory;
    Potion smallPotion{50, "Small Potion"};
    Potion largePotion{100, "Large Potion"};
    MainCharacter mc("Theodore", 100, 5, "Air");
    inventory.addPotion(smallPotion);
    inventory.addPotion(largePotion);
    inventory.removePotion("Small Potion");
    EXPECT_FALSE(inventory.hasPotion("Small Potion"));
    EXPECT_TRUE(inventory.hasPotion("Large Potion"));

    // Edge case: removing non-existent potion
    EXPECT_TRUE(inventory.hasPotion("Null Potion"));
}
TEST(InventoryTestSuite, testRemovePotionInvalid) {
    Inventory inventory;
    Potion smallPotion{50, "Small Potion"};
    Potion largePotion{100, "Large Potion"};
    MainCharacter mc("Theodore", 100, 5, "Air");

    inventory.addPotion(smallPotion);
    inventory.addPotion(largePotion);

    inventory.removePotion("Mysterious Potion");    // this potion does not exist in our program
    EXPECT_TRUE(inventory.hasPotion("Large Potion"));
}

TEST(InventoryTestSuite, testGetPotionInvalid) {
    Inventory inventory;
    Potion smallPotion{50, "Small Potion"};
    Potion largePotion{100, "Large Potion"};
    MainCharacter mc("Theodore", 100, 5, "Air");

    inventory.addPotion(smallPotion);
    Potion retrieved = inventory.getPotion("Small Potion");
    EXPECT_EQ(retrieved.getType(), "Small Potion");
    EXPECT_EQ(retrieved.getHealingAmount(), 25);

    // Edge case: potion not found
    EXPECT_THROW(inventory.getPotion("Mysterious Potion"), std::runtime_error);
}


TEST(InventoryTestSuite, testUsePotionInvalid) {
    Inventory inventory;
    Potion smallPotion{50, "Small Potion"};
    Potion largePotion{100, "Large Potion"};
    MainCharacter mc("Theodore", 100, 5, "Air");

    // Edge case: inventory empty
    EXPECT_NO_THROW(inventory.usePotion(mc));
}

TEST(InventoryTestSuite, PrintInventory) {
    Inventory inventory;
    Potion smallPotion{50, "Small Potion"};
    Potion largePotion{100, "Large Potion"};
        MainCharacter mc("Theodore", 100, 5, "Air");

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
