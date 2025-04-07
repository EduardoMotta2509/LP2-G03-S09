// sin DIP
#include <iostream>

using namespace std;

// Servicio de envío de correos
class EmailService {
public:
    void enviarEmail(const string& mensaje) {
        cout << "Enviando email: " << mensaje << endl;
    }
};

// Notificador que depende directamente de EmailService (violación de DIP)
class Notificador {
private:
    EmailService emailService; // Dependencia directa

public:
    void enviarNotificacion(const string& mensaje) {
        emailService.enviarEmail(mensaje);
    }
};

int main() {
    Notificador notificador;
    notificador.enviarNotificacion("Hola, tienes un nuevo mensaje.");

    return 0;
}


// Aplicando DIP
#include <iostream>
#include <memory>

using namespace std;

// Interfaz para cualquier servicio de notificación
class INotificacion {
public:
    virtual void enviar(const string& mensaje) = 0;
    virtual ~INotificacion() {}
};

// Implementación de notificación por Email
class EmailService : public INotificacion {
public:
    void enviar(const string& mensaje) override {
        cout << "Enviando email: " << mensaje << endl;
    }
};

// Nueva implementación de notificación por SMS (fácil de agregar sin modificar Notificador)
class SMSService : public INotificacion {
public:
    void enviar(const string& mensaje) override {
        cout << "Enviando SMS: " << mensaje << endl;
    }
};

// Notificador depende de una abstracción (INotificacion), no de una clase concreta
class Notificador {
private:
    INotificacion& servicioNotificacion; // Inyección de Dependencia

public:
    Notificador(INotificacion& servicio) : servicioNotificacion(servicio) {}

    void enviarNotificacion(const string& mensaje) {
        servicioNotificacion.enviar(mensaje);
    }
};

int main() {
    EmailService email;
    SMSService sms;

    Notificador notificadorPorEmail(email);
    Notificador notificadorPorSMS(sms);

    notificadorPorEmail.enviarNotificacion("Hola, tienes un nuevo mensaje por email.");
    notificadorPorSMS.enviarNotificacion("Hola, tienes un nuevo mensaje por SMS.");

    return 0;
}