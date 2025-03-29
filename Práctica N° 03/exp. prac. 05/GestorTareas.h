#ifndef GESTORTAREAS_H
#define GESTORTAREAS_H

#include <iostrem>
#include <vector>
#include "Interfaces.h"
#include "Tareas.h"
#include "Usuario.h"

using namespace std;

class GestorTareas : public IMostrable, public IGestionable{
public:
    vector<Usuario> usuarios;
    vector<TareaBase> tareas;

    GestorTareas(vector<Usuario> _usuarios, vector<TareaBase> _tareas){
        usuarios=_usuarios;
        tarea=_tareas;
    }

    void agregarUsuario(Usuario nuevoUsuario){
        usuarios.push_back(nuevoUsuario);
    }

    void agregarTarea(Tarea nuevaTarea){
        tareas.push_back(nuevaTarea);
    }

    void eliminarTarea(string idTarea){
        for ( int i=0; i<tareas.size(); i++ ){
            if ( tareas[i].getId == idTarea ){
                tareas.erase( tareas.begin() + i );
            }
        }
        return false;
    }

    bool buscarUsuarioXID(string idUsuario){
        for ( int i=0; i<usuarios.size(); i++ ){
            if( usuarios[i].getID == idUsuario ){
                return true;
                break;
            }
        }
    }
    bool buscarTareaXID(string idTarea){
        for ( int i=0; i<tareas.size(); i++ ){
            if (tareas.[i].getId == idTarea){
                return true;
                break;
            }
        }
        return false;
    }

    void asignarTarea(string idUsuario, string idTarea){
        if (buscarTareaXID(idTarea) && buscarUsuarioXID(idUsuario)){
            for ( int i=0; i<tareas.size(); i++ ){
                if (tareas.[i].getId == idTarea){
                    Tarea tareaXAsignar=tareas[i];
                }
            }
            for ( int i=0; i<usuarios.size(); i++ ){
                if( usuarios[i].getID == idUsuario ){
                    usuarios[i].asignarTarea(tareaXAsignar);
                }
            }
        }
    }

    void mostrarInformación() override {
        cout<<"Tareas en el sistema: "<<endl;
        for ( int i=0; i<tareas.size; i++ ){
            tareas[i].mostrarInformación();
        }
    }

};
#endif