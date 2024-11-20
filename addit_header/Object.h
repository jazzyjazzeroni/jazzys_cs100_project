#include <string>
#ifndef OBJECT_H
#define OBJECT_H
using namespace std;

class Object {
public:
    string type; // "character" | "sword" | "potion" | "empty"

    Object();
    Object(const string& type);

    string getType() const;
    void setType(const string& newType);
};

#endif