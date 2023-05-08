#ifndef TP4_COLAS_H
#define TP4_COLAS_H

#include <stdbool.h>
#include "colas.h"
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

void vaciar_buffer();

void pausa();

void limpiar_pantalla();

Cola intercambiar(Cola caux);

// void intercambiar(Cola c, Cola aux);

Cola cargarCola();

bool buscar(Cola c, int clave);

Cola insertar(Cola c, TipoElemento x, int pos);

Cola eliminarTodas(Cola c, int clave, bool* estado);

bool Comparar(Cola c1, Cola c2);

Cola norepetidos(Cola c);

void divisores(Cola cola, Cola Divisor_total, Cola Divisor_parcial, int numero_actual, float longitud_cola);

#endif // TP3_LISTAS_H