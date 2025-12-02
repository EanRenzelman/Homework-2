#include <iostream>
#include "Set.h"
using namespace std;

int main() {
    Set first;
    first += 10;
    first += 13;
    first += 14;
    first += 17;
    first += 19;

    Set second;
    second += 11;
    second += 13;
    second += 14;
    second += 16;
    second += 20;

    cout << "First set: ";
    first.print();

    cout << "Second set: ";
    second.print();

    cout << "Union: ";
    Set unionSet = first + second;
    unionSet.print();

    cout << "Intersection: ";
    Set interSet = first * second;
    interSet.print();

    cout << "Difference (first - second): ";
    Set diff1 = first - second;
    diff1.print();

    cout << "Difference (second - first): ";
    Set diff2 = second - first;
    diff2.print();

    return 0;
}
