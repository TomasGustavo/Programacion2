#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TP5_arboles.h"
#include "listas.h"
#include "tipo_elemento.h"

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

// ----------------------------------------------------------------------------------------------------

/// @brief Función que solicita el ingreso de un número entero o de "." como representación de nulo.
/// @param n Retorna el valor entero
/// @return Retorna verdadero si se ingresa un entero, o falso en caso de nulo.
bool ingresoEntero(int *n)
{
    char s[10];
    bool resultado = true;
    *n = 0;
    printf(ANSI_bMAGENTA "Ingrese una clave numérica o '.' para nulo: " ANSI_YELLOW);
    scanf("%s", s);
    if (s[0] == '.')
    {
        resultado = false;
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if ((s[i] >= '0') && (s[i] <= '9'))
            {
                *n = *n * 10 + (s[i] - 48);
            }
        }
    }
    return resultado;
}

/// @brief Función que carga un (sub)árbol en preorden a partir del nodo padre N recursivamente
/// @param A Arbol binario donde se cargara el nuevo nodo
/// @param N Nodo a cargar
/// @param sa El entero 'sa' indica cómo se enlazará el nuevo valor:
/// • 0: El nuevo nodo (con su TE) se asignará a la raíz de A. En este caso N no es utilizado.
/// • -1: El nuevo nodo (con su TE) se enlazará como hijo izquierdo de N.
/// • 1: El nuevo nodo (con su TE) se enlazará como hijo derecho de N.
void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa)
{
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A))
    {
        b = ingresoEntero(&n);
        if (b)
        {
            X = te_crear(n);

            if (sa == -1)
                N1 = a_conectar_hi(A, N, X);
            else if (sa == 1)
                N1 = a_conectar_hd(A, N, X);
            else
                N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }
    }
}

/// @brief Función que recibe el árbol a ser cargado y llama a la función recursiva que realiza la carga nodo por nodo
/// @param A Arbol binario donde se cargaran los nodos
void cargar_arbol_binario(ArbolBinario A)
{
    Cargar_SubArbol(A, NULL, 0);
}

/// @brief Muestra el arbol "pre orden" a partir de un nodo (de ahi hacia abajo)
/// @param N Nodo del arbol
void mostrar_pre_orden(NodoArbol N)
{
    TipoElemento x;
    if (N == NULL)
    {
        printf(".");
    }
    else
    {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        mostrar_pre_orden(n_hijoizquierdo(N));
        mostrar_pre_orden(n_hijoderecho(N));
    }
}

/// @brief Muestra el arbol "in orden" a partir de un nodo (de ahi hacia abajo)
/// @param N Nodo del arbol
void mostrar_in_orden(NodoArbol N)
{
    TipoElemento x;
    if (N == NULL)
    {
        printf(".");
    }
    else
    {
        mostrar_in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        mostrar_in_orden(n_hijoderecho(N));
    }
}

/// @brief Muestra el arbol "post orden" a partir de un nodo (de ahi hacia abajo)
/// @param N Nodo del arbol
void mostrar_post_orden(NodoArbol N)
{
    TipoElemento x;
    if (N == NULL)
    {
        printf(".");
    }
    else
    {
        mostrar_post_orden(n_hijoizquierdo(N));
        mostrar_post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
    }
}

// ----------------------------------------------------------------------------------------------------

/// @brief Recorre el arbol binario en busca de los nodos hojas
/// @param Q Nodo del arbol (recibe la raíz de arbol)
void buscar_hojas(NodoArbol Q)
{
    TipoElemento x;
    if (!a_es_rama_nula(Q))
    {
        if (a_es_rama_nula(n_hijoizquierdo(Q)) && a_es_rama_nula(n_hijoderecho(Q)))
        {
            x = n_recuperar(Q);
            printf("%d ", x->clave);
        }
        buscar_hojas(n_hijoizquierdo(Q));
        buscar_hojas(n_hijoderecho(Q));
    }
}

/// @brief Muestra los nodos hojas de un arbol
/// @param A Arbol binario cargado de enteros
void hojas(ArbolBinario A)
{
    printf(ANSI_GREEN "Las hojas son: ");
    buscar_hojas(a_raiz(A));
}