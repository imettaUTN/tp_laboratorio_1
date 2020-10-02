#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "menus.h"
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
    opcion = menu(hasValueOpc1);
    do
    {
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
                if(subMenuInformar()==1)
                {
                    if(isValidReturnedFunctionValue(sortEmployees(listado,LENGTH,subMenuOrder())))
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
                    else{
                        printf("Terminal error. System will exit \n");
                        exit = TRUE;
                        break;
                    }
                    float averageSalary = calculateAverageSalaries(listado,LENGTH);
                    if(isValidReturnedFunctionValue((int) averageSalary))
                    {
                        printf("the average of employees salaries is %.2f \n",averageSalary);
                    }
                    else{
                        printf("Terminal error. System will exit \n");
                        exit = TRUE;
                        break;
                    }

                    int cantOfSalaryUpAvg = amountOfEmployeesUpsAvg(listado,LENGTH,averageSalary);
                    if(isValidReturnedFunctionValue(cantOfSalaryUpAvg))
                    {
                        printf("the amount of employees whose salaries are up average salary %d \n",cantOfSalaryUpAvg);
                    }
                    else{
                        printf("Terminal error. System will exit \n");
                        exit = TRUE;
                        break;
                    }
                }
                break;
        }
        system("pause");
        system("cls");
        opcion = menu(hasValueOpc1);
    } while(!exit && opcion != 5 );
       return TRUE;
}
