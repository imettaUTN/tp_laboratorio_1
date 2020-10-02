#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menus.h"
#define TRUE 1
#define FALSE 0




int menu(int hasValueOp1)
{
    int opcion  = 0;
    int first = TRUE ;
    do
    {
        if(!first)
        {
            printf("Opcion invalida. Reingrese la operacion a realizar :\n");
        }
        else
        {
            printf("Ingrese la operacion a realizar :\n");

        }
        first = FALSE;
        printf("");
        scanf("%d", &opcion);

        if(opcion > 1 && opcion < 5 && !hasValueOp1)
        {
            printf("First must add a new employee \n");
            // le pongo -1 para que vuelva a iterar
            opcion = -1;
        }
        system("cls");
    }
    while(opcion < 0 || opcion > 5);
    return opcion;
}

int subMenuInformar()
{
    int opcion = 0 ;
    int first = TRUE;
    do
    {
        if(!first)
        {
            printf("Input error value. :\n");

        }
        else
        {
            printf("");

        }
        first = FALSE;

        scanf("%d", &opcion);
    }
    while(opcion < 1 || opcion > 2);

    return opcion;
}

int subMenuOrder()
{
    int opcion = 0 ;
    int first = TRUE;
    do
    {
        if(!first)
        {
            printf("Input error value. :\n");

        }
        else
        {
            printf("Enter the order to list the employees:\n");
            printf("0. Down\n");
            printf("1. UP\n");
        }
        first = FALSE;
        scanf("%d", &opcion);
    }
    while(opcion < 0 || opcion > 1);

    return opcion;
}
