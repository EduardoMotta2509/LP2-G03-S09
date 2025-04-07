#ifndef REGISTROPAGOS_H
#define REGISTROPAGOS_H

#include <iostream>
using namespace std;
#include <vector>
#include "Pago.h"

class RegistroPagos{
private:
    vector<Pago> pagantes;
public:
    RegistroPagos(vector<Pago> _pagantes) : pagantes(_pagantes) {}

    void nuevoPagante(Pago nuevoPagante){
        pagantes.push_back(nuevoPagante);
    }

    bool buscarXnombre(string nombre){
        for ( int i=0; i<pagantes.size(); i++) {
            if (pagantes[i].getNombreCliente() == nombre){
                cout<<"Cliente con nombre ---> "<<nombre<<" ENCONTRADO"<<endl;
                return true;
            }
        }
        return false;
    }
    
    void mostrarPagantes(){
        cout<<"----------PAGANTES----------"<<endl;
        for (int i=0; i<pagantes.size(); i++){
            cout<<"NOMBRE DEL PAGANTE: "<<pagantes[i].getNombreCliente()<<endl;
            cout<<"PAGOS TOTALES: "<<pagantes[i].getPagosTotales()<<endl;
        }
        cout<<"----------------------------"<<endl;
    }
    
};
#endif

