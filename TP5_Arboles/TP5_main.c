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

/// @brief Menu principal del TP de Arboles
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

/// @brief Menu del Punto 4
void menu_punto4()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                     4   Operaciones con un arbol n-ario                     |\n");
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

/// @brief PUNTO 2A: Retornar una lista con todos los nodos terminales u hojas.
void main_hojas()
{
    ArbolBinario A;
    A = a_crear();
    cargar_arbol_binario(A);
    hojas(A);
    vaciar_buffer();
    pausa();
    limpiar_pantalla();
}

/// @brief PUNTO 2B: Retornar en una estructura todos los nodos interiores (los que no son ni hojas ni raíz).
void main_interior()
{
    ArbolBinario A;
    Lista L;
    A = a_crear();
    L = l_crear();
    cargar_arbol_binario(A);
    L = nodos_interiores(A);
    vaciar_buffer();
    printf(ANSI_bGREEN "Nodos interiores: \n");
    l_mostrarLista(L);
    if (l_es_vacia(L))
    {
        printf("La lista esta vacia");
    }
    printf(ANSI_RESET);
    pausa();
    limpiar_pantalla();
}

/// @brief Punto 2C: Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la posición de cada ocurrencia (puntero al nodo).
void main_buscar()
{
    ArbolBinario A;
    Lista L;
    int clave, validador;
    A = a_crear();
    L = l_crear();
    cargar_arbol_binario(A);
    if (!a_es_vacio(A))
    {
        printf(ANSI_bMAGENTA "Ingrese el elemento a buscar [-999.999 - 999.999]: " ANSI_YELLOW);
        validador = scanf("%d", &clave);
        vaciar_buffer();
        while (validador != 1 || clave < -999999 || clave > 999999)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bBLUE "Ingrese el elemento a buscar [-999.999 - 999.999]: " ANSI_YELLOW);
            validador = scanf("%d", &clave);
            vaciar_buffer();
        }
        L = ocurrencias(A, clave);
        printf(ANSI_bGREEN "Posiciones del elemento %d: \n", clave);
        l_mostrarLista_valor(L);
        if (l_es_vacia(L))
        {
            printf(ANSI_bRED "no se encontro el elemento en el arbol\n");
        }
        printf(ANSI_RESET);
        pausa();
        limpiar_pantalla();
    }
}

/// @brief Punto 3
void main_nodo_binario()
{
    ArbolBinario A;
    int validador, clave, nivelNodo;
    NodoArbol N, N1, HI, HD, NHermano, raiz;
    TipoElemento X, XI, XD, XHermano;
    A = a_crear();
    cargar_arbol_binario(A);
    if (!a_es_vacio(A))
    {
        printf(ANSI_bMAGENTA "Ingrese la clave [-999.999 - 999.999]: " ANSI_YELLOW);
        validador = scanf("%d", &clave);
        vaciar_buffer();
        while (validador != 1 || clave < -999999 || clave > 999999)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bBLUE "Ingrese la clave [-999.999 - 999.999]: " ANSI_YELLOW);
            validador = scanf("%d", &clave);
            vaciar_buffer();
        }
        if (existe_nodo(A, clave))
        {
            // PUNTO 3A: Indicar el nombre del nodo padre.
            N = nodo_padre(A, clave);
            X = n_recuperar(N);
            printf(ANSI_bMAGENTA "\nNodo padre: %i", X->clave);

            // PUNTO 3B: Listar los hijos
            N1 = devolver_nodo(A, clave);
            HI = n_hijoizquierdo(N1);
            HD = n_hijoderecho(N1);
            printf(ANSI_bMAGENTA "\nHijos: ");
            if (HI != NULL)
            {
                XI = n_recuperar(HI);
                printf(ANSI_bMAGENTA "%i (Hijo izquierdo) ", XI->clave);
            }
            else
                printf(ANSI_bMAGENTA "Hijo izquierdo nulo ");
            if (HD != NULL)
            {
                XD = n_recuperar(HD);
                printf(ANSI_bMAGENTA "%i (Hijo derecho) ", XD->clave);
            }
            else
                printf(ANSI_bMAGENTA "Hijo derecho nulo");

            // PUNTO 3C: Listar el hermano
            printf(ANSI_bMAGENTA "\nHermano: " ANSI_YELLOW);
            NHermano = nodo_hermano(A, clave);
            if (NHermano == NULL)
                printf(ANSI_bMAGENTA "Hhermano nulo");
            else
            {
                XHermano = n_recuperar(NHermano);
                printf(ANSI_bMAGENTA "%i", XHermano->clave);
            }
            // PUNTO 3D: Calcular el nivel en el que se encuentra.
            nivelNodo = nivel(A, clave);
            printf(ANSI_bMAGENTA "\nNivel: %i", nivelNodo);

            // PUNTO 3E: Calcular la altura de su rama
            printf(ANSI_bMAGENTA "\nAltura: %i" ANSI_YELLOW, nodo_altura(N1));

            // PUNTO 3F: Listar todos los nodos que están en el mismo nivel
            printf(ANSI_bMAGENTA "\nNodos del mismo nivel: " ANSI_YELLOW);
        }
        else
        {
            printf(ANSI_bMAGENTA "\nNo se ha encontrado la clave en el arbol" ANSI_YELLOW);
        }
    }
    else
    {
        printf(ANSI_bMAGENTA "\nEl arbol esta vacio" ANSI_YELLOW);
    }
    printf(ANSI_RESET);
    pausa();
    limpiar_pantalla();
}

void main_cantidad_hojas(){
    ArbolBinario A;
    int clave, cantidadHojas;
    A = a_crear();
    cargar_arbol_binario(A);
    if (!a_es_vacio(A)) printf(ANSI_bMAGENTA "\n El arbol esta vacio");
    else {
        cantidadHojas = hojas_nario(A);
        printf(ANSI_bMAGENTA "\n La cantidad de hojas del arbol es %i", cantidadHojas);
    }
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
                    main_hojas();
                    break;
                case 2:
                    main_interior();
                    break;
                case 3:
                    main_buscar();
                    break;
                case 0:
                    salir_p2 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            main_nodo_binario();
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
                    break;
                case 2:
                    main_cantidad_hojas();
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 0:
                    salir_p4 = true;
                }
            }
            break;
            menu_principal();
        case 7:
            break;
        case 9:
            break;
        case 10:
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}