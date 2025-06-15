#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Contenedor {
private:
    vector<T> datos;

public:
    void agregar(T elemento) {
        datos.push_back(elemento);
    }

    void mostrar() {
        cout << "[ ";
        for (const T& elem : datos) {
            cout << elem << " ";
        }
        cout << "]" << endl;
    }

    T obtener(int index) const {
        if (index >= 0 && index < datos.size()) {
            return datos[index];
        } else {
            cout<<"Índice fuera de rango"<<endl;
            return 0;
        }
    }

    int tamaño() {
        return datos.size();
    }
};

#endif