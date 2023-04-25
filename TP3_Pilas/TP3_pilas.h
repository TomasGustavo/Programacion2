#ifndef TP3_PILAS_H
#define TP3_PILAS_H

#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"
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

Pila conversor(int numero, int base);

void mostrarhex(Pila pila);

bool buscar_c (Pila p, int x);

Pila insertar(Pila p,TipoElemento elem, int posi);

Pila eliminar_por_clave(Pila pila, int clave);

Pila duplicar_pila(Pila pila);

int contar(Pila pila);

bool compara_pilas(Pila p1, Pila p2);

Pila invertir_pila(Pila pila);

Pila elemento_en_comun(Pila p1, Pila p2);

Pila repetidor(Pila p1);

#endif // TP3_LISTAS_H