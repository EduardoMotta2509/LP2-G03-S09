#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <string>
using namespace std;

class Curso {
private:
    string nombreCurso;
    int codigo;
public:
    Curso(string n, int c) : nombreCurso(n), codigo(c) {}
    void mostrarInfo() {
        cout << "Curso: " << nombreCurso << " (Código: " << codigo << ")" << endl;
    }
};

#endif