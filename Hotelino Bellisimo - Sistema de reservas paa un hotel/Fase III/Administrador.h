#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include <limits>
#include <vector>
#include "Huesped.h"
#include "HotelManager.h"
using namespace std;

class Administrador : public Huesped{
private:
    static HotelManager* hotelManager;
    
public:
    Administrador() : Huesped() {}
    
    Administrador(string user, string password, bool esAdmin) 
        : Huesped(user, password, esAdmin) {}
    
    static void setHotelManager(HotelManager* manager) {
        hotelManager = manager;
    }
    
    // Función 1: Crear nueva habitación
    void funcionAdmin1(){
        cout << "\n=== CREAR NUEVA HABITACIÓN ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        int codigo;
        double tarifa;
        
        cout << "Código de habitación: ";
        while (!(cin >> codigo)) {
            cout << "Entrada inválida. Ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        TipoHabitacion tipo = hotelManager->solicitarTipoHabitacion();
        
        cout << "Tarifa base: $";
        while (!(cin >> tarifa) || tarifa <= 0) {
            cout << "Entrada inválida. Ingrese una tarifa válida: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        hotelManager->crearHabitacion(tipo, codigo, tarifa);
    }
    
    // Función 2: Actualizar tarifa de habitación
    void funcionAdmin2(){
        cout << "\n=== ACTUALIZAR TARIFA ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        int codigo;
        double nuevaTarifa;
        
        cout << "Código de habitación: ";
        while (!(cin >> codigo)) {
            cout << "Entrada inválida. Ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Nueva tarifa: $";
        while (!(cin >> nuevaTarifa) || nuevaTarifa <= 0) {
            cout << "Entrada inválida. Ingrese una tarifa válida: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        hotelManager->actualizarTarifa(codigo, nuevaTarifa);
    }
    
    // Función 3: Bloquear/Desbloquear habitación
    void funcionAdmin3(){
        cout << "\n=== GESTIÓN DE BLOQUEO ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        int codigo, opcion;
        
        cout << "Código de habitación: ";
        while (!(cin >> codigo)) {
            cout << "Entrada inválida. Ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "1. Bloquear" << endl;
        cout << "2. Desbloquear" << endl;
        cout << "3. Poner en mantenimiento" << endl;
        cout << "Seleccione opción: ";
        
        while (!(cin >> opcion) || opcion < 1 || opcion > 3) {
            cout << "Entrada inválida. Ingrese 1, 2 o 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        switch (opcion) {
            case 1:
                hotelManager->bloquearHabitacion(codigo);
                break;
            case 2:
                hotelManager->desbloquearHabitacion(codigo);
                break;
            case 3:
                hotelManager->ponerEnMantenimiento(codigo);
                break;
        }
    }
    
    // Función 4: Buscar habitaciones por código
    void funcionAdmin4(){
        cout << "\n=== BUSCAR POR CÓDIGO ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        int codigo;
        cout << "Código de habitación: ";
        while (!(cin >> codigo)) {
            cout << "Entrada inválida. Ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        hotelManager->buscarPorCodigo(codigo);
    }
    
    // Función 5: Buscar habitaciones por tipo
    void funcionAdmin5(){
        cout << "\n=== BUSCAR POR TIPO ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        TipoHabitacion tipo = hotelManager->solicitarTipoHabitacion();
        hotelManager->buscarPorTipo(tipo);
    }
    
    // Función 6: Buscar habitaciones por rango de precio
    void funcionAdmin6(){
        cout << "\n=== BUSCAR POR PRECIO ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        double minimo, maximo;
        
        cout << "Precio mínimo: $";
        while (!(cin >> minimo) || minimo < 0) {
            cout << "Entrada inválida. Ingrese un precio válido: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Precio máximo: $";
        while (!(cin >> maximo) || maximo < minimo) {
            cout << "Entrada inválida. Debe ser mayor que el mínimo: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        hotelManager->buscarPorRangoPrecio(minimo, maximo);
    }
    
    // Función 7: Cancelar reserva (administrador)
    void funcionAdmin7(){
        cout << "\n=== CANCELAR RESERVA ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        int idReserva;
        string userHuesped;
        
        cout << "ID de reserva: ";
        while (!(cin >> idReserva)) {
            cout << "Entrada inválida. Ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Usuario del huésped: ";
        cin >> userHuesped;
        
        hotelManager->cancelarReserva(idReserva, userHuesped);
    }
    
    // Función 8: Generar reporte de ocupación
    void funcionAdmin8(){
        cout << "\n=== REPORTE DE OCUPACIÓN ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        hotelManager->generarReporteOcupacion();
    }
    
    // Función 9: Generar reporte de ingresos
    void funcionAdmin9(){
        cout << "\n=== REPORTE DE INGRESOS ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        hotelManager->generarReporteIngresos();
    }
    
    // Función 10: Listar todas las habitaciones y reservas
    void funcionAdmin10(){
        cout << "\n=== LISTADOS COMPLETOS ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        int opcion;
        cout << "1. Listar todas las habitaciones" << endl;
        cout << "2. Listar todas las reservas" << endl;
        cout << "Seleccione opción: ";
        
        while (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
            cout << "Entrada inválida. Ingrese 1 o 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if (opcion == 1) {
            hotelManager->listarTodasLasHabitaciones();
        } else {
            hotelManager->listarTodasLasReservas();
        }
    }
};

// Inicializar el puntero estático
HotelManager* Administrador::hotelManager = nullptr;

#endif
