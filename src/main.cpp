#include "arbol.h"
#include <iostream>
#include <string>
int main(){
 
 Arbol *arbol = new Arbol(1, "daniel1", "alvarez1", 1);
 arbol->AgregarNodo(2, "daniel2", "alvarez2", 1, 1);
 arbol->AgregarNodo(3, "daniel3", "alvarez3", 1, 1);
 arbol->AgregarNodo(4, "daniel4", "alvarez4", 1, 2);
 arbol->AgregarNodo(5, "daniel5", "alvarez5", 1, 2);
 arbol->AgregarNodo(6, "daniel6", "alvarez6", 1, 2);
 arbol->AgregarNodo(7, "daniel7", "alvarez7", 1, 2);
 arbol->AgregarNodo(8, "daniel8", "alvarez8", 1, 3);

 cout << *(arbol);

 delete arbol;

 return 0;
}