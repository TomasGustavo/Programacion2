#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP6_tabla_hash.h"
#include "archivos.h"
#include "tabla_hash.h"

void menu_alumnos()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 ABM Alumnos                                |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Dar de alta un alumno\n");
    printf("  2   Dar de baja un alumno\n");
    printf("  3   Modificar datos de un alumno\n");
    printf("  4   Mostrar archivo binario\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

void main_baja(TablaHash th)
{
    int validador;
    int legajo;
    printf(ANSI_bMAGENTA "Ingrese el legajo [1 - 999999]: " ANSI_YELLOW);
    validador = scanf("%d", &legajo);
    vaciar_buffer();
    while (validador != 1 || legajo < 1 || legajo > 999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese el legajo [1 - 999.999]: " ANSI_YELLOW);
        validador = scanf("%d", &legajo);
        vaciar_buffer();
    }
    baja(th, legajo);
}

void main_modificar(TablaHash th)
{
    int validador;
    int legajo;
    printf(ANSI_bMAGENTA "Ingrese el legajo [1 - 999999]: " ANSI_YELLOW);
    validador = scanf("%d", &legajo);
    vaciar_buffer();
    while (validador != 1 || legajo < 1 || legajo > 999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese el legajo [1 - 999.999]: " ANSI_YELLOW);
        validador = scanf("%d", &legajo);
        vaciar_buffer();
    }
    modificar(th, legajo);
}

void main_punto4()
{
    bool salir_p4 = false;
    int opcion;
    FILE *archivo;
    crear_archivo_binario();
    TablaHash th = th_crear(TAMANIO_MAXIMO, &FuncionHash);
    while (!salir_p4)
    {
        limpiar_pantalla();
        menu_alumnos();
        int validador = scanf("%i", &opcion);
        vaciar_buffer();
        while (validador != 1 || opcion < 0 || opcion > 4)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            while (getchar() != '\n')
                ;
            validador = scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 1:
            alta(th);
            break;
        case 2:
            main_baja(th);
            break;
        case 3:
            main_modificar(th);
            break;
        case 4:
            mostrarArchivo();
            break;
        case 0:
            salir_p4 = true;
        }
    }
}

void main_punto5()
{
    const int N_MIN = 1;
    const int N_MAX = 2000;
    const int A_MAX = 10000;

    int min, max, repeticiones, clave, validador;
    // Cantidad de repeticiones
    printf(ANSI_bMAGENTA "Ingrese la cantidad de repeticiones que se ejecutara la carga de estructuras [1-1000]: " ANSI_YELLOW);
    validador = scanf("%d", &repeticiones);
    vaciar_buffer();
    while (validador != 1 || repeticiones < N_MIN || repeticiones > 1000)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese la cantidad de repeticiones que se ejecutara la carga de arboles [1-1000]: " ANSI_YELLOW);
        validador = scanf("%d", &repeticiones);
        vaciar_buffer();
    }

    // Cantidad de claves a cargar en cada estructura
    printf(ANSI_bMAGENTA "Ingrese la cantidad de claves a cargar en cada estructura [%d-%d]: " ANSI_YELLOW, N_MIN, N_MAX);
    validador = scanf("%d", &clave);
    vaciar_buffer();
    while (validador != 1 || clave < N_MIN || clave > N_MAX)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese la cantidad de claves a cargar en cada estructura [%d-%d]: " ANSI_YELLOW, N_MIN, N_MAX);
        validador = scanf("%d", &clave);
        vaciar_buffer();
    }

    // Rango mínimo
    printf(ANSI_bMAGENTA "Ingrese el rango mínimo de la serie aleatoria [1-%d]: " ANSI_YELLOW, A_MAX);
    validador = scanf("%d", &min);
    vaciar_buffer();
    while (validador != 1 || min < N_MIN || min > A_MAX)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese el rango mínimo de la serie aleatoria [1-%d]: " ANSI_YELLOW, A_MAX);
        validador = scanf("%d", &min);
        vaciar_buffer();
    }

    // Rango máximo
    printf(ANSI_bMAGENTA "Ingrese el rango máximo de la serie aleatoria [%d-999.999]\n" ANSI_YELLOW, (min * 2));
    printf(ANSI_bRED "Tener en cuenta que la diferencia entre el máximo y el mínimo tiene que ser superior a la cantidad de nodos x2: " ANSI_YELLOW);
    validador = scanf("%d", &max);
    vaciar_buffer();
    while ((validador != 1) || ((max - min) < (clave * 2)) || (max > 999999))
    {
        printf("ERROR\n");
        printf("datos fuera de rango\nPor favor Ingrese nuevamente el rango máximo de la serie aleatoria [%d-999.999]: " ANSI_YELLOW, (min * 2));
        validador = scanf("%d", &max);
        vaciar_buffer();
    }

    cargar_AVL_HASH(repeticiones, clave, min, max);
    pausa();
    limpiar_pantalla();
}

void menu_personas()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                  PUNTO 6                                   |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Agregar persona\n");
    printf("  2   Buscar por fecha\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

void main_6b(TablaHash *th)
{
    int validador, fecha;
    unsigned int dia, mes, anio;
    bool fechaValida = false;
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
        printf("%s", fechaValida ? ANSI_GREEN "\nLa fecha es válida\n" : ANSI_RED "\nLa fecha no es válida, vuelva a ingresarla\n");
    }

    fecha = juntarNumeros(dia, mes, anio);
    recuperarPersonas(*th, fecha);
}

void main_punto6()
{
    bool salir_p6 = false;
    int opcion;
    TablaHash th = th_crear(TAMANIO_MAXIMO_P6, FuncionHash_Punto6);
    while (!salir_p6)
    {
        limpiar_pantalla();
        menu_personas();
        int validador = scanf("%i", &opcion);
        while (validador != 1 || opcion < 0 || opcion > 2)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "Por favor seleccione una opción: " ANSI_YELLOW);
            while (getchar() != '\n')
                ;
            validador = scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 1:
            cargarPersona(&th);
            break;
        case 2:
            main_6b(&th);
            break;
        case 0:
            salir_p6 = true;
        }
    }
}

/// @brief Menú principal del TP de tabla hash
void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                               TP6 TABLA HASH                               |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   ABM Alumnos\n");
    printf("  2   Comparación en tiempos de acceso\n");
    printf("  3   Buscar por fecha\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

int main()
{
    bool salir = false;
    int opcion;

    while (!salir)
    {
        limpiar_pantalla();
        menu_principal();
        int validador = scanf("%i", &opcion);
        vaciar_buffer();
        while (validador != 1 || opcion < 0 || opcion > 3)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "Por favor seleccione una opción: " ANSI_YELLOW);
            validador = scanf("%i", &opcion);
            vaciar_buffer();
        }

        switch (opcion)
        {

        case 1:
            main_punto4();
            break;
        case 2:
            main_punto5();
            break;
        case 3:
            main_punto6();
            break;
        case 0:
            salir = true;
            break;
        }
    }

    return 0;
}