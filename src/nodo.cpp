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
void Nodo::SetPago(float pago){
    this->pago=pago;
}
std::ostream& operator << (std::ostream &o, const Nodo &nodo)
{
    /*string pagoSalida = to_string(nodo.pago);
    string salida = nodo.ID +", "+ nodo.nombre + " " + nodo.apellido + ", " + nodo.nombreSupervisor + ", " + pagoSalida;
    o << salida;*/

    o <<nodo.ID;
    o << "; ";
    o << nodo.nombre << " " <<nodo.apellido;
    o << "; ";
    o << nodo.nombreSupervisor;
    o << "; ";
    o << nodo.pago;
    o << endl;

    // Imprimir información de cada hijo
    for (Nodo *nodoHijo : nodo.hijos)
    {
        o << *nodoHijo;
    }

    return o;
}

