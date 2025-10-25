#include <iostream>
#include <vector>
#include "libro.h"
#include "Biblioteca.h"
using namespace std;

// -------- Clase base usuario --------
class usuario {
protected:
    string nombre;
    int id;

public:
    usuario(string n, int i) : nombre(n), id(i) {}  //define usuario
    void mostrarInfo() const {
        cout << "Nombre: " << nombre << ", ID: " << id << endl;
    }
};

// -------- Clase derivada estudiante --------
class estudiante : public usuario {
    int maxlibros = 4;   //maximo de libros por estudiante
    vector<libro> librosPrestados;

public:
    estudiante(string n, int i) : usuario(n, i) {}

    void prestarLibro(Biblioteca &biblio, libro &Libro) {  //metodo para poder pedir y ejecutar prestamo
        int a = biblio.direccion(Libro);                    //dirección de nuestro libro en la biblioteca
        if (a == -1) {                                      //no está
            cout << "El libro no se encuentra disponible.\n";
            return;
        }

        vector<libro> &librosBiblio = biblio.getLibros();         //obtener biblioteca y realizarle cambios dentro de esta
        if (librosBiblio[a].estaDisponible()) {                    //si está disponible
            if (librosPrestados.size() < maxlibros) {                //si el estudiante no hallegado al maximo de libros
                librosPrestados.push_back(Libro);                     //el libro entra a nuestro inventario de libros
                librosBiblio[a].setDisponibilidad(false);             //el libro no es eliminado de la biblioteca pero si se cambia su disponibilidad a no disponible
                cout << "Libro prestado con éxito.\n";
            } else {
                cout << "Has alcanzado el límite de libros prestados.\n";
            }
        } else {
            cout << "El libro no está disponible.\n";
        }
    }

    void mostrarLibrosPrestados() const {                                  //para que el estudiante sepa cuantos libros ha pedido prestado
        cout << "\nLibros prestados por " << nombre << ":\n";
        if (librosPrestados.empty()) {
            cout << "  Ninguno.\n";
            return;
        }
        for (auto &l : librosPrestados)
            cout << "  - " << l.getTitulo() << " (" << l.getAutor() << ")\n";
    }
};

// -------- Clase derivada profesor --------
class profesor : public usuario {
    int maxlibros = 10;
    vector<libro> librosPrestados;
//lo mismo que la clase estudiante pero con un mayor limite de libros que puede pedir
public:
    profesor(string n, int i) : usuario(n, i) {}

    void prestarLibro(Biblioteca &biblio, libro &Libro) {
        int a = biblio.direccion(Libro);
        if (a == -1) {
            cout << "El libro no se encuentra disponible.\n";
            return;
        }

        vector<libro> &librosBiblio = biblio.getLibros();
        if (librosBiblio[a].estaDisponible()) {
            if (librosPrestados.size() < maxlibros) {
                librosPrestados.push_back(Libro);
                librosBiblio[a].setDisponibilidad(false);
                cout << "Libro prestado con éxito.\n";
            } else {
                cout << "Has alcanzado el límite de libros prestados.\n";
            }
        } else {
            cout << "El libro no está disponible.\n";
        }
    }

    void mostrarLibrosPrestados() const {
        cout << "\nLibros prestados por " << nombre << ":\n";
        if (librosPrestados.empty()) {
            cout << "  Ninguno.\n";
            return;
        }
        for (auto &l : librosPrestados)
            cout << "  - " << l.getTitulo() << " (" << l.getAutor() << ")\n";
    }
};

// -------- Función principal -------- //puesta en acción del programa
int main() {
    // Crear algunos libros
    libro l1("Cien años de soledad", "Gabriel García Márquez", "1234", true);
    libro l2("El Principito", "Antoine de Saint-Exupéry", "5678", true);
    libro l3("1984", "George Orwell", "9999", true);

    // Crear biblioteca y agregar libros
    Biblioteca biblio;
    biblio.agregar(l1);
    biblio.agregar(l2);
    biblio.agregar(l3);

    cout << "\n--- Libros en la biblioteca ---\n";
    biblio.mostrar();

    // Crear usuarios
    estudiante e1("Luis", 101);
    profesor p1("Ana", 202);

    // Préstamos
    e1.prestarLibro(biblio, l1);
    p1.prestarLibro(biblio, l2);

    // Mostrar libros prestados
    e1.mostrarLibrosPrestados();
    p1.mostrarLibrosPrestados();

    cout << "\n--- Libros en la biblioteca tras los préstamos ---\n";
    biblio.mostrar();

    return 0;
}
