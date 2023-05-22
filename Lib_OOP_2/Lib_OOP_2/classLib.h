#ifndef _CLASSLIB_H_
#define _CLASSLIB_H_
#include <iostream>
#include <fstream>
class MyClass {
    friend std::ostream& operator<<(std::ostream& ost, const MyClass& tree);
    friend std::istream& operator>>(std::istream& ifst, const MyClass& tree);
public:

    MyClass() : value(0) {}    // Default constructor

    MyClass(int val);   // Constructor with parameters

    MyClass(const MyClass& other);    // Copy constructor

    int& operator[](int index);    // Overloading [] for indexing

    MyClass& operator=(const MyClass& other);    // Overloading = for assignment

    int* operator->();     // Overloading -> for "smart access"

    void operator()(int val);    // Pseudo variable (setter)

    void showDialog();
    bool operator<(const MyClass& other) const {
        return value < other.value;
    }

    bool operator>(const MyClass& other) const {
        return value > other.value;
    }

    bool operator==(const MyClass& other) const {
        return value == other.value;
    }

    bool operator!=(const MyClass& other) const {
        return !(*this == other);
    }

protected:
    int value;
};
#endif