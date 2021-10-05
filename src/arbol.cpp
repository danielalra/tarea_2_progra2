#include <map>
#include "arbol.h"
#include "nodo.h"
#include <sstream>
#include <iostream>

Arbol::Arbol() {
    this->raiz=nullptr;
    this->totalBruto=0;
    this->totalNeto=0;
    this->retencion=0;
}

Arbol::~Arbol() {
    if(raiz!=nullptr){
        delete this->raiz;
    }
}


void Arbol::AgregarNodo(int id, string nombre, string apellido, int tipoEmpleado, int idSupervisor)
{
    if(idSupervisor == 0){

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

istream& operator > (istream &lector2, Arbol &arbol)
{
    string linea {""};

    int id {0};
    int salario {0};

    while (getline(lector2, linea)){
        istringstream stream(linea);

        id=0;
        salario=0;
        
        stream >> id >>salario; 

        salario=salario*0.93; //retencion del 7%

        arbol.SetSalario(id,salario,1);
    }

    return lector2;
}

istream& operator < (istream &lector3, Arbol &arbol)
{
    string linea {""};

    int id {0};
    int salario {0};
    int horas {0};

    while (getline(lector3, linea)){
        istringstream stream(linea);

        id=0;
        salario=0;
        horas=0;
        
        stream >> id >>salario >> horas;

        arbol.SetSalario(id,salario,horas);
    }

    return lector3;
}
