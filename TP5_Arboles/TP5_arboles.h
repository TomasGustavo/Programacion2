#ifndef TP5_ARBOLES_H
#define TP5_ARBOLES_H

#include <stdbool.h>
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "listas.h"
#include "arbol-avl.h"
#include "arbol-binario-busqueda.h"

#define ANSI_RED "\e[31m"
#define ANSI_GREEN "\e[32m"
#define ANSI_YELLOW "\e[33m"
#define ANSI_BLUE "\e[34m"
#define ANSI_MAGENTA "\e[35m"
#define ANSI_CYAN "\e[36m"
#define ANSI_WHITE "\e[37m"
#define ANSI_bRED "\e[91m"
#define ANSI_bGREEN "\e[92m"
#define ANSI_bYELLOW "\e[93m"
#define ANSI_bBLUE "\e[94m"
#define ANSI_bMAGENTA "\e[95m"
#define ANSI_bCYAN "\e[96m"
#define ANSI_bWHITE "\e[97m"
#define ANSI_RESET "\e[0m"

void vaciar_buffer();

void pausa();

void limpiar_pantalla();

void cargar_arbol_binario(ArbolBinario A);

void cargar_arbol_binario_sin_repeticiones(ArbolBinario A);

void mostrar_pre_orden(NodoArbol N);

void mostrar_in_orden(NodoArbol N);

void mostrar_post_orden(NodoArbol N);

Lista hojas(ArbolBinario A);

Lista nodos_interiores(ArbolBinario A);

Lista ocurrencias(ArbolBinario A, int elemento);

void l_mostrarLista_valor(Lista L);

bool existe_nodo(ArbolBinario A, int clave);

NodoArbol nodo_padre(ArbolBinario A, int clave);

NodoArbol devolver_nodo(ArbolBinario A, int clave);

NodoArbol nodo_hermano(ArbolBinario A, int clave);

int nivel(ArbolBinario A, int clave);

int nodo_altura(NodoArbol Q);

int hojas_nario(ArbolBinario A);

bool arbol_similar(ArbolBinario A1, ArbolBinario A2);

NodoArbol padre_nario(ArbolBinario A, int clave);

Lista hermanos_nario(ArbolBinario A, int clave);

void comparar_equivalencia(NodoArbol Q1, NodoArbol Q2, int *equivalentes);

int arbol_equivalentes(ArbolBinario A1, ArbolBinario A2);

int nivel_nario(ArbolBinario A, int clave);

Lista nodos_internos_nario(ArbolBinario A);

Lista nodos_nivel(ArbolBinario A, int clave);

bool nivel_hojas_nario(ArbolBinario A);

Lista anchura_nario(ArbolBinario A);

int altura_nario(NodoArbol Q);

void cargar_repeticiones_AVL_BB(int repeticiones, int nodos, int min, int max);

void free_avl(NodoArbol Q);

void free_abb(NodoArbol Q);

ArbolAVL BToAVL(ArbolBinario AB);

int altura_avl(ArbolAVL A_AVL);

#endif // TP5_ARBOLES_H