#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>

using namespace std;

class CuentaBancaria {
private:
    string titular;
    string numeroCuenta;
    double saldo;
public:
    double tasaInteres;

    CuentaBancaria(string _titular, string _numeroCuenta, double _saldo, double _tasaInteres){
        titular=_titular;
        numeroCuenta=_numeroCuenta;
        saldo=_saldo;
        tasaInteres=_tasaInteres;
    }

    string getTitular(){
        return titular;
    }
    string getNumeroCuenta(){
        return numeroCuenta;
    }
    double getSaldo(){
        return saldo;
    }

    void setTitular(string _titular){
        titular=_titular;
    }
    
    void setNumeroCuenta(string _numeroCuenta){
        numeroCuenta=_numeroCuenta;
    }
    void setSaldo(double _saldo){
        saldo=_saldo;
    }

    void depositar(double monto){
        cout<<"····························································"<<endl;
        cout<<"Saldo anterior: S/."<<saldo<<endl;
        cout<<"Depositando S/."<<monto<<" a la cuenta: "<<numeroCuenta<<endl;
        saldo=saldo+monto;
        cout<<"Saldo NUEVO: S/."<<saldo<<endl;
        cout<<"····························································"<<endl;
        
    }
    void retirar(double monto){
        if (monto>saldo){
            cout<<"·····················SALDO INSUFICIENTE·····················"<<endl;
            cout<<"Se intentó retirar S/."<<monto<<" saldo disponible: S/."<<saldo<<endl;
        }
        else{
            
            cout<<"····························································"<<endl;
            cout<<"Saldo anterior: S/."<<saldo<<endl;
            cout<<"Se retiró: S/."<<monto<<" de la cuenta: "<<numeroCuenta<<endl;
            saldo=saldo-monto;
            cout<<"Saldo actual: S/."<<saldo<<endl;
            cout<<"····························································"<<endl;
        }
    }

    void mostrarInfo(){
        cout<<"···············································"<<endl;
        cout<<"     Titular: "<<titular<<endl;
        cout<<"     Numero de cuenta: "<<numeroCuenta<<endl;
        cout<<"     Saldo: "<<saldo<<endl;
        cout<<"     Tasa de interes: "<<tasaInteres<<endl;
        cout<<"···············································"<<endl;
    }
};
#endif