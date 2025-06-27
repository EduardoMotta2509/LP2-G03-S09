#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#include "Huesped.h"
#include "Administrador.h"
#include "Cuentas.h"
#include "HotelManager.h"

// Initialize empty vectors for accounts and hotel manager
vector<Administrador> admins;
vector<Huesped> huespeds;
Cuentas cuentas(admins, huespeds);
HotelManager hotelManager; // Instancia global del gestor del hotel

int panelAdministrador() {
    int opcionFUNCION;
    do {
        cout<<"\n         Panel del Administrador"<<endl;
        cout<<"             1. Crear nueva habitación"<<endl;
        cout<<"             2. Actualizar tarifa de habitación"<<endl;
        cout<<"             3. Gestión de bloqueo de habitaciones"<<endl;
        cout<<"             4. Buscar habitación por código"<<endl;
        cout<<"             5. Buscar habitaciones por tipo"<<endl;
        cout<<"             6. Buscar habitaciones por precio"<<endl;
        cout<<"             7. Cancelar reserva"<<endl;
        cout<<"             8. Generar reporte de ocupación"<<endl;
        cout<<"             9. Generar reporte de ingresos"<<endl;
        cout<<"             10. Listados completos"<<endl;
        cout<<"             Ingrese la opcion deseada: ";
        while (!(cin >> opcionFUNCION) || (opcionFUNCION < 1 || opcionFUNCION>10)) {
            cout << "Entrada invalida. Ingrese en el rango de 1 - 10: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return opcionFUNCION;
    } while (opcionFUNCION < 1 || opcionFUNCION>10);
}

int panelHuesped() {
    int opcionFUNCION;
    do {
        cout<<"\n         Panel del Huesped"<<endl;
        cout<<"             1. Buscar habitaciones disponibles"<<endl;
        cout<<"             2. Realizar reserva"<<endl;
        cout<<"             3. Ver mis reservas"<<endl;
        cout<<"             4. Cancelar reserva"<<endl;
        cout<<"             5. Explorar habitaciones"<<endl;
        cout<<"             Ingrese la opcion deseada: ";
        while (!(cin >> opcionFUNCION) || (opcionFUNCION < 1 || opcionFUNCION>5)) {
            cout << "Entrada invalida. Ingrese en el rango de 1 - 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return opcionFUNCION;
    } while (opcionFUNCION < 1 || opcionFUNCION>5);
}

void entornoAdmin(Administrador &admin){
    int salir;
    do {
        int opcion = panelAdministrador();
        
        switch (opcion){
            case 1:
                cout<<"                 === CREAR NUEVA HABITACIÓN ==="<<endl;
                admin.funcionAdmin1();
                break;
            case 2:
                cout<<"                 === ACTUALIZAR TARIFA ==="<<endl;
                admin.funcionAdmin2();
                break;
            case 3:
                cout<<"                 === GESTIÓN DE BLOQUEO ==="<<endl;
                admin.funcionAdmin3();
                break;
            case 4:
                cout<<"                 === BUSCAR POR CÓDIGO ==="<<endl;
                admin.funcionAdmin4();
                break;
            case 5:
                cout<<"                 === BUSCAR POR TIPO ==="<<endl;
                admin.funcionAdmin5();
                break;
            case 6:
                cout<<"                 === BUSCAR POR PRECIO ==="<<endl;
                admin.funcionAdmin6();
                break;
            case 7:
                cout<<"                 === CANCELAR RESERVA ==="<<endl;
                admin.funcionAdmin7();
                break;
            case 8:
                cout<<"                 === REPORTE DE OCUPACIÓN ==="<<endl;
                admin.funcionAdmin8();
                break;
            case 9:
                cout<<"                 === REPORTE DE INGRESOS ==="<<endl;
                admin.funcionAdmin9();
                break;
            case 10:
                cout<<"                 === LISTADOS COMPLETOS ==="<<endl;
                admin.funcionAdmin10();
                break;
        }
        
        do{
            cout<<"\n1. Volver al panel       2. Salir"<<endl;
            cout<<"Ingrese la opcion deseada: ";
            while (!(cin >> salir) || (salir != 1 && salir != 2)) {
                cout << "Entrada invalida. Ingrese solo 1 o 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (salir!=1 && salir!=2);
        
    } while (salir==1);
}

void entornoHuesped(Huesped &huesped){
    int salir;
    do {
        int opcion = panelHuesped();
        
        switch (opcion){
            case 1:
                cout<<"                 === BUSCAR HABITACIONES DISPONIBLES ==="<<endl;
                huesped.funcionHuesped1();
                break;
            case 2:
                cout<<"                 === REALIZAR RESERVA ==="<<endl;
                huesped.funcionHuesped2();
                break;
            case 3:
                cout<<"                 === MIS RESERVAS ==="<<endl;
                huesped.funcionHuesped3();
                break;
            case 4:
                cout<<"                 === CANCELAR RESERVA ==="<<endl;
                huesped.funcionHuesped4();
                break;
            case 5:
                cout<<"                 === EXPLORAR HABITACIONES ==="<<endl;
                huesped.funcionHuesped5();
                break;
        }
        
        do{
            cout<<"\n1. Volver al panel       2. Salir"<<endl;
            cout<<"Ingrese la opcion deseada: ";
            while (!(cin >> salir) || (salir != 1 && salir != 2)) {
                cout << "Entrada invalida. Ingrese solo 1 o 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (salir!=1 && salir!=2);
        
    } while (salir==1); 
}

void signIn(){
    int opcionCREAR;
    string AdminUser;
    string AdminPassword;
    string HuespedUser;
    string HuespedPassword;
    
    do {
        cout<<"     SIGN-IN"<<endl;
        cout<<"     1. Crear usuario Administrador"<<endl;
        cout<<"     2. Crear usuario Huesped"<<endl;
        cout<<"     Ingrese la opcion deseada: ";
        while (!(cin >> opcionCREAR) || (opcionCREAR != 1 && opcionCREAR != 2)) {
            cout << "Entrada invalida. Ingrese solo 1 o 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcionCREAR!=1 && opcionCREAR!=2);
    
    if(opcionCREAR==1) {
        cout<<"     REGISTRO DE USUARIO ADMINISTRADOR"<<endl;
        cout<<"     ingrese su usuario: ";
        cin>>AdminUser;
        cout<<"     ingrese su password: ";
        cin>>AdminPassword;

        Administrador admin(AdminUser, AdminPassword, true);
        cuentas.agregarAdmin(admin);
        cout << "Administrador registrado exitosamente!" << endl;

    } else {
        cout<<"     REGISTRO DE USUARIO HUESPED"<<endl;
        cout<<"     ingrese su usuario: ";
        cin>>HuespedUser;
        cout<<"     ingrese su password: ";
        cin>>HuespedPassword;

        Huesped huesped(HuespedUser, HuespedPassword, false);
        cuentas.agregarHuesped(huesped);
        cout << "Huesped registrado exitosamente!" << endl;
    }
}

void login(){
    int opcionLOGIN;
    do {
        do {
            cout<<"\n    HOTELINO BELLISSIMO "<<endl;
            cout<<"     1. Iniciar sesión (LOG-IN)"<<endl;
            cout<<"     2. Crear una cuenta (SIGN-IN)"<<endl;
            cout<<"     3. Exit"<<endl;
            cout<<"     Ingrese la opcion deseada: ";
            while (!(cin >> opcionLOGIN) || (opcionLOGIN != 1 && opcionLOGIN != 2 && opcionLOGIN != 3)) {
                cout << "Entrada invalida. Ingrese solo en el rango 1 - 3: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (opcionLOGIN!=1 && opcionLOGIN!=2 && opcionLOGIN!=3);
        
        switch (opcionLOGIN){
            case 1: {
                string userLogin, passLogin;
                cout << "\n=== INICIO DE SESIÓN ===" << endl;
                cout << "Usuario: ";
                cin >> userLogin;
                cout << "Contraseña: ";
                cin >> passLogin;
            
                Administrador* adminLog = cuentas.buscarAdmin(userLogin, passLogin);
                if (adminLog != nullptr) {
                    cout << "¡Bienvenido Administrador " << userLogin << "!" << endl;
                    cout << "Acceso completo al sistema de gestión hotelera." << endl;
                    entornoAdmin(*adminLog);
                    break;
                }
            
                Huesped* huespedLog = cuentas.buscarHuesped(userLogin, passLogin);
                if (huespedLog != nullptr) {
                    cout << "¡Bienvenido Huésped " << userLogin << "!" << endl;
                    cout << "Puede realizar reservas y gestionar su estadía." << endl;
                    entornoHuesped(*huespedLog);
                    break;
                }
            
                cout<<"Usuario o contraseña incorrectos." << endl;
                break;
            }
            case 2:
                signIn();
                break;
            case 3:
                cout << "¡Gracias por usar Hotelino Bellissimo!" << endl;
                cout << "¡Esperamos verle pronto!" << endl;
                return;
        }
    } while (opcionLOGIN != 3);
}

int main()
{
    cout << "==================================================" << endl;
    cout << "       SISTEMA DE GESTIÓN HOTELERA" << endl;
    cout << "           HOTELINO BELLISSIMO" << endl;
    cout << "==================================================" << endl;
    cout << "Inicializando sistema..." << endl;
    
    // Inicializar los punteros estáticos del HotelManager
    Administrador::setHotelManager(&hotelManager);
    Huesped::setHotelManager(&hotelManager);
    
    cout << "Sistema inicializado correctamente." << endl;
    cout << "Habitaciones predeterminadas cargadas." << endl;
    cout << "Listo para recibir usuarios." << endl;
    
    login();
    return 0;
}