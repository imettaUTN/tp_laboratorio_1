#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#define TRUE 1
#define FALSE 0

int salaryValidation(float salary)
{

    if(salary < 0)
    {
        return invalidSalary;
    }
    return TRUE;
}

int idValidation(int id)
{
    if(id < 0)
    {
        return invalidID;
    }
    return TRUE;
}


int numberValidation(int nro)
{
    while(!isdigit(nro))
    {
        printf("%s\n",isValidReturnedFunctionValue(isNotNumber));
        printf("%s\n",isValidReturnedFunctionValue(generalError));
        scanf("%d",&nro);
    }
    return nro;
}

int stringValidation(char * str)
{
    if(strlen(str) <= MAXLENGHSTRING)
    {

        int i = 0;
        while (str[i] != '\0')
        {
            // Si no es del alfabeto y no es un espacio regresamos false o 0
            if (!isalpha(str[i]) )// El espacio no cuenta como válido
            {
                return invalidStringFormat ;
            }
            i++;
        }
    }
    else
    {
        return invalidStringLengt;
    }
    // Si terminamos de recorrer la cadena y no encontramos errores, regresamos 1
    return TRUE;
}

int isValidReturnedFunctionValue(int value)
{
    char * menssager = "";
    switch(value)
    {
    case nullPointer:
        strcpy(menssager,"null pointer");
        break;
    case invalidLengt:
        strcpy(menssager,"invalid lenght");
        break;
    case employeeNotFound:
        strcpy(menssager,"employee not found");
        break;
    case InvalidIndex:
        strcpy(menssager,"invalid index");
        break;
    case generalError:
        strcpy(menssager,"error, retray");
        break;
    case invalidSalary:
        strcpy(menssager,"salary invalid");
        break;
    case invalidID:
        strcpy(menssager,"invalid id");
        break;
    case withOutFreeSpace:
        strcpy(menssager,"With out free space");
        break;
    case isNotNumber:
        strcpy(menssager,"The value is not a number");
        break;
    case almostMustBe2Emp:
        strcpy(menssager,"There must be at least 2 employees loaded to order");
        break;
    default:
        return TRUE;
        break;
    }
    printf("%s \n",menssager);
    return FALSE;
}

