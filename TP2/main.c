#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define LENGTH 1000
int main()
{
    int opcion = 0;
    int hasValueOpc1 =0;
    int id = 100;
    int exit =-1;
    int firstExitOptionValue = 1;
    Employee listado[LENGTH];

    // Lo primero que se hace es inicializar el vector
    initEmployees(listado,LENGTH);

    opcion = menu(hasValueOpc1);
    do
    {
        switch(opcion)
        {
            case 1:
                hasValueOpc1 = 1;
                if(!generalErrorValidation(addEmployee(listado,LENGTH,++id)))
                {
                    printf("Terminal error. System will exit");
                    exit = 1;
                }

                break;
            case 2:
                if(!generalErrorValidation(modifyEmployee(listado,LENGTH)))
                {
                    printf("Terminal error. System will exit");
                    exit = 1;
                }
                break;
            case 3:
                if(generalErrorValidation(removeEmployee(listado,LENGTH)))
                {
                    printf("Terminal error. System will exit");
                    exit = 1;
                }
                break;
            case 4:
                if(subMenuOpc4() == 1)
                {
                    if(!generalErrorValidation(sortEmployees(listado,LENGTH,order())))
                    {
                        printf("Terminal error. System will exit");
                        exit = 1;
                        break;
                    }
                }
                else
                {
                    float total = calculateTotalSalary(listado,LENGTH);
                    if(generalErrorValidation((int) total))
                    {
                        printf("Total employees salaries is %.2f",total);
                    }
                    else{
                        printf("Terminal error. System will exit");
                        exit = 1;
                        break;
                    }


                    float averageSalary = calculateAverageSalary(listado,LENGTH);
                    if(generalErrorValidation((int) averageSalary))
                    {
                        printf("the average of employees salaries is %.2f",averageSalary);
                    }
                    else{
                        printf("Terminal error. System will exit");
                        exit = 1;
                        break;
                    }

                    int cantOfSalaryUpAvg = amountOfEmployeesUpsAvg(listado,LENGTH,averageSalary);
                    if(generalErrorValidation(cantOfSalaryUpAvg))
                    {
                        printf("the amount of employees whose salaries are up average salary %.2f",cantOfSalaryUpAvg);
                    }
                    else{
                        printf("Terminal error. System will exit");
                        exit = 1;
                        break;
                    }

                }
                break;
        }

        // Add the option to exit , if there wasnt terminal error before
        if(exit == -1)
        {
            do
            {
                if(!firstExitOptionValue)
                {
                    printf("Input error, re-enter. Do you want to exit ? yes 1, not 0");
                }
                else
                {
                    printf("Do you want to exit ? yes 1, not 0");
                }
                scanf("%d",&exit);
            }while(exit < 0 || exit > 1);
        }
        system("pause");
        system("cls");
        opcion = menu(hasValueOpc1);
    } while(!exit);
    return 0;
}
