#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP7_Conjuntos.h"


/// @brief Main punto 2
void main_punto2(){
    Conjunto Cinterseccion, Cunion, Cdiferencia;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    printf(ANSI_bMAGENTA"Carga del primer conjunto\n");
    A = cargarConjunto();
    printf(ANSI_bMAGENTA"Carga del segundo conjunto\n");
    B = cargarConjunto();

    int cardA = cto_cantidad_elementos(A);
    int cardB = cto_cantidad_elementos(B);

    if (cardA == 0 && cardB == 0){
         printf(ANSI_bMAGENTA"Los conjuntos estan vacios\n");
    } else {
        Cinterseccion = p2_interseccion(A, B);
        Cdiferencia = p2_diferencia(A, B);
        Cunion = p2_union(A,B);
        printf(ANSI_bMAGENTA"Interseccion: \n"ANSI_bBLUE);
        cto_mostrar(Cinterseccion);
        printf(ANSI_bMAGENTA"Diferencia: \n"ANSI_bBLUE);
        cto_mostrar(Cdiferencia);
        printf(ANSI_bMAGENTA"Unión: \n"ANSI_bBLUE);
        cto_mostrar(Cunion);
        printf(ANSI_bMAGENTA"Pertenencia: \n"ANSI_bBLUE);
        vaciar_buffer();
        pausa();
        limpiar_pantalla();
    }
}

void main_punto3(){
    const int MIN = 2;
    const int MAX = 10;
    int cant_c;
    Lista lista_c = l_crear();
    Conjunto C= cto_crear();
    Conjunto C2= cto_crear();
    printf("Cuantos conjuntos desea cargar? entre [2 - 10]: ");
    int validador = scanf("%d",&cant_c);
    vaciar_buffer();
    while (validador != 1 || cant_c < MIN || cant_c > MAX){
        printf("----- ERROR -----");
        printf("DATO fuera de rango, ingrese una cantidad entre 2 y 10: ");
        validador = scanf("%d",&cant_c);
        vaciar_buffer();
    }
    for(int i=0; i<cant_c; i++){
        Conjunto conjunto = cto_crear();
        conjunto = cargarConjunto();
        TipoElemento x = te_crear_con_valor(i,conjunto);
        l_agregar(lista_c,x);
        
    }
    
    C = p3_union(lista_c);
    cto_mostrar(C);
    C2 = p3_interseccion(lista_c);
    cto_mostrar(C2);
    pausa();
}

void main_punto4(){
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();
    int rta;
   
    printf(ANSI_bMAGENTA"Carga del primer conjunto\n");
    A = cargarConjunto();
    vaciar_buffer();
    printf(ANSI_bMAGENTA"Carga del segundo conjunto\n");
    B = cargarConjunto();
    vaciar_buffer();
    printf(ANSI_bMAGENTA"Carga del tercer conjunto\n");
    C = cargarConjunto();
    vaciar_buffer();

    rta = transitividad(A,B,C);
    switch (rta)
    {
    case 0:
        printf(ANSI_bGREEN"\n\n\tA es subConjunto de B y B es subconjunto de C, por lo tanto A es subconjunto de C");
        break;
    case 1:
        printf(ANSI_bRED"\n\n\tA es subConjunto de B pero B NO es subconjunto de C, por lo tanto A NO es subconjunto de C");
        break;
    case 2:
        printf(ANSI_bGREEN"\n\n\tA No es subConjunto de B, por lo tanto no cumple con la regla de transitividad por mas que B sea subconjunto de C");
        break;
    default:
        break;
    }
    pausa();
}

void main_punto8(){
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    bool iguales;
   
    printf(ANSI_bMAGENTA"Carga del primer conjunto\n");
    A = cargarConjunto();
    vaciar_buffer();
    printf(ANSI_bMAGENTA"Carga del segundo conjunto\n");
    B = cargarConjunto();
    vaciar_buffer();

    if (cto_cantidad_elementos(A) != cto_cantidad_elementos(B)){
        printf(ANSI_RED"\n\n\tLos conjuntos NO son iguales pues no tiene el mismo tamaño uno del otro!\n");
    }
    else{
        iguales = conjuntos_iguales(A,B);
        if(iguales==true){
            printf(ANSI_bGREEN"\n\n\tEl conjunto A es igual al B y viceversa!\n");
        }
        else{
            printf(ANSI_bRED"\n\n\tLos conjuntos son distintos!\n");
        }
    }
    pausa();
}


/// @brief Menú principal del TP de conjuntos
void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                               TP6 CONJUNTOS                               |\n");
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
        case 2:
            main_punto2();
            break;
        case 3:
            main_punto3();
            break;
        case 4:
            main_punto4();
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
            main_punto8();
            break;
        case 0:
            salir = true;
            break;
        }
    }

    return 0;
}