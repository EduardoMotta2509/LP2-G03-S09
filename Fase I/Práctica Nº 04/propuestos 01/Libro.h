#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include "Autor.h"
using namespace std;

class Libro{
private:
    string isbn;
    string titulo;    
    int cantEjemplares;
    int añoPublicacion;
    Autor* autor;
public:
    Libro(string _isbn, string _titulo, int _añoPublicacion, int _cantEjemplares, Autor* _autor) : isbn(_isbn), titulo(_titulo), cantEjemplares(_cantEjemplares), añoPublicacion(_añoPublicacion),autor(_autor) {}

    string getISBN(){ return isbn; }
    string getTitulo(){ return titulo; }
    int getCantEjemplares() { return cantEjemplares; }
    int getAñoPublicacion() { return añoPublicacion; }
    Autor* getAutor() { return autor; }

    void reducirCantEjemplares(int cant){
        if (cant <= 0) {
            cout << "Cantidad inválida para reducir" << endl;
            return;
        }

        if (cantEjemplares >= cant) {
            cantEjemplares-=cant;
        }
        else {
            cout<<"No hay suficientes ejemplares para reducir"<<endl;
        }
    }
};
#endif