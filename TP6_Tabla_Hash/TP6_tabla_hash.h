#ifndef TP6_TABLA_HASH_H
#define TP6_TABLA_HASH_H

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

struct AlumnoRep{
    int legajo;
    int dni;
    char nombre[20];
    char apellido[20];
    char domicilio [20];
    int TE;
};
typedef struct AlumnoRep *Alumno;

struct PosicionEstadoRep{
    int legajo;
    bool estado;
    int posicion;
};
typedef struct PosicionEstadoRep *PosicionEstado;

void vaciar_buffer();

void pausa();

void limpiar_pantalla();

#endif // Tabla hash