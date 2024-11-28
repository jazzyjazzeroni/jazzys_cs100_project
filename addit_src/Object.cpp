#include "../addit_header/Object.h"
#include <iostream>
#include <string>
using namespace std;

Object::Object() : type("Null"), value(0) {}

Object::Object(const string& type, int value) : type(type), value(value) {}

string Object::getType() const {
    return type;
}

int Object::getValue() const {
    return value;
}   

 void Object::setType(const string& newType) {
    type = newType;
 }
void Object::setValue(int newValue) {
    value = newValue;
}   

void Object::print() const {
    cout << "Name: " << type << ", Value: " << value << endl;
}
// int main() {
//     Object sword("Sword", 10);
//     sword.print();

//     sword.setType("Potion");
//     sword.setValue(15);
//     sword.print();

//     return 0;
// } works fine