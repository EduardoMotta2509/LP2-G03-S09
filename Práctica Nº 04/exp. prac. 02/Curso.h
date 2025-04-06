#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <vector>
using namespace std;

class Estudiante;
class Curso{
    private:
    string nombre;
    string codigo;
    string descripcion;
    string fechaInicio;
    string fechaFin;
    vector<Estudiante*> estudiantes;

    public:
    Curso(string nombre, string codigo, string descripcion, string fechaInicio, string fechaFin);

    string getNombre() const;
    string getCodigo() const;

    void agregarEstudiante(Estudiante* estudiante);
    void eliminarEstudiante(Estudiante* estudiante);

    void imprimirEstudiantes() const;
};
#endif