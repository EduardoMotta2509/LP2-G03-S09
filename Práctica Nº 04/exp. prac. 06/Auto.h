#ifndef AUTO_H
#define AUTO_H

#include "Motor.h"
#include <iostream>
using namespace std;

class Auto {
private:
    string marca;
    Motor* motor; 

public:
    Auto(string m, int hp) : marca(m) {
        motor = new Motor(hp);
    }

    ~Auto() {
        delete motor;
        cout << "Motor destruido al eliminar el auto." << endl;
    }

    Motor& getMotor() {
        return *motor;
    }

    void mostrarAuto() const {
        cout << "Auto marca " << marca << " con ";
        motor->mostrarInfo();
    }
};
#endif
