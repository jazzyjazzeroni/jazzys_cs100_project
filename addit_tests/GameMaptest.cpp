#include "gtest/gtest.h"
#include "GameMap.h"
#include "Swords.h"
#include "Goblin.h"
#include "Potions.h"
#include <vector>

using namespace std;

vector<vector<int>> createMatrix(int width, int height, int Value = 0) {
    return vector<vector<int>>(height, vector<int>(width, Value));
}

TEST(GameMapTest, ValidInitialmMapTest) {
    vector<vector<int>> layout = createMatrix(3, 3);
    layout[0][0] = 4; 
    layout[1][1] = 1; 
    layout[2][2] = 2; 

    GameMap gameMap(layout, 3, 3);

    EXPECT_EQ(gameMap.getNumGoblins(), 1);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 0);

    EXPECT_EQ(gameMap.getObjectAt(0, 0).getType(), "Goblin");
    EXPECT_EQ(gameMap.getObjectAt(1, 1).getType(), "Sword");
    EXPECT_EQ(gameMap.getObjectAt(2, 2).getType(), "Potion");
}

TEST(GameMapTest, ValidInitializeMatrixTest) {
   vector<vector<int>> layout = {
        {0, 1, 2},
        {4, 5, 6},
        {3, 4, 0}
    };
    GameMap gameMap(layout, 3, 3);

    EXPECT_EQ(gameMap.getNumGoblins(), 2);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 0);

    EXPECT_EQ(gameMap.getObjectAt(0, 1).getType(), "Goblin");
    EXPECT_EQ(gameMap.getObjectAt(1, 0).getType(), "Sword");
    EXPECT_EQ(gameMap.getObjectAt(1, 1).getType(), "Potion");
}


TEST(GameMapTest, EmptyMatrixInitialization) {
    vector<vector<int>> layout = createMatrix(3, 3);
    GameMap gameMap(layout, 3, 3);

    EXPECT_EQ(gameMap.getNumGoblins(), 0);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 0);

    EXPECT_EQ(gameMap.getObjectAt(0, 0).getType(), "Null");
    EXPECT_EQ(gameMap.getObjectAt(1, 1).getType(), "Null");
    EXPECT_EQ(gameMap.getObjectAt(2, 2).getType(), "Null");
}

TEST(GameMapTest, InvalidMatrixInitialization) {
    vector<vector<int>> layout = {
        {0, 1, 2},
        {4, 5, 6},
        {1, 1} 
    };
    EXPECT_ANY_THROW(GameMap gameMap(layout, 3, 3)); 
}

TEST(GameMapTest, InvalidMatrixSizeTest) {
    vector<vector<int>> layout = {
        {0, 1, 2},
        {4, 5, 6},
        {3, 4, 0},
        {5, 5, 3} 
    };
    EXPECT_ANY_THROW(GameMap gameMap(layout, 3, 3)); 
}

TEST(GameMapTest, NegativeMatrixTest) {
    vector<vector<int>> layout = {
        {0, 1, 2},
        {4, 5, 6},
        {0, 3, -12} 
    };
    EXPECT_ANY_THROW(GameMap gameMap(layout, 3, 3)); 
}

TEST(GameMapTest, LargeNumberMatrixInvalidTest) {
    vector<vector<int>> layout = {
        {0, 1, 2},
        {4, 5, 6},
        {3, 0, 1000} 
    };
    EXPECT_ANY_THROW(GameMap gameMap(layout, 3, 3)); 
}

// invalid layout size
TEST(GameMapTest, InvalidLayoutSizeTest) {
    std::vector<std::vector<int>> layout = {
        {0, 1},
        {2, 2, 6} 
    };
    EXPECT_ANY_THROW(GameMap gameMap(layout, 3, 2)); 
}

// kill goblin test
TEST(GameMapTest, KillGoblinValidTest) {
    vector<vector<int>> layout = {
        {0, 4, 0},
        {0, 0, 0},
        {4, 0, 0}
    };
    GameMap gameMap(layout, 3, 3);

    EXPECT_EQ(gameMap.getNumGoblins(), 2);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 0);

    gameMap.killGoblin(1, 0);

    EXPECT_EQ(gameMap.getGoblinsKilled(), 1);
    EXPECT_EQ(gameMap.getObjectAt(1, 0).getType(), "Null");
    EXPECT_EQ(gameMap.getNumGoblins(), 2); 
}

TEST(GameMapTest, KillGoblinInvalidCoordinates) {
    vector<vector<int>> layout = {
        {0, 4, 0},
        {0, 0, 0},
        {4, 0, 0}
    };
    GameMap gameMap(layout, 3, 3);

    EXPECT_ANY_THROW(gameMap.killGoblin(-10, 0)); 
    EXPECT_ANY_THROW(gameMap.killGoblin(5, 0)); 
    EXPECT_ANY_THROW(gameMap.killGoblin(0, 5)); 
}

TEST(GameMapTest, NullspaceTest) {
    vector<ector<int>> layout = {
        {0, 4, 0},
        {0, 0, 0},
        {4, 0, 0}
    };
    GameMap gameMap(layout, 3, 3);

    EXPECT_ANY_THROW(gameMap.killGoblin(0, 0)); 
    EXPECT_ANY_THROW(gameMap.killGoblin(1, 1)); 
}

TEST(GameMapTest, InvalidKilledGoblintest) {
    vector<vector<int>> layout = {
        {0, 4, 0},
        {0, 0, 0},
        {4, 0, 0}
    };
    GameMap gameMap(layout, 3, 3);

    gameMap.killGoblin(1, 0);
    EXPECT_ANY_THROW(gameMap.killGoblin(1, 0)); 
}

TEST(GameMapTest, InvalidObjectTest) {
    vector<vector<int>> layout = createMatrix(3, 3);
    GameMap gameMap(layout, 3, 3);

    EXPECT_ANY_THROW(gameMap.getObjectAt(-1, 0)); 
    EXPECT_ANY_THROW(gameMap.getObjectAt(5, 0)); 
    EXPECT_ANY_THROW(gameMap.getObjectAt(0, 5));
}

// get object tests
TEST(GameMapTest, GetObjectValidTests) {
    vector<vector<int>> layout = createMatrix(3, 3);
    layout[0][0] = 4; 
    layout[1][1] = 1; 

    GameMap gameMap(layout, 3, 3);

    EXPECT_EQ(gameMap.getObjectAt(0, 0).getType(), "Goblin");
    EXPECT_EQ(gameMap.getObjectAt(1, 1).getType(), "Sword");
}

TEST(GameMapTest, GetObjectInvalidTests) {
    vector<vector<int>> layout = createMatrix(3, 3);
    GameMap gameMap(layout, 3, 3);

    EXPECT_ANY_THROW(gameMap.getObjectAt(-1, 0));
    EXPECT_ANY_THROW(gameMap.getObjectAt(5, 0)); 
    EXPECT_ANY_THROW(gameMap.getObjectAt(0, 5)); 
}

TEST(GameMapTest, SetObjectValidTests) {
    vector<vector<int>> layout = createMatrix(3, 3);
    GameMap gameMap(layout, 3, 3);

    Sword sword(10, "Long Sword");
    gameMap.setObjectAt(1, 1, sword);

    EXPECT_EQ(gameMap.getObjectAt(1, 1).getType(), "Sword");
    EXPECT_EQ(gameMap.getObjectAt(1, 1).getValue(), 10);
}

TEST(GameMapTest, SetObjectInvalidTests) {
    vector<vector<int>> layout = createMatrix(3, 3);
    GameMap gameMap(layout, 3, 3);

    Sword sword(10, "Long Sword");
    EXPECT_ANY_THROW(gameMap.setObjectAt(-1, 0, sword)); 
    EXPECT_ANY_THROW(gameMap.setObjectAt(5, 0, sword)); 
    EXPECT_ANY_THROW(gameMap.setObjectAt(0, 5, sword)); 
}

TEST(GameMapTest, SetObjectAtInvalidObjectTest) {
    vector<vector<int>> layout = createMatrix(3, 3);
    GameMap gameMap(layout, 3, 3);

    Sword sword(10, "Long Sword");
    gameMap.setObjectAt(1, 1, sword);

    Goblin goblin(10);
    EXPECT_ANY_THROW(gameMap.setObjectAt(1, 1, goblin));
}

TEST(GameMapTest, SetObjectANulltest) {
    vector<vector<int>> layout = createMatrix(3, 3);
    GameMap gameMap(layout, 3, 3);

    Sword sword(10, "Long Sword");
    gameMap.setObjectAt(1, 1, sword);

    EXPECT_ANY_THROW(gameMap.setObjectAt(0, 0, sword)); 
}

TEST(GameMapTest, SetObjectFullTests) {
    vector<vector<int>> layout = createMatrix(3, 3);
    GameMap gameMap(layout, 3, 3);

    Sword sword(10, "Long Sword");
    gameMap.setObjectAt(1, 1, sword);

    Sword sword2(20, "Short Sword");
    gameMap.setObjectAt(1, 1, sword2);

    EXPECT_EQ(gameMap.getObjectAt(1, 1).getType(), "Sword");
    EXPECT_EQ(gameMap.getObjectAt(1, 1).getValue(), 10);
}

//tests for getNumGoblins and getGoblinsKilled

TEST(GameMapTest, GoblinsCountAndKill) {
    vector<vector<int>> layout = {
        {4, 4, 4},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap gameMap(layout, 3, 3);

    EXPECT_EQ(gameMap.getNumGoblins(), 3);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 0);

    gameMap.killGoblin(0, 0);
    gameMap.killGoblin(1, 0);

    EXPECT_EQ(gameMap.getNumGoblins(), 3);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 2);
}

TEST(GameMapTest, InvalidNumGoblins) {
    vector<vector<int>> layout = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap gameMap(layout, 3, 3);

    EXPECT_EQ(gameMap.getNumGoblins(), 0);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 0);
}

TEST(GameMapTest, InvalidGoblinsKilled) {
    vector<vector<int>> layout = {
        {4, 4, 4},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap gameMap(layout, 3, 3);

    EXPECT_EQ(gameMap.getNumGoblins(), 3);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 0);

    gameMap.killGoblin(0, 0);
    gameMap.killGoblin(1, 0);
    gameMap.killGoblin(2, 0);

    EXPECT_EQ(gameMap.getNumGoblins(), 3);
    EXPECT_EQ(gameMap.getGoblinsKilled(), 3);
}

// Test edge cases for map boundaries
TEST(GameMapTest, BoundaryCoordinatesTest) {
    vector<vector<int>> layout = createMatrix(5, 5);
    layout[0][0] = 1; 
    layout[4][4] = 4; 

    GameMap gameMap(layout, 5, 5);

    EXPECT_EQ(gameMap.getObjectAt(0, 0).getType(), "Sword");  
    EXPECT_EQ(gameMap.getObjectAt(4, 4).getType(), "Goblin");  

    Sword sword(5, "Short Sword");
    gameMap.setObjectAt(0, 0, sword);

    EXPECT_EQ(gameMap.getObjectAt(0, 0).getType(), "Sword"); 
}

TEST(GameMapTest, BoundaryCoordinatesValidTest) {
    vector<vector<int>> layout = createMatrix(5, 5);
    layout[0][0] = 1; 
    layout[4][4] = 4; 

    GameMap gameMap(layout, 5, 5);

    EXPECT_EQ(gameMap.getObjectAt(0, 0).getType(), "Sword");   
    EXPECT_EQ(gameMap.getObjectAt(4, 4).getType(), "Goblin");  

    Goblin goblin(10);
    gameMap.setObjectAt(4, 4, goblin);

    EXPECT_EQ(gameMap.getObjectAt(4, 4).getType(), "Goblin"); 
}

TEST(GameMapTest, BoundaryCoordinatesPotions) {
    vector<vector<int>> layout = createMatrix(5, 5);
    layout[0][0] = 1;
    layout[4][4] = 4;

    GameMap gameMap(layout, 5, 5);

    EXPECT_EQ(gameMap.getObjectAt(0, 0).getType(), "Sword"); 
    EXPECT_EQ(gameMap.getObjectAt(4, 4).getType(), "Goblin");  

    Potion potion(10, "Health Potion");
    gameMap.setObjectAt(4, 4, potion);

    EXPECT_EQ(gameMap.getObjectAt(4, 4).getType(), "Potion"); 
}

TEST(GameMapTest, BoundaryCoordinatesInvalidTest) {
    vector<vector<int>> layout = createMatrix(5, 5);
    layout[0][0] = 1; 
    layout[4][4] = 4; 

    GameMap gameMap(layout, 5, 5);

    EXPECT_EQ(gameMap.getObjectAt(0, 0).getType(), "Sword");  
    EXPECT_EQ(gameMap.getObjectAt(4, 4).getType(), "Goblin");  

    Sword sword(5, "Short Sword");
    EXPECT_ANY_THROW(gameMap.setObjectAt(5, 0, sword)); 
    EXPECT_ANY_THROW(gameMap.setObjectAt(0, 5, sword)); 
}
