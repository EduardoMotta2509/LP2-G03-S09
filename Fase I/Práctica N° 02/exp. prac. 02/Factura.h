#ifndef FACTURA_H
#define FACTURA_H

#include<iostream>

using namespace std;

class Factura{
private:
    int numeroFactura;
    string fechaEmision;
    string nombreCliente;
    float monto;
public:
    int totalFacturas;

    Factura(int _numeroFactura, string _fechaEmision, string _nombreCliente, int _totalFacturas, float _monto){
        numeroFactura=_numeroFactura;
        fechaEmision=_fechaEmision;
        nombreCliente=_nombreCliente;
        totalFacturas=_totalFacturas;
        monto=_monto
    }

    int getNumeroFactura(){
        return numeroFactura;
    }
    string getFechaEmision(){
        return fechaEmision;
    }
    string getNombreCliente(){
        return nombreCliente;
    }
    float getMonto(){
        return monto;
    }

    void setNumeroFactura(int _numeroFactura){
        numeroFactura=_numeroFactura;
    }
    void setFechaEmision(string _fechaEmision){
        fechaEmision=_fechaEmision;
    }
    void setNombreCliente(string _nombreCliente){
        nombreCliente=_nombreCliente;
    }
    void setMonto(float _monto){
        monto=_monto;
    }
    
    void mostrarFactura(){
        cout<<"···············································"<<endl;
        cout<<"     Número de Factura:"<<numeroFactura<<endl;
        cout<<"     Fecha de Emisión:"<<fechaEmision<<endl;
        cout<<"     Nombre del Cliente:"<<nombreCliente<<endl;
        cout<<"     Total de facturas: "<<totalFacturas<<endl;
        cout<<"     MONTO: "<<monto<<endl;
        cout<<"···············································"<<endl;
    }

};
#endif