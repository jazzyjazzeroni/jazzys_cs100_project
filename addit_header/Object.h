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

    string getType() const;
    void setType(const string& newType);
    int getValue() const;
    void setValue(int newValue);
    void print() const;
};

#endif
