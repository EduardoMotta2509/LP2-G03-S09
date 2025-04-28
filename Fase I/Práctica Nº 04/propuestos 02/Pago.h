#ifndef PAGO_H
#define PAGO_H

#include <iostream>
using namespace std;
#include "Cliente.h"
#include "Venta.h"

class Pago{
private:
    Cliente* cliente;
    vector<Venta> historialPagos;
    float pagosTotales = 0;
public:
    Pago(Cliente* _cliente, vector<Venta> _historialPagos) : cliente(_cliente), historialPagos(_historialPagos) {}
    
    string getNombreCliente(){ return cliente->getNombre();}
    float getPagosTotales(){ return pagosTotales; }
    
    void hacerPago(Venta nuevaVenta){
        cliente->añadirNuevaCompra(nuevaVenta);
        historialPagos.push_back(nuevaVenta);
        pagosTotales += nuevaVenta.getTotal();
    }
    
    void mostrarHistorial(){
        cout<<"PAGOS DEL CLIENTE ---> "<<cliente->getNombre()<<"\n"<<endl;
        cout<<"PAGOS TOTALES DEL CLIENTE ---> "<<pagosTotales<<"\n"<<endl;
        for (int i=0; i<historialPagos.size(); i++){
            historialPagos[i].mostrarVenta();
        }
    }

};
#endif
