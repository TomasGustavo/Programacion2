#ifndef TP1_RECURSIVIDAD_H
#define TP1_RECURSIVIDAD_H

#include <stdbool.h>
#define ANSI_RED "\e[31m"
#define ANSI_GREEN "\e[32m"
#define ANSI_YELLOW "\e[33m"
#define ANSI_BLUE "\e[34m"
#define ANSI_MAGENTA "\e[35m"
#define ANSI_CYAN "\e[36m"
#define ANSI_bRED "\e[91m"
#define ANSI_bGREEN "\e[92m"
#define ANSI_bYELLOW "\e[93m"
#define ANSI_bBLUE "\e[94m"
#define ANSI_bMAGENTA "\e[95m"
#define ANSI_bCYAN "\e[96m"
#define ANSI_RESET "\e[0m"

bool palindromo(char *cadena, int principio, int final);

char *chinos(int n);

long long terminoSerieFibonacci(int num);

char *buscaSumaSubconjunto(int tamano, int nivel, int suma, char *salidaparcial, int *ent, int *subset, int subsetSize);

void explosion(int n, int b, int* arreglo, int i);

#endif // TP1_RECURSIVIDAD_H
