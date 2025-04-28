#include <iostream>
#include "TareaBase.h"
#include "TareaCompuesta.h"
#include "TareaSimple.h"
#include "Usuario.h"
#include "GestorTareas.h"
#include "GestorUsuarios.h"
#include "RepositorioTareas.h"
#include "RepositorioUsuarios.h"
#include "IRepositorioTareas.h"
#include "IRepositorioUsuarios.h"

using namespace std;

//version 21:00 hrs

int main() {
    // Crear repositorios
    IRepositorioTareas* repoTareas = new RepositorioTareas();
    IRepositorioUsuarios* repoUsuarios = new RepositorioUsuarios();

    // Crear gestores con inyección de dependencias
    GestorTareas gestorTareas(repoTareas);
    GestorUsuarios gestorUsuarios((RepositorioUsuarios*)repoUsuarios, (RepositorioTareas*)repoTareas);

    // Crear tareas simples
    TareaSimple* tarea1 = new TareaSimple("1", "Configurar servidor", "Alta", "2025-04-01", "Pendiente");
    TareaSimple* tarea2 = new TareaSimple("2", "Diseñar interfaz", "Media", "2025-04-05", "En progreso");
    
    // Crear tarea compuesta con subtareas
    vector<TareaBase*> subtareas;
    subtareas.push_back(new TareaSimple("3", "Configurar base de datos", "Alta", "2025-04-02", "Pendiente"));
    subtareas.push_back(new TareaSimple("4", "Definir API", "Alta", "2025-04-03", "Pendiente"));
    
    TareaCompuesta* tareaCompuesta = new TareaCompuesta("5", "Desarrollo Backend", "Alta", "2025-04-10", "Pendiente", subtareas);

    // Agregar tareas al gestor
    gestorTareas.agregarTarea(tarea1);
    gestorTareas.agregarTarea(tarea2);
    gestorTareas.agregarTarea(tareaCompuesta);

    // Crear usuarios
    vector<TareaBase*> tareasVacias;
    Usuario* usuario1 = new Usuario("u1", "Carlos", tareasVacias);
    Usuario* usuario2 = new Usuario("u2", "Ana", tareasVacias);

    // Agregar usuarios al gestor
    gestorUsuarios.agregarUsuario(usuario1);
    gestorUsuarios.agregarUsuario(usuario2);

    // Asignar tareas a usuarios
    gestorUsuarios.asignarTarea("1", "u1");
    gestorUsuarios.asignarTarea("2", "u2");

    // Mostrar tareas y usuarios
    gestorTareas.mostrarTarea();
    gestorUsuarios.mostrarUsuario();

    // Liberar memoria
    delete tarea1;
    delete tarea2;
    delete tareaCompuesta;
    delete usuario1;
    delete usuario2;
    delete repoTareas;
    delete repoUsuarios;

    cout << "Presiona Enter para salir...";
    cin.get();

    return 0;
}
