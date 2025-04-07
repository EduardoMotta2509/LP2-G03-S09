// SIN APLICAR SRP
#include <iostream>
#include <vector>

using namespace std;

class UserManager {
public:
    void addUser(const string& name) {
        users.push_back(name);
        saveToDatabase(name);
    }

    void displayUsers() {
        for (const auto& user : users) {
            cout << "Usuario: " << user << endl;
        }
    }

private:
    vector<string> users;

    void saveToDatabase(const string& name) {
        cout << "Se guardó el usuario " << name << " en la base de datos." << endl;
    }
};

int main() {
    UserManager userManager;
    userManager.addUser("Alice");
    userManager.addUser("Bob");

    userManager.displayUsers();

    return 0;
}


/////////////
// APLICANDO SRP

#include <iostream>
#include <vector>

using namespace std;

// Clase que representa un usuario
class User {
public:
    User(const string& name) : name(name) {}

    string getName() const {
        return name;
    }

private:
    string name;
};

// Clase responsable de la persistencia de datos
class UserRepository {
public:
    void saveUser(const User& user) {
        cout << "Se guardó el usuario " << user.getName() << " en la base de datos." << endl;
    }
};

// Clase que maneja la lógica de negocio de los usuarios
class UserManager {
public:
    void addUser(const string& name) {
        User user(name);
        users.push_back(user);
        repository.saveUser(user);
    }

    void displayUsers() {
        for (const auto& user : users) {
            cout << "Usuario: " << user.getName() << endl;
        }
    }

private:
    vector<User> users;
    UserRepository repository;
};

int main() {
    UserManager userManager;
    userManager.addUser("Alice");
    userManager.addUser("Bob");

    userManager.displayUsers();

    return 0;
}