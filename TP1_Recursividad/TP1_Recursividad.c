#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP1_Recursividad.h"


// PUNTO 1 - PALINDROMO
bool palindromo(char *cadena, int principio, int final){
    bool respuesta;
    if ((principio == final)  || (final < principio)){
        respuesta = true;
    } else {
        if (cadena[principio] == cadena[final]){
            respuesta = palindromo(cadena, principio+1, final-1);
        } else{
            respuesta = false;
        }
    }
    return respuesta;
}

// PUNTO 2 - PRODUCTO
long long producto(int m, int n){
    long long resultado;
    bool negativo = false;

    /*Si n es negativo, lo convierte a positivo para que funcione la recursion,
     pero el boolean lo recuerda para mas adelante */

    if (n < 0){
        n = n * (-1);
        negativo = true;
    }

    /*Si n es 0 (caso base) devuelve 0 y si es mayor, vuelve
    a llamar a la funcion con n-1 (tiede al caso base)*/
    if (n==0){
        resultado = 0;
    }
    else{
        resultado = m + producto(m, n-1);
    }

    /*si n era negativo al entrar a la funcion, ahora multiplica al resultado 
    por -1*/
    if (negativo == true){
        resultado = resultado * (-1);
    }

    
    return resultado;
}

// PUNTO 3 - FIBONACCI
long long terminoSerieFibonacci(int num){
    long long resultado;
    if (num <= 1) resultado = num;
    else resultado = terminoSerieFibonacci(num-1) + terminoSerieFibonacci(num-2);  
    return resultado;
}

// PUNTO 6 - CHINOS
char *chinos(int n){
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

// PUNTO 10 - BOMBA
void explosion(int n, int b, int* arreglo, int i){
    int n1,n2;

    n1 = n/b;
    n2 = n-(n/b);

    if (n1 > b) {
        explosion(n1,b, arreglo,i);
    } else {
        arreglo[i] = n1;
        i++;
    }

    if (n2 > b) {
        explosion(n2,b,arreglo,i);
    } else {
        arreglo [i] = n2;
        i++;
    }
}