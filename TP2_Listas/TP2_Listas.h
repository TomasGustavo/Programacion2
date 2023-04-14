#ifndef TP2_LISTAS_H
#define TP2_LISTAS_H

#include <stdbool.h>
#include "listas.h"
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

Lista cargarListaClaves();

int menor(Lista lista, int * posicion);

int mayor(Lista lista, int * repeticiones);

float promedio (Lista l, int i, float suma);

Lista multiplos (Lista l, int n);

bool esMultiplo (Lista l1, Lista l2, int * escalar);

float polinomio (Lista l, float x);

Lista rango (Lista l, int xMax, int xMin, int i);

bool sublista (Lista l1, Lista l2);

#endif // TP2_LISTAS_H
