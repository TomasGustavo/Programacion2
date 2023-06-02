#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP6_tabla_hash.h"

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

int main(){
    bool salir = false;
    int opcion;

    while(!salir){
        menu_principal();
        int validador = scanf("%i", &opcion);
        vaciar_buffer();
        while (validador != 1 || opcion < 0 || opcion > 3 ){
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            validador = scanf("%i", &opcion);
            vaciar_buffer();
        }

        switch(opcion){
            
            case 1:
                //main_punto4()
                break;
            case 2:
                //main_punto5()
                break;
            case 3:
                //main_punto6()
                break;
            case 0:
                salir = true;
                break;
        }
    }


    return 0;
}