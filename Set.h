#ifndef SET_H
#define SET_H

#include <iostream>

class Set {
private:
    int* data;
    int size;




    
    bool exists(int value) const;

public:
    Set();
    ~Set();
    Set(const Set& other);      // copy constructor
    Set& operator=(const Set& other); // copy assignment

    Set& operator+=(int value); // add
    Set& operator-=(int value); // remove

    friend Set operator*(const Set& a, const Set& b); // intersection
    friend Set operator+(const Set& a, const Set& b); // union
    friend Set operator-(const Set& a, const Set& b); // difference

    void print() const;
};




















#endif
