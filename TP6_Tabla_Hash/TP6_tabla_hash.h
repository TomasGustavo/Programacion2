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
#include "tabla_hash.h"

static const int TAMANIO_MAXIMO = 100;
static const int NRO_PRIMO = 97;

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

struct PersonaRep{
    int fecha;
    int dni;
    char nombre[20];
    char apellido[20];
};
typedef struct PersonaRep *Persona;

void vaciar_buffer();

void pausa();

void limpiar_pantalla();

bool validarFecha(unsigned int dia, unsigned int mes,unsigned int anio);

int juntarNumeros(unsigned int dia, unsigned int mes, unsigned int anio);

void cargarPersona();

int FuncionHash (int n);

void alta(TablaHash th);

void bajas(TablaHash th, int legajo);

void modificar(FILE *archivo,TablaHash th,int legajo);

bool buscarAlumnoEnTabla(TablaHash th, int legajo);

void menu_modificar();

void mostrar_modificacion(FILE *archivo, TablaHash th, int legajo );

#endif // Tabla hash