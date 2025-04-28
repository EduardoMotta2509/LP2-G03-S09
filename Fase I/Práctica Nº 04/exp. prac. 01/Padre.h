#ifndef PADRE_H
#define PADRE_H
#include <string>
#include <vector>
#include "Hijo.h"
using namespace std;

class Padre{
    private:
    string nombre;
    static const int max_hijos = 10;
    Hijo* hijos[max_hijos];
    int numHijos;

    public:
    Padre();
    Padre(string nom);

    void setNombre(string nom);
    string getNombre();

    void agregarHijo(Hijo* h);
    void imprimirInfo();
};
#endif