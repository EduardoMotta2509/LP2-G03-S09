#include <iostream>
#include <vector>
#include <algorithm>
#include "SistemaEntrega.h"
using namespace std;

template <typename T>
void ordenarArreglo(vector<T>& arreglo) {
    int n = arreglo.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arreglo[j] > arreglo[j + 1]) {
                swap(arreglo[j], arreglo[j + 1]);
            }
        }
    }
}

template <typename T>
void mostrarArreglo(const vector<T>& arreglo) {
    for (const T& val : arreglo) {
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    vector<int> paradasInt = {40, 20, 30};
    SistemaEntrega<int> sistema1(0, 50, paradasInt);
    sistema1.generarInforme();
    sistema1.agregarPuntoParada(40);
    sistema1.generarInforme();

    vector<float> paradasFloat = {320.5, 70.2, 40.3};
    SistemaEntrega<float> sistema2(1.0, 10.0, paradasFloat);
    sistema2.generarInforme();

    cout << "\nOrdenando paradas (enteros): ";
    ordenarArreglo(paradasInt);
    mostrarArreglo(paradasInt);

    cout << "\nOrdenando paradas (floats): ";
    ordenarArreglo(paradasFloat);
    mostrarArreglo(paradasFloat);

    return 0;
}