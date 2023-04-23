#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP3_pilas.h"
#include "pilas.h"
#include "tipo_elemento.h"

void main_conversor()
{
    int numero, validador, base;
    printf(ANSI_BLUE "Ingrese un numero: " ANSI_YELLOW);
    validador = scanf("%i", &numero);
    while ((validador != 1) || (numero < 0) || (numero > 9999999))
    {
        printf(ANSI_RED "Entrada invalida!\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese un numero: " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &numero);
    }
    printf(ANSI_BLUE "Ingrese la base [2-16]: " ANSI_YELLOW);
    validador = scanf("%i", &base);
    while ((validador != 1) || (base < 0) || (base > 16))
    {
        printf(ANSI_RED "Entrada invalida!\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese la base [2-16]: " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &base);
    }
    printf(ANSI_BLUE "%d en base %d es: " ANSI_GREEN, numero, base);
    Pila pila = conversor(numero, base);
    mostrarhex(pila);
    printf(ANSI_BLUE);
}

void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 TP3 PILAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con pilas\n");
    printf("  3   Pilas iguales\n");
    printf("  4   Conversor de base\n");
    printf("  5   Invertir pila\n");
    printf("  6   Eliminar item\n");
    printf("  7   Elementos en común\n");
    printf("  8   \n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

void menu_punto2()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                         2   Operaciones con pilas                         |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Buscar elemento\n");
    printf("  2   Insertar elemento\n");
    printf("  3   Eliminar elemento\n");
    printf("  4   Intercambiar elementos\n");
    printf("  5   Duplicar pila\n");
    printf("  6   Contar elementos\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

int main()
{
    bool salir1 = false;
    bool salir = false;
    int opcion;
    while (!salir)
    {
        menu_principal();
        scanf("%i", &opcion);
        while (getchar() != '\n')
            ;
        while (opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            scanf("%i", &opcion);
            while (getchar() != '\n')
                ;
        }
        switch (opcion)
        {
        case 2:
            while (!salir1)
            {
                menu_punto2();
                scanf("%i", &opcion);
                while (opcion < 0 || opcion > 6)
                {
                    printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
                    printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
                    while (getchar() != '\n')
                        ;
                    scanf("%i", &opcion);
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
                case 0:
                    salir1 = true;
                }
            }
            break;
            menu_principal();
        case 3:

            getch();
            break;
        case 4:
            main_conversor();
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
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}