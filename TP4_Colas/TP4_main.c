#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP4_colas.h"
#include "colas.h"
#include "tipo_elemento.h"

void main_buscarElemento()
{
    Cola c;
    int clave, validador;
    bool rta;
    printf(ANSI_bMAGENTA "Cargar la lista: \n");
    c = cargarCola();

    printf(ANSI_bMAGENTA "Ingrese el elemento a buscar [-999.999 - 999.999]: \n" ANSI_RESET);
    validador = scanf("%d", &clave);
    vaciar_buffer();
    while (validador != 1 || clave < -999999 || clave > 999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese el elemento a buscar [-999.999 - 999.999]: \n" ANSI_RESET);
        validador = scanf("%d", &clave);
        vaciar_buffer();
    }

    rta = buscar(c, clave);

    if (rta == true)
        printf(ANSI_bGREEN "Se encontró el elemento %i en la cola\n", clave);
    else
    {
        printf(ANSI_RED "No se encontró el elemento en la cola\n");
    }
}

void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 TP3 PILAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con colas\n");
    printf("  3   Colas iguales\n");
    printf("  4   Elementos no repetidos\n");
    printf("  5   Divisores\n");
    printf("  6   Lista con valores comunes\n");
    printf("  7   Cola de clientes\n");
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
    printf("  4   Contar los elementos\n");
    printf("  5   Realizar una copia\n");
    printf("  6   Invertir\n");
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
                    main_buscarElemento();
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