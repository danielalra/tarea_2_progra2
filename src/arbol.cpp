#include <map>
#include "arbol.h"
#include "nodo.h"

Arbol::Arbol() {
    this->raiz=nullptr;
}

Arbol::~Arbol() {
    if(raiz!=nullptr){
        delete this->raiz;
    }
}


void Arbol::AgregarNodo(int ID, string nombre, string apellido, int tipoEmpleado, int IDsupervisor)
{
    if(IDsupervisor == 0){

        Nodo *nodoRaiz = new Nodo(ID, nombre, apellido, tipoEmpleado, ID);
        this->raiz = nodoRaiz;
        this->elementos.insert(pair<int,Nodo *>(ID, nodoRaiz)); 
    }
    else{
        Nodo *nodo = new Nodo(ID, nombre, apellido, tipoEmpleado, IDsupervisor);
        // Buscar ese nodo padre
        Nodo *nodoSupervisor = this->elementos.at(IDsupervisor);
        nodo->SetNombreSupervisor(nodoSupervisor->GetNombreCompleto()); 
        nodoSupervisor->AgregarHijo(nodo);


        // Agregar nodo al índice
        this->elementos.insert(pair<int,Nodo *>(ID, nodo));
    }

}
void Arbol::SetPago(int ID, int pago){
    Nodo *nodo = this->elementos.at(ID);
    nodo->SetPago(pago);
}
std::ostream& operator << (std::ostream &o, const Arbol &arbol){
    Nodo* raiz = arbol.raiz;
    o << *(raiz);

    return o;
}