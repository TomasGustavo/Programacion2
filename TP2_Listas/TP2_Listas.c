#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP2_Listas.h"
#include "tipo_elemento.h"
#include "listas.h"

Lista cargarListaClaves(){
    int tamano, validador, claveIngresada;
    TipoElemento X;
    Lista L;

    L = l_crear();
    printf("Ingrese la cantidad de elementos de la lista: \n");
    validador = scanf("%i", &tamano);

    while ((validador != 1) || (tamano < 0) || (tamano > 99))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese el tamaño del conjunto [1-99] (se truncara si coloca decimales): " ANSI_YELLOW);
        while (getchar() != '\n');
        validador = scanf("%i", &tamano);
    }

    for (int i = 1; i <= tamano; i++)
    {
        printf(ANSI_bBLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
        validador = scanf("%d", &claveIngresada);
        while ((validador != 1) || (claveIngresada <= -10000) || (claveIngresada >= 10000))
        {
            printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
            printf(ANSI_bBLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
            while (getchar() != '\n');
            validador = scanf("%d", &claveIngresada);
        }
        X = te_crear(claveIngresada);
        l_agregar(L,X);
    }
    printf(ANSI_bGREEN "La lista fue cargada con exito \n");
    return L;
}


int menor (Lista lista, int * posicion){
    TipoElemento x, menor;
    int posActual = 1;
    Iterador ite = iterador(lista);
    menor = siguiente(ite);
    posActual++;
    while (hay_siguiente(ite)){
        x = siguiente(ite);
        if (x->clave < menor->clave){
            menor = x;
            *posicion = posActual;
        }
        posActual++;
    }

    return menor->clave;
}

int mayor (Lista lista, int * repeticiones) {
    TipoElemento x, mayor;
    Iterador ite = iterador(lista);
    int cantidad = 1;
    mayor = siguiente(ite);

    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        if (x->clave > mayor->clave){
            mayor = x;
            cantidad = 1;
        } else if (x->clave == mayor->clave){
            cantidad++;
        }
    }

    *repeticiones = cantidad;
    return mayor->clave;
    
}