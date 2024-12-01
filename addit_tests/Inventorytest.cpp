#include "gtest/gtest.h"
#include "../addit_header/Inventory.h"


TEST(InventoryTest, AddItemTest) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);

    EXPECT_EQ(inventory.getNumItems(), 1);
    EXPECT_EQ(inventory.getItemAt(0).getType(), "Sword");
    EXPECT_EQ(inventory.getItemAt(0).getDamage(), 5);
    EXPECT_EQ(inventory.getItemAt(0).getName(), "Normal Sword");
}

TEST(InventoryTest, AddMultipleItemsTest) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    Sword sword2(10, "Better Sword");
    Sword sword3(15, "Greater Sword");
    inventory.addItem(sword);
    inventory.addItem(sword2);
    inventory.addItem(sword3);

    EXPECT_EQ(inventory.getNumItems(), 3);
    EXPECT_EQ(inventory.getItemAt(0).getType(), "Sword");
    EXPECT_EQ(inventory.getItemAt(0).getDamage(), 5);
    EXPECT_EQ(inventory.getItemAt(0).getName(), "Normal Sword");
    EXPECT_EQ(inventory.getItemAt(1).getType(), "Sword");
    EXPECT_EQ(inventory.getItemAt(1).getDamage(), 10);
    EXPECT_EQ(inventory.getItemAt(1).getName(), "Better Sword");
    EXPECT_EQ(inventory.getItemAt(2).getType(), "Sword");
    EXPECT_EQ(inventory.getItemAt(2).getDamage(), 15);
    EXPECT_EQ(inventory.getItemAt(2).getName(), "Greater Sword");
}

TEST(InventoryTest, RemoveItemTest) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);
    inventory.removeItem(0);

    EXPECT_EQ(inventory.getNumItems(), 0);
}


TEST(InventoryTest, RemoveMultipleItemsTest) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    Sword sword2(10, "Better Sword");
    Sword sword3(15, "Greater Sword");
    inventory.addItem(sword);
    inventory.addItem(sword2);
    inventory.addItem(sword3);
    inventory.removeItem(0);
    inventory.removeItem(1);

    EXPECT_EQ(inventory.getNumItems(), 1);
    EXPECT_EQ(inventory.getItemAt(0).getType(), "Sword");
    EXPECT_EQ(inventory.getItemAt(0).getDamage(), 10);
    EXPECT_EQ(inventory.getItemAt(0).getName(), "Better Sword");
}

TEST(InventoryTest, RemoveInvalidItemTest) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);

    EXPECT_ANY_THROW(inventory.removeItem(1));
}

TEST(InventoryTest, RemoveInvalidItemTest2) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);

    EXPECT_ANY_THROW(inventory.removeItem(-1));
}

TEST(InventoryTest, GetItemTest) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);

    EXPECT_EQ(inventory.getItemAt(0).getType(), "Sword");
    EXPECT_EQ(inventory.getItemAt(0).getDamage(), 5);
    EXPECT_EQ(inventory.getItemAt(0).getName(), "Normal Sword");
}

TEST(InventoryTest, GetInvalidItemTest) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);

    EXPECT_ANY_THROW(inventory.getItemAt(1));
}

TEST(InventoryTest, GetInvalidItemTest2) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);

    EXPECT_ANY_THROW(inventory.getItemAt(-1));
}

TEST(InventoryTest, GetNumItemsTest) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);

    EXPECT_EQ(inventory.getNumItems(), 1);
}

TEST(InventoryTest, GetNumItemsTest2) {
    Inventory inventory;

    EXPECT_EQ(inventory.getNumItems(), 0);
}

TEST(InventoryTest, GetNumItemsTest3) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    Sword sword2(10, "Better Sword");
    Sword sword3(15, "Greater Sword");
    inventory.addItem(sword);
    inventory.addItem(sword2);
    inventory.addItem(sword3);

    EXPECT_EQ(inventory.getNumItems(), 3);
}

TEST(InventoryTest, GetNumItemsTest4) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);
    inventory.removeItem(0);

    EXPECT_EQ(inventory.getNumItems(), 0);
}

TEST(InventoryTest, GetNumItemsTest5) {
    Inventory inventory;
    Sword sword(5, "Normal Sword");
    inventory.addItem(sword);
    inventory.removeItem(0);
    inventory.removeItem(0);

    EXPECT_EQ(inventory.getNumItems(), 0);
}