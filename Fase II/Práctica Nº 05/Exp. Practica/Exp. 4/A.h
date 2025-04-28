#ifndef A_H
#define A_H

#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "Constructor de A" << endl;
    }
    ~A() {
        cout << "Destructor de A" << endl;
    }
};

#endif