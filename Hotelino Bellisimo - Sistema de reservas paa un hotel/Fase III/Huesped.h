#ifndef HUESPED_H
#define HUESPED_H
#include <iostream>
#include <limits>
#include "HotelManager.h"
using namespace std;

class Huesped{
private:
    string password;
    string user;
    bool esAdmin;
    
protected:
    static HotelManager* hotelManager;
    
public:
    Huesped(){
        user = "sin user";
        password = "sin password";
        esAdmin = false;
    }
    
    Huesped(string user, string password, bool esAdmin) 
        : user(user), password(password), esAdmin(esAdmin) {
        if(esAdmin){
            cout<<"Cuenta ADMINISTRADOR creada exitosamente!"<<endl;
        } else{
            cout<<"Cuenta HUESPED creada exitosamente!"<<endl;
        }
    }
    
    // Getters
    string getUser() const { return user; }
    string getPassword() const { return password; }
    bool getEsAdmin() const { return esAdmin; }
    
    // Setters
    void setUser(const string& newUser){ user = newUser; }
    void setPassword(const string& newPassword){ password = newPassword; }
    void setEsAdmin(bool admin){ esAdmin = admin; }
    
    // Método estático para inicializar el HotelManager
    static void setHotelManager(HotelManager* manager) {
        hotelManager = manager;
    }
    
    // Función 1: Buscar habitaciones disponibles
    void funcionHuesped1(){
        cout << "\n=== BUSCAR HABITACIONES DISPONIBLES ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        cout << "Ingrese las fechas de su estadía:" << endl;
        Fecha entrada = hotelManager->solicitarFecha("Fecha de entrada:");
        Fecha salida = hotelManager->solicitarFecha("Fecha de salida:");
        
        if (!(entrada < salida)) {
            cout << "Error: La fecha de entrada debe ser anterior a la de salida." << endl;
            return;
        }
        
        int opcion;
        cout << "\n¿Desea filtrar por tipo de habitación?" << endl;
        cout << "1. Sí" << endl;
        cout << "2. No, mostrar todas" << endl;
        cout << "Seleccione opción: ";
        
        while (!(cin >> opcion) || (opcion != 1 && opcion != 2)) {
            cout << "Entrada inválida. Ingrese 1 o 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if (opcion == 1) {
            TipoHabitacion tipo = hotelManager->solicitarTipoHabitacion();
            vector<int> disponibles = hotelManager->buscarDisponibles(entrada, salida, tipo);
            
            if (disponibles.empty()) {
                cout << "No hay habitaciones disponibles del tipo seleccionado." << endl;
            } else {
                cout << "\nHabitaciones disponibles:" << endl;
                for (int codigo : disponibles) {
                    hotelManager->buscarPorCodigo(codigo);
                    cout << endl;
                }
            }
        } else {
            hotelManager->mostrarHabitacionesDisponibles(entrada, salida);
        }
    }
    
    // Función 2: Realizar reserva
    void funcionHuesped2(){
        cout << "\n=== REALIZAR RESERVA ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        int codigoHab;
        cout << "Código de habitación a reservar: ";
        while (!(cin >> codigoHab)) {
            cout << "Entrada inválida. Ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        // Mostrar información de la habitación
        cout << "\nInformación de la habitación seleccionada:" << endl;
        hotelManager->buscarPorCodigo(codigoHab);
        
        cout << "\nIngrese las fechas de su reserva:" << endl;
        Fecha entrada = hotelManager->solicitarFecha("Fecha de entrada:");
        Fecha salida = hotelManager->solicitarFecha("Fecha de salida:");
        
        if (!(entrada < salida)) {
            cout << "Error: La fecha de entrada debe ser anterior a la de salida." << endl;
            return;
        }
        
        // Intentar crear la reserva
        bool exito = hotelManager->crearReserva(codigoHab, user, entrada, salida);
        
        if (exito) {
            cout << "\n¡Reserva realizada con éxito!" << endl;
            cout << "Recibirá un email de confirmación en breve." << endl;
        }
    }
    
    // Función 3: Ver mis reservas
    void funcionHuesped3(){
        cout << "\n=== MIS RESERVAS ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        hotelManager->mostrarReservasHuesped(user);
    }
    
    // Función 4: Cancelar reserva
    void funcionHuesped4(){
        cout << "\n=== CANCELAR RESERVA ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        // Primero mostrar las reservas del huésped
        cout << "Sus reservas actuales:" << endl;
        hotelManager->mostrarReservasHuesped(user);
        
        int idReserva;
        cout << "\nIngrese el ID de la reserva que desea cancelar: ";
        while (!(cin >> idReserva)) {
            cout << "Entrada inválida. Ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        char confirmacion;
        cout << "¿Está seguro de que desea cancelar la reserva #" << idReserva << "? (s/n): ";
        cin >> confirmacion;
        
        if (confirmacion == 's' || confirmacion == 'S') {
            bool exito = hotelManager->cancelarReserva(idReserva, user);
            if (exito) {
                cout << "Su reserva ha sido cancelada exitosamente." << endl;
            }
        } else {
            cout << "Cancelación abortada." << endl;
        }
    }
    
    // Función 5: Buscar habitaciones por filtros
    void funcionHuesped5(){
        cout << "\n=== BUSCAR HABITACIONES POR FILTROS ===" << endl;
        if (!hotelManager) {
            cout << "Error: Sistema no inicializado." << endl;
            return;
        }
        
        int opcion;
        cout << "Seleccione el tipo de búsqueda:" << endl;
        cout << "1. Buscar por código específico" << endl;
        cout << "2. Buscar por tipo de habitación" << endl;
        cout << "3. Buscar por rango de precio" << endl;
        cout << "4. Ver todas las habitaciones" << endl;
        cout << "Seleccione opción: ";
        
        while (!(cin >> opcion) || opcion < 1 || opcion > 4) {
            cout << "Entrada inválida. Ingrese un número del 1 al 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        switch (opcion) {
            case 1: {
                int codigo;
                cout << "Ingrese el código de habitación: ";
                while (!(cin >> codigo)) {
                    cout << "Entrada inválida. Ingrese un número: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                hotelManager->buscarPorCodigo(codigo);
                break;
            }
            case 2: {
                TipoHabitacion tipo = hotelManager->solicitarTipoHabitacion();
                hotelManager->buscarPorTipo(tipo);
                break;
            }
            case 3: {
                double minimo, maximo;
                cout << "Precio mínimo por noche: $";
                while (!(cin >> minimo) || minimo < 0) {
                    cout << "Entrada inválida. Ingrese un precio válido: $";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                cout << "Precio máximo por noche: $";
                while (!(cin >> maximo) || maximo < minimo) {
                    cout << "Entrada inválida. Debe ser mayor que el mínimo: $";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                hotelManager->buscarPorRangoPrecio(minimo, maximo);
                break;
            }
            case 4: {
                hotelManager->listarTodasLasHabitaciones();
                break;
            }
        }
    }
};

// Inicializar el puntero estático
HotelManager* Huesped::hotelManager = nullptr;

#endif