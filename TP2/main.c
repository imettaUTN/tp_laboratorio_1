#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "common.h"
#define TRUE 1
#define FALSE 0
#define LENGTH 1000
int main()
{
    int opcion = 0;
    int hasValueOpc1 =FALSE;
    int id = 100;
    int exit = FALSE;
    Employee listado[LENGTH];
    // first of all is initialize list
    initEmployees(listado,LENGTH);
    opcion =common_getMenu("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.EXIT\n","Opcion invalida. Reingrese",1,5,3);
        do
        {
            validarOpcionesMenu(&opcion,hasValueOpc1,"First must add a new employee \n");
            switch(opcion)
                {
                case 1:
                    hasValueOpc1 = TRUE;
                    if(!isValidReturnedFunctionValue(addEmployee(listado,LENGTH,++id)))
                    {
                        printf("Terminal error. System will exit \n");
                        exit = TRUE;
                    }
                    break;
                case 2:
                    if(!isValidReturnedFunctionValue(modifyEmployee(listado,LENGTH)))
                    {
                        printf("Terminal error. System will exit \n");
                        exit = TRUE;
                    }
                    break;
                case 3:
                    if(!isValidReturnedFunctionValue(removeEmployee(listado,LENGTH)))
                    {
                        printf("Terminal error. System will exit \n");
                        exit = TRUE;
                    }
                    break;
                case 4:
                    if(common_getMenu("Ingrese la operacion a realizar :\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2. Total y promedio de los salarios, y cúantos empleados superan el salario promedio\n","Opcion invalida. Reingrese",1,2,3)==1)
                    {
                        if(isValidReturnedFunctionValue(sortEmployees(listado,LENGTH,common_getMenu("Enter the order to list the employees:\n0. Down\n1. UP\n","Opcion invalida. Reingrese",0,1,2))))
                        {
                            printEmployees(listado,LENGTH);
                        }
                        else
                        {
                            printf("Terminal error. System will exit \n");
                            exit = TRUE;
                            break;
                        }
                    }
                    else
                    {
                        float total = calculateTotalSalary(listado,LENGTH);
                        if(isValidReturnedFunctionValue((int) total))
                        {
                            printf("Total employees salaries is %.2f \n",total);
                        }
                        else
                        {
                            printf("Terminal error. System will exit \n");
                            exit = TRUE;
                            break;
                        }
                        float averageSalary = calculateAverageSalaries(listado,LENGTH);
                        if(isValidReturnedFunctionValue((int) averageSalary))
                        {
                            printf("the average of employees salaries is %.2f \n",averageSalary);
                        }
                        else
                        {
                            printf("Terminal error. System will exit \n");
                            exit = TRUE;
                            break;
                        }

                        int cantOfSalaryUpAvg = amountOfEmployeesUpsAvg(listado,LENGTH,averageSalary);
                        if(isValidReturnedFunctionValue(cantOfSalaryUpAvg))
                        {
                            printf("the amount of employees whose salaries are up average salary %d \n",cantOfSalaryUpAvg);
                        }
                        else
                        {
                            printf("Terminal error. System will exit \n");
                            exit = TRUE;
                            break;
                        }
                    }
                    break;
                }
            system("pause");
            system("cls");
            opcion =common_getMenu("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.EXIT\n","Opcion invalida. Reingrese",1,5,3);

        }
        while(!exit && opcion != 5 );

    return TRUE;
}
