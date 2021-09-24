#include <map>
#include "arbol.h"
#include "nodo.h"

Arbol::Arbol(int ID, string nombre, string apellido, int tipoEmpleado) {

    Nodo *nodoRaiz = new Nodo(ID, nombre, apellido, tipoEmpleado, ID);
    this->raiz = nodoRaiz;

    this->elementos.insert(pair<int,Nodo *>(ID, nodoRaiz));
}

Arbol::~Arbol() {

    delete this->raiz;

}


void Arbol::AgregarNodo(int ID, string nombre, string apellido, int tipoEmpleado, int IDsupervisor)
{
    Nodo *nodo = new Nodo(ID, nombre, apellido, tipoEmpleado, IDsupervisor);

    // Buscar ese nodo padre
    Nodo *nodoPadre = this->elementos.at(IDsupervisor);
    nodoPadre->AgregarHijo(nodo);

    // Agregar nodo al índice
    this->elementos.insert(pair<int,Nodo *>(ID, nodo));
}
void Arbol::AgregarRaiz(int ID, string nombre, string apellido, int tipoEmpleado){
    Nodo *nodoRaiz = new Nodo(ID, nombre, apellido, tipoEmpleado, ID);
    this->raiz = nodoRaiz;

    this->elementos.insert(pair<int,Nodo *>(ID, nodoRaiz));
}


std::ostream& operator << (std::ostream &o, const Arbol &arbol){
    Nodo* raiz = arbol.raiz;
    o << *(raiz);

    return o;
}