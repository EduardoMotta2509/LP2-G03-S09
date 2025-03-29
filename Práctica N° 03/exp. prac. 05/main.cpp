#include <iostream>
#include "Tareas.h"
#include "Usuario.h"

using namespace std;

int main() {
    // Crear algunas tareas simples
    TareaSimple tarea1("1", "Configurar servidor", "Pendiente", "Alta", "2025-04-01");
    TareaSimple tarea2("2", "Diseñar interfaz", "En progreso", "Media", "2025-04-05");
    
    // Crear una tarea compuesta
    vector<TareaBase*> subtareas;
    subtareas.push_back(new TareaSimple("3", "Configurar base de datos", "Pendiente", "Alta", "2025-04-02"));
    subtareas.push_back(new TareaSimple("4", "Definir API", "Pendiente", "Alta", "2025-04-03"));
    
    TareaCompuesta tareaCompuesta("5", "Desarrollo backend", "Pendiente", "Alta", "2025-04-10", subtareas);
    
    // Crear usuario y asignar tareas
    Usuario usuario("U1", "Eduardo", {});
    usuario.asignarTarea(&tarea1);
    usuario.asignarTarea(&tarea2);
    usuario.asignarTarea(&tareaCompuesta);
    
    // Mostrar información del usuario y sus tareas
    cout << "=== Información del usuario ===\n";
    usuario.mostrarInformación();
    
    // Desasignar una tarea
    cout << "\n=== Eliminando tarea 2 ===\n";
    usuario.desasignarTarea("2");
    usuario.mostrarInformación();
    
    
    return 0;
}