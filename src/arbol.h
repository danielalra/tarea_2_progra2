#ifndef ARBOL_H
#define ARBOL_H
#include "nodo.h"
#include <map>
using namespace std;

class Arbol{

    float bruto;
    float neto;

    Nodo *raiz;
    map <int, Nodo *> elementos;
    
    public:
    Arbol();
    ~Arbol();
    void AgregarNodo(int, string, string, int, int);
    void SetSalario(int, float, int);
    float GetBruto();
    float GetNeto();
    float GetRetencion();

    //leer un archivo con formato de Personas.txt
    friend std::istream& operator >> (std::istream &i, Arbol &arbol);

    //escribir el archivo deseado
    friend std::ostream& operator << (std::ostream &o, const Arbol &arbol);

};
#endif