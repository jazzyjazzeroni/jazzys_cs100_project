// #include "gtest/gtest.h"
// #include "../addit_header/GameMap.h"

// class GameMapTestSuite : public ::testing::Test {
// protected:
//     GameMap defaultMap;
//     GameMap gameMap;

//     void SetUp() override {
//         vector<vector<int>> initMatrix = {
//             {1, 0, 6},
//             {2, 5, 0},
//             {4, 9, 7}
//         };
//         gameMap = GameMap(initMatrix, 3, 3);
//     }
// };

// TEST_F(GameMapTestSuite, testDefaultConstructor) {
//     EXPECT_EQ(defaultMap.getWidth(), 0);
//     EXPECT_EQ(defaultMap.getHeight(), 0);
//     EXPECT_EQ(defaultMap.getNumGoblins(), 0);
//     EXPECT_EQ(defaultMap.getGoblinsKilled(), 0);
// }

// TEST_F(GameMapTestSuite, testOverloadedConstructor) {
//     EXPECT_EQ(gameMap.getWidth(), 3);
//     EXPECT_EQ(gameMap.getHeight(), 3);
//     EXPECT_EQ(gameMap.getNumGoblins(), 4);  // Goblins with codes 1, 2, 4, 5
// }

// TEST_F(GameMapTestSuite, testGoblinKillPositive) {
//     gameMap.killGoblin(0, 0);  // Goblin at (0,0)
//     EXPECT_EQ(gameMap.getGoblinsKilled(), 1);
//     EXPECT_EQ(gameMap.getNumGoblins(), 3);
// }

// TEST_F(GameMapTestSuite, testGoblinKillNegative) {
//     EXPECT_THROW(gameMap.killGoblin(-1, 0), std::out_of_range);  // Negative index
//     EXPECT_THROW(gameMap.killGoblin(3, 3), std::out_of_range);  // Out of bounds
//     EXPECT_NO_THROW(gameMap.killGoblin(2, 2));  // No goblin here
//     EXPECT_EQ(gameMap.getGoblinsKilled(), 0);
// }

// TEST_F(GameMapTestSuite, testGetObjectValid) {
//     auto obj = gameMap.getObjectAt(0, 0);
//     EXPECT_EQ(obj->getType(), "Goblin");
// }

// TEST_F(GameMapTestSuite, testGetObjectInvalid) {
//     EXPECT_THROW(gameMap.getObjectAt(-1, 0), std::out_of_range);  // Negative index
//     EXPECT_THROW(gameMap.getObjectAt(3, 3), std::out_of_range);  // Out of bounds
// }

// TEST_F(GameMapTestSuite, testSetObjectValid) {
//     auto newObj = std::make_shared<Object>();
//     gameMap.setObjectAt(0, 0, newObj);
//     auto obj = gameMap.getObjectAt(0, 0);
//     EXPECT_EQ(obj->getType(), "Object");  // Replaced Goblin with empty object
// }

// TEST_F(GameMapTestSuite, testSetObjectAtInvalid) {
//     auto newObj = std::make_shared<Object>();
//     EXPECT_THROW(gameMap.setObjectAt(-1, 0, newObj), std::out_of_range);  // Negative index
//     EXPECT_THROW(gameMap.setObjectAt(3, 3, newObj), std::out_of_range);  // Out of bounds
// }

// TEST_F(GameMapTestSuite, NumGoblinsAfterActions) {
//     gameMap.killGoblin(1, 0);  // Kill Goblin at (1,0)
//     EXPECT_EQ(gameMap.getNumGoblins(), 3);
//     EXPECT_EQ(gameMap.getGoblinsKilled(), 1);
// }

// TEST_F(GameMapTestSuite, testMapLimits) {
//     EXPECT_NO_THROW(gameMap.getObjectAt(2, 2));  // Last valid index
//     EXPECT_THROW(gameMap.getObjectAt(3, 3), std::out_of_range);  // Out of bounds
//     EXPECT_THROW(gameMap.setObjectAt(-1, -1, std::make_shared<Object>()), std::out_of_range);
// }
