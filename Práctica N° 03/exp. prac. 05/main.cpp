#include <iostream>
#include "Tareas.h"
#include "Usuario.h"

using namespace std;

int main() {
    // Crear algunas tareas simples
    TareaSimple tarea1("1", "Configurar servidor",  "Alta", "2025-04-01", "Pendiente");
    TareaSimple tarea2("2", "Diseñar interfaz", "Media", "2025-04-05", "En progreso");
    
    // Crear una tarea compuesta
    vector<TareaBase*> subtareas;
    subtareas.push_back(new TareaSimple("3", "Configurar base de datos", "Alta", "2025-04-02", "Pendiente"));
    subtareas.push_back(new TareaSimple("4", "Definir API", "Alta", "2025-04-03", "Pendiente"));
    
    TareaCompuesta tareaCompuesta("5", "Desarrollo backend", "Alta", "2025-04-10", "Pendiente", subtareas);
    
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
