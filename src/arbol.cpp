#include <map>
#include "arbol.h"
#include "nodo.h"
#include <sstream>
#include <iostream>
using namespace std;

Arbol::Arbol() {
    this->raiz=nullptr;

}

Arbol::~Arbol() {
    if(raiz!=nullptr){
        delete this->raiz;
    }
    this->bruto=0;
    this->neto=0;
}


void Arbol::AgregarNodo(int id, string nombre, string apellido, int tipoEmpleado, int idSupervisor)
{
    if(id == 1){

        Nodo *nodoRaiz = new Nodo(id, nombre, apellido, tipoEmpleado, idSupervisor);
        this->raiz = nodoRaiz;
        this->elementos.insert(pair<int,Nodo *>(id, nodoRaiz)); 
    }
    else{
        Nodo *nodo = new Nodo(id, nombre, apellido, tipoEmpleado, idSupervisor);
        // Buscar ese nodo supervisor
        Nodo *nodoSupervisor = this->elementos.at(idSupervisor);
        nodo->SetNombreSupervisorNodo(nodoSupervisor->GetNombreNodo());
        nodoSupervisor->AgregarHijo(nodo);


        // Agregar nodo al índice
        this->elementos.insert(pair<int,Nodo *>(id, nodo));
    }

}
void Arbol::SetSalario(int id, float salario, int horas){
    Nodo *nodo = this->elementos.at(id);

    nodo->SetSalarioNodo(salario, horas);
    this->bruto+=nodo->GetBrutoNodo();
    this->neto+=nodo->GetNetoNodo();
}
float Arbol::GetBruto(){
    return this->bruto;
}
float Arbol::GetNeto(){
    return this->neto;
}
float Arbol::GetRetencion(){
    return ((this->bruto)-(this->neto));
}


ostream& operator << (ostream &o, const Arbol &arbol){
    Nodo* raiz = arbol.raiz;
    o << *(raiz);  
    return o;
}
istream& operator >> (istream &lector, Arbol &arbol)
{
    string linea {""};

    int id {0};
    string nombre {""};
    string apellido {""};
    string correo {""};
    int tipoEmpleado {0};
    int idSupervisor {0};

    while (getline(lector, linea)){
        istringstream stream(linea);

        id=0;
        nombre="";
        apellido="";
        correo="";
        tipoEmpleado=0;
        idSupervisor=0;
        
        stream >> id >> nombre >> apellido >> correo >> tipoEmpleado >> idSupervisor;

        arbol.AgregarNodo(id, nombre, apellido, tipoEmpleado, idSupervisor);
    }

    return lector;
}
