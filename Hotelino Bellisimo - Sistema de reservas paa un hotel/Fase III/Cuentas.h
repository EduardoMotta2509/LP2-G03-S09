#ifndef CUENTAS_H
#define CUENTAS_H
#include <iostream>
#include <vector>
#include "Huesped.h"
#include "Administrador.h"
using namespace std;

class Cuentas{
private:
    vector<Administrador> cuentasAdmins;
    vector<Huesped> cuentasHuespeds;

public:
    Cuentas(vector<Administrador>& cuentasAdmins, vector<Huesped>& cuentasHuespeds)
        : cuentasAdmins(cuentasAdmins), cuentasHuespeds(cuentasHuespeds) {}
    
    void agregarAdmin(const Administrador& nuevo){
        cuentasAdmins.push_back(nuevo);
    }
    
    void agregarHuesped(const Huesped& nuevo){
        cuentasHuespeds.push_back(nuevo);
    }
    
    Administrador* buscarAdmin(const string& user, const string& password) {
        for (auto &admin : cuentasAdmins) {
            if (admin.getUser() == user && admin.getPassword() == password) {
                return &admin;
            }
        }
        return nullptr;
    }
    
    Huesped* buscarHuesped(const string& user, const string& password) {
        for (auto &huesped : cuentasHuespeds) {
            if (huesped.getUser() == user && huesped.getPassword() == password) {
                return &huesped;
            }
        }
        return nullptr;
    }
};

#endif