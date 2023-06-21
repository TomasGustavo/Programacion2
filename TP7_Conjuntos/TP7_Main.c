#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP7_Conjuntos.h"

/// @brief Main punto 2
void main_punto2()
{
    int validador, clave;
    Conjunto Cinterseccion, Cunion, Cdiferencia;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    printf(ANSI_bMAGENTA "Carga del conjunto A\n");
    A = cargarConjunto();
    printf(ANSI_bMAGENTA "Carga del conjunto B\n");
    B = cargarConjunto();
    printf(ANSI_bMAGENTA "Ingrese una clave: \n");
        validador = scanf("%d", &clave);
        while ((validador != 1) || (clave < -10000) || (clave >= 10000))
        {
            printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
            printf(ANSI_bBLUE "Ingrese una clave: " ANSI_YELLOW);
            vaciar_buffer();
            validador = scanf("%d", &clave);
        }

    int cardA = cto_cantidad_elementos(A);
    int cardB = cto_cantidad_elementos(B);

    bool perteneceA = false;
    bool perteneceB = false;


    if (cardA == 0 && cardB == 0)
    {
        printf(ANSI_bMAGENTA "\nLos conjuntos estan vacíos\n");
    }
    else
    {
        limpiar_pantalla();
        printf(ANSI_bMAGENTA "CONJUNTO A\n" ANSI_bYELLOW);
        cto_mostrar(A);
        printf(ANSI_bMAGENTA "CONJUNTO B\n" ANSI_bYELLOW);
        cto_mostrar(B);
        Cinterseccion = p2_interseccion(A, B);
        Cdiferencia = p2_diferencia(A, B);
        Cunion = p2_union(A, B);
        printf(ANSI_bMAGENTA "Intersección: \n" ANSI_bBLUE);
        cto_mostrar(Cinterseccion);
        printf(ANSI_bMAGENTA "Diferencia de A con B: \n" ANSI_bBLUE);
        cto_mostrar(Cdiferencia);
        printf(ANSI_bMAGENTA "Diferencia de B con A: \n" ANSI_bBLUE);
        Cdiferencia = p2_diferencia(B, A);
        cto_mostrar(Cdiferencia);
        printf(ANSI_bMAGENTA "Unión: \n" ANSI_bBLUE);
        cto_mostrar(Cunion);
        printf(ANSI_bMAGENTA "Pertenencia: \n" ANSI_bBLUE);
        perteneceA = p2_perteneceClave(A, clave);
        perteneceB = p2_perteneceClave(B, clave);
        if (perteneceA && perteneceB) printf(ANSI_bGREEN "La clave pertenece a ambos conjuntos");
        else if (perteneceA) printf(ANSI_bGREEN "La clave pertenece al conjunto A");
        else if (perteneceB) printf(ANSI_bGREEN "La clave pertenece al conjunto B");
        else printf(ANSI_bRED "La clave no pertenece a ningun conjunto");
    }
    vaciar_buffer();
    pausa();
    limpiar_pantalla();
}

void main_punto3()
{
    const int MIN = 2;
    const int MAX = 10;
    int cant_c;
    Lista lista_c = l_crear();
    Conjunto C = cto_crear();
    Conjunto C2 = cto_crear();
    printf("Cuantos conjuntos desea cargar? entre [2 - 10]: ");
    int validador = scanf("%d", &cant_c);
    vaciar_buffer();
    while (validador != 1 || cant_c < MIN || cant_c > MAX)
    {
        printf("----- ERROR -----");
        printf("DATO fuera de rango, ingrese una cantidad entre 2 y 10: ");
        validador = scanf("%d", &cant_c);
        vaciar_buffer();
    }
    for (int i = 0; i < cant_c; i++)
    {
        Conjunto conjunto = cto_crear();
        conjunto = cargarConjunto();
        TipoElemento x = te_crear_con_valor(i, conjunto);
        l_agregar(lista_c, x);
    }

    C = p3_union(lista_c);
    cto_mostrar(C);
    C2 = p3_interseccion(lista_c);
    cto_mostrar(C2);
    vaciar_buffer();
    pausa();
    limpiar_pantalla();
}

void main_punto5()
{
    Conjunto Cdiferencia;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    printf(ANSI_bMAGENTA "Carga del conjunto A\n");
    A = cargarConjunto();
    printf(ANSI_bMAGENTA "Carga del conjunto B\n");
    B = cargarConjunto();

    int cardA = cto_cantidad_elementos(A);
    int cardB = cto_cantidad_elementos(B);

    if (cardA == 0 && cardB == 0)
    {
        printf(ANSI_bMAGENTA "\nLos conjuntos estan vacíos\n");
    }
    else
    {
        limpiar_pantalla();
        printf(ANSI_bMAGENTA "CONJUNTO A\n" ANSI_bYELLOW);
        cto_mostrar(A);
        printf(ANSI_bMAGENTA "CONJUNTO B\n" ANSI_bYELLOW);
        cto_mostrar(B);
        printf(ANSI_bMAGENTA "Diferencia simétrica: \n" ANSI_bBLUE);
        Cdiferencia = diferencia_simetrica(A, B);
        cto_mostrar(Cdiferencia);
    }
    vaciar_buffer();
    pausa();
    limpiar_pantalla();
}

void main_punto6()
{
    Conjunto Cdiferencia;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    bool AsubB, BsubA;
    printf(ANSI_bMAGENTA "Carga del conjunto A\n");
    A = cargarConjuntoPositivos();
    printf(ANSI_bMAGENTA "Carga del conjunto B\n");
    B = cargarConjuntoPositivos();

    int cardA = cto_cantidad_elementos(A);
    int cardB = cto_cantidad_elementos(B);

    if (cardA == 0 && cardB == 0)
    {
        printf(ANSI_bMAGENTA "\nLos conjuntos estan vacíos\n");
    }
    else
    {
        limpiar_pantalla();
        printf(ANSI_bMAGENTA "CONJUNTO A\n" ANSI_bYELLOW);
        cto_mostrar(A);
        printf(ANSI_bMAGENTA "CONJUNTO B\n" ANSI_bYELLOW);
        cto_mostrar(B);
        AsubB = esSubconjunto(A, B);
        BsubA = esSubconjunto(B, A);
        if (AsubB && BsubA)
        {
            printf(ANSI_RED "No son subconjuntos propios porque son iguales\n" ANSI_bBLUE);
        }
        else if (AsubB)
        {
            printf(ANSI_bGREEN "A es subconjunto propio de B\n" ANSI_bBLUE);
        }
        else if (BsubA)
        {
            printf(ANSI_bGREEN "B es subconjunto propio de A\n" ANSI_bBLUE);
        }
        else
        {
            printf(ANSI_RED "Ninguno es subconjunto propio del otro\n" ANSI_bBLUE);
        }
    }
    printf(ANSI_bMAGENTA "\nLa complejidad algorítmica utilizando la implementación de Arboles AVL seria O(n * log n) ya que el 'cto_recuperar' es O(n) y el 'cto_pertenece' es O(log n), resultado en Orden lineal * logaritmo, que su vez se repite n veces por el while que depende de la cantidad de elementos del subconjunto.\n\nLa complejidad algorítmica utilizando la implementación de listas seria O(n^2) ya que 'cto_recuperar' es O(n) y el 'cto_pertenece' O(n) que su vez se repite n veces por el while que depende de la cantidad de elementos del subconjunto.\n" ANSI_bBLUE);
    vaciar_buffer();
    pausa();
    limpiar_pantalla();
}

void main_punto7()
{
    Conjunto Cdiferencia;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();
    printf(ANSI_bMAGENTA "Carga del conjunto A\n");
    A = cargarConjunto();
    printf(ANSI_bMAGENTA "Carga del conjunto B\n");
    B = cargarConjunto();
    printf(ANSI_bMAGENTA "Carga del conjunto C\n");
    C = cargarConjunto();

    int cardA = cto_cantidad_elementos(A);
    int cardB = cto_cantidad_elementos(B);
    int cardC = cto_cantidad_elementos(C);

    if (cardA == 0 && cardB == 0 && cardC == 0)
    {
        printf(ANSI_bMAGENTA "\nLos conjuntos estan vacíos\n");
    }
    else
    {
        limpiar_pantalla();
        printf(ANSI_bMAGENTA "CONJUNTO A\n" ANSI_bYELLOW);
        cto_mostrar(A);
        printf(ANSI_bMAGENTA "CONJUNTO B\n" ANSI_bYELLOW);
        cto_mostrar(B);
        printf(ANSI_bMAGENTA "CONJUNTO C\n" ANSI_bYELLOW);
        cto_mostrar(C);
        if (esSubconjunto(A, B))
            printf(ANSI_bMAGENTA "A es subconjunto total de B\n");
        else if (esSubconjuntoParcial(A, B))
            printf(ANSI_bMAGENTA "A es subconjunto parcial de B\n");

        if (esSubconjunto(A, C))
            printf(ANSI_bMAGENTA "A es subconjunto total de C\n");
        else if (esSubconjuntoParcial(A, C))
            printf(ANSI_bMAGENTA "A es subconjunto parcial de C\n");

        if (esSubconjunto(B, A))
            printf(ANSI_bMAGENTA "B es subconjunto total de A\n");
        else if (esSubconjuntoParcial(B, A))
            printf(ANSI_bMAGENTA "B es subconjunto parcial de A\n");

        if (esSubconjunto(B, C))
            printf(ANSI_bMAGENTA "B es subconjunto total de C\n");
        else if (esSubconjuntoParcial(B, C))
            printf(ANSI_bMAGENTA "B es subconjunto parcial de C\n");

        if (esSubconjunto(C, A))
            printf(ANSI_bMAGENTA "C es subconjunto total de A\n");
        else if (esSubconjuntoParcial(C, A))
            printf(ANSI_bMAGENTA "C es subconjunto parcial de A\n");

        if (esSubconjunto(C, B))
            printf(ANSI_bMAGENTA "C es subconjunto total de B\n");
        else if (esSubconjuntoParcial(C, B))
            printf(ANSI_bMAGENTA "C es subconjunto parcial de B\n");
    }
    printf(ANSI_bMAGENTA "\nLa complejidad algorítmica infiere de la misma manera ya sea para 'esSubconjunto' como para 'esSubconjuntoParcial; utilizando la implementación de Arboles AVL seria O(n * log n) ya que el 'cto_recuperar' es O(n) y el 'cto_pertenece' es O(log n), resultado en Orden lineal * logaritmo, que su vez se repite n veces por el while que depende de la cantidad de elementos del subconjunto. Estos procesos se repiten 6 veces, lo cual no aumenta el nivel de complejidad.\n\nLa complejidad algorítmica infiere de la misma manera ya sea para 'esSubconjunto' como para 'esSubconjuntoParcial; utilizando la implementación de listas seria O(n^2) ya que 'cto_recuperar' es O(n) y el 'cto_pertenece' O(n) que su vez se repite n veces por el while que depende de la cantidad de elementos del subconjunto. Estos procesos se repiten 6 veces, lo cual no aumenta el nivel de complejidad.\n" ANSI_bBLUE);
    vaciar_buffer();
    pausa();
    limpiar_pantalla();
}

void main_punto4()
{
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();
    int rta;

    printf(ANSI_bRED "\n\n\t----- Atención -----\n\n");
    printf(ANSI_bMAGENTA "Los conjuntos se cargaran en orden, esto quiere decir que para demostrar la transitividad primero se cargara el conjunto A, luego el conjunto B y por ultimo el C, TENER ESTO EN CUENTA!\n");
    pausa();
    limpiar_pantalla();
    printf(ANSI_bMAGENTA "Carga del primer conjunto\n");
    A = cargarConjunto();
    vaciar_buffer();
    printf(ANSI_bMAGENTA "Carga del segundo conjunto\n");
    B = cargarConjunto();
    vaciar_buffer();
    printf(ANSI_bMAGENTA "Carga del tercer conjunto\n");
    C = cargarConjunto();
    vaciar_buffer();

    rta = transitividad(A, B, C);
    switch (rta)
    {
    case 0:
        printf(ANSI_bGREEN "\n\n\tA es subConjunto de B y B es subconjunto de C, por lo tanto A es subconjunto de C");
        break;
    case 1:
        printf(ANSI_bRED "\n\n\tA es subConjunto de B pero B NO es subconjunto de C, por lo tanto A NO es subconjunto de C");
        break;
    case 2:
        printf(ANSI_bGREEN "\n\n\tA No es subConjunto de B, por lo tanto no cumple con la regla de transitividad por mas que B sea subconjunto de C");
        break;
    default:
        break;
    }
    pausa();
}

void main_punto8()
{
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    bool iguales;

    printf(ANSI_bMAGENTA "Carga del primer conjunto\n");
    A = cargarConjunto();
    vaciar_buffer();
    printf(ANSI_bMAGENTA "Carga del segundo conjunto\n");
    B = cargarConjunto();
    vaciar_buffer();

    if (cto_cantidad_elementos(A) != cto_cantidad_elementos(B))
    {
        printf(ANSI_RED "\n\nLos conjuntos NO son iguales pues no tiene el mismo tamaño uno del otro!\n");
    }
    else
    {
        iguales = conjuntos_iguales(A, B);
        if (iguales == true)
        {
            printf(ANSI_bGREEN "\n\nEl conjunto A es igual al B y viceversa!\n");
        }
        else
        {
            printf(ANSI_bRED "\n\nLos conjuntos son distintos!\n");
        }
    }
    printf(ANSI_bMAGENTA "\nLa complejidad algorítmica utilizando la implementación de Arboles AVL seria O(n * log n) ya que el 'cto_recuperar' es O(n) y el 'cto_pertenece' es O(log n), resultado en Orden lineal * logaritmo, que su vez se repite n veces por el while que depende de la cantidad de elementos del subconjunto.\n\nLa complejidad algorítmica utilizando la implementación de listas seria O(n^2) ya que 'cto_recuperar' es O(n) y el 'cto_pertenece' O(n) que su vez se repite n veces por el while que depende de la cantidad de elementos del subconjunto.\n" ANSI_bBLUE);
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
            main_punto5();
            break;
        case 6:
            main_punto6();
            break;
        case 7:
            main_punto7();
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