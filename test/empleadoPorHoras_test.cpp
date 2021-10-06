#include <gtest/gtest.h>
#include "C:/progra2/tarea_2_progra2/src/empleadoPorHoras.h"
#include <string>
using namespace std;

namespace{

    TEST(EmpleadoPorHorasTest, CalcularSalario_GetNeto_test){
        EmpleadoPorHoras *empleado1 = new EmpleadoPorHoras(4,"Daniel", "Alvarez",3);
        empleado1->CalcularSalario(200,4);

        float salario = empleado1->GetNeto();

        EXPECT_FLOAT_EQ(800, salario);
    }
    TEST(EmpleadoPorHorasTest, CalcularSalario_GetBruto_test){
        EmpleadoPorHoras *empleado1 = new EmpleadoPorHoras(4,"Daniel", "Alvarez",3);
        empleado1->CalcularSalario(200,4);

        float salario = empleado1->GetBruto();

        EXPECT_FLOAT_EQ(800, salario);
    }


    TEST(EmpleadoPorHoras_Test, SetNombreSupervisor_GetNombreSupervisor_Test){
       EmpleadoPorHoras *empleado1 = new EmpleadoPorHoras(4,"Daniel", "Alvarez",3);
       empleado1->SetNombreSupervisor("Juan Perez");
       string nombreSupervisor = empleado1->GetNombreSupervisor();
       EXPECT_EQ("Juan Perez", nombreSupervisor); 
    } 
    TEST(EmpleadoPorHoras_Test, Getid_Test){
       EmpleadoPorHoras *empleado1 = new EmpleadoPorHoras(4,"Daniel", "Alvarez",3);
       int id = empleado1->Getid();
       EXPECT_EQ(4, id); 
    }  
    TEST(EmpleadoPorHoras_Test, GetNombreCompleto_Test){
       EmpleadoPorHoras *empleado1 = new EmpleadoPorHoras(4,"Daniel", "Alvarez",3);
       string nombreSupervisor = empleado1->GetNombreCompleto();
       EXPECT_EQ("Daniel Alvarez", nombreSupervisor);
    }

}