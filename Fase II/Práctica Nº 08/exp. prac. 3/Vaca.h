#ifndef VACA_H
#define VACA_H

#include "Animal.h"

class Vaca : public Animal {
public:
    void hacerSonido() override {
        cout << "La vaca dice: Muuuuu" << endl;
    }
};

#endif
