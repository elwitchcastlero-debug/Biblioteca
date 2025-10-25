#include "Biblioteca.h"
#include <iostream>
#include <vector>
using namespace std;

void Biblioteca::agregar(const libro& Libro) {
    libros.push_back(Libro);
}

void Biblioteca::quitar(const libro& Libro) {
    bool encontrado = false;
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->getisbn_sn() == Libro.getisbn_sn()) {
            libros.erase(it);
            encontrado = true;
            cout << "Libro eliminado.\n";
            break;
        }
    }
    if (!encontrado)
        cout << "Libro no encontrado.\n";
}

int Biblioteca::direccion(const libro& Libro) const {
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i].getTitulo() == Libro.getTitulo() ||
            libros[i].getAutor() == Libro.getAutor()) {
            cout << "Libro encontrado en estante " << i + 1 << endl;
            return i;
        }
    }
    cout << "No se encontró el libro.\n";
    return -1;
}

void Biblioteca::mostrar() const {
    for (int i = 0; i < libros.size(); i++) {
        cout << "Estante " << i + 1 << ": ";
        vector<string> datos = libros[i].glibro();
        for (int j = 0; j < datos.size(); j++) {
            cout << datos[j] << " ";
        }
        cout << endl;
    }
}

vector<libro>& Biblioteca::getLibros() {
    return libros;
}