#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "ComponenteA.h"
#include "ComponenteB.h"

using namespace std;

class Sistema {
private:
    ComponenteA a;
    ComponenteB b;
public:
    Sistema() {
        cout << "Constructor de Sistema" << endl;
    }
    ~Sistema() {
        cout << "Destructor de Sistema" << endl;
    }
};

#endif