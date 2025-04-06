#ifndef REPOSITORIOUSUARIOS_H
#define REPOSITORIOUSUARIOS_H

#include <iostream>
#include <vector>
#include "Usuario.h"
using namespace std;

class RepositorioUsuarios {
private:
    vector<Usuario*> usuarios;
public:
    RepositorioUsuarios(vector<Usuario*> _usuarios) : usuarios(_usuarios) {}

    bool buscarXnombre(string nombre){
        for (int i=0; i<usuarios.size(); i++) {
            if (usuarios[i]->getNombre() == nombre) {
                cout<<"Usuario con nombre: "<<nombre<<" encontrado"<<endl;
                return true;
            }
        }
        return false;
    }

    void registrarUsuario(Usuario* nuevoUsuario){
        usuarios.push_back(nuevoUsuario);
    }
};
#endif