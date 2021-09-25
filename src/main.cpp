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
    int IDsupervisor {0};
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
 return 0;
}