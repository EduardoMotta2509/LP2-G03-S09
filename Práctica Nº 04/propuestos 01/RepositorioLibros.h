#ifndef REPOSITORIOLIBROS_H
#define REPOSITORIOLIBROS_H

#include <iostream>
#include <vector>
#include "Libro.h"
using namespace std;

class RepositorioLibros{
private:
    vector<Libro*> libros;
public:
    RepositorioLibros(vector<Libro*> _libros) : libros(_libros) {}

    bool buscarXisbn(string isbn){
        for (int i=0; i<libros.size(); i++) {
            if (libros[i]->getISBN() == isbn) {
                cout<<"Libro con ISBN: "<<isbn<<" encontrado"<<endl;
                return true;
            }
        }
        return false;
    }
    void registrarLibro(Libro* nuevoLibro){
        libros.push_back(nuevoLibro);
    }

};
#endif