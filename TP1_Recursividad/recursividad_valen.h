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

int producto(int m, int n);

int terminoSerieFibonacci(int num);

float division(int m, int n);

void agregarSeparadorMiles(char *cadena, int longitud, int contador);

char *chinos(int n);

char* ondaDigital(char *onda);

void ondaDigitalPrint(char *onda, int i);

int *subconjuntoQueSumanN(int *cadena[], int n);

bool divisiblePor7(int n);

int *explosion(int n, int b);

#endif // TP1_RECURSIVIDAD_H
