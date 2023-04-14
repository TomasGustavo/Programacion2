#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "TP2_Listas.h"
#include "listas.h"
#include "tipo_elemento.h"

// PUNTO 2A
void main_menor(){
    int men, rta;
    int * punteroMenor;
   // punteroMenor = &men;
    Lista l = cargarListaClaves();
    if (!l_es_vacia(l)) l_mostrarLista(l);
    
    if (!l_es_vacia(l)){
        rta = menor(l, punteroMenor);
        printf("El menor es %d en la posicion: %d\n", rta, *punteroMenor);
    } else printf("Noy hay menor porque la lista es vacia");
   
}

// PUNTO 2B
void main_mayor(){
    int repeticiones, rta;
    int * punteroMayor;
    //punteroMayor = &repeticiones;
    Lista l = cargarListaClaves();
    if (!l_es_vacia(l)) l_mostrarLista(l);
    
    if (!l_es_vacia(l)){
        rta = mayor(l, punteroMayor);
        printf("El mayor es %d y se repite %d veces\n", rta, *punteroMayor);
    } else printf("Noy hay mayor porque la lista es vacia");
   
}

// PUNTO 2C
void main_promedio(){
    float prom;
    Lista l = cargarListaClaves();
    if (!l_es_vacia(l)) l_mostrarLista(l);
    
    if (!l_es_vacia(l)){
        prom = promedio(l,0,0);
        printf("El promedio es %.3f\n", prom);
    } else printf("Noy hay promedio porque la lista es vacia");
}

// PUNTO 2D
void main_multiplos(){
    int n, validador;
    Lista l = cargarListaClaves();
    if (!l_es_vacia(l)) l_mostrarLista(l);
    
    printf("Ingrese un numero n (los decimales seran truncados): ");
    fflush(stdin); 
    validador = scanf("%d", &n);

    while ((validador != 1) || (n <= -10000) || (n >= 10000)){
        printf(ANSI_RED "Entrada invalida\n");
        printf(ANSI_BLUE "Ingrese un numero (se truncara si coloca decimales): ");
        while (getchar() != '\n');
        validador = scanf("%i", &n);
    }


    if (!l_es_vacia(l)){
        Lista resultado = multiplos(l,n);
        if (l_es_vacia(resultado)) printf("No hay multiplos para mostrar");
        else l_mostrarLista(resultado);
    } else printf("Noy hay multiplos porque la lista es vacia");
}


// PUNTO 3
void main_multiplo(){
    int escalar;
    bool rta;
    int * punteroEscalar;
    punteroEscalar = &escalar;
    
    printf(ANSI_bMAGENTA "Carga de lista 1\n");
    Lista l1 = cargarListaClaves();
       if (!l_es_vacia(l1)) l_mostrarLista(l1);
    
    printf(ANSI_bMAGENTA "Carga de lista 2\n");
    Lista l2 = cargarListaClaves();
       if (!l_es_vacia(l2)) l_mostrarLista(l2);

    if (l_es_vacia(l1) && l_es_vacia(l2)){
        printf(ANSI_RED "No es multiplo ya que son vacias");
    } else {
        rta = esMultiplo(l1, l2, punteroEscalar);
        if (rta == true) printf(ANSI_bGREEN "Es multiplo ");
        else printf(ANSI_RED "No es multiplo");

        if (rta == true && *punteroEscalar != 0) printf("y el escalar es %d", *punteroEscalar);
    }
    
}

//PUNTO 6
void main_sublista(){
    bool rta;
    
    printf(ANSI_bMAGENTA "Carga de lista 1\n");
    Lista l1 = cargarListaClaves();
       if (!l_es_vacia(l1)) l_mostrarLista(l1);
    
    printf(ANSI_bMAGENTA "Carga de lista 2\n");
    Lista l2 = cargarListaClaves();
       if (!l_es_vacia(l2)) l_mostrarLista(l2);

    
    rta = sublista(l1, l2);
    if (rta == true) printf(ANSI_bGREEN "La segunda lista es sublista de la primera");
    else printf(ANSI_RED "La segunda lista no es sublista de la primera");

}


void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 TP2 LISTAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con listas\n");
    printf("  3   Múltiplo\n");
    printf("  4   Comparar 2 listas\n");
    printf("  5   Polinomio\n");
    printf("  6   Sublista\n");
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
    printf(" |                                 TP2 LISTAS                                |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Menor de los datos\n");
    printf("  2   Mayor de los datos\n");
    printf("  3   Promedio\n");
    printf("  4   Lista de multiplos\n");;
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
        while (opcion < 0 || opcion > 6 || opcion == 1)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            while (getchar() != '\n');
            scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 2:
             while (!salir1)
            {
                menu_punto2();
                scanf("%i", &opcion);
                while (opcion < 0 || opcion > 4)
                {
                    printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
                    printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
                    while (getchar() != '\n');
                    scanf("%i", &opcion);
                }
                switch (opcion)
                {
                case 1:
                    main_menor();
                    getch();
                    break;
                case 2:
                    main_mayor();
                    getch();
                    break;
                case 3:
                    main_promedio();
                    getch();
                    break;
                case 4:
                    main_multiplos();
                    getch();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            main_multiplo();
            getch();
            break;
        case 4:
            //main_comparar();
            getch();
            break;
        case 5:
            //main_polinomio();
            getch();
            break;
        case 6:
            main_sublista();
            getch();
            break;
        case 7:
            salir = true;
            break;
        }
    }
    return 0;
}