#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
int main()
{
    int operandA = 0;
    int operandB = 0;
    int resultsAdd;
    int resultsSubtract;
    int resultsMultiply;
    float resultsDevide ;
    long long int resultFactorial;
    int operationsMadeFlag = 0;
    int hasValueOperandA = 0;
    int hasValueOperandB = 0;
    int opcion ;
    opcion = menu(hasValueOperandA,hasValueOperandB,operandA, operandB);
    do
    {
        switch(opcion)
        {
        case 1:
            printf("Ingrese el operando A\n");
            scanf("%d", &operandA);
            // si cambio algun operando, tengo que volver a realizar las operaciones
            operationsMadeFlag = 0;
            hasValueOperandA = 1;
            break;
        case 2:
            printf("Ingrese el operando B \n");
            scanf("%d", &operandB);
            hasValueOperandB = 1;
            // si cambio algun operando, tengo que volver a realizar las operaciones
            operationsMadeFlag = 0;
            break;
        case 3:
            if( hasValueOperandA && hasValueOperandB )
            {
                resultsAdd = add(operandA, operandB);
                resultsSubtract = substract(operandA, operandB);
                resultsMultiply = multiply(operandA, operandB);
                if( operandB != 0)
                {
                resultsDevide = divide(operandA, operandB);
                }
                else
                {
                    printf("No se puede divir por 0 \n");
                }
                if( operandA >= 0)
                {
                    resultFactorial = factorial(operandA);
                }
                else
                {
                    printf("El operado tiene que ser positivo para hacer el factorial \n");
                }
                operationsMadeFlag = 1;
                printf("Operaciones realizadas \n");
            }
            else
            {
                printf("Debe ingresar los operandos A y B \n");
            }
            break;

        case 4:
            if( hasValueOperandA && hasValueOperandB  )
            {
                if(!operationsMadeFlag)
                {
                    printf("Primero deber realizar las operaciones\n");
                    break;
                }
                printf("resultado suma entre %d, %d es: %d \n", operandA, operandB, resultsAdd);
                printf("resultado resta entre %d, %d es: %d \n", operandA, operandB, resultsSubtract);
                printf("resultado multiplicacón entre %d, %d es: %d \n", operandA, operandB, resultsMultiply);
                if( operandB != 0 )
                {
                    printf("resultado division entre %d, %d es: %.2f \n", operandA, operandB, resultsDevide);
                }
                if(operandA >= 0)
                {
                    printf("resultado factorial operando A %d es %d \n", operandA, resultFactorial);
                }
            }
            else
            {
                printf("Debe ingresar los operandos A y B \n");
            }
            break;
        }
        system("pause");
        system("cls");
        // tengo que usar banderas, xq nose cuando sale del scanf del switch las  variable de los operados pierde el valor
        opcion = menu(hasValueOperandA,hasValueOperandB,operandA, operandB);
    }
    while( opcion != 5);
    return 0;

}
