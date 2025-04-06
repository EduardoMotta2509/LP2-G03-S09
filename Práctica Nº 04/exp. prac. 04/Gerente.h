#ifndef GERENTE_H
#define GERENTE_H

#include "Trabajador.h"

class Gerente : public Trabajador {
private:
    vector<Trabajador*> trabajadoresACargo;
public:
    Gerente(string n, int i) : Trabajador(n, i) {}

    void agregarTrabajador(Trabajador* t) {
        trabajadoresACargo.push_back(t);
    }

    void mostrarTrabajadoresACargo() {
        cout << "Trabajadores a cargo de " << nombre << ":" << endl;
        for (Trabajador* t : trabajadoresACargo) {
            cout << " - " << t->nombre << " (ID: " << t->id << ")" << endl;
        }
        cout << endl;
    }
};

#endif