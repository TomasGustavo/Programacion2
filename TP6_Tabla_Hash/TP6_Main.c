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
    printf(" |                                  ABM alumnos                                |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   dar de alta un alumno\n");
    printf("  2   dar de baja un alumno\n");
    printf("  3   modificar datos de alumnos\n");
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
    bajas(th, legajo);
}

void main_modificar(TablaHash th)
{
    FILE *archivo;
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
    modificar(archivo, th, legajo);
}

void main_punto4()
{
    bool salir_p4 = false;
    int opcion;
    crear_txt();

    TablaHash th = th_crear(TAMANIO_MAXIMO, &FuncionHash);
    while (!salir_p4)
    {
        menu_alumnos();
        int validador = scanf("%i", &opcion);
        while (validador != 1 || opcion < 0 || opcion > 9)
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
        case 0:
            salir_p4 = true;
        }
    }
}

/// @brief Menú principal del TP de tabla hash
void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 TP6 TABLA HASH                                 |\n");
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
        menu_principal();
        int validador = scanf("%i", &opcion);
        vaciar_buffer();
        while (validador != 1 || opcion < 0 || opcion > 3)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            validador = scanf("%i", &opcion);
            vaciar_buffer();
        }

        switch (opcion)
        {

        case 1:
            menu_alumnos();
            main_punto4();
            break;
        case 2:
            // main_punto5()
            break;
        case 3:
            // main_punto6()
            break;
        case 0:
            salir = true;
            break;
        }
    }

    return 0;
}