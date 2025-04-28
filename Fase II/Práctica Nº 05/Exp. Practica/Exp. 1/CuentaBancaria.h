#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria {
private:
    string numero;
    string titular;
    double saldo;

public:
    CuentaBancaria(string num, string tit, double sal) : numero(num), titular(tit), saldo(sal) 
    {
        cout << "Cuenta Bancaria creada: "<<titular<<endl;
    }

    CuentaBancaria& depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Depósito de " << monto << " realizado. Nuevo saldo: " << saldo << endl;
        } else {
            cout << "Monto de depósito inválido." << endl;
        }
        return *this;
    }

    CuentaBancaria& retirar(double monto) {
        if (monto > 0) {
            if (monto <= saldo) {
                saldo -= monto;
                cout << "Retiro de " << monto << " realizado. Nuevo saldo: " << saldo << endl;
            } else {
                cout << "Fondos insuficientes." << endl;
            }
        } else {
            cout << "Monto de retiro inválido." << endl;
        }
        return *this;
    }

    void mostrarSaldo() const {
        cout << "Saldo actual de la cuenta " << numero << " (" << titular << "): " << saldo << endl;
    }

    CuentaBancaria& setNumero(const string& num) {
        numero = num;
        return *this;
    }

    CuentaBancaria& setTitular(const string& tit) {
        titular = tit;
        return *this;
    }

    CuentaBancaria& setSaldo(double sal) {
        saldo = sal;
        return *this;
    }

    string getNumero() const { 
        return numero; 
        
    }
    string getTitular() const { 
        return titular; 
        
    }
    double getSaldo() const { 
        return saldo; }
};
#endif 