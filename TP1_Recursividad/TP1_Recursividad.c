#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP1_Recursividad.h"

// PUNTO 1 - PALINDROMO
bool palindromo(char *cadena, int principio, int final)
{
    bool respuesta;
    if ((principio == final) || (final < principio))
    {
        respuesta = true;
    }
    else
    {
        if (cadena[principio] == cadena[final])
        {
            respuesta = palindromo(cadena, principio + 1, final - 1);
        }
        else
        {
            respuesta = false;
        }
    }
    return respuesta;
}

// PUNTO 2 - PRODUCTO
long long producto(int m, int n)
{
    long long resultado;
    bool negativo = false;
    /*Si n es negativo, lo convierte a positivo para que funcione la recursion,
     pero el boolean lo recuerda para mas adelante */
    if (n < 0)
    {
        n = n * (-1);
        negativo = true;
    }
    /*Si n es 0 (caso base) devuelve 0 y si es mayor, vuelve
    a llamar a la función con n-1 (tiende al caso base)*/
    if (n == 0)
    {
        resultado = 0;
    }
    else
    {
        resultado = m + producto(m, n - 1);
    }
    /*si n era negativo al entrar a la función, ahora multiplica al resultado
    por -1*/
    if (negativo == true)
    {
        resultado = resultado * (-1);
    }
    return resultado;
}

// PUNTO 3 - FIBONACCI
long long terminoSerieFibonacci(int num)
{
    long long resultado;
    if (num <= 1)
        resultado = num;
    else
        resultado = terminoSerieFibonacci(num - 1) + terminoSerieFibonacci(num - 2);
    return resultado;
}

// PUNTO 4 - DIVISION
float division(int m, int n, int limite_Decimal)
{
    /*esta función se encarga de restar en cada sucesión el valor del dividendo(m)
    con el del divisor(n) hasta que el resto sea menor a n  y
    realizara restas sucesivas para los decimales de una manera similar a los enteros*/

    if (n < 0 && m < 0)
    {
        /*como ambos valores son negativos
        se convierten en positivo para el resultado final*/
        m = m * -1;
        n = n * -1;
    }
    else if (n < 0)
    {
        n = n * -1;
    }
    else if (m < 0)
    {
        m = m * -1;
    }

    float resto = m;
    float cociente = 0;
    /*una vez que el resto sea menor a n se divide el resto por el n
    para saber si el cociente(resultado) tiene valores decimales*/
    if (resto == 0)
    {
        cociente = resto;
        return cociente;
    }

    else if (resto < n && limite_Decimal != 0)
    {
        resto = resto * 10;
        if (resto < n)
        {
            /*en caso que el resto siga siendo menor a n,
            esta parte se encarga de solo mover un 0 a la derecha como valor decimal*/
            cociente = division(resto, n, limite_Decimal);
            cociente = cociente * 0.1;
            return cociente;
        }
        else
        {
            cociente = division(resto - n, n, limite_Decimal - 1);
            cociente++;
            cociente = cociente * 0.1; /*esta parte se encarga de desplazar a la parte decimal
            los valores correspondientes a la misma*/
            return cociente;
        }
    }
    else if (limite_Decimal == 0)
    {
        /* si el numero decimal es muy grande el limite_Decimal
        se va a encargar de cortar la función con 4 dígitos decimales*/
        return cociente;
    }
    else
    {

        cociente = division(m - n, n, limite_Decimal);

        /*luego se usa el cociente como contador una vez retornada la sucesión
        para obtener el resultado según la cantidad de sucesiones*/
        cociente++;
        return cociente;
    }
}

// PUNTO 5 - PUNTOS MILES
void agregarSeparadorMiles(char *cadena, int longitud, int contador)
{
    if (longitud == 0)
    {
        printf("%c", cadena[longitud]);
    }
    else
    {
        if (contador == 1)
        {
            agregarSeparadorMiles(cadena, longitud - 1, 3);
            printf(".");
            printf("%c", cadena[longitud]);
        }
        else
        {
            agregarSeparadorMiles(cadena, longitud - 1, contador - 1);
            printf("%c", cadena[longitud]);
        }
    }
}

// PUNTO 6 - CHINOS
/* char *chinos(int n){
    char* cadena;
    char *cadenaAnt;
    int longitud;

    if (n==1){
        cadena = (char*) malloc(6 * sizeof(char));
        strcpy(cadena, "(-.-)");
    } else {
        cadenaAnt = chinos(n - 1);
        longitud = strlen(cadenaAnt) + 7;
        cadena = (char*) malloc(sizeof(char) * longitud);
        sprintf(cadena, "(-.%s.-)", cadenaAnt);
    }

    return cadena;
} */

void chinos(int n)
{
    int color = rand() % 6 + 31; // generar un código de color aleatorio entre 31 y 37
    if (n == 1)
    {
        printf("\033[%dm%s\033[0m", color, "(-.-)");
    }
    else
    {
        printf("\033[%dm%s", color, "(-.");
        chinos(n - 1);
        printf("\033[%dm%s", color, ".-)");
    }
}

// PUNTO 7
void ondaDigital(char *onda, int i)
{

    if ((i > 0) && (onda[i] != onda[i - 1]))
    {
        printf("│");
    }

    if ((onda[i]) == 'h')
    {
        printf("¯");
    }
    else
    {
        printf("_");
    }

    if (i < (strlen(onda) - 2))
    {
        ondaDigital(onda, i + 1);
    }
}

// PUNTO 8 - SUBCONJUNTO
char *buscaSumaSubconjunto(int tamano, int nivel, int suma, char *salidaparcial, int *ent, int *subset, int subsetSize)
{
    int i;
    char *salida = (char *)malloc(sizeof(char) * 1000);
    strcpy(salida, "");

    if (tamano == nivel)
    {
        if (suma == 0)
        {
            strcat(salida, "{");
            for (i = 0; i < subsetSize; i++)
            {
                char temp[10];
                sprintf(temp, "%d ", subset[i]);
                strcat(salida, temp);
            }
            strcat(salida, "}\n");
            strcpy(salidaparcial, salida);
        }
        return salidaparcial;
    }

    strcpy(salida, buscaSumaSubconjunto(tamano, nivel + 1, suma, salidaparcial, ent, subset, subsetSize));
    salidaparcial[0] = '\0';
    subset[subsetSize] = ent[nivel];
    subsetSize++;
    strcat(salida, buscaSumaSubconjunto(tamano, nivel + 1, suma - ent[nivel], salidaparcial, ent, subset, subsetSize));
    return salida;
}

// PUNTO 9 - DIVISIBLE POR 7
bool divisiblePor7(int n)
{
    bool condicion;
    int cifra_derecha;
    int numero_izquierda;
    if (n < 0)
    {
        n = n * -1;
    }

    if (n < 70)
    {
        if (n % 7 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        cifra_derecha = n % 10;
        numero_izquierda = n / 10;
        cifra_derecha = cifra_derecha * 2;
        numero_izquierda = numero_izquierda - cifra_derecha;
        condicion = divisiblePor7(numero_izquierda);
        return condicion;
    }
}

// PUNTO 10 - BOMBA
void explosion(int n, int b, int *arreglo, int i)
{
    int n1, n2;
    if (n <= b)
    {
        printf("%d ", n);
        // arreglo[i] = n;
        // i++;
    }
    else
    {
        n1 = n / b;
        n2 = n - (n / b);

        if (n1 > b)
        {
            explosion(n1, b, arreglo, i);
        }
        else
        {
            printf("%d ", n1);
            // arreglo[i] = n1;
            // i++;
        }

        if (n2 > b)
        {
            explosion(n2, b, arreglo, i);
        }
        else
        {
            printf("%d ", n2);
            // arreglo[i] = n2;
            // i++;
        }
    }
}