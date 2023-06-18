#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
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
        vaciar_buffer();
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
                vaciar_buffer();
                validador = scanf("%d", &claveIngresada);
                pertenece = cto_pertenece(A, claveIngresada);
            }
            X = te_crear(claveIngresada);
            cto_agregar(A, X);
        }
        printf(ANSI_bGREEN "El conjunto fue cargado con éxito \n");
        cto_mostrar(A);
    }
    else
        printf(ANSI_bGREEN "El conjunto fue creado vacío \n");
    return A;
}

Conjunto cargarConjuntoPositivos()
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
        vaciar_buffer();
        validador = scanf("%i", &tamano);
    }
    if (tamano > 0)
    {
        for (int i = 1; i <= tamano; i++)
        {
            printf(ANSI_bBLUE "Ingrese el elemento #%d del conjunto: " ANSI_YELLOW, i);
            validador = scanf("%d", &claveIngresada);
            pertenece = cto_pertenece(A, claveIngresada);
            while ((validador != 1) || (claveIngresada < 0) || (claveIngresada >= 10000) ||
                   pertenece)
            {
                printf(ANSI_RED "Entrada invalida. Ingresar solo numero naturales (> 0)\n" ANSI_RESET);
                printf(ANSI_bBLUE "Ingrese el elemento #%d del conjunto: " ANSI_YELLOW, i);
                vaciar_buffer();
                validador = scanf("%d", &claveIngresada);
                pertenece = cto_pertenece(A, claveIngresada);
            }
            X = te_crear(claveIngresada);
            cto_agregar(A, X);
        }
        printf(ANSI_bGREEN "El conjunto fue cargado con éxito \n");
        cto_mostrar(A);
    }
    else
        printf(ANSI_bGREEN "El conjunto fue creado vacío \n");
    return A;
}

// ------------------------------------ PUNTO 2 ------------------------------------------

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
            cto_agregar(res, X);
        }
    }
    return res;
}

Conjunto p2_union(Conjunto A, Conjunto B)
{
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(A, i);
        cto_agregar(res, X);
    }

    card = cto_cantidad_elementos(B);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(B, i);
        if (!cto_pertenece(res, X->clave))
            cto_agregar(res, X);
    }

    return res;
}

Conjunto p2_diferencia(Conjunto A, Conjunto B)
{
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    for (int i = 1; i <= card; i++)
    {
        X = cto_recuperar(A, i);
        if (!cto_pertenece(B, X->clave))
        {
            cto_agregar(res, X);
        }
    }
    return res;
}

// ------------------------------------ PUNTO 5 ------------------------------------------

Conjunto diferencia_simetrica(Conjunto A, Conjunto B)
{
    Conjunto res = cto_crear();
    TipoElemento X = te_crear(0);
    Conjunto difA = cto_diferencia(A, B);
    Conjunto difB = cto_diferencia(B, A);
    res = cto_union(difA, difB);
    free(difA);
    free(difB);
    return res;
}

// ------------------------------------ PUNTO 3 ------------------------------------------

Conjunto p3_union(Lista lista_c)
{
    Conjunto rta = cto_crear();
    Conjunto A = cto_crear();
    TipoElemento x = te_crear(0);
    TipoElemento c = te_crear(0);
    int card;
    int largo = l_longitud(lista_c);

    for (int i = 0; i < largo; i++)
    {
        x = l_recuperar(lista_c, i + 1);
        card = cto_cantidad_elementos((Conjunto)x->valor);
        for (int j = 1; j <= card; j++)
        {
            c = cto_recuperar(x->valor, j);
            if (!cto_pertenece(rta, c->clave))
            {
                cto_agregar(rta, c);
            }
        }
    }
    return rta;
}

Conjunto p3_interseccion(Lista lista_c)
{
    Conjunto rta = cto_crear();
    TipoElemento x = te_crear(0);
    TipoElemento c = te_crear(0);
    TipoElemento c2 = te_crear(0);
    int card, card2, existe = 0;
    int largo = l_longitud(lista_c);

    c = l_recuperar(lista_c, 1);
    card = cto_cantidad_elementos((Conjunto)c->valor);
    for (int i = 1; i <= card; i++)
    {
        x = cto_recuperar(c->valor, i);
        for (int j = largo; j > 1; j--)
        {
            c2 = l_recuperar(lista_c, j);
            if (cto_pertenece(c2->valor, x->clave))
            {
                existe++;
            }
        }
        if (existe == (largo - 1))
        {
            cto_agregar(rta, x);
        }
        existe = 0;
    }
    return rta;
}

// ------------------------------------ PUNTO 6 y 7 ------------------------------------------
/**/
bool esSubconjunto(Conjunto A, Conjunto B)
{
    bool res = true;
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    int i = 1;
    while (i <= card && res)
    {
        X = cto_recuperar(A, i);
        if (!cto_pertenece(B, X->clave))
            res = false;
        i++;
    }
    return res;
}

// ------------------------------------ PUNTO 7 ------------------------------------------

bool esSubconjuntoParcial(Conjunto A, Conjunto B)
{
    bool res = true;
    TipoElemento X = te_crear(0);
    int card = cto_cantidad_elementos(A);
    int elementos = 0;
    int i = 1;
    while (i <= card)
    {
        X = cto_recuperar(A, i);
        if (cto_pertenece(B, X->clave))
            elementos++;
        i++;
    }
    int cant = ceil((float)card / 2);
    if (elementos < cant)
        res = false;
    return res;
}
// ------------------------------------ PUNTO 4 ------------------------------------------

bool esSubConjunto4(Conjunto A, Conjunto B)
{
    TipoElemento x = te_crear(0);
    int cantidad = cto_cantidad_elementos(A);
    for (int i = 1; i <= cantidad; i++)
    {
        x = cto_recuperar(A, i);
        if (!cto_pertenece(B, x->clave))
        {
            return false;
        }
    }
    return true;
}

int transitividad(Conjunto A, Conjunto B, Conjunto C)
{
    bool ab, bc;
    if (ab = esSubConjunto4(A, B))
    {
        if (bc = esSubConjunto4(B, C))
        {
            return 0; // 0 = A es subconjunto de C
        }
        else
        {
            return 1; // 1 = A es subconjunto de B pero B no es subconjunto de C
        }
    }
    else
    {
        return 2; // 2 = A no es subconjunto de B
    }
}

// ------------------------------------ PUNTO 8 ------------------------------------------

bool conjuntos_iguales(Conjunto a, Conjunto b)
{
    TipoElemento x = te_crear(0);
    int cantidad = cto_cantidad_elementos(a);

    for (int i = 1; i <= cantidad; i++)
    {
        x = cto_recuperar(a, i);
        if (!cto_pertenece(b, x->clave))
        {
            return false;
        }
    }
    return true;
}