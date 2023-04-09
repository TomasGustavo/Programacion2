#include <stdio.h>
#include <stdbool.h>
#include "TP0_Repaso.h"

bool digitoEnNumero(long n, short d)
{
    while (n != 0)
    {
        if (n % 10 == d)
        {
            return true;
        }
        n /= 10;
    }
    return false;
}

void main()
{
    long numero;
    short digito;
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);
    printf("Ingrese un digito (0-9): ");
    scanf("%hd", &digito);
    if (digitoEnNumero(numero, digito) == true)
    {
        printf("Verdadero");
    }
    else
    {
        printf("Falso");
    }
};