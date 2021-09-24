#include "nodo.h"
#include "empleado.h"

Nodo::Nodo(Empleado empleado) : empleado(empleado){
    this->ID = this->empleado.getID();
}

Nodo::~Nodo(){
    for (Nodo* hijo : this->hijos){
        delete hijo;
    }
}

void Nodo::AgregarHijo(Nodo *hijo) {
    this->hijos.push_back(hijo);
}