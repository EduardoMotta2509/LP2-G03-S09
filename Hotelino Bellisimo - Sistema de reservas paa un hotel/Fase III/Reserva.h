#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

class Fecha {
private:
    int dia, mes, año;

public:
    Fecha() {
        time_t t = time(0);
        tm* now = localtime(&t);
        dia = now->tm_mday;
        mes = now->tm_mon + 1;
        año = now->tm_year + 1900;
    }
    
    Fecha(int d, int m, int a) : dia(d), mes(m), año(a) {}
    
    // Getters
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAño() const { return año; }
    
    // Setters
    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAño(int a) { año = a; }
    
    string toString() const {
        stringstream ss;
        ss << setfill('0') << setw(2) << dia << "/" 
           << setfill('0') << setw(2) << mes << "/" << año;
        return ss.str();
    }
    
    // Operador de comparación
    bool operator<(const Fecha& otra) const {
        if (año != otra.año) return año < otra.año;
        if (mes != otra.mes) return mes < otra.mes;
        return dia < otra.dia;
    }
    bool operator>(const Fecha& otra) const {
        if (año != otra.año) return año > otra.año;
        if (mes != otra.mes) return mes > otra.mes;
        return dia > otra.dia;
    }
    
    bool operator==(const Fecha& otra) const {
        return (dia == otra.dia && mes == otra.mes && año == otra.año);
    }
    
    bool operator<=(const Fecha& otra) const {
        return (*this < otra) || (*this == otra);
    }
    
    // Calcular diferencia en días (aproximada)
    int diferenciaDias(const Fecha& otra) const {
        // Cálculo simplificado - en un sistema real usarías una librería de fechas
        int dias1 = año * 365 + mes * 30 + dia;
        int dias2 = otra.año * 365 + otra.mes * 30 + otra.dia;
        return abs(dias2 - dias1);
    }
};

enum EstadoReserva {
    ACTIVA,
    CANCELADA,
    COMPLETADA,
    NO_SHOW
};

class Reserva {
private:
    static int contadorId;
    int idReserva;
    int codigoHabitacion;
    string userHuesped;
    Fecha fechaEntrada;
    Fecha fechaSalida;
    int numeroNoches;
    double montoTotal;
    EstadoReserva estado;
    Fecha fechaReserva;
    string observaciones;

public:
    Reserva(int codHab, const string& user, const Fecha& entrada, const Fecha& salida, double monto)
        : idReserva(++contadorId), codigoHabitacion(codHab), userHuesped(user),
          fechaEntrada(entrada), fechaSalida(salida), montoTotal(monto), 
          estado(ACTIVA), fechaReserva(), observaciones("") {
        numeroNoches = entrada.diferenciaDias(salida);
        if (numeroNoches <= 0) numeroNoches = 1;
    }
    
    // Getters
    int getIdReserva() const { return idReserva; }
    int getCodigoHabitacion() const { return codigoHabitacion; }
    string getUserHuesped() const { return userHuesped; }
    Fecha getFechaEntrada() const { return fechaEntrada; }
    Fecha getFechaSalida() const { return fechaSalida; }
    int getNumeroNoches() const { return numeroNoches; }
    double getMontoTotal() const { return montoTotal; }
    EstadoReserva getEstado() const { return estado; }
    Fecha getFechaReserva() const { return fechaReserva; }
    string getObservaciones() const { return observaciones; }
    
    // Setters
    void setEstado(EstadoReserva nuevoEstado) { estado = nuevoEstado; }
    void setObservaciones(const string& obs) { observaciones = obs; }
    void setMontoTotal(double monto) { montoTotal = monto; }
    
    string getEstadoString() const {
        switch(estado) {
            case ACTIVA: return "Activa";
            case CANCELADA: return "Cancelada";
            case COMPLETADA: return "Completada";
            case NO_SHOW: return "No Show";
            default: return "Desconocido";
        }
    }
    
    void cancelar() {
        estado = CANCELADA;
    }
    
    void completar() {
        estado = COMPLETADA;
    }
    
    void marcarNoShow() {
        estado = NO_SHOW;
    }
    
    bool estaActiva() const {
        return estado == ACTIVA;
    }
    
    bool conflictoCon(const Fecha& entrada, const Fecha& salida) const {
        if (estado != ACTIVA) return false;
        
        // Verificar si hay solapamiento de fechas
        return !(salida < fechaEntrada || entrada > fechaSalida);
    }
    
    void mostrarInfo() const {
        cout << "=== RESERVA #" << idReserva << " ===" << endl;
        cout << "Habitación: " << codigoHabitacion << endl;
        cout << "Huésped: " << userHuesped << endl;
        cout << "Entrada: " << fechaEntrada.toString() << endl;
        cout << "Salida: " << fechaSalida.toString() << endl;
        cout << "Noches: " << numeroNoches << endl;
        cout << "Monto Total: $" << fixed << setprecision(2) << montoTotal << endl;
        cout << "Estado: " << getEstadoString() << endl;
        cout << "Fecha de Reserva: " << fechaReserva.toString() << endl;
        if (!observaciones.empty()) {
            cout << "Observaciones: " << observaciones << endl;
        }
        cout << "=========================" << endl;
    }
};

// Inicializar contador estático
int Reserva::contadorId = 0;

#endif