#include "gtest/gtest.h"
#include "../addit_header/Object.h"

#include <string>
#ifndef OBJECT_H
#define OBJECT_H
using namespace std;

class Object {
public:
    string type; // "character" | "sword" | "potion" | "empty"
    int value; // 0 | 5 | 10 | 15

    Object();
    Object(const string& type, int value);
    virtual ~Object() = default;

    string getType() const;
    void setType(const string& newType);
    int getValue() const;
    void setValue(int newValue);
    void print() const;
};

#endif

//start default constructor tests

TEST(ObjectTest, ValidDefaultConstructor) {
    Object obj;
    EXPECT_EQ(obj.getType(), "Null");
    EXPECT_EQ(obj.getValue(), 0);
}

//end default constructor tests


//start parameterized constructor tests

TEST(ObjectTest, GoblinParameterConstructor) {
    Object obj("Goblin", 10);
    EXPECT_EQ(obj.getType(), "Goblin");
    EXPECT_EQ(obj.getValue(), 10);
}

TEST(ObjectTest, PotionParameterConstructor) {
    Object obj("Potion", 4);
    EXPECT_EQ(obj.getType(), "Potion");
    EXPECT_EQ(obj.getValue(), 4);
}

TEST(ObjectTest, SwordParameterConstructor) {
    Object obj("Sword", 5);
    EXPECT_EQ(obj.getType(), "Sword");
    EXPECT_EQ(obj.getValue(), 5);
}


TEST(ObjectTest, InvalidEmptyStringConstructor) {
    Object obj("", 10);
    EXPECT_EQ(obj.getType(), "Null");
    EXPECT_EQ(obj.getValue(), 10);
}


TEST(ObjectTest, InvalidtypeConstructor) {
    Object obj("wrong_obj", 10);
    EXPECT_EQ(obj.getType(), "Null");
    EXPECT_EQ(obj.getValue(), 10);
}

TEST(ObjectTest, InvalidValuenNegConstructor) {
    Object obj("Goblin", -10);
    EXPECT_EQ(obj.getType(), "Goblin");
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, InvalidOutBoundsConstructor) {
    Object obj("Goblin", 1500);
    EXPECT_EQ(obj.getType(), "Goblin");
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, InvalidParameterConstructor) {
    Object obj("worng_obj", -1500);
    EXPECT_EQ(obj.getType(), "Null");
    EXPECT_EQ(obj.getValue(), 00);
}

//end parameterized constructor tests

//start destructor tests

TEST(ObjectTest, ValidDestructorTest) {
    Object obj;
    EXPECT_EQ(obj.getType(), "Null");
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, DefaultNullTest) {
    Object obj;
    EXPECT_EQ(obj.getType(), "Null");
}

TEST(ObjectTest, DefaultZeroTest) {
    Object obj;
    EXPECT_EQ(obj.getValue(), 0);
}

//end destructor tests

//start setter tests

TEST(ObjectTest, SwordSetterValid) {
    Object obj;
    obj.setType("sword");
    obj.setValue(5);
    EXPECT_EQ(obj.getType(), "sword");
    EXPECT_EQ(obj.getValue(), 5);
}

TEST(ObjectTest, PotionSetterValid) {
    Object obj;
    obj.setType("potion");
    obj.setValue(10);
    EXPECT_EQ(obj.getType(), "potion");
    EXPECT_EQ(obj.getValue(), 10);
}

TEST(ObjectTest, GoblinSettersValid) {
    Object obj;
    obj.setType("Goblin");
    obj.setValue(15);
    EXPECT_EQ(obj.getType(), "Goblin");
    EXPECT_EQ(obj.getValue(), 15);
}

TEST(ObjectTest, ValidSetType) {
    Object obj;
    obj.setType("Sword");
    EXPECT_EQ(obj.getType(), "Sword");
}

TEST(ObjectTest, ValidSetValue) {
    Object obj;
    obj.setValue(5);
    EXPECT_EQ(obj.getValue(), 5);
}

TEST(ObjectTest, InValidSetType) {
    Object obj;
    obj.setType("");
    EXPECT_EQ(obj.getType(), "Null");
}

TEST(ObjectTest, InValidSetValueNeg) {
    Object obj;
    obj.setValue(-10);
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, InValidLargeValue) {
    Object obj;
    obj.setValue(5000);
    EXPECT_EQ(obj.getValue(), 15);
}

//end setter tests

//start getter tests

TEST(ObjectTest, ValidGoblinGetterTest) {
    Object obj("Goblin", 10);
    EXPECT_EQ(obj.getType(), "Goblin");
    EXPECT_EQ(obj.getValue(), 10);
}


TEST(ObjectTest, ValidPotionGetterTest) {
    Object obj("Potion", 10);
    EXPECT_EQ(obj.getType(), "Potion");
    EXPECT_EQ(obj.getValue(), 10);
}

TEST(ObjectTest, ValidSwordGetterTest) {
    Object obj("Sword", 7);
    EXPECT_EQ(obj.getType(), "Sword");
    EXPECT_EQ(obj.getValue(), 7);
}


TEST(ObjectTest, InvalidGetterTyprTest) {
    Object obj("Invalid", 15);
    EXPECT_EQ(obj.getType(), "Null");
    EXPECT_EQ(obj.getValue(), 15);
}

TEST(ObjectTest, InvalidGetterValTest) {
    Object obj("Sword", 1500);
    EXPECT_EQ(obj.getType(), "Sword");
    EXPECT_EQ(obj.getValue(), 15);
}

TEST(ObjectTest, InvalidGetterNegValTest) {
    Object obj("Potion", -15);
    EXPECT_EQ(obj.getType(), "Potion");
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, InvalidValidTotalGetterTest) {
    Object obj("Inavalid", -1000);
    EXPECT_EQ(obj.getType(), "Null");
    EXPECT_EQ(obj.getValue(), 0);
}

//end getter tests

