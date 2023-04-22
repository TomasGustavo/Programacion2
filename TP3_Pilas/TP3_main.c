#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP3_pilas.h"
#include "pilas.h"
#include "tipo_elemento.h"

int vaciar_buffer(void)
{
    char nada[200];
    fgets(nada, 200, stdin);
    return 0;
}

void pausa()
{
    printf(ANSI_YELLOW "\npresiones ENTER para continuar...." ANSI_RESET);
    getchar();
}

void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

// PUNTO 2A
void main_buscar_clave(){
    Pila pila = p_crear();
    int cant,valor,clave;
    bool rta;
    printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar [0-99]: "ANSI_RESET);
    int validador = scanf("%d",&cant);
    vaciar_buffer();
    while (validador != 1 || cant<0 || cant>=100){
        limpiar_pantalla();
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingrasar un numero entre [0-99]\n\n"ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar: "ANSI_RESET);
        validador = scanf("%d",&cant);
        vaciar_buffer();
        
    }
    
    for (int i=0;i<cant;i++){
        printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
        validador = scanf("%d",&valor);
        vaciar_buffer();
        while(validador!=1 || valor<-999999 || valor>999999){
            limpiar_pantalla();
            printf(ANSI_RED"\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
            validador = scanf("%d",&valor); 
            vaciar_buffer();
            
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila,elemento);
        limpiar_pantalla();
    }
    printf(ANSI_bGREEN"");
    p_mostrar(pila);
    printf("\n"ANSI_RESET);
    printf(ANSI_bBLUE"ingrese clave a buscar en la pila: "ANSI_RESET);
    validador = scanf("%d",&clave);
    vaciar_buffer();
    while(validador!=1 || clave<-999999 || clave>999999){
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE"ingrese clave a buscar en la pila: "ANSI_RESET);
        validador = scanf("%d",&clave); 
        vaciar_buffer();
    }

    rta = buscar_c(pila,clave);
    if(rta == true){
        printf(ANSI_bGREEN"La clave fue enconrtada en la pila\n"ANSI_RESET);
    } 

    else{
        printf(ANSI_RED"La clave no fue enconrtada en la pila\n"ANSI_RESET);
    }

    printf(ANSI_bGREEN"");
    p_mostrar(pila);
    printf("\n"ANSI_RESET);

    pausa();
    limpiar_pantalla();
}

// PUNTO 2C
void main_eliminar_por_clave(){
    Pila pila = p_crear();
    int cant,valor,clave;
    printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar [0-99]: "ANSI_RESET);
    int validador = scanf("%d",&cant);
    vaciar_buffer();
    while (validador != 1 || cant<0 || cant>=100){
        limpiar_pantalla();
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingrasar un numero entre [0-99]\n\n"ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar: "ANSI_RESET);
        validador = scanf("%d",&cant);
        vaciar_buffer();
        
    }
    
    for (int i=0;i<cant;i++){
        printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
        validador = scanf("%d",&valor);
        vaciar_buffer();
        while(validador!=1 || valor<-999999 || valor>999999){
            limpiar_pantalla();
            printf(ANSI_RED"\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
            validador = scanf("%d",&valor); 
            vaciar_buffer();
            
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila,elemento);
        limpiar_pantalla();
    }
    printf(ANSI_bGREEN"");
    p_mostrar(pila);
    printf("\n"ANSI_RESET);

    printf(ANSI_bBLUE"ingrese clave a eliminar en la pila: "ANSI_RESET);
    validador = scanf("%d",&clave);
    vaciar_buffer();
    while(validador!=1 || clave<-999999 || clave>999999){
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE"ingrese clave a eliminar en la pila: "ANSI_RESET);
        validador = scanf("%d",&clave); 
        vaciar_buffer();
    }
    
    pila = eliminar_por_clave(pila,clave);

    printf(ANSI_bGREEN"");
    p_mostrar(pila);
    printf("\n"ANSI_RESET);
    pausa();
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
        while (opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            while (getchar() != '\n')
                ;
            scanf("%i", &opcion);
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
                    main_buscar_clave();
                    getch();
                    break;
                case 2:

                    getch();
                    break;
                case 3:
                    main_eliminar_por_clave();
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