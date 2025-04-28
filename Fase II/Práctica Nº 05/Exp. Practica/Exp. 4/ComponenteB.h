#ifndef COMPONENTEB_H
#define COMPONENTEB_H

#include <iostream>

using namespace std;

class ComponenteB {
public:
    ComponenteB() {
        cout << "Constructor de ComponenteB" << endl;
    }
    ~ComponenteB() {
        cout << "Destructor de ComponenteB" << endl;
    }
};

#endif