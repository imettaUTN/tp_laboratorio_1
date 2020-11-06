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
    char buffer[4][100];
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
             ll_add(pArrayListEmployee,aux);
        }
        else
        {
            break;
        }
    }
    allOk = 1;

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
    int allOk = 0;

    if(pFile == NULL && pArrayListEmployee == NULL  )
    {
        printf("No se puede abrir el archivo \n");
        return allOk;
    }

    while(!feof(pFile))
    {
        Employee * aux ;
        fread(&aux,sizeof(Employee),1,pFile);
        ll_add(pArrayListEmployee,aux);
    }
    allOk = 1;
    return allOk;
}
