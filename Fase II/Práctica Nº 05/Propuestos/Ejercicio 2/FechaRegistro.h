#ifndef FECHAREGISTRO_H
#define FECHAREGISTRO_H

#include <iostream>
using namespace std;

class FechaRegistro{
private:
    int dia, mes, anio;
public:
    FechaRegistro(int d, int m, int a) : dia(d), mes(m), anio(a) {}
    void mostrarFechaRegistro() const {
    cout<<"Fecha de Registro: "<< dia << "/" << mes << "/" << anio << endl;
    }
};
#endif