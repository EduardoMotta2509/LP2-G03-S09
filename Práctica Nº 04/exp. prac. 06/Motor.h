#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
using namespace std;

class Motor {
private:
    int caballosFuerza;
public:
    Motor(int hp = 100) : caballosFuerza(hp) {}

    void setHP(int hp) {
        caballosFuerza = hp;
    }

    int getHP() const {
        return caballosFuerza;
    }

    void mostrarInfo() const {
        cout << "Motor con " << caballosFuerza << " HP" << endl;
    }
};

#endif
