#ifndef HIJO_H
#define HIJO_H

#include <string>
using namespace std;

class Hijo{
    private:
    string nombre;

    public:
    Hijo();
    Hijo(string nom);

    void setNombre(string nom);
    string getNombre();
};
#endif