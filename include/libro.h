#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <vector>
using namespace std;

class libro {
    string titulo;
    string autor;
    string isbn_sn;
    bool disponible;

public:
    libro(string t = "", string a = "", string i = "", bool d = true)
        : titulo(t), autor(a), isbn_sn(i), disponible(d) {}

    // Métodos de acceso
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    string getisbn_sn() const { return isbn_sn; }
    bool estaDisponible() const { return disponible; }

    void setDisponibilidad(bool d) { disponible = d; }

    vector<string> glibro() const {
        return {titulo, autor, isbn_sn, disponible ? "Disponible" : "No disponible"};
    }
};

#endif
