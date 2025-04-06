#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <vector>

using namespace std;

class Curso;

class Estudiante{
    private:
    string nombre;
    string apellido;
    string id;
    string correo;
    vector<Curso*> cursos;
    
    public:
    Estudiante(string nombre, string apellido, string id, string correo);

    string getNombreCompleto() const;
    string getId() const;

    void agregarCurso(Curso* curso);
    void eliminarCurso(Curso* curso);
    
    void imprimirCursos() const;
};
#endif