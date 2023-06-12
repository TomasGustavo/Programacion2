#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP7_Conjuntos.h"

/// @brief Menú principal del TP de conjuntos
void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                               TP6 TABLA HASH                               |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones de conjuntos\n");
    printf("  3   Union e intersección\n");
    printf("  4   Demostrar la propiedad de la transitividad\n");
    printf("  5   Diferencia simétrica\n");
    printf("  6   Subconjuntos propios\n");
    printf("  7   Subconjuntos parciales o totales\n");
    printf("  8   Conjuntos iguales\n");
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
        while (validador != 1 || opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "Por favor seleccione una opción: " ANSI_YELLOW);
            validador = scanf("%i", &opcion);
            vaciar_buffer();
        }

        switch (opcion)
        {
        case 1:
            // main_punto2();
            break;
        case 2:
            // main_punto3();
            break;
        case 3:
            // main_punto4();
            break;
        case 4:
            // main_punto4();
            break;
        case 5:
            // main_punto5();
            break;
        case 6:
            // main_punto6();
            break;
        case 7:
            // main_punto7();
            break;
        case 8:
            // main_punto8();
            break;
        case 0:
            salir = true;
            break;
        }
    }

    return 0;
}