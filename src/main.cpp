#include "arbol.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main(){

     Arbol *arbol = new Arbol();


    //leer Persnas.txt 
    std::ifstream lectorPersonas("Personas.txt", std::ifstream::in);
    if (!lectorPersonas.is_open())
    {
        std::cerr << "Error leyendo archivo Personas.txt" << std::endl;
        return -1;
    }

     lectorPersonas >> *arbol;

    lectorPersonas.close();



    //  leer Nomina.txt y asignar salarios
    std::ifstream lectorNomina("Nomina.txt", std::ifstream::in);
    if (!lectorNomina.is_open())
    {
        std::cerr << "Error leyendo archivo Nomina.txt" << std::endl;
        return -1;
    }

        lectorNomina > *arbol;
    
    lectorNomina.close();



    //leer HorasTrabajadas.txt y asignar pagos
    std::ifstream lectorHorasTrabajadas("HorasTrabajadas.txt", std::ifstream::in);
    if (!lectorHorasTrabajadas.is_open())
    {
        std::cerr << "Error leyendo archivo HorasTrabajadas.txt" << std::endl;
        return -1;
    }

        lectorHorasTrabajadas < *arbol;

    lectorHorasTrabajadas.close();

    //escribir el archivo de salida
    std::ofstream escritor("Cuentas.csv", std::ofstream::out); 

    escritor << *(arbol);
    //escritor << totalNeto <<"; "<<retencion<<"; "<< totalBruto << endl;

    escritor.close();
    //hols*/
    //cout << *arbol;

    delete arbol;

 return 0;
}