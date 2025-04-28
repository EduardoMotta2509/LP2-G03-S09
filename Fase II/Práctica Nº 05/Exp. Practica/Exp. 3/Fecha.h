#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>

using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
};

#endif 