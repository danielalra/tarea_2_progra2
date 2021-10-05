#include <gtest/gtest.h>
#include "../src/empleadoPorHoras.h"
#include <string>
using namespace std;

namespace{

  
    TEST(EmpleadoPorHoras_Test, Getid_Test){
       EmpleadoPorHoras *empleado1 = new EmpleadoPorHoras(4,"Daniel", "Alvarez",3);
       int id = empleado1->Getid();
       EXPECT_EQ(4, id); 
    }  
    TEST(EmpleadoPorHoras_Test, GetNombreCompleto_Test){
       EmpleadoPorHoras *empleado1 = new EmpleadoPorHoras(4,"Daniel", "Alvarez",3);
       string nombre = empleado1->GetNombreCompleto();
       EXPECT_EQ("Daniel Alvarez", nombre);
    }

}