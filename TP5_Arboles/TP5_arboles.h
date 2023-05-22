#ifndef TP5_ARBOLES_H
#define TP5_ARBOLES_H

#include <stdbool.h>
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "listas.h"

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

void mostrar_pre_orden(NodoArbol N);

void mostrar_in_orden(NodoArbol N);

void mostrar_post_orden(NodoArbol N);

void hojas(ArbolBinario A);

Lista nodos_interiores(ArbolBinario A);

#endif // TP5_ARBOLES_H