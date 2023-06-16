#ifndef TP7_CONJUNTOS_H
#define TP7_CONJUNTOS_H

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

#include "tipo_elemento.h"
#include "listas.h"
#include "arbol-avl.h"
#include "conjuntos.h"

void vaciar_buffer();

void pausa();

void limpiar_pantalla();

Conjunto cargarConjunto();

Conjunto cargarConjuntoPositivos();

Conjunto p2_interseccion(Conjunto conjunto_a, Conjunto conjunto_b);

Conjunto p2_union(Conjunto A, Conjunto B);

Conjunto p2_diferencia(Conjunto A, Conjunto B);

Conjunto p3_union(Lista lista_c);

Conjunto p3_interseccion(Lista lista_c);

Conjunto diferencia_simetrica(Conjunto A, Conjunto B);

bool esSubconjunto(Conjunto A, Conjunto B);

bool esSubConjunto4(Conjunto A, Conjunto B);

bool esSubconjuntoParcial(Conjunto A, Conjunto B);

int transitividad(Conjunto A, Conjunto B, Conjunto C);

bool conjuntos_iguales(Conjunto a, Conjunto b);

#endif // Conjuntos