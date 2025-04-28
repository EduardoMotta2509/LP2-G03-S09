#ifndef REPOSITORIOUSUARIOS_H
#define REPOSITORIOUSUARIOS_H

#include <vector>
#include <iostream>
#include "Usuario.h"
#include "IRepositorioUsuarios.h"

class RepositorioUsuarios : public IRepositorioUsuarios {
private:
    vector<Usuario> usuarios;

public:
    void guardarUsuario(Usuario usuario) override {
        usuarios.push_back(usuario);
    }
    
    void eliminarUsuario(string idUsuario) override {
        for ( int i=0; i<usuarios.size(); i++ ){
            if ( usuarios[i].getID() == idUsuario ){
                usuarios.erase(usuarios.begin() + i);
                break;
            }
        }
    }
    
    vector<Usuario> listarUsuarios() override {
        return usuarios;
    }
    
    Usuario* buscarUsuarioXID(string idUsuario) override {
        for ( int i=0; i<usuarios.size(); i++ ){
            if( usuarios[i].getID() == idUsuario ){
                return &usuarios[i];
                break;
            }
        }
        return nullptr;
    }
};
#endif
