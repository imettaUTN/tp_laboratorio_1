#include <stdio.h>

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

int factorial( int numero)
{
    // Calcular el factorial del numero solicitado
    int resultado = 1;
    if(numero == 0 || numero == 1 )
    {
        return 1;
    }

    while(numero > 1)
    {
       resultado *= numero;
       numero--;
    }
    return resultado;
}

int menu(void)
{
    int opcion  = 0;

    do
    {
        printf("Ingrese la operacion a realizar :\n");
        printf("1. Ingresar 1er operando (A=x)\n");
        printf("2. Ingresar 2do operando (B=y)\n");
        printf("3. Calcular todas las operaciones\n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n");
        printf(" d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!) \n");
        printf("4. Informar resultados :\n");
        printf("5. Salir\n");
        scanf("%d", &opcion);
    }
    while(opcion < 0 || opcion > 5);

    return opcion;

}
int IngresoValidado(int validaZero)
{
    int operando = NULL;
    printf("Ingrese el operando \n");
    scanf("%d", &operando);
    int valido = 1;

    do
    {
        if(operando < 0)
        {
            printf("El operando tiene que ser positivo \n");
            valido = 0;
        }

        if(!validaZero)
        {
            printf("%d",operando);
            while(operando == 0)
            {
                printf("El operando no puede ser 0\n");
                printf("Ingrese el operando \n");
                scanf("%d", &operando);
                valido = 0;
            }
        }
    }
    while(!valido);
    return operando;

}
int validarOperandoosIngresado(int op1,int op2)
{
    if(op1 != NULL && op2 != NULL)
    {
       return 1;
    }
    printf("Debe ingresar los operandos \n");
    return 1;

}
