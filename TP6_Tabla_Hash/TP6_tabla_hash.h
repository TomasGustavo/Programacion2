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

static const int TAMANIO_MAXIMO_P6 = 50;
static const int NRO_PRIMO_P6 = 47;

struct AlumnoRep{
    int legajo;
    char nombre[20];
    char apellido[20];
    char domicilio [20];
    long long TE;
    bool estado;
};
typedef struct AlumnoRep *Alumno;

struct PersonaRep{
    int fecha;
    unsigned int dni;
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

int FuncionHash1 (int n);

void cargar_AVL_HASH(int repeticiones, int claves, int rango_min, int rango_max);

void cargarPersona(TablaHash* th);

void agregarATabla(TablaHash* th, Persona persona);

void recuperarPersonas(TablaHash th, int fecha);

int FuncionHash_Punto6(int n);

#endif // Tabla hash