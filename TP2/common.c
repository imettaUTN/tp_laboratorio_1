#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#define TRUE 1
#define FALSE 0


void validarOpcionesMenu(int *opcion, int hasValueOp1, char * msj)
{
    if(*opcion > 1 && *opcion < 5 && !hasValueOp1)
    {
        // le pongo -1 para que vuelva a iterar
        printf("%s\n",msj);
        *opcion = -1;
    }
}

int common_getMenu( char * menssager,char * errorMenssager,int min, int max, int reintentos)
{
    int buffer;
    if(menssager !=NULL && errorMenssager != NULL && min <= max && reintentos >= 0)
    {
        do
        {
            printf("%s \n",menssager);
            if(common_getInt(&buffer,"ingrese la operacion a realizar"))
            {

                if(buffer >= min && buffer <= max)
                {
                    return  buffer;
                    break;
                }

            }
            reintentos --;
        }
        while(reintentos >=0 );
    }
    return -1;
}

int common_getInt(int * pResultado, char * menssager)
{
    char buffer[5000];
    printf("%s\n",menssager);
    scanf("%s",buffer);
    if(esNumero(buffer))
    {
        if(get_index(buffer,'.') > 0)
        {
            printf("soy float");
            return FALSE;
        }
        *pResultado =atoi(buffer);
        return TRUE;
    }
    return FALSE;
}

int common_getFloat(float * pResultado, char * menssager)
{
    char buffer[5000];
    printf("%s\n",menssager);
    scanf("%s",buffer);
    if(esNumero(buffer))
    {
        *pResultado = atof(buffer);
        return TRUE;
    }
    return FALSE;
}

//Returns the index of the first occurence of char c in char* string. If not found -1 is returned.
int get_index(char* string, char c)
{
    char *e = strchr(string, c);
    if (e == NULL)
    {
        return -1;
    }
    return (int)(e - string);
}

int esNumero(char *s)
{
    int inicioAnalisis = 0;
    int cantPtos = FALSE;
    if(s[0] == '-')
    {
        inicioAnalisis =1;
    }
    for(int i = inicioAnalisis ; s[i] != '\0' ; i++)
    {
        if(s[i] == '.')
        {
            // si la cantidad de veces que aparece el pto es distinta de 0 tiro erro
            // si la posicion en la que aparece es la primera tiro error ( al menos tiene que haber un digito adelante)
            if(cantPtos != 0 || i == inicioAnalisis )
            {
                return FALSE;
                break;
            }
            cantPtos++;
            i++;
        }
        if(s[i] > '9' || s[i] < '0')
        {
            return FALSE;
            break;
        }
    }
    return TRUE;
}




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

