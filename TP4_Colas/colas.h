#ifndef COLAS_H
#define COLAS_H

#include <stdbool.h>
#include "tipo_elemento.h"
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


struct ColaRep;
typedef struct ColaRep *Cola;

Cola c_crear();

void c_encolar(Cola cola, TipoElemento elemento);

TipoElemento c_desencolar(Cola cola);

bool c_es_vacia(Cola cola);

bool c_es_llena(Cola cola);

void c_mostrar(Cola cola);

TipoElemento c_recuperar(Cola cola);

#endif // COLAS_H
