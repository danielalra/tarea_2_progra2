#ifndef ARBOL_H
#define ARBOL_H
#include "nodo.h"
#include <map>
using namespace std;

class Arbol{

    Nodo *raiz;
    map <int, Nodo *> elementos;
    

    public:
    Arbol();
    ~Arbol();
    void AgregarNodo(int, string, string, int, int);
    void SetSalario(int, float, int);
    friend std::ostream& operator << (std::ostream &o, const Arbol &arbol);
    friend std::istream& operator >> (std::istream &i, Arbol &arbol);

};
#endif