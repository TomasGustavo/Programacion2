#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include "TP6_tabla_hash.h"
#include "listas.h"
#include "tabla_hash.h"
#include "tipo_elemento.h"
#include "arbol-avl.h"

int FuncionHash(int n)
{
    return n % NRO_PRIMO;
}

/// @brief Vacía el buffer de entrada.
void vaciar_buffer()
{
    char nada[200];
    fgets(nada, 200, stdin);
}

/// @brief Frena la ejecución del código esperando el ingreso de un carácter.
void pausa()
{
    printf(ANSI_bYELLOW "\n\nPresione una tecla para continuar...." ANSI_RESET);
    getchar();
}

/// @brief Secuencia de escape ANSI que se utiliza para limpiar la pantalla de la terminal y posicionar el cursor en la esquina superior izquierda.
void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

// -------------------------------------------------- PUNTO 5 --------------------------------------------------
int FuncionHash1(int n)
{
    return n % 10;
}

/// @brief Función que genera números aleatorios dentro de un rango
/// @param min Rango mínimo
/// @param max Rango máximo
/// @return Numero aleatorio generado
int getRandom(int min, int max)
{
    int n_aleatorio;
    n_aleatorio = min + (rand() % (max - min + 1));
    return n_aleatorio;
}

void free_avl(NodoArbol Q)
{
    if (avl_es_rama_nula(Q))
    {
        return;
    }

    free_avl(n_hijoizquierdo(Q));
    free_avl(n_hijoderecho(Q));
    free(Q);
    Q = NULL;
}

/// @brief Función que carga una clave en un arbol AVL y en una Tabla Hash
/// @param th Tabla Hash a cargar
/// @param A_AVL Arbol AVL a cargar la serie aleatoria
/// @param min Valor mínimo del rango aleatorio
/// @param max Valor máximo del rango aleatorio
void cargar_clave_AVL_HASH(TablaHash *th, ArbolAVL *A_AVL, int min, int max)
{
    TipoElemento X;
    int n_aleatorio;
    if (!avl_es_lleno(*A_AVL))
    {
        n_aleatorio = getRandom(min, max);
        while (avl_buscar(*A_AVL, n_aleatorio) != NULL)
        {
            n_aleatorio = getRandom(min, max);
        }
        X = te_crear(n_aleatorio);
        avl_insertar(*A_AVL, X);
        th_insertar(*th, X);
    }
}

/// @brief Función que repite 'repeticiones' veces el proceso de carga del arbol AVL y la Tabla Hash
/// @param repeticiones Cantidad de repeticiones
/// @param claves Cantidad de claves a cargar en cada estructura
/// @param min Valor mínimo del rango aleatorio
/// @param max Valor máximo del rango aleatorio
void cargar_AVL_HASH(int repeticiones, int claves, int rango_min, int rango_max)
{
    srand(time(NULL)); // Establecer semilla
    int claveABuscar;
    long long totalAVL = 0;
    long long totalHASH = 0;
    struct timespec start, end;
    long long msHASH, msAVL;
    TipoElemento X;
    for (int i = 1; i <= repeticiones; i++)
    {
        ArbolAVL A_AVL = avl_crear();
        TablaHash th = th_crear(claves, FuncionHash1);
        for (int i = 1; i <= claves; i++) // Repite n veces el proceso de carga de los nodos
        {
            cargar_clave_AVL_HASH(&th, &A_AVL, rango_min, rango_max);
        }
        // generar un random y buscar en las dos tablas tomando tiempo
        claveABuscar = getRandom(rango_min, rango_max);
        clock_gettime(CLOCK_REALTIME, &start);
        X = th_recuperar(th, claveABuscar); // Busco la clave
        clock_gettime(CLOCK_REALTIME, &end);
        msHASH = (end.tv_nsec - start.tv_nsec);
        totalHASH += msHASH;

        clock_gettime(CLOCK_REALTIME, &start);
        X = avl_buscar(A_AVL, claveABuscar); // Busco la clave
        clock_gettime(CLOCK_REALTIME, &end);
        msAVL = (end.tv_nsec - start.tv_nsec);
        totalAVL += msAVL;

        free(th);
        free_avl(avl_raiz(A_AVL));
    }
    printf(ANSI_GREEN "El tiempo total de HASH en ms es: " ANSI_YELLOW "%lld nanosegundos\n", totalHASH);
    printf(ANSI_GREEN "El tiempo total de AVL en ms es: " ANSI_YELLOW "%lld nanosegundos\n", totalAVL);
}

// -------------------------------------------------- PUNTO 6 --------------------------------------------------

///@brief Funcion que dado un dia, mes y año indica si la fecha es valida
bool validarFecha(unsigned int dia, unsigned int mes, unsigned int anio)
{
    unsigned int dia_maximo;
    bool fecha_correcta = false;

    if (mes >= 1 && mes <= 12)
    {
        switch (mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dia_maximo = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            dia_maximo = 30;
            break;

        case 2:
            if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
                dia_maximo = 29;
            else
                dia_maximo = 28;
        }

        if (dia >= 1 && dia <= dia_maximo)
            fecha_correcta = true;
    }
    return fecha_correcta;
}

// Funciones para pasar la fecha a un mismo string y luego devolver el numero resultado
//  para pasar a la funcion hash
/*
void enteroACadena(unsigned int numero, char *bufer)
{
    sprintf(bufer, "%u", numero);
}

int juntarNumeros(unsigned int dia, unsigned int mes, unsigned int anio)
{
    char cadenadia[3];
    char cadenames[3];
    char cadenaanio[5];
    char fecha[9];
    memset(&fecha, 0, sizeof(fecha));
    enteroACadena(dia, cadenadia);
    enteroACadena(mes, cadenames);
    enteroACadena(anio, cadenaanio);
    strcat(fecha, cadenadia);
    strcat(fecha, cadenames);
    strcat(fecha, cadenaanio);
    int entero = (int)strtol(fecha, NULL, 10);
    return entero;
}
*/
int juntarNumeros(unsigned int dia, unsigned int mes, unsigned int anio)
{
    char fecha[9];
    sprintf(fecha, "%02u%02u%04u", dia, mes, anio);
    int entero = atoi(fecha);
    return entero;
}

void cargarPersona(TablaHash *th)
{
    Persona persona = malloc(sizeof(struct PersonaRep));
    unsigned int dia, mes, anio, dni;
    int validador, fecha;
    bool fechaValida = false;
    // Cargar DNI
    printf(ANSI_bMAGENTA "DNI: " ANSI_YELLOW);
    validador = scanf("%u", &persona->dni);
    vaciar_buffer();
    while (validador != 1 || persona->dni < 1 ||  persona->dni > 99999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bMAGENTA "DNI: " ANSI_YELLOW);
        validador = scanf("%d", &persona->dni);
        vaciar_buffer();
    }

    // Cargar nombre
    printf(ANSI_bMAGENTA "Nombre: " ANSI_YELLOW);
    fgets(persona->nombre, 20, stdin);

    // Cargar apellido
    printf(ANSI_bMAGENTA "Apellido: " ANSI_YELLOW);
    fgets(persona->apellido, 20, stdin);

    while (!fechaValida)
    {
        // Cargar fecha
        printf(ANSI_bMAGENTA "Ingresar la fecha de vacunación\n" ANSI_YELLOW);

        // Cargar dia
        printf(ANSI_bMAGENTA "Día: " ANSI_YELLOW);
        validador = scanf("%u", &dia);
        vaciar_buffer();
        while (validador != 1 || dia < 1 || dia > 31)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bMAGENTA "Día: " ANSI_YELLOW);
            validador = scanf("%u", &dia);
            vaciar_buffer();
        }

        // Cargar mes
        printf(ANSI_bMAGENTA "Mes: " ANSI_YELLOW);
        validador = scanf("%u", &mes);
        vaciar_buffer();
        while (validador != 1 || mes < 1 || mes > 12)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bMAGENTA "Mes: " ANSI_YELLOW);
            validador = scanf("%u", &mes);
            vaciar_buffer();
        }

        // Cargar año
        printf(ANSI_bMAGENTA "Año: " ANSI_YELLOW);
        validador = scanf("%u", &anio);
        vaciar_buffer();
        while (validador != 1 || anio < 2020 || anio > 2023)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bMAGENTA "Año: " ANSI_YELLOW);
            validador = scanf("%u", &anio);
            vaciar_buffer();
        }

        fechaValida = validarFecha(dia, mes, anio);
        printf("%s", fechaValida ? "La fecha es válida\n" : "La fecha no es válida, vuelva a ingresarla\n");
    }

    persona->fecha = juntarNumeros(dia, mes, anio);

    agregarATabla(th, persona);
    printf(ANSI_bGREEN "Persona cargada correctamente!\n" ANSI_bYELLOW);
    pausa();
}

void agregarATabla(TablaHash *th, Persona persona)
{

    TipoElemento X = th_recuperar(*th, persona->fecha);
    if (X == NULL)
    {
        Lista L = l_crear();
        X = te_crear_con_valor(0, persona);
        l_agregar(L, X);
        TipoElemento X1 = te_crear_con_valor(persona->fecha, L);
        th_insertar(*th, X1);
    }
    else
    {
        TipoElemento X1 = te_crear_con_valor(0, persona);
        Lista L = (Lista)X->valor;
        l_agregar(L, X1);
        X->valor = L;
        th_insertar(*th, X);
    }
}

void mostrarPersonas(Lista L){
    Persona persona = malloc(sizeof(struct PersonaRep));
    TipoElemento X = te_crear(0);
    Iterador ite = iterador(L);

    while (hay_siguiente(ite))
    {
        X = siguiente(ite);
        persona = (Persona)X->valor;
        printf(ANSI_bMAGENTA "\nNombre: " ANSI_YELLOW "%s", persona->nombre);
        printf(ANSI_bMAGENTA "Apellido: " ANSI_YELLOW "%s", persona->apellido);
        printf(ANSI_bMAGENTA "DNI: " ANSI_YELLOW "%u \n", persona->dni);
    }
    pausa();   
}

void recuperarPersonas(TablaHash th, int fecha){
    TipoElemento X = th_recuperar(th, fecha);
    if (X == NULL)
    {
        printf(ANSI_bRED "\nNo hay personas vacunadas en esa fecha");
        pausa();
    }
    else 
    {
        Lista L = (Lista)X->valor;
        mostrarPersonas(L);
    }
}

