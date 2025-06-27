#ifndef HOTEL_MANAGER_H
#define HOTEL_MANAGER_H
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#include "Habitacion.h"
#include "Reserva.h"
using namespace std;

class HotelManager {
private:
    vector<unique_ptr<Habitacion>> habitaciones;
    vector<Reserva> reservas;
    
    string getTipoString(TipoHabitacion tipo) const {
        switch(tipo) {
            case SIMPLE: return "Simple";
            case DOBLE: return "Doble";
            case MATRIMONIAL: return "Matrimonial";
            case SUITE: return "Suite";
            default: return "Desconocido";
        }
    }
    
public:
    HotelManager() {
        // Inicializar algunas habitaciones por defecto
        inicializarHabitacionesDefault();
    }
    
    ~HotelManager() = default;
    
    void inicializarHabitacionesDefault() {
        // Habitaciones simples (101-110)
        for (int i = 101; i <= 110; i++) {
            habitaciones.push_back(make_unique<HabitacionSimple>(i, 50.0));
        }
        
        // Habitaciones dobles (201-210)
        for (int i = 201; i <= 210; i++) {
            habitaciones.push_back(make_unique<HabitacionDoble>(i, 80.0));
        }
        
        // Habitaciones matrimoniales (301-310)
        for (int i = 301; i <= 310; i++) {
            habitaciones.push_back(make_unique<HabitacionMatrimonial>(i, 120.0));
        }
        
        // Suites (401-405)
        for (int i = 401; i <= 405; i++) {
            habitaciones.push_back(make_unique<Suite>(i, 300.0));
        }
    }
    
    // ========== ADMINISTRACIÓN DE HABITACIONES ==========
    
    void crearHabitacion(TipoHabitacion tipo, int codigo, double tarifa) {
        // Verificar que no existe una habitación con ese código
        for (const auto& hab : habitaciones) {
            if (hab->getCodigo() == codigo) {
                cout << "Error: Ya existe una habitación con el código " << codigo << endl;
                return;
            }
        }
        
        unique_ptr<Habitacion> nuevaHab;
        switch (tipo) {
            case SIMPLE:
                nuevaHab = make_unique<HabitacionSimple>(codigo, tarifa);
                break;
            case DOBLE:
                nuevaHab = make_unique<HabitacionDoble>(codigo, tarifa);
                break;
            case MATRIMONIAL:
                nuevaHab = make_unique<HabitacionMatrimonial>(codigo, tarifa);
                break;
            case SUITE:
                nuevaHab = make_unique<Suite>(codigo, tarifa);
                break;
        }
        
        habitaciones.push_back(move(nuevaHab));
        cout << "Habitación " << codigo << " creada exitosamente!" << endl;
    }
    
    void actualizarTarifa(int codigo, double nuevaTarifa) {
        auto it = find_if(habitaciones.begin(), habitaciones.end(),
                         [codigo](const unique_ptr<Habitacion>& hab) {
                             return hab->getCodigo() == codigo;
                         });
        
        if (it != habitaciones.end()) {
            (*it)->setTarifaBase(nuevaTarifa);
            cout << "Tarifa actualizada para habitación " << codigo << ": $" << nuevaTarifa << endl;
        } else {
            cout << "Habitación no encontrada." << endl;
        }
    }
    
    void bloquearHabitacion(int codigo) {
        auto it = find_if(habitaciones.begin(), habitaciones.end(),
                         [codigo](const unique_ptr<Habitacion>& hab) {
                             return hab->getCodigo() == codigo;
                         });
        
        if (it != habitaciones.end()) {
            (*it)->bloquear();
            cout << "Habitación " << codigo << " bloqueada." << endl;
        } else {
            cout << "Habitación no encontrada." << endl;
        }
    }
    
    void desbloquearHabitacion(int codigo) {
        auto it = find_if(habitaciones.begin(), habitaciones.end(),
                         [codigo](const unique_ptr<Habitacion>& hab) {
                             return hab->getCodigo() == codigo;
                         });
        
        if (it != habitaciones.end()) {
            (*it)->desbloquear();
            cout << "Habitación " << codigo << " desbloqueada." << endl;
        } else {
            cout << "Habitación no encontrada." << endl;
        }
    }
    
    void ponerEnMantenimiento(int codigo) {
        auto it = find_if(habitaciones.begin(), habitaciones.end(),
                         [codigo](const unique_ptr<Habitacion>& hab) {
                             return hab->getCodigo() == codigo;
                         });
        
        if (it != habitaciones.end()) {
            (*it)->mantenimiento();
            cout << "Habitación " << codigo << " puesta en mantenimiento." << endl;
        } else {
            cout << "Habitación no encontrada." << endl;
        }
    }
    
    // ========== BÚSQUEDA DE HABITACIONES ==========
    
    void buscarPorCodigo(int codigo) {
        auto it = find_if(habitaciones.begin(), habitaciones.end(),
                         [codigo](const unique_ptr<Habitacion>& hab) {
                             return hab->getCodigo() == codigo;
                         });
        
        if (it != habitaciones.end()) {
            (*it)->mostrarInfo();
        } else {
            cout << "Habitación no encontrada." << endl;
        }
    }
    
    void buscarPorTipo(TipoHabitacion tipo) {
        cout << "\n=== HABITACIONES TIPO " << getTipoString(tipo) << " ===" << endl;
        bool encontrado = false;
        
        for (const auto& hab : habitaciones) {
            if (hab->getTipo() == tipo) {
                hab->mostrarInfo();
                cout << endl;
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            cout << "No hay habitaciones de este tipo." << endl;
        }
    }
    
    void buscarPorRangoPrecio(double minimo, double maximo) {
        cout << "\n=== HABITACIONES EN RANGO $" << minimo << " - $" << maximo << " ===" << endl;
        bool encontrado = false;
        
        for (const auto& hab : habitaciones) {
            if (hab->getTarifaBase() >= minimo && hab->getTarifaBase() <= maximo) {
                hab->mostrarInfo();
                cout << endl;
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            cout << "No hay habitaciones en este rango de precio." << endl;
        }
    }
    
    vector<int> buscarDisponibles(const Fecha& entrada, const Fecha& salida, TipoHabitacion tipo = static_cast<TipoHabitacion>(0)) {
        vector<int> disponibles;
        
        for (const auto& hab : habitaciones) {
            if (!hab->estaDisponible()) continue;
            
            if (tipo != 0 && hab->getTipo() != tipo) continue;
            
            bool disponible = true;
            for (const auto& reserva : reservas) {
                if (reserva.getCodigoHabitacion() == hab->getCodigo() && 
                    reserva.conflictoCon(entrada, salida)) {
                    disponible = false;
                    break;
                }
            }
            
            if (disponible) {
                disponibles.push_back(hab->getCodigo());
            }
        }
        
        return disponibles;
    }
    
    void mostrarHabitacionesDisponibles(const Fecha& entrada, const Fecha& salida) {
        cout << "\n=== HABITACIONES DISPONIBLES ===" << endl;
        cout << "Periodo: " << entrada.toString() << " - " << salida.toString() << endl;
        
        vector<int> disponibles = buscarDisponibles(entrada, salida);
        
        if (disponibles.empty()) {
            cout << "No hay habitaciones disponibles para el periodo seleccionado." << endl;
            return;
        }
        
        for (int codigo : disponibles) {
            buscarPorCodigo(codigo);
            cout << endl;
        }
    }
    
    // ========== MANEJO DE RESERVAS ==========
    
    bool crearReserva(int codigoHab, const string& userHuesped, 
                     const Fecha& entrada, const Fecha& salida) {
        // Verificar que la habitación existe
        auto it = find_if(habitaciones.begin(), habitaciones.end(),
                         [codigoHab](const unique_ptr<Habitacion>& hab) {
                             return hab->getCodigo() == codigoHab;
                         });
        
        if (it == habitaciones.end()) {
            cout << "Error: Habitación no encontrada." << endl;
            return false;
        }
        
        // Verificar disponibilidad
        if (!(*it)->estaDisponible()) {
            cout << "Error: Habitación no disponible." << endl;
            return false;
        }
        
        // Verificar conflictos con otras reservas
        for (const auto& reserva : reservas) {
            if (reserva.getCodigoHabitacion() == codigoHab && 
                reserva.conflictoCon(entrada, salida)) {
                cout << "Error: La habitación ya está reservada para esas fechas." << endl;
                return false;
            }
        }
        
        // Calcular monto total usando polimorfismo
        int noches = entrada.diferenciaDias(salida);
        if (noches <= 0) noches = 1;
        double montoTotal = (*it)->calcularTarifa(noches);
        
        // Crear reserva
        Reserva nuevaReserva(codigoHab, userHuesped, entrada, salida, montoTotal);
        reservas.push_back(nuevaReserva);
        
        // Marcar habitación como ocupada
        (*it)->ocupar();
        
        cout << "¡Reserva creada exitosamente!" << endl;
        cout << "ID de Reserva: " << nuevaReserva.getIdReserva() << endl;
        cout << "Monto Total: $" << fixed << setprecision(2) << montoTotal << endl;
        
        return true;
    }
    
    bool cancelarReserva(int idReserva, const string& userHuesped) {
        auto it = find_if(reservas.begin(), reservas.end(),
                         [idReserva, userHuesped](Reserva& res) {
                             return res.getIdReserva() == idReserva && 
                                    res.getUserHuesped() == userHuesped;
                         });
        
        if (it != reservas.end() && it->estaActiva()) {
            it->cancelar();
            
            // Liberar habitación
            auto habIt = find_if(habitaciones.begin(), habitaciones.end(),
                               [&it](const unique_ptr<Habitacion>& hab) {
                                   return hab->getCodigo() == it->getCodigoHabitacion();
                               });
            
            if (habIt != habitaciones.end()) {
                (*habIt)->liberar();
            }
            
            cout << "Reserva #" << idReserva << " cancelada exitosamente." << endl;
            return true;
        } else {
            cout << "Reserva no encontrada o no puede cancelarse." << endl;
            return false;
        }
    }
    
    void mostrarReservasHuesped(const string& userHuesped) {
        cout << "\n=== RESERVAS DE " << userHuesped << " ===" << endl;
        bool encontrado = false;
        
        for (const auto& reserva : reservas) {
            if (reserva.getUserHuesped() == userHuesped) {
                reserva.mostrarInfo();
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            cout << "No hay reservas para este huésped." << endl;
        }
    }
    
    // ========== REPORTES ==========
    
    void generarReporteOcupacion() {
        cout << "\n=============== REPORTE DE OCUPACIÓN ===============" << endl;
        
        int totalHabitaciones = habitaciones.size();
        int disponibles = 0, ocupadas = 0, mantenimiento = 0, bloqueadas = 0;
        
        for (const auto& hab : habitaciones) {
            switch (hab->getEstado()) {
                case DISPONIBLE: disponibles++; break;
                case OCUPADA: ocupadas++; break;
                case MANTENIMIENTO: mantenimiento++; break;
                case BLOQUEADA: bloqueadas++; break;
            }
        }
        
        cout << "Total de Habitaciones: " << totalHabitaciones << endl;
        cout << "Disponibles: " << disponibles << " (" << fixed << setprecision(1) 
             << (disponibles * 100.0 / totalHabitaciones) << "%)" << endl;
        cout << "Ocupadas: " << ocupadas << " (" << fixed << setprecision(1) 
             << (ocupadas * 100.0 / totalHabitaciones) << "%)" << endl;
        cout << "En Mantenimiento: " << mantenimiento << " (" << fixed << setprecision(1) 
             << (mantenimiento * 100.0 / totalHabitaciones) << "%)" << endl;
        cout << "Bloqueadas: " << bloqueadas << " (" << fixed << setprecision(1) 
             << (bloqueadas * 100.0 / totalHabitaciones) << "%)" << endl;
        
        cout << "\n--- Detalle por Tipo ---" << endl;
        for (int tipo = SIMPLE; tipo <= SUITE; tipo++) {
            TipoHabitacion t = static_cast<TipoHabitacion>(tipo);
            int count = count_if(habitaciones.begin(), habitaciones.end(),
                               [t](const unique_ptr<Habitacion>& hab) {
                                   return hab->getTipo() == t;
                               });
            cout << getTipoString(t) << ": " << count << " habitaciones" << endl;
        }
        cout << "==================================================" << endl;
    }
    
    void generarReporteIngresos() {
        cout << "\n=============== REPORTE DE INGRESOS ===============" << endl;
        
        double ingresosTotales = 0.0;
        double ingresosActivos = 0.0;
        int reservasActivas = 0;
        int reservasCanceladas = 0;
        int reservasCompletadas = 0;
        
        for (const auto& reserva : reservas) {
            ingresosTotales += reserva.getMontoTotal();
            
            switch (reserva.getEstado()) {
                case ACTIVA:
                    ingresosActivos += reserva.getMontoTotal();
                    reservasActivas++;
                    break;
                case CANCELADA:
                    reservasCanceladas++;
                    break;
                case COMPLETADA:
                    reservasCompletadas++;
                    break;
                case NO_SHOW:
                    break;
            }
        }
        
        cout << "Total de Reservas: " << reservas.size() << endl;
        cout << "Reservas Activas: " << reservasActivas << endl;
        cout << "Reservas Completadas: " << reservasCompletadas << endl;
        cout << "Reservas Canceladas: " << reservasCanceladas << endl;
        cout << endl;
        cout << "Ingresos Totales: $" << fixed << setprecision(2) << ingresosTotales << endl;
        cout << "Ingresos de Reservas Activas: $" << fixed << setprecision(2) << ingresosActivos << endl;
        cout << "Ingreso Promedio por Reserva: $" << fixed << setprecision(2) 
             << (reservas.empty() ? 0.0 : ingresosTotales / reservas.size()) << endl;
        
        cout << "\n--- Ingresos por Tipo de Habitación ---" << endl;
        for (int tipo = SIMPLE; tipo <= SUITE; tipo++) {
            TipoHabitacion t = static_cast<TipoHabitacion>(tipo);
            double ingresosTipo = 0.0;
            int reservasTipo = 0;
            
            for (const auto& reserva : reservas) {
                auto it = find_if(habitaciones.begin(), habitaciones.end(),
                                 [&reserva](const unique_ptr<Habitacion>& hab) {
                                     return hab->getCodigo() == reserva.getCodigoHabitacion();
                                 });
                
                if (it != habitaciones.end() && (*it)->getTipo() == t) {
                    ingresosTipo += reserva.getMontoTotal();
                    reservasTipo++;
                }
            }
            
            cout << getTipoString(t) << ": $" << fixed << setprecision(2) 
                 << ingresosTipo << " (" << reservasTipo << " reservas)" << endl;
        }
        cout << "==================================================" << endl;
    }
    
    void listarTodasLasHabitaciones() {
        cout << "\n=============== LISTADO DE HABITACIONES ===============" << endl;
        for (const auto& hab : habitaciones) {
            hab->mostrarInfo();
            cout << endl;
        }
        cout << "======================================================" << endl;
    }
    
    void listarTodasLasReservas() {
        cout << "\n=============== LISTADO DE RESERVAS ===============" << endl;
        if (reservas.empty()) {
            cout << "No hay reservas registradas." << endl;
        } else {
            for (const auto& reserva : reservas) {
                reserva.mostrarInfo();
            }
        }
        cout << "===================================================" << endl;
    }
    
    // Funciones auxiliares para entrada de datos
    Fecha solicitarFecha(const string& mensaje) {
        int dia, mes, año;
        cout << mensaje << endl;
        cout << "Día: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Año: ";
        cin >> año;
        return Fecha(dia, mes, año);
    }
    
    TipoHabitacion solicitarTipoHabitacion() {
        int tipo;
        cout << "\nTipos de habitación:" << endl;
        cout << "1. Simple" << endl;
        cout << "2. Doble" << endl;
        cout << "3. Matrimonial" << endl;
        cout << "4. Suite" << endl;
        cout << "Seleccione tipo: ";
        
        while (!(cin >> tipo) || tipo < 1 || tipo > 4) {
            cout << "Entrada inválida. Ingrese un número del 1 al 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        return static_cast<TipoHabitacion>(tipo);
    }
};

#endif