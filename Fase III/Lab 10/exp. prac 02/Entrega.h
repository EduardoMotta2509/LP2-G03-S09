#ifndef ENTREGA_H
#define ENTREGA_H

#include <iostream>
using namespace std;

class Entrega {
public:
    static int codigo;

    Entrega() {
        codigo++;
    }

    template <typename T>
    void asignarVehiculo(T vehiculo){
        cout << "Entrega [" << codigo << "] asignada al vehículo: " << vehiculo << endl;
    }

    template <typename T>
    void planificarHorario(T horaSalida){
        cout << "Entrega [" << codigo << "] programada para las: " << horaSalida << endl;
    }
};
#endif
