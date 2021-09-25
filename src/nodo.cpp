#include "nodo.h"
#include <string>
#include <iostream>
using namespace std;

Nodo::Nodo(int ID, string nombre, string apellido, int tipoEmpleado, int IDsupervisor){
    this->ID=ID;
    this->nombre=nombre;
    this->apellido=apellido;
    this->tipoEmpleado=tipoEmpleado;
    this->IDsupervisor=IDsupervisor;
    this->pago=0;
}

Nodo::~Nodo(){
    for (Nodo* hijo : this->hijos){
        delete hijo;
    }
}

void Nodo::AgregarHijo(Nodo *hijo) {
    this->hijos.push_back(hijo);
}
string Nodo::GetNombreCompleto(){
    return this->nombre+ " " +this->apellido;
}

void Nodo::SetNombreSupervisor(string nombreSupervisor){
    this->nombreSupervisor=nombreSupervisor;
}
void Nodo::SetPago(int pago){
    this->pago=pago;
}
std::ostream& operator << (std::ostream &o, const Nodo &nodo)
{

    o << nodo.ID;
    o << ",";
    o << nodo.nombre << " " <<nodo.apellido;
    o << ",";
    o << nodo.nombreSupervisor;
    o << std::endl;

    // Imprimir información de cada hijo
    for (Nodo *nodoHijo : nodo.hijos)
    {
        o << *nodoHijo;
    }

    return o;
}

