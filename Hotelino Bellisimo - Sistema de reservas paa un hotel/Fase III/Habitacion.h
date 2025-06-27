#ifndef HABITACION_H
#define HABITACION_H
#include <iostream>
#include <string>
using namespace std;


enum TipoHabitacion {
    SIMPLE = 1,
    DOBLE = 2,
    MATRIMONIAL = 3,
    SUITE = 4
};


enum EstadoHabitacion {
    DISPONIBLE,
    OCUPADA,
    MANTENIMIENTO,
    BLOQUEADA
};


class Habitacion {
protected:
    int codigo;
    TipoHabitacion tipo;
    EstadoHabitacion estado;
    double tarifaBase;
    string descripcion;
    int capacidad;

public:
    Habitacion(int codigo, TipoHabitacion tipo, double tarifaBase, string descripcion, int capacidad)
        : codigo(codigo), tipo(tipo), estado(DISPONIBLE), tarifaBase(tarifaBase), 
          descripcion(descripcion), capacidad(capacidad) {}

    virtual ~Habitacion() {}

    virtual double calcularTarifa(int noches) const = 0;

    int getCodigo() const { return codigo; }
    TipoHabitacion getTipo() const { return tipo; }
    EstadoHabitacion getEstado() const { return estado; }
    double getTarifaBase() const { return tarifaBase; }
    string getDescripcion() const { return descripcion; }
    int getCapacidad() const { return capacidad; }
    
    void setEstado(EstadoHabitacion nuevoEstado) { estado = nuevoEstado; }
    void setTarifaBase(double nuevaTarifa) { tarifaBase = nuevaTarifa; }
    void setDescripcion(const string& nuevaDescripcion) { descripcion = nuevaDescripcion; }
    
    bool estaDisponible() const { return estado == DISPONIBLE; }
    void bloquear() { estado = BLOQUEADA; }
    void desbloquear() { estado = DISPONIBLE; }
    void ocupar() { estado = OCUPADA; }
    void liberar() { estado = DISPONIBLE; }
    void mantenimiento() { estado = MANTENIMIENTO; }
    
    string getTipoString() const {
        switch(tipo) {
            case SIMPLE: return "Simple";
            case DOBLE: return "Doble";
            case MATRIMONIAL: return "Matrimonial";
            case SUITE: return "Suite";
            default: return "Desconocido";
        }
    }
    
    string getEstadoString() const {
        switch(estado) {
            case DISPONIBLE: return "Disponible";
            case OCUPADA: return "Ocupada";
            case MANTENIMIENTO: return "Mantenimiento";
            case BLOQUEADA: return "Bloqueada";
            default: return "Desconocido";
        }
    }
    
    virtual void mostrarInfo() const {
        cout << "Código: " << codigo << " | Tipo: " << getTipoString() 
             << " | Estado: " << getEstadoString() << " | Tarifa Base: $" << tarifaBase
             << " | Capacidad: " << capacidad << " personas" << endl;
        cout << "Descripción: " << descripcion << endl;
    }
};


class HabitacionSimple : public Habitacion {
public:
    HabitacionSimple(int codigo, double tarifaBase) 
        : Habitacion(codigo, SIMPLE, tarifaBase, "Habitación simple con una cama individual", 1) {}
    
    double calcularTarifa(int noches) const override {
        return tarifaBase * noches;
    }
};


class HabitacionDoble : public Habitacion {
public:
    HabitacionDoble(int codigo, double tarifaBase) 
        : Habitacion(codigo, DOBLE, tarifaBase, "Habitación doble con dos camas individuales", 2) {}
    
    double calcularTarifa(int noches) const override {
        
        double tarifa = tarifaBase * noches;
        if (noches > 3) {
            tarifa *= 0.95; 
        }
        return tarifa;
    }
};


class HabitacionMatrimonial : public Habitacion {
public:
    HabitacionMatrimonial(int codigo, double tarifaBase) 
        : Habitacion(codigo, MATRIMONIAL, tarifaBase, "Habitación matrimonial con cama queen size", 2) {}
    
    double calcularTarifa(int noches) const override {
        
        double tarifa = tarifaBase * noches;
        if (noches > 5) {
            tarifa *= 0.90; 
        }
        return tarifa;
    }
};

class Suite : public Habitacion {
public:
    Suite(int codigo, double tarifaBase) 
        : Habitacion(codigo, SUITE, tarifaBase, "Suite de lujo con sala, dormitorio y baño premium", 4) {}
    
    double calcularTarifa(int noches) const override {
        
        double tarifa = tarifaBase * noches;
        tarifa *= 1.20;
        if (noches > 7) {
            tarifa *= 0.85; 
        }
        return tarifa;
    }
    
    void mostrarInfo() const override {
        Habitacion::mostrarInfo();
        cout << "*** SUITE DE LUJO - Incluye servicios premium ***" << endl;
    }
};

#endif
