#ifndef GESTORUSUARIOS_H
#define GESTORUSUARIOS_H

#include <iostream>
#include <vector>
#include "Usuario.h"
#include "IRepositorioTareas.h"
#include "IRepositorioUsuarios.h"
#include "IUsuarioGestionable.h"
#include "IVisualizarUsuario.h"

using namespace std;

class GestorUsuarios : public IVisualizarUsuario , public IUsuarioGestionable{
private:
    IRepositorioUsuarios* repo;
    IRepositorioTareas* repoTareas;
public:
    GestorUsuarios(IRepositorioUsuarios* _repo, IRepositorioTareas* _repoTareas) : repo(_repo) , repoTareas(_repoTareas){}

    void agregarUsuario(Usuario* nuevoUsuario) override {
        repo->guardarUsuario(*nuevoUsuario);
    }

    void eliminarUsuario(string idUsuario) override {
        repo->eliminarUsuario(idUsuario);
    }

    void asignarTarea(string idTarea, string idUsuario){
        Usuario* usuario = repo->buscarUsuarioXID(idUsuario);
        TareaBase* tarea = repoTareas->buscarTareaXID(idTarea);
        if (!usuario || !tarea) {
            cout << "Usuario o tarea no encontrados" << endl;
            return;
        }
        else{
            usuario->asignarTarea(tarea);
        }
    }

    void mostrarUsuario() override {
        vector<Usuario> usuarios = repo->listarUsuarios();
        cout<<"Usuarios en el sistema: "<<endl;
        for ( Usuario& usuario : usuarios){
            usuario.mostrarUsuario();
        }
    }
    
};
#endif

