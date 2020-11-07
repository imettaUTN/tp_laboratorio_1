#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Common.h"
#define TRUE 1
#define FALSE 0


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    option =common_getMenu("1 CARGA EMPLEADOS ARH TXT\n2 CARGA EMPLEADOS ARH BIN:\n3 ALTA EMPLEADO\n4 MODIFICA EMPLADO\n5 BAJA EMPLEADO\n6 LISTAR EMPLEADOS\n7 ORDENAR EMPLEADOS\n8 GRABAR EMPLEADOS ARH TXT\n9 GRABAR EMPLEADOS ARH BIN \n10SALIR","Opcion invalida. Reingrese",1,10,3);
    char * pathTxt = "C:\\Programacion1\\TP3\\data.csv";
    char * pathBin = "C:\\Programacion1\\TP3\\data.csv";
    int exit = FALSE;
    do
    {
        switch(option)
        {
        case 1:
            controller_loadFromText(pathTxt,listaEmpleados);
            break;
        case 2:
            controller_loadFromBinary(pathBin,listaEmpleados);
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsText(pathTxt,listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary(pathBin,listaEmpleados);
            break;
        case 10:
            printf("El sistema se va a cerrar\n");
            exit = TRUE;
            break;
        }

        if(!exit)
        {
            printf("¿Desea continuar operador? YES 1 NOT 0\n");
            scanf("%d",&exit);
            exit = !exit;
            system("cls");
        }
        if(!exit)
        {
            option =common_getMenu("1 CARGA EMPLEADOS ARH TXT\n2 CARGA EMPLEADOS ARH BIN:\n3 ALTA EMPLEADO\n4 MODIFICA EMPLADO\n5 BAJA EMPLEADO\n6 LISTAR EMPLEADOS\n7 ORDENAR EMPLEADOS\n8 GRABAR EMPLEADOS ARH TXT\n9 GRABAR EMPLEADOS ARH BIN \n10SALIR","Opcion invalida. Reingrese",1,10,3);
            system("pause");
        }

    }
    while(!exit && option != 10 );
    // libero la memoria
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
