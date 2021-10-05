#include "arbol.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main(){
    
    //variables a utilizar
    string linea {""};
    int id {0};
    string nombre{""};
    string apellido{""};
    string correo{""};
    int tipoEmpleado {0};
    int idSupervisor {0};
    float salario {0};
    int horas {0};
    double totalNeto {0};
    double totalBruto {0};
    double retencion {0};
    int contador {1};

    Arbol *arbol = new Arbol();

    //leer Persnas.txt y crear el arbol
    std::ifstream lectorPersonas("Personas.txt", std::ifstream::in);
    if (!lectorPersonas.is_open())
    {
        std::cerr << "Error leyendo archivo Personas.txt" << std::endl;
        return -1;
    }

    while (getline(lectorPersonas, linea)){
        std::istringstream stream(linea);

        nombre="";
        apellido="";
        correo="";
        tipoEmpleado=0;
        idSupervisor=0;
        
        stream >> id >> nombre >> apellido >> correo >> tipoEmpleado >> idSupervisor;

        arbol->AgregarNodo(id, nombre, apellido, tipoEmpleado, idSupervisor);
    }
    lectorPersonas.close();
    //  leer Nomina.txt y asignar pagos

    /*std::ifstream lectorNomina("Nomina.txt", std::ifstream::in);
    if (!lectorNomina.is_open())
    {
        std::cerr << "Error leyendo archivo Nomina.txt" << std::endl;
        return -1;
    }
    while (getline(lectorNomina, linea)){
        std::istringstream stream(linea);

        ID=0;
        pago=0;
        
        stream >> ID >> pago;

        double reteniendo {pago*0.07}; 
        retencion+=reteniendo;
        totalBruto+=pago;
        pago = pago-reteniendo;
        totalNeto+=pago;

        arbol->SetSalario(ID, pago);

    }
    lectorNomina.close();

    //leer HorasTrabajadas.txt y asignar pagos
    std::ifstream lectorHorasTrabajadas("HorasTrabajadas.txt", std::ifstream::in);
    if (!lectorHorasTrabajadas.is_open())
    {
        std::cerr << "Error leyendo archivo HorasTrabajadas.txt" << std::endl;
        return -1;
    }
    while (getline(lectorHorasTrabajadas, linea)){
        std::istringstream stream(linea);

        ID=0;
       pago=0;
       horas=0;

        stream >> ID >> pago;
        stream >> horas;

        pago=pago*horas;
        totalBruto+=pago;
        totalNeto+=pago;

        arbol->SetSalario(ID, pago);

    }
    lectorHorasTrabajadas.close();

    //escribir el archivo de salida
    std::ofstream escritor("Cuentas.csv", std::ofstream::out); 

    escritor << *(arbol);
    escritor << totalNeto <<"; "<<retencion<<"; "<< totalBruto << endl;

    escritor.close();
    //hols*/
    cout << *(arbol);

    delete arbol;

 return 0;
}