#include <iostream>
#include "Curso.h"
#include "Estudiante.h"
using namespace std;
// ========= SOLO ESTUDIANTE==========
Estudiante::Estudiante(string nombre, string apellido, string id, string correo): nombre(nombre), apellido(apellido), id(id), correo(correo) {}

void Estudiante::agregarCurso(Curso* curso){
    for (Curso* c : cursos){
        if (c == curso) return;
    }
    cursos.push_back(curso);
    curso->agregarEstudiante(this);
}

void Estudiante::eliminarCurso (Curso* curso){
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        if (*it == curso){
            cursos.erase(it);
            curso->eliminarEstudiante(this);
            break;
        }
    }
}

void Estudiante::imprimirCursos() const{
    cout<<"Estudiante: "<<getNombreCompleto()<<"(ID: "<<id<<")"<<endl;
    cout<<"Cursos inscritos: "<<endl;
    for(Curso* c : cursos){
        cout<<" -"<<c->getNombre()<<" ("<< c->getCodigo()<<") "<<endl;
    }
    cout<<endl;
}

string Estudiante::getNombreCompleto() const{
    return nombre + " "+ apellido;
}

string Estudiante::getId() const{
    return id;
}

//====== SOLO CURSO ========

Curso::Curso(string nombre, string codigo, string descripcion, string fechaInicio, string fechaFin) : nombre(nombre),codigo(codigo), descripcion(descripcion), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

void Curso::agregarEstudiante(Estudiante* estudiante){
    for(Estudiante* e : estudiantes) {
        if (e == estudiante) return;
    }
    estudiantes.push_back(estudiante);

    estudiante->agregarCurso(this);
}

void Curso::eliminarEstudiante(Estudiante* estudiante){
    for(auto it = estudiantes.begin(); it != estudiantes.end(); ++it){
        if(*it==estudiante){
            estudiantes.erase(it);

            estudiante->eliminarCurso(this);
            break;
        }
    }
}

void Curso::imprimirEstudiantes() const{
    cout<<"Curso: "<<nombre<<" ("<<codigo<<") "<<endl;
    cout<<"Estudiantes inscritos:"<<endl;
    for(Estudiante* e : estudiantes){
        cout<<" -"<<e->getNombreCompleto()<<"(ID: "<<e->getId()<<")"<<endl;
    }
    cout<<endl;
}

string Curso::getNombre() const{
    return nombre;
}
string Curso::getCodigo() const{
    return codigo;
}

//===== FUNCIÓN PRINCIPAL======
 int main(){
    Estudiante e1("Eduardo", "Motta", "2024001337", "emmf@gmail.com");
    Estudiante e2("Nicolas", "Calle", "2024001355", "nica@gmail.com");
    Estudiante e3("Jose", "Lima", "2024023156", "jose.lima@gmail.com");

    Curso c1("Comunicación", "COM01","Curso de comu","06/02/2025","28/04/2025");
    Curso c2("Matemática", "MAT02","Curso de matemática básica","10/03/2025","12/05/2025");

    c1.agregarEstudiante(&e1);
    c1.agregarEstudiante(&e2);

    c2.agregarEstudiante(&e2);
    c2.agregarEstudiante(&e3);

    c1.imprimirEstudiantes();
    c2.imprimirEstudiantes();

    e1.imprimirCursos();
    e2.imprimirCursos();
    e3.imprimirCursos();

    c1.eliminarEstudiante(&e2);

    cout<<"Nico se ha portado mal así que lo sacaron del curso de comu"<<endl;

    c1.imprimirEstudiantes();
    e2.imprimirCursos();

    return 0;
 }