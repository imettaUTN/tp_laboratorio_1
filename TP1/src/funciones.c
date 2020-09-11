#include <stdio.h>
#include <stddef.h>

int add(int numero1, int numero2)
{
    return numero1 +  numero2;
}

int substract(int numero1, int numero2)
{
    return numero1 -  numero2;
}

int multiply(int numero1, int numero2)
{
    return numero1 * numero2;
}

float divide(int numero1, int numero2)
{
   return numero1  / numero2;
}


long long int factorial( int numero)
{
    // Calcular el factorial del numero solicitado
    int resultado = 1;
    if(numero == 0 || numero == 1 )
    {
        return 1;
    }
    if (numero >= 0)
    {
       resultado *= factorial(--numero);
    }
    return resultado;
}

int menu(int hasValueOpA, int hasValueOpB, int opA , int opB)
{
    int opcion  = 0;
    do
    {   printf("Ingrese la operacion a realizar :\n");
        if(hasValueOpA)
        {
             printf("1. Ingresar 1er operando (A=%d)\n", opA);
        }
        else
        {
             printf("1. Ingresar 1er operando (A=x)\n");
        }

        if(hasValueOpB)
        {
             printf("2. Ingresar 1er operando (B=%d)\n", opB);
        }
        else
        {
             printf("2. Ingresar 1er operando (B=y)\n");
        }
        printf("3. Calcular todas las operaciones\n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n");
        printf(" d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!) \n");
        printf("4. Informar resultados :\n");
        printf("5. Salir\n");
        scanf("%d", &opcion);
    }
    while(opcion < 0 || opcion > 5);

    return opcion;

}
