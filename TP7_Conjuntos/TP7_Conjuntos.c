#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "arbol-avl.h"
#include "TP7_Conjuntos.h"
#include "conjuntos.h"

/// @brief Vacía el buffer de entrada.
void vaciar_buffer()
{
    char nada[200];
    fgets(nada, 200, stdin);
}

/// @brief Frena la ejecución del código esperando el ingreso de un carácter.
void pausa()
{
    printf(ANSI_bYELLOW "\n\nPresione una tecla para continuar...." ANSI_RESET);
    getchar();
}

/// @brief Secuencia de escape ANSI que se utiliza para limpiar la pantalla de la terminal y posicionar el cursor en la esquina superior izquierda.
void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

Conjunto cargarConjunto()
{
    int tamano, validador, claveIngresada;
    TipoElemento X;
    bool pertenece;
    Conjunto A = cto_crear();
    printf(ANSI_BLUE "Ingrese la cardinalidad del conjunto: " ANSI_YELLOW);
    validador = scanf("%i", &tamano);
    while ((validador != 1) || (tamano < 0) || (tamano > 99))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese la cardinalidad del conjunto: " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &tamano);
    }
    if (tamano > 0)
    {
        for (int i = 1; i <= tamano; i++)
        {
            printf(ANSI_bBLUE "Ingrese el elemento #%d del conjunto: " ANSI_YELLOW, i);
            validador = scanf("%d", &claveIngresada);
            pertenece = cto_pertenece(A, claveIngresada);
            while ((validador != 1) || (claveIngresada <= -10000) || (claveIngresada >= 10000) ||
                   pertenece)
            {
                printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
                printf(ANSI_bBLUE "Ingrese el elemento #%d del conjunto: " ANSI_YELLOW, i);
                while (getchar() != '\n')
                    ;
                validador = scanf("%d", &claveIngresada);
                pertenece = cto_pertenece(A, claveIngresada);
            }
            X = te_crear(claveIngresada);
            cto_agregar(A,X);
        }
        printf(ANSI_bGREEN "El conjunto fue cargado con éxito \n");
        cto_mostrar(A);
    }
    else
        printf(ANSI_bGREEN "El conjunto fue creado vacío \n");
    return A;
}

Conjunto p2_interseccion(Conjunto A, Conjunto B)
{
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(A, i);
        if (cto_pertenece(B, X->clave))
        {
            cto_agregar(res,X);
        }
    }
    return res;
}

Conjunto p2_union(Conjunto A, Conjunto B){
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(A, i);
        cto_agregar(res,X);
    }

    card = cto_cantidad_elementos(B);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(B, i);
        if (!cto_pertenece(res, X->clave))
            cto_agregar(res,X);
    }

    return res;
}

Conjunto p2_diferencia(Conjunto A, Conjunto B){
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(A,i);
        if (!cto_pertenece(B, X->clave))
        {
            cto_agregar(res,X);
        }
    }
    card = cto_cantidad_elementos(B);
        for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(B,i);
        if (!cto_pertenece(A, X->clave))
        {
            cto_agregar(res,X);
        }
    }
    return res;
}