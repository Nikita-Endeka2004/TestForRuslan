#include "pch.h"
#include "classLib.h"

MyClass::MyClass(int val) : value(val) {}
MyClass::MyClass(const MyClass& other) : value(other.value) {}
int& MyClass::operator[](int index) { return value; }
MyClass& MyClass::operator=(const MyClass& other) {
    value = other.value;
    return *this;
}
int* MyClass::operator->() { return &value; }
void MyClass::operator()(int val) { value = val; }
std::ostream& operator<<(std::ostream& ost, const MyClass& tree) {
    ost << tree.value;
    return ost;
}
std::istream& operator>>(std::istream& ist, const MyClass& tree) {
    ist >> tree.value;
    return ist;
}
void MyClass::showDialog() {
    std::cout << "Enter a value: ";
    std::cin >> value;
}
