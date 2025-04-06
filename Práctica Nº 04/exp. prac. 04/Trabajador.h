#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trabajador {
protected:
    string nombre;
    int id;
    vector<Trabajador*> companeros; // Asociación reflexiva

public:
    Trabajador(string n, int i) : nombre(n), id(i) {}

    void agregarCompanero(Trabajador* t) {
        companeros.push_back(t);
    }

    void mostrarInfo() {
        cout << "Trabajador: " << nombre << " (ID: " << id << ")" << endl;
    }

    void mostrarCompaneros() {
        cout << "Compañeros de " << nombre << ":" << endl;
        for (Trabajador* t : companeros) {
            cout << " - " << t->nombre << " (ID: " << t->id << ")" << endl;
        }
        cout << endl;
    }
};

#endif