#include "arbol.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(){

    std::ifstream lector("Personas.txt", std::ifstream::in);
    if (!lector.is_open())
    {
        std::cerr << "Error leyendo archivo ejemplo.txt" << std::endl;
        return -1;
    }

    string linea {""};
    int ID {0};
    string nombre{""};
    string apellido{""};
    string correo{""};
    int tipoEmpleado {0};
    int IDsupervisor {47};
    int contador {1};

    Arbol *arbol = new Arbol();

    while (getline(lector, linea)){
        std::istringstream stream(linea);

        nombre="";
        apellido="";
        correo="";
        tipoEmpleado=0;
        IDsupervisor=0;
        
        stream >> ID >> nombre >> apellido >> correo >> tipoEmpleado >> IDsupervisor;

        arbol->AgregarNodo(ID, nombre, apellido, tipoEmpleado, IDsupervisor);
        contador++;
        
    }

    cout << *(arbol);

    delete arbol;

    lector.close();
    



 
 /*Arbol *arbol = new Arbol(1, "daniel1", "alvarez1", 1);
 arbol->AgregarNodo(2, "daniel2", "alvarez2", 1, 1);
 arbol->AgregarNodo(3, "daniel3", "alvarez3", 1, 1);
 arbol->AgregarNodo(4, "daniel4", "alvarez4", 1, 2);
 arbol->AgregarNodo(5, "daniel5", "alvarez5", 1, 2);
 arbol->AgregarNodo(6, "daniel6", "alvarez6", 1, 2);
 arbol->AgregarNodo(7, "daniel7", "alvarez7", 1, 2);
 arbol->AgregarNodo(8, "daniel8", "alvarez8", 1, 3);

 cout << *(arbol);

 delete arbol;*/


 return 0;
}