#include "gtest/gtest.h"
#include "../addit_header/Level.h"

TEST(LevelsTest, testLevel1) {
    vector<vector<int>> level1Map = {
        {0, 1, 0, 5, 0},  
        {0, 0, 2, 0, 6},  
        {4, 0, 0, 1, 0},  
        {0, 5, 0, 4, 0} 
    };
    Level level1(1, level1Map, 2);
    level1.start();
    ASSERT_EQ(level1.getGameMap().getGoblinsKilled(), 2);
}

TEST(LevelsTest, testLevel2) {
    vector<vector<int>> level2Map = {
        {0, 1, 0, 5, 4},  
        {1, 0, 2, 0, 6},  
        {4, 0, 0, 0, 2},  
        {0, 5, 0, 4, 0},  
        {0, 4, 0, 0, 0}
    };
    Level level2(2, level2Map, 3);
    level2.start();
    ASSERT_EQ(level2.getGameMap().getGoblinsKilled(), 3);
}


TEST(LevelsTest, testLevel3) {
    vector<vector<int>> level3Map = {
        {0, 1, 0, 5, 4},  
        {1, 0, 2, 0, 6},  
        {4, 0, 0, 0, 2},  
        {0, 5, 3, 4, 0},  
        {0, 4, 0, 0, 0},
        {6, 4, 0, 4, 0}
    };
    Level level3(3, level3Map, 4);
    level3.start();
    ASSERT_EQ(level3.getGameMap().getGoblinsKilled(), 4);
}

TEST(LevelsTest, testLevel4) {
    vector<vector<int>> level4Map = {
        {0, 1, 0, 5, 4, 0},  
        {1, 0, 2, 0, 6, 4},  
        {4, 0, 0, 0, 2, 3},  
        {0, 5, 3, 4, 0, 0},  
        {0, 4, 0, 0, 0, 5},
        {6, 4, 0, 4, 0, 4}
    };
    Level level4(4, level4Map, 5);
    level4.start();
    ASSERT_EQ(level4.getGameMap().getGoblinsKilled(), 5);
}

vector<vector<int>> createLevelMatrix(int width, int height, int value = 0) {
    return vector<vector<int>>(height, vector<int>(width, value));
}

TEST(LevelsTest, ValidInitialLevelTest) {
    vector<vector<int>> layout = createLevelMatrix(3, 3);
    layout[0][0] = 4; 
    layout[1][1] = 1; 
    layout[2][2] = 2; 

    Levels levels(layout, 3, 3);

    EXPECT_EQ(levels.getNumGoblins(), 1);
    EXPECT_EQ(levels.getGoblinsKilled(), 0);

    EXPECT_EQ(levels.getObjectAt(0, 0).getType(), "Goblin");
    EXPECT_EQ(levels.getObjectAt(1, 1).getType(), "Sword");
    EXPECT_EQ(levels.getObjectAt(2, 2).getType(), "Potion");
}

TEST(LevelsTest, ValidInitializeLevelTest) {
    vector<vector<int>> layout = {
        {0, 1, 2},
        {4, 5, 6},
        {3, 4, 0}
    };
    Level levels(layout, 3, 3);

    EXPECT_EQ(levels.getNumGoblins(), 2);
    EXPECT_EQ(levels.getGoblinsKilled(), 0);

    EXPECT_EQ(levels.getObjectAt(0, 1).getType(), "Goblin");
    EXPECT_EQ(levels.getObjectAt(1, 0).getType(), "Sword");
    EXPECT_EQ(levels.getObjectAt(1, 1).getType(), "Potion");
}

TEST(LevelsTest, EmptyLevelInitialiseTest) {
    vector<vector<int>> layout = createLevelMatrix(5, 5);
    Levels levels(layout, 5, 5);

    EXPECT_EQ(levels.getNumGoblins(), 0);
    EXPECT_EQ(levels.getGoblinsKilled(), 0);

    EXPECT_EQ(levels.getObjectAt(0, 0).getType(), "Null");
    EXPECT_EQ(levels.getObjectAt(1, 1).getType(), "Null");
    EXPECT_EQ(levels.getObjectAt(2, 2).getType(), "Null");
}

TEST(LevelsTest, InvalidLevelSizeTest) {
    vector<vector<int>> layout = {
        {0, 1, 2},
        {4, 5, 6},
        {3, 4, 0},
        {5, 5, 3} 
    };
    EXPECT_ANY_THROW(Levels levels(layout, 3, 3)); 
}

TEST(LevelsTest, KillGoblinValidTest) {
    vector<vector<int>> layout = {
        {0, 4, 0},
        {0, 0, 0},
        {4, 0, 0}
    };
    Levels levels(layout, 3, 3);

    EXPECT_EQ(levels.getNumGoblins(), 2);
    EXPECT_EQ(levels.getGoblinsKilled(), 0);

    levels.killGoblin(1, 0);

    EXPECT_EQ(levels.getGoblinsKilled(), 1);
    EXPECT_EQ(levels.getObjectAt(1, 0).getType(), "Null");
    EXPECT_EQ(levels.getNumGoblins(), 2); 
}

TEST(LevelsTest, KillGoblinInvalidCoordinateTest) {
    vector<vector<int>> layout = {
        {0, 4, 0},
        {0, 0, 0},
        {4, 0, 0}
    };
    Levels levels(layout, 3, 3);

    EXPECT_ANY_THROW(levels.killGoblin(-10, 0)); 
    EXPECT_ANY_THROW(levels.killGoblin(5, 0)); 
    EXPECT_ANY_THROW(levels.killGoblin(0, 5)); 
}

TEST(LevelsTest, GetObjectAtValidTest) {
    vector<vector<int>> layout = createLevelMatrix(3, 3);
    layout[0][0] = 4;
    layout[1][1] = 1;
    layout[2][2] = 2;

    Levels levels(layout, 3, 3);

    EXPECT_EQ(levels.getObjectAt(0, 0).getType(), "Goblin");
    EXPECT_EQ(levels.getObjectAt(1, 1).getType(), "Sword");
    EXPECT_EQ(levels.getObjectAt(2, 2).getType(), "Potion");
}

TEST(LevelsTest, SetObjectValidTest) {
    vector<vector<int>> layout = createLevelMatrix(3, 3);
    Levels levels(layout, 3, 3);

    Sword sword(10, "Long Sword");
    levels.setObjectAt(1, 1, sword);

    EXPECT_EQ(levels.getObjectAt(1, 1).getType(), "Sword");
    EXPECT_EQ(levels.getObjectAt(1, 1).getValue(), 10);
}

TEST(LevelsTest, SetObjectInvalidTest) {
    vector<vector<int>> layout = createLevelMatrix(3, 3);
    Levels levels(layout, 3, 3);

    Sword sword(10, "Long Sword");
    EXPECT_ANY_THROW(levels.setObjectAt(-1, 0, sword)); 
    EXPECT_ANY_THROW(levels.setObjectAt(5, 0, sword)); 
    EXPECT_ANY_THROW(levels.setObjectAt(0, 5, sword)); 
}

TEST(LevelsTest, SetObjectAtInvalidObjectTest) {
    vector<vector<int>> layout = createLevelMatrix(3, 3);
    Levels levels(layout, 3, 3);

    Sword sword(10, "Long Sword");
    levels.setObjectAt(1, 1, sword);

    Goblin goblin(10);
    EXPECT_ANY_THROW(levels.setObjectAt(1, 1, goblin)); 
}

TEST(LevelsTest, GetNumGoblinsAndKilledTests) {
    vector<vector<int>> layout = {
        {4, 4, 4},
        {0, 0, 0},
        {0, 0, 0}
    };
    Levels levels(layout, 3, 3);

    EXPECT_EQ(levels.getNumGoblins(), 3);
    EXPECT_EQ(levels.getGoblinsKilled(), 0);

    levels.killGoblin(0, 0);
    levels.killGoblin(1, 0);

    EXPECT_EQ(levels.getNumGoblins(), 3);
    EXPECT_EQ(levels.getGoblinsKilled(), 2);
}

TEST(LevelsTest, testEmptyMap) {
    vector<vector<int>> emptyMap = createLevelMatrix(5, 5);
    Level emptyLevel(1, emptyMap, 0); 
    emptyLevel.start();
    ASSERT_EQ(emptyLevel.getGameMap().getGoblinsKilled(), 0);  
}

TEST(LevelsTest, testPlayerStartsOnGoblin) {
    vector<vector<int>> level1Map = {
        {0, 1, 0, 5, 0},  
        {0, 0, 2, 0, 6},  
        {4, 0, 0, 1, 0},  
        {0, 5, 0, 4, 0}
    };
    Level level1(1, level1Map, 2);
    level1.start();
    ASSERT_EQ(level1.getGameMap().getGoblinsKilled(), 1); 
}

TEST(LevelsTest, testNonRectangularMap) {
    vector<vector<int>> irregularMap = {
        {0, 1, 0},
        {4, 0, 2, 0},
        {0, 0, 3}
    };
    EXPECT_ANY_THROW(Level level(1, irregularMap, 1)); 
}

TEST(LevelsTest, testMaxGoblins) {
    vector<vector<int>> maxGoblinsMap = {
        {4, 4, 4, 4, 4},  
        {4, 4, 4, 4, 4},  
        {4, 4, 4, 4, 4},  
        {4, 4, 4, 4, 4}
    };
    Level maxGoblinsLevel(1, maxGoblinsMap, 16);  
    maxGoblinsLevel.start();
    ASSERT_EQ(maxGoblinsLevel.getGameMap().getGoblinsKilled(), 16); 
}

TEST(LevelsTest, testPlayerDiesOnFirstAction) {
    vector<vector<int>> level1Map = {
        {0, 1, 0, 5, 0},  
        {0, 0, 2, 0, 6},  
        {4, 0, 0, 1, 0},  
        {0, 5, 0, 4, 0}
    };
    Level level1(1, level1Map, 1);  
    level1.start();
    ASSERT_EQ(level1.getGameMap().getGoblinsKilled(), 0); 
}

TEST(LevelsTest, testUnreachableGoblin) {
    vector<vector<int>> level1Map = {
        {0, 1, 0, 5, 0},  
        {0, 0, 2, 0, 6},  
        {4, 0, 0, 1, 0},  
        {0, 5, 0, 4, 0}
    };
    Level unreachableLevel(1, level1Map, 3); 
    unreachableLevel.start();
    ASSERT_EQ(unreachableLevel.getGameMap().getGoblinsKilled(), 2);
}
