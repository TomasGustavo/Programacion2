#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "TP2_Listas.h"
#include "listas.h"
#include "tipo_elemento.h"

int vaciar_buffer(void)
{
    char nada[200];
    fgets(nada, 200, stdin);
    return 0;
}

// PUNTO 2A
void main_menor()
{
    int rta;
    int *punteroMenor = calloc(1,sizeof(int));
    
    // punteroMenor = &men;
    Lista l = cargarListaClaves();
    if (!l_es_vacia(l))
        l_mostrarLista(l);

    if (!l_es_vacia(l))
    {
        rta = menor(l, punteroMenor);
        printf("El menor es %d en la posición: %d\n", rta, *punteroMenor);
    }
    else
        printf("Noy hay menor porque la lista es vacía");
}

// PUNTO 2B
void main_mayor()
{
    int rta;
    int *repeticiones = calloc(1,sizeof(int));
    // punteroMayor = &repeticiones;
    Lista l = cargarListaClaves();
    if (!l_es_vacia(l))
        l_mostrarLista(l);

    if (!l_es_vacia(l))
    {
        rta = mayor(l, repeticiones);
        printf("El mayor es %d y se repite %d veces\n", rta, *repeticiones);
    }
    else
        printf("Noy hay mayor porque la lista es vacía");
}

// PUNTO 2C
void main_promedio()
{
    float prom;
    Lista l = cargarListaClaves();
    if (!l_es_vacia(l))
        l_mostrarLista(l);

    if (!l_es_vacia(l))
    {
        prom = promedio(l, 0, 0);
        printf("El promedio es %.3f\n", prom);
    }
    else
        printf("Noy hay promedio porque la lista es vacía");
}

// PUNTO 2D
void main_multiplos()
{
    int n, validador;
    Lista l = cargarListaClaves();
    if (!l_es_vacia(l))
        l_mostrarLista(l);
    printf("Ingrese un numero n (los decimales serán truncados): ");
    fflush(stdin);
    validador = scanf("%d", &n);
    while ((validador != 1) || (n <= -10000) || (n >= 10000))
    {
        printf(ANSI_RED "Entrada invalida\n");
        printf(ANSI_BLUE "Ingrese un numero (se truncara si coloca decimales): ");
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }
    if (!l_es_vacia(l))
    {
        Lista resultado = multiplos(l, n);
        if (l_es_vacia(resultado))
            printf("No hay múltiplos para mostrar");
        else
            l_mostrarLista(resultado);
    }
    else
        printf("Noy hay múltiplos porque la lista es vacía");
}

// PUNTO 3
void main_multiplo()
{
    int escalar;
    bool rta;
    int *punteroEscalar;
    punteroEscalar = &escalar;
    printf(ANSI_bMAGENTA "Carga de lista 1\n");
    Lista l1 = cargarListaClaves();
    if (!l_es_vacia(l1))
        l_mostrarLista(l1);
    printf(ANSI_bMAGENTA "Carga de lista 2\n");
    Lista l2 = cargarListaClaves();
    if (!l_es_vacia(l2))
        l_mostrarLista(l2);
    if (l_es_vacia(l1) && l_es_vacia(l2))
    {
        printf(ANSI_RED "No es múltiplo ya que son vacías");
    }
    else
    {
        rta = esMultiplo(l1, l2, punteroEscalar);
        if (rta == true)
            printf(ANSI_bGREEN "Es múltiplo ");
        else
            printf(ANSI_RED "No es múltiplo");

        if (rta == true && *punteroEscalar != 0)
            printf("y el escalar es %d", *punteroEscalar);
    }
}

// PUNTO 4
void main_comparar()
{
    printf(ANSI_bMAGENTA "Carga de lista 1\n" ANSI_RESET);
    Lista l1 = cargarListaClaves(); // O(n)
    if (!l_es_vacia(l1))
        l_mostrarLista(l1);
    printf(ANSI_bMAGENTA "Carga de lista 2\n" ANSI_RESET);
    Lista l2 = cargarListaClaves(); // O(n)
    if (!l_es_vacia(l1))
        l_mostrarLista(l2); // O(n)
    if (l_longitud(l1) != l_longitud(l2))
    {
        printf(ANSI_RED "------ERROR------\nListas de distintos tamaños.\n" ANSI_RESET);
        return;
    }
    else
    {
        int rta = ComparaListas(l1, l2); // O(n)
        switch (rta)
        {
        case 0:
            printf(ANSI_GREEN "Lista 1 mayor que Lista 2\n" ANSI_RESET);
            getch();
            break;
        case 1:
            printf(ANSI_GREEN "Lista 1 menor que Lista 2\n" ANSI_RESET);
            getch();
            break;
        case 2:
            printf(ANSI_GREEN "Lista 1 igual que Lista 2\n" ANSI_RESET);
            getch();
            break;
        }
    }
}

// PUNTO 6
void main_sublista()
{
    bool rta;
    printf(ANSI_bMAGENTA "Carga de lista 1\n");
    Lista l1 = cargarListaClavesSinRepetir(); // O(n^2)
    if (!l_es_vacia(l1))
        l_mostrarLista(l1); // O(n)
    printf(ANSI_bMAGENTA "Carga de lista 2\n");
    Lista l2 = cargarListaClavesSinRepetir(); // O(n^2)
    if (!l_es_vacia(l2))
        l_mostrarLista(l2); // O(n)
    rta = sublista(l1, l2); // O(n^2)
    if (rta == true)
        printf(ANSI_bGREEN "La segunda lista es sublista de la primera\n");
    else
    {
        printf(ANSI_RED "La segunda lista no es sublista de la primera\n");
        rta = sublista(l2, l1); // O(n^2)
        if (rta == true)
        {
            printf(ANSI_bGREEN "La primera lista es sublista de la segunda\n");
        }
        else
        {
            printf(ANSI_RED "La primera lista tampoco es sublista de la segunda\n");
        }
    }
}

void main_polinomio()
{
    int cant_terminos, exponente, validador, cantidadDeResultados;
    float r_min, r_max, intervalo, coeficiente;
    const int TAMANIO_MAXIMO = 10;
    Lista polinomio, resultado;
    polinomio = l_crear();
    resultado = l_crear();
    printf("\n");
    // VALIDAR DATOS > 0 < TAMANIO_MAXIMO           HECHO =)
    printf(ANSI_BLUE "Ingrese la cantidad de términos del polinomio: " ANSI_YELLOW);
    vaciar_buffer();
    validador = scanf("%d", &cant_terminos);
    while (cant_terminos < 0 || cant_terminos > TAMANIO_MAXIMO || validador != 1)
    {
        printf(ANSI_RED "----ERROR----\nCantidad de términos fuera de rango o caracteres incorrectos. Reingrese datos\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese la cantidad de términos del polinomio: " ANSI_YELLOW);
        vaciar_buffer();
        validador = scanf("%d", &cant_terminos);
    }
    for (int i = 0; i < cant_terminos; i++)
    {
        // VALIDAR DATOS >= -100 <= 100     HECHO =)
        printf(ANSI_BLUE "Ingrese el coeficiente del termino %d: " ANSI_YELLOW, i + 1);
        vaciar_buffer();
        validador = scanf("%f", &coeficiente);
        while (coeficiente < -100 || coeficiente > 100 || validador != 1)
        {
            printf(ANSI_RED "----ERROR----\nCantidad de términos fuera de rango o caracteres incorrectos. Reingrese coeficiente\n" ANSI_RESET);
            printf(ANSI_BLUE "Ingrese el coeficiente del termino %d: " ANSI_YELLOW, i + 1);
            vaciar_buffer();
            validador = scanf("%f", &coeficiente);
        }

        // VALIDAR DATOS >= 0 <= 10         HECHO =)
        printf(ANSI_BLUE "Ingrese el exponente del termino %d: " ANSI_YELLOW, i + 1);
        vaciar_buffer();
        validador = scanf("%d", &exponente);
        while (exponente < 0 || exponente > 10 || validador != 1)
        {
            printf(ANSI_RED "----ERROR----\nCantidad de términos fuera de rango o caracteres incorrectos. Reingrese exponente\n" ANSI_RESET);
            printf(ANSI_BLUE "Ingrese el exponente del termino %d: " ANSI_YELLOW, i + 1);
            vaciar_buffer();
            validador = scanf("%d", &exponente);
        }
        // VALIDAR QUE LA LISTA NO ESTE LLENA           HECHO =)
        if (l_es_llena(polinomio))
        {
            printf(ANSI_RED "LISTA LLENA" ANSI_RESET);
            break;
        }
        else
        {
            agregarTermino(polinomio, exponente, coeficiente);
        }
    }

    printf(ANSI_GREEN "Lista cargada con éxito!\n");
    printf("\n");
    // VALIDAR DATOS         HECHO =)
    printf(ANSI_BLUE "Ingrese el rango mínimo: " ANSI_YELLOW);
    vaciar_buffer();
    validador = scanf("%f", &r_min);
    while (r_min < -100 || r_min > 100 || validador != 1)
    {
        printf(ANSI_RED "----ERROR----\n");
        if (r_min < -100 || r_min > 100)
        {
            printf("El valor de rango min tiene que ser entre [-100;100] \n" ANSI_RESET);
        }
        else
        {
            printf("DATO invalido, tiene que ser un numero, ingrese dato nuevamente: \n" ANSI_RESET);
        }
        printf(ANSI_BLUE "Ingrese el rango mínimo: " ANSI_YELLOW);
        vaciar_buffer();
        validador = scanf("%f", &r_min);
    }
    // VALIDAR DATOS > r_min            HECHO =)
    printf(ANSI_BLUE "Ingrese el rango máximo: " ANSI_YELLOW);
    vaciar_buffer();
    validador = scanf("%f", &r_max);
    while (r_max < r_min || validador != 1)
    {
        printf(ANSI_RED "----ERROR----\n");
        if (r_max < r_min)
        {
            printf("El valor de rango máximo tiene que ser mayor o igual que el rango mínimo \n" ANSI_RESET);
        }
        else
        {
            printf("DATO invalido, tiene que ser un numero, ingrese dato nuevamente: \n" ANSI_RESET);
        }
        printf(ANSI_BLUE "Ingrese el rango máximo: " ANSI_YELLOW);
        vaciar_buffer();
        validador = scanf("%f", &r_max);
    }
    // VALIDAR DATOS >= 0           HECHO =)
    printf(ANSI_BLUE "Ingrese el valor de intervalo: " ANSI_YELLOW);
    vaciar_buffer();
    validador = scanf("%f", &intervalo);
    while (intervalo <= 0 || validador != 1)
    {
        printf(ANSI_RED "----ERROR----\n");
        if (intervalo <= 0)
        {
            printf("El intervalo tiene que ser mayor que 0, ingrese dato nuevamente: \n" ANSI_RESET);
        }
        else
        {
            printf("DATO invalido, tiene que ser mayor que 0, ingrese dato nuevamente: \n" ANSI_RESET);
        }
        printf(ANSI_BLUE "Ingrese el valor de intervalo: " ANSI_YELLOW);
        vaciar_buffer();
        validador = scanf("%f", &intervalo);
    }
    cantidadDeResultados = ((r_max - r_min) / intervalo) + 1;
    if (cantidadDeResultados > 100)
    {
        printf(ANSI_RED "La cantidad de resultados dentro del rango es mayor a 100. Se mostraran los primeros 100.");
    }
    resultado = rango(polinomio, r_min, r_max, intervalo);
    printf("\n");
    mostrar_polinomio(resultado);
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
    printf(" |                         2   Operaciones con listas                         |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Menor de los datos\n");
    printf("  2   Mayor de los datos\n");
    printf("  3   Promedio\n");
    printf("  4   Lista de múltiplos\n");
    ;
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
                while (opcion < 0 || opcion > 4)
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
            main_comparar();
            getch();
            break;
        case 5:
            main_polinomio();
            getch();
            break;
        case 6:
            main_sublista();
            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}