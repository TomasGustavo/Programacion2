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
#include <float.h>
#include <math.h>

int primo;

// Valida si todos los elementos de una cadena son letras
bool sonLetras(char *cadena)
{
    bool res = true;
    for (int i = 0; i < strlen(cadena) - 1; i++)
    {
        if (!isalpha(cadena[i]))
        {
            res = false;
        }
    }
    return res;
}

// Pasa todos los caracteres de la cadena a minúscula

void a_mayuscula(char *cadena)
{
    int i = 0;

    while (cadena[i] != '\0')
    {
        cadena[i] = toupper(cadena[i]);
        i++;
    }
}

int FuncionHash_Punto4(int n)
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

bool esPrimo(int numero)
{
    if (numero <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(numero); i++)
    {
        if (numero % i == 0)
        {
            return false;
        }
    }

    return true;
}

int numeroPrimoMasCercanoMenor(int numero)
{
    int numeroPrimo = numero - 1;

    while (numeroPrimo > 1)
    {
        if (esPrimo(numeroPrimo))
        {
            return numeroPrimo;
        }

        numeroPrimo--;
    }

    return -1; // No se encontró un número primo menor
}

int FuncionHash_Punto5(int n)
{
    return n % primo;
    // return n % numeroPrimoMasCercanoMenor(n);
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

long long calcular_diferencia(struct timespec inicio, struct timespec fin)
{
    long long diferencia = (fin.tv_sec - inicio.tv_sec) * 1000000000LL; // Diferencia en nanosegundos
    diferencia += fin.tv_nsec - inicio.tv_nsec;                         // Sumar la diferencia de nanosegundos

    return diferencia;
}

// MAIN PUNTO 5
/// @brief Función que repite 'repeticiones' veces el proceso de carga del arbol AVL y la Tabla Hash
/// @param repeticiones Cantidad de repeticiones
/// @param claves Cantidad de claves a cargar en cada estructura
/// @param min Valor mínimo del rango aleatorio
/// @param max Valor máximo del rango aleatorio
void cargar_AVL_HASH(int repeticiones, int claves, int rango_min, int rango_max)
{
    srand(time(NULL)); // Establecer semilla
    int claveABuscar;
    struct timespec start, end;
    TipoElemento X;

    unsigned long long tiempo_minimo_avl, tiempo_maximo_avl, tiempo_suma_avl = 0, tiempo_actual_avl;
    unsigned long long tiempo_minimo_th, tiempo_maximo_th, tiempo_suma_th = 0, tiempo_actual_th;
    double tiempo_promedio_avl, tiempo_promedio_th, tiempo_no_esta_promedio_th, tiempo_no_esta_promedio_avl;
    unsigned long long tiempo_no_esta_avl = 0, tiempo_no_esta_th = 0;
    int no_esta_avl = 0, no_esta_th = 0;

    ArbolAVL A_AVL = avl_crear();
    primo = numeroPrimoMasCercanoMenor(claves);
    TablaHash th = th_crear(claves, &FuncionHash_Punto5);
    for (int i = 1; i <= claves; i++) // Repite n veces el proceso de carga de los nodos
    {
        cargar_clave_AVL_HASH(&th, &A_AVL, rango_min, rango_max);
    }
    // generar un random y buscar en las dos tablas tomando tiempo
    claveABuscar = getRandom(rango_min, rango_max);

    // Tiempo y búsqueda en hash
    clock_gettime(CLOCK_REALTIME, &start);
    X = th_recuperar(th, claveABuscar); // Busco la clave
    clock_gettime(CLOCK_REALTIME, &end);
    if (X == NULL)
    {
        tiempo_no_esta_th += (end.tv_nsec - start.tv_nsec);
        no_esta_th++;
    }
    // Estadísticas iniciales de hash
    tiempo_actual_th = (end.tv_nsec - start.tv_nsec);
    tiempo_minimo_th = tiempo_actual_th;
    tiempo_maximo_th = tiempo_actual_th;
    tiempo_suma_th += tiempo_actual_th;

    // Tiempo y búsqueda en avl
    clock_gettime(CLOCK_REALTIME, &start);
    X = avl_buscar(A_AVL, claveABuscar); // Busco la clave
    clock_gettime(CLOCK_REALTIME, &end);
    if (X == NULL)
    {
        tiempo_no_esta_avl += (end.tv_nsec - start.tv_nsec);
        no_esta_avl++;
    }
    // Estadísticas iniciales de avl
    tiempo_actual_avl = (end.tv_nsec - start.tv_nsec);
    tiempo_minimo_avl = tiempo_actual_avl;
    tiempo_maximo_avl = tiempo_actual_avl;
    tiempo_suma_avl += tiempo_actual_avl;

    for (int i = 1; i < repeticiones; i++)
    {
        // generar un random y buscar en las dos tablas tomando tiempo
        claveABuscar = getRandom(rango_min, rango_max);

        // Tiempo y búsqueda en hash
        clock_gettime(CLOCK_REALTIME, &start);
        X = th_recuperar(th, claveABuscar); // Busco la clave
        clock_gettime(CLOCK_REALTIME, &end);
        if (X == NULL)
        {
            tiempo_no_esta_th += (end.tv_nsec - start.tv_nsec);
            no_esta_th++;
        }

        // Estadísticas de hash
        tiempo_actual_th = (end.tv_nsec - start.tv_nsec);
        if (tiempo_minimo_th > tiempo_actual_th)
        {
            tiempo_minimo_th = tiempo_actual_th;
        }
        if (tiempo_maximo_th < tiempo_actual_th)
        {
            tiempo_maximo_th = tiempo_actual_th;
        }
        tiempo_suma_th += tiempo_actual_th;

        // Tiempo y búsqueda en avl
        clock_gettime(CLOCK_REALTIME, &start);
        X = avl_buscar(A_AVL, claveABuscar); // Busco la clave
        clock_gettime(CLOCK_REALTIME, &end);
        if (X == NULL)
        {
            tiempo_no_esta_avl += (end.tv_nsec - start.tv_nsec);
            no_esta_avl++;
        }

        // Estadísticas de avl
        tiempo_actual_avl = (end.tv_nsec - start.tv_nsec);
        if (tiempo_minimo_avl > tiempo_actual_avl)
        {
            tiempo_minimo_avl = tiempo_actual_avl;
        }
        if (tiempo_maximo_avl < tiempo_actual_avl)
        {
            tiempo_maximo_avl = tiempo_actual_avl;
        }
        tiempo_suma_avl += tiempo_actual_avl;
    }
    free(th);
    free_avl(avl_raiz(A_AVL));

    tiempo_promedio_th = tiempo_suma_th / repeticiones;
    tiempo_promedio_avl = tiempo_suma_avl / repeticiones;
    if (no_esta_th != 0)
    {
        tiempo_no_esta_promedio_th = tiempo_no_esta_th / no_esta_th;
    }
    if (no_esta_avl != 0)
    {
        tiempo_no_esta_promedio_avl = tiempo_no_esta_avl / no_esta_avl;
    }
    printf(ANSI_GREEN "\nSe realizaron %d búsquedas en las estructuras, las estadísticas son:\n", repeticiones);
    printf(ANSI_GREEN "El tiempo mínimo del arbol AVL es: " ANSI_YELLOW "%llu nanosegundos\n", tiempo_minimo_avl);
    printf(ANSI_GREEN "El tiempo máximo del arbol AVL es: " ANSI_YELLOW "%llu nanosegundos\n", tiempo_maximo_avl);
    printf(ANSI_GREEN "El tiempo promedio del arbol AVL es: " ANSI_YELLOW "%.2f nanosegundos\n", tiempo_promedio_avl);
    if (no_esta_avl != 0)
    {
        printf(ANSI_GREEN "El tiempo promedio del arbol AVL si no esta la clave es: " ANSI_YELLOW "%.2f nanosegundos\n", tiempo_no_esta_promedio_avl);
    }
    printf(ANSI_GREEN "El tiempo total del arbol AVL es: " ANSI_YELLOW "%llu nanosegundos\n\n", tiempo_suma_avl);
    printf(ANSI_GREEN "El tiempo mínimo de la tabla hash es: " ANSI_YELLOW "%llu nanosegundos\n", tiempo_minimo_th);
    printf(ANSI_GREEN "El tiempo máximo de la tabla hash es: " ANSI_YELLOW "%llu nanosegundos\n", tiempo_maximo_th);
    printf(ANSI_GREEN "El tiempo promedio de la tabla hash es: " ANSI_YELLOW "%.2f nanosegundos\n", tiempo_promedio_th);
    if (no_esta_avl != 0)
    {
        printf(ANSI_GREEN "El tiempo promedio de la tabla hash si no esta la clave es: " ANSI_YELLOW "%.2f nanosegundos\n", tiempo_no_esta_promedio_th);
    }
    printf(ANSI_GREEN "El tiempo total de la tabla hash es: " ANSI_YELLOW "%llu nanosegundos\n\n", tiempo_suma_th);
}

// -------------------------------------------------- PUNTO 6 --------------------------------------------------

int FuncionHash_Punto6(int n)
{
    return n % NRO_PRIMO_P6;
}

///@brief Función que dado un día, mes y año indica si la fecha es valida
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
    while (validador != 1 || persona->dni < 1 || persona->dni > 99999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bMAGENTA "DNI: " ANSI_YELLOW);
        validador = scanf("%d", &persona->dni);
        vaciar_buffer();
    }
    // Cargar nombre
    bool estado_nombre = true;
    do
    {
        if (!estado_nombre)
        {
            printf(ANSI_RED "ERROR\tNO ES UNA CADENA VALIDA\n" ANSI_RESET);
        }
        printf(ANSI_bMAGENTA "Nombre: " ANSI_YELLOW);
        fgets(persona->nombre, 20, stdin);
        persona->nombre[strcspn(persona->nombre, "\n")] = '\0'; // Eliminar el carácter de nueva línea
        estado_nombre = sonLetras(persona->nombre);
    } while (!estado_nombre);

    // Cargar apellido
    bool estado_apellido = true;
    do
    {
        if (!estado_apellido)
        {
            printf(ANSI_RED "ERROR\tNO ES UNA CADENA VALIDA\n" ANSI_RESET);
        }
        printf(ANSI_bMAGENTA "Apellido: " ANSI_YELLOW);
        fgets(persona->apellido, 20, stdin);
        persona->apellido[strcspn(persona->apellido, "\n")] = '\0'; // Eliminar el carácter de nueva línea
        estado_apellido = sonLetras(persona->apellido);
    } while (!estado_apellido);

    while (!fechaValida)
    {
        // Cargar fecha
        printf(ANSI_bMAGENTA "Ingresar la fecha de vacunación\n" ANSI_YELLOW);

        // Cargar día
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
        while (validador != 1 || anio < 2020 || anio > 2025)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n");
            printf("El rango es entre 2020 y 2025\n\n" ANSI_RESET);
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
    printf(ANSI_bGREEN "\nPersona cargada correctamente!\n" ANSI_bYELLOW);
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

void mostrarPersonas(Lista L)
{
    Persona persona = malloc(sizeof(struct PersonaRep));
    TipoElemento X = te_crear(0);
    Iterador ite = iterador(L);

    while (hay_siguiente(ite))
    {
        X = siguiente(ite);
        persona = (Persona)X->valor;
        printf(ANSI_bMAGENTA "\nNombre: " ANSI_YELLOW "%s\n", persona->nombre);
        printf(ANSI_bMAGENTA "Apellido: " ANSI_YELLOW "%s\n", persona->apellido);
        printf(ANSI_bMAGENTA "DNI: " ANSI_YELLOW "%u \n", persona->dni);
    }
    pausa();
}

void recuperarPersonas(TablaHash th, int fecha)
{
    TipoElemento X = th_recuperar(th, fecha);
    if (X == NULL)
    {
        printf(ANSI_bRED "\nNo hay personas vacunadas en esa fecha");
        pausa();
    }
    else
    {
        Lista L = (Lista)X->valor;
        printf(ANSI_CYAN "\n\nListado de personas que se vacunaron en esa fecha\n\n");
        mostrarPersonas(L);
    }
}
