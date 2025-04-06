#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <iostream>
#include <vector>
#include "Libro.h"
#include "Usuario.h"
using namespace std;

class Prestamo{
private:
    string fechaPrestamo;
    string fechaDevolucion;
    Libro* libroPrestado;
    Usuario* usuarioPrestando;
    RepositorioLibros* repoL;
    RepositorioUsuarios repoU;
public:
    Prestamo(string _fechaPrestamo, string _fechaDevolucion, Libro* _libroPrestado, Usuario* _usuarioPrestando, RepositorioLibros* _repoL, RepositorioUsuarios* _repoU) : fechaPrestamo(_fechaPrestamo), fechaDevolucion(_fechaDevolucion), libroPrestado(_libroPrestado), usuarioPrestando(_usuarioPrestando),  repoL(_repoL), repoU(_repoU) {}

    void realizarPrestamo(int cant){
        if (repoU->buscarXnombre(usuarioPrestando->getNombre()) && repoL->buscarXisbn(libroPrestado->getISBN())) {
            cout<<"Libro: "<<libroPrestado->getTitulo()<<" prestado a usuario: "<<usuarioPrestando->getNombre()<<endl;
            libroPrestado->reducirCantEjemplares(cant);
            usuarioPrestando->añadirLibroPrestado(libroPrestado);
        }
        else {
            cout << "Error al realizar el préstamo. Verifica que el libro y el usuario existan." << endl;
        }
    }
};
#endif