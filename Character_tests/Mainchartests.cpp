#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

class MockMainChar {
public:
    MOCK_METHOD(double, getHealth, (), (const));
    MOCK_METHOD(void, takeDamage, (double));
    MOCK_METHOD(void, heal, (double));
    MOCK_METHOD(bool, isAlive, (), (const));

    MOCK_METHOD(void, move, (char direction));
    MOCK_METHOD(std::string, getType, (), (const));
};

TEST(MainCharacterTest, HealthManagementTest) {
    MockMainChar mockMain;

    EXPECT_CALL(mockMain, getHealth())
        .Times(1)
        .WillOnce(testing::Return(100.0));

    EXPECT_EQ(mockMain.getHealth(), 100.0);

    EXPECT_CALL(mockMain, takeDamage(20.0))
        .Times(1);

    mockMain.takeDamage(20.0);

    EXPECT_CALL(mockMain, isAlive())
        .Times(1)
        .WillOnce(testing::Return(true));

    EXPECT_TRUE(mockMain.isAlive());
}

TEST(MainCharacterTest, MovementTest) {
    MockMainChar mockMain;

    EXPECT_CALL(mockMain, move('W')).Times(1);
    EXPECT_CALL(mockMain, move('A')).Times(1);
    EXPECT_CALL(mockMain, move('S')).Times(1);
    EXPECT_CALL(mockMain, move('D')).Times(1);

    mockMain.move('W');
    mockMain.move('A');
    mockMain.move('S');
    mockMain.move('D');

    // Test invalid input handling
    EXPECT_THROW({
        EXPECT_CALL(mockMain, move('X')).Times(1);
        mockMain.move('X'); 
    }, std::runtime_error);
}

TEST(MainCharacterTest, TypeTest) {
    MockMainChar mockMain;

    EXPECT_CALL(mockMain, getType())
        .Times(1)
        .WillOnce(testing::Return("Good"));

    EXPECT_EQ(mockMain.getType(), "Good");
}


TEST(MainCharacterTest, HealthValidation) {
    MockMainChar mockMain;

    EXPECT_CALL(mockMain, heal(0.0)).Times(0); 
    EXPECT_CALL(mockMain, heal(-5.0)).Times(0); 

    EXPECT_THROW({
        mockMain.heal(0.0); 
    }, std::invalid_argument);

    EXPECT_THROW({
        mockMain.heal(-5.0); // Should throw an exception
    }, std::invalid_argument);

    // Test upper limit for healing
    EXPECT_THROW({
        mockMain.heal(10.0); // Above allowed healing value should throw
    }, std::invalid_argument);

    EXPECT_CALL(mockMain, heal(5.0)).Times(1);
    mockMain.heal(5.0); // Valid healing
}

TEST(MainCharacterTest, DamageValidation) {
    MockMainChar mockMain;


    EXPECT_CALL(mockMain, takeDamage(0.0)).Times(0); 
    EXPECT_CALL(mockMain, takeDamage(-10.0)).Times(0); 

    EXPECT_THROW({
        mockMain.takeDamage(0.0); 
    }, std::invalid_argument);

    EXPECT_THROW({
        mockMain.takeDamage(-10.0); 
    }, std::invalid_argument);

    // Valid damage value
    EXPECT_CALL(mockMain, takeDamage(25.0)).Times(1);
    mockMain.takeDamage(25.0);
}

TEST(MainCharacterTest, IsAliveBehavior) {
    MockMainChar mockMain;

    EXPECT_CALL(mockMain, isAlive())
        .Times(1)
        .WillOnce(testing::Return(true));

    EXPECT_TRUE(mockMain.isAlive());

    EXPECT_CALL(mockMain, isAlive())
        .Times(1)
        .WillOnce(testing::Return(false));

    EXPECT_FALSE(mockMain.isAlive());
}

TEST(MainCharacterTest, MovementValidation) {
    MockMainChar mockMain;

    EXPECT_CALL(mockMain, move('W')).Times(1);
    EXPECT_CALL(mockMain, move('A')).Times(1);
    EXPECT_CALL(mockMain, move('S')).Times(1);
    EXPECT_CALL(mockMain, move('D')).Times(1);

    mockMain.move('W');
    mockMain.move('A');
    mockMain.move('S');
    mockMain.move('D');

    EXPECT_THROW({
        mockMain.move('X'); 
    }, std::invalid_argument);

    EXPECT_THROW({
        mockMain.move('1');
    }, std::invalid_argument);

    EXPECT_THROW({
        mockMain.move('\0');
    }, std::invalid_argument);
}

TEST(MainCharacterTest, TypeValidation) {
    MockMainChar mockMain;

    EXPECT_CALL(mockMain, getType())
        .Times(1)
        .WillOnce(testing::Return("Good"));

    EXPECT_EQ(mockMain.getType(), "Good");

    EXPECT_CALL(mockMain, getType())
        .Times(1)
        .WillOnce(testing::Return("Bad"));

    EXPECT_EQ(mockMain.getType(), "Bad");

    EXPECT_CALL(mockMain, getType())
        .Times(1)
        .WillOnce(testing::Return("Unknown"));

    EXPECT_EQ(mockMain.getType(), "Unknown");
}

