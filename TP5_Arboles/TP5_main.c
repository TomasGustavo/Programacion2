#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP5_arboles.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "arbol-binario.h"
#include "listas.h"

/// @brief Menu principal del TP de Colas
void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 TP5 ARBOLES                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con un arbol binario\n");
    printf("  3   Operaciones con un nodo\n");
    printf("  4-8 Operaciones con un arbol n-ario\n");
    printf("  7   Arboles binarios equivalentes\n");
    printf("  9   Convertir Arbol binario a arbol AVL\n");
    printf("  10  Alturas arbol binario de búsqueda vs AVL\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

/// @brief Menu del Punto 2: Operaciones con un arbol binario
void menu_punto2()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                    2   Operaciones con un arbol binario                     |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Mostrar nodos terminales u hojas\n");
    printf("  2   Nodos interiores\n");
    printf("  3   Buscar todas las ocurrencias de una clave con su posición\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

/// @brief Menu del Punto 2: Operaciones con un arbol binario
void menu_punto4()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                     3   Operaciones con un arbol n-ario                     |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Mostrar recorrido en anchura\n");
    printf("  2   Cantidad de hojas\n");
    printf("  3   Arbol similar\n");
    printf("  4   Padre del nodo\n");
    printf("  5   Hermanos del nodo\n");
    printf("  6   Altura del arbol\n");
    printf("  7   Nivel de un nodo\n");
    printf("  8   Nodos interiores\n");
    printf("  9   Nivel de todas las hojas\n");
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
    bool salir_p2 = false;
    bool salir_p4 = false;
    int opcion;
    while (!salir)
    {
        menu_principal();
        int validador = scanf("%i", &opcion);
        while (getchar() != '\n')
            ;
        while (validador != 1 || opcion < 0 || opcion > 10 || opcion == 1 || opcion == 5 || opcion == 6)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            validador = scanf("%i", &opcion);
            while (getchar() != '\n')
                ;
        }
        switch (opcion)
        {
        case 2:
            while (!salir_p2)
            {
                menu_punto2();
                validador = scanf("%i", &opcion);
                while (validador != 1 || opcion < 0 || opcion > 3)
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
                    getch();
                    break;
                case 2:
                    getch();
                    break;
                case 3:
                    getch();
                    break;
                case 0:
                    salir_p2 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            getch();
            break;
        case 4:
            while (!salir_p4)
            {
                menu_punto4();
                validador = scanf("%i", &opcion);
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
                    getch();
                    break;
                case 2:
                    getch();
                    break;
                case 3:
                    getch();
                    break;
                case 4:
                    getch();
                    break;
                case 5:
                    getch();
                    break;
                case 6:
                    getch();
                    break;
                case 7:
                    getch();
                    break;
                case 8:
                    getch();
                    break;
                case 9:
                    getch();
                    break;
                case 0:
                    salir_p4 = true;
                }
            }
            break;
            menu_principal();
        case 7:
            getch();
            break;
        case 9:
            getch();
            break;
        case 10:
            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}