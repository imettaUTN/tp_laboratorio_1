#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Common.h"
#define TRUE 1
#define FALSE 0

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

//Returns the index of the first occurence of char c in char* string. If not found -1 is returned.
int common_get_index(char* string, char c)
{
    char *e = strchr(string, c);
    if (e == NULL)
    {
        return -1;
    }
    return (int)(e - string);
}

int common_getInt(int * pResultado, char * menssager)
{
    char buffer[5000];
    printf("%s\n",menssager);
    scanf("%s",buffer);
    if(common_esNumero(buffer))
    {
        if(common_get_index(buffer,'.') > 0)
        {
            printf("soy float");
            return FALSE;
        }
        *pResultado =atoi(buffer);
        return TRUE;
    }
    return FALSE;
}

int common_esNumero(char *s)
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

