#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int allOk = 0;
    char buffer[4][128];
    int cant ;
    if(pFile == NULL && pArrayListEmployee == NULL  )
    {
        printf("No se puede abrir el archivo \n");
        return allOk;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
    while(!feof(pFile))
    {
        Employee * aux;
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(cant == 4)
        {
            aux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(aux != NULL)
            {
               allOk= ll_add(pArrayListEmployee,aux);
            }
            free(aux);
        }
        else
        {
            break;
        }
    }

    return allOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int allOk=0;
    Employee* auxEmployee;
    int count = 0;

    if(pFile!=NULL)
    {
        do
        {
            //pido memoria para el buffe del empleado a leer
            auxEmployee=employee_new();
            if(auxEmployee !=NULL)
            {
                // leo  el archivo
               count = fread(auxEmployee, sizeof(Employee), 1, pFile);
               if(count >0)
               {
                   // agrego la estructura a la lista
                allOk= ll_add(pArrayListEmployee,auxEmployee);
               }
               free(auxEmployee);
            }

        }
        while(!feof(pFile));
    }
    return allOk;
}
