#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
int main()
{
    int operando1 = NULL;
    int operando2 = NULL;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int operacionesRealizadas = 0;
    float resultadoDivision;
    int resultadoFactorialOp = 0;

    int opcion ;
    opcion = menu();
    do
    {
        switch(opcion)
        {
            case 1:
                operando1 = IngresoValidado(0);
                // si cambio algun operando, tengo que volver a realizar las operaciones
                operacionesRealizadas = 0;
                break;
            case 2:
                operando2 = IngresoValidado(1);
                // si cambio algun operando, tengo que volver a realizar las operaciones
                operacionesRealizadas = 0;
                break;
            case 3:
                if(validarOperandoosIngresado(operando1,operando2) )
                {
                    resultadoSuma = add(operando1, operando2);
                    resultadoResta = substract(operando1, operando2);
                    resultadoMultiplicacion = multiply(operando1, operando2);
                    resultadoDivision = divide(operando1, operando2);
                    resultadoFactorialOp = factorial(operando1);
                    operacionesRealizadas = 1;
                }
                break;
            case 4:
                if(validarOperandoosIngresado(operando1,operando2) )
                {
                    if(operacionesRealizadas)
                    {
                        printf("resultado suma entre %d, %d es: %d \n", operando1, operando2, resultadoSuma);
                        printf("resultado resta entre %d, %d es: %d \n", operando1, operando2, resultadoResta);
                        printf("resultado multiplicacón entre %d, %d es: %d \n", operando1, operando2, resultadoMultiplicacion);
                        printf("resultado division entre %d, %d es: %.2f \n", operando1, operando2, resultadoDivision);
                        printf("resultado factorial operando A %d es %d \n", operando1, resultadoFactorialOp);
                    }
                    else
                    {
                        printf("Primero debe realizar las operaciones \n");
                    }
                }
                break;
        }
        system("pause");
        system("cls");
        opcion = menu();
    }
    while(opcion != 5);
    return 0;

}
