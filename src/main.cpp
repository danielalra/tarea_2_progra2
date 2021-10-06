#ifndef UNIT_TEST

#include "arbol.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main(){

    //variables a utilizar
    string linea {" "};

    int id {0};
    int salario {0};
    int horas {0};

    //el arbol
     Arbol *arbol = new Arbol();


    //leer Persnas.txt 
    std::ifstream lectorPersonas("C:/progra2/tarea_2_progra2/src//Personas.txt", std::ifstream::in);
    if (!lectorPersonas.is_open())
    {
        std::cerr << "Error leyendo archivo Personas.txt" << std::endl;
        return -1;
    }

     lectorPersonas >> *arbol;

    lectorPersonas.close();


    //  leer Nomina.txt
    std::ifstream lectorNomina("C:/progra2/tarea_2_progra2/src//Nomina.txt", std::ifstream::in);
    if (!lectorNomina.is_open())
    {
        std::cerr << "Error leyendo archivo Nomina.txt" << std::endl;
        return -1;
    }
    while (getline(lectorNomina, linea)){
        istringstream stream(linea);

        id=0;
        salario=0;
        
        stream >> id >>salario;

        arbol->AsignarSalario(id,salario,1);
    }

    lectorNomina.close();

    

    //leer HorasTrabajadas.txt y asignar salarios
    std::ifstream lectorHorasTrabajadas("C:/progra2/tarea_2_progra2/src//HorasTrabajadas.txt", std::ifstream::in);
    if (!lectorHorasTrabajadas.is_open())
    {
        std::cerr << "Error leyendo archivo HorasTrabajadas.txt" << std::endl;
        return -1;
    }

    while (getline(lectorHorasTrabajadas, linea)){
        istringstream stream(linea);

        id=0;
        salario=0;
        horas=0;

        /*string string1 {""};
        string string2 {""};
        string string3 {""};*/
        
        stream >> id >> salario >> horas;

        //stream >> string1 >> string2 >> string3;
       // cout << string1 << " " << string2 << " " << string3 <<endl;


        arbol->AsignarSalario(id,salario,horas);
    }

    lectorHorasTrabajadas.close();
    
    //escribir el archivo de salida 
    std::ofstream escritor1("Cuentas.csv", std::ofstream::out); 

    escritor1 << *(arbol);
    escritor1 << arbol->GetNeto() <<", "<<arbol->GetRetencion()<<", "<< arbol->GetBruto() << endl;

    escritor1.close();
    
    //cout << *arbol;

    delete arbol;

 return 0;
}

#endif