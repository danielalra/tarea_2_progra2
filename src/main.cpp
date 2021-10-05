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
    float bruto {0};
    float neto {0};
    float retencion {0};

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
    while (getline(lectorNomina, linea)){
        istringstream stream(linea);

        id=0;
        salario=0;
        
        stream >> id >>salario;

         //actualiza el bruto
        bruto+=salario;

        //obtiene el dinero retenido
        int retenido = salario*0.07;

        //actualiza neto y retencion 
        salario=salario-retenido;
        neto+=salario;
        retencion+=retenido;

        arbol->SetSalario(id,salario,1);
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
        istringstream stream(linea);

        id=0;
        salario=0;
        horas=0;
        
        stream >> id >>salario >> horas;

        //actualiza neto y bruto

        arbol->SetSalario(id,salario,horas);
        bruto+=salario*horas;
        neto+=salario*horas;
    }

    lectorHorasTrabajadas.close();
    /*
    //escribir el archivo de salida
    std::ofstream escritor("Cuentas.csv", std::ofstream::out); 

    escritor << *(arbol);
    escritor << neto <<", "<<retencion<<", "<< bruto << endl;
    //cout << bruto-(neto + retencion) << endl;

    escritor.close();
    */
    cout << *arbol;

    delete arbol;

 return 0;
}