#ifndef COMPONENTEA_H
#define COMPONENTEA_H

#include <iostream>

using namespace std;

class ComponenteA {
public:
    ComponenteA() {
        cout << "Constructor de ComponenteA" << endl;
    }
    ~ComponenteA() {
        cout << "Destructor de ComponenteA" << endl;
    }
};

#endif