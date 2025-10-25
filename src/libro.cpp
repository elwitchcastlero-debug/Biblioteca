#ifndef LIBRO_H
#define LIBRO_H
#include<iostream>
#include<vector>
using namespace std;
class libro{
    string titulo;
    string autor;
    string isbn_sn;
    bool disponibilidad;
public:
    libro(string x, string y, string z, bool k):titulo(x), autor(y), isbn_sn(z), disponibilidad(k){}
vector<string> glibro() const {
        vector<string> book;
        book.push_back("Título: " + titulo);
        book.push_back("Autor: " + autor);
        book.push_back("ISBN/SN: " + isbn_sn);
        book.push_back(disponibilidad ? "Disponible" : "No disponible");
        return book;
    }
string getTitulo() const{
    return titulo;
}
string getAutor() const{
    return autor;
}
string getisbn_sn()const{
    return isbn_sn;
}
bool estaDisponible() const { 
    return disponibilidad; }
void setDisponibilidad(bool estado) { 
    disponibilidad = estado; }
};
#endif
