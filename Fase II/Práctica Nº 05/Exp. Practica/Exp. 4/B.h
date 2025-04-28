#ifndef B_H
#define B_H

#include <iostream>
#include "A.h"

using namespace std;

class B {
private:
    A a;
public:
    B() {
        cout << "Constructor de B" << endl;
    }
    ~B() {
        cout << "Destructor de B" << endl;
    }
};

#endif