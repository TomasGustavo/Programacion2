#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "TP2_Listas.h"
#include "tipo_elemento.h"
#include "listas.h"

struct valoresXY
{
    float X;
    float Y;
};

Lista cargarListaClaves()
{
    int tamano, validador, claveIngresada;
    TipoElemento X;
    Lista L;
    L = l_crear();
    printf("Ingrese la cantidad de elementos de la lista: \n");
    validador = scanf("%i", &tamano);
    while ((validador != 1) || (tamano < 0) || (tamano > 99))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese el tamaño del conjunto [1-99] (se truncara si coloca decimales): " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &tamano);
    }
    if (tamano > 0)
    {
        for (int i = 1; i <= tamano; i++)
        {
            printf(ANSI_bBLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
            validador = scanf("%d", &claveIngresada);
            while ((validador != 1) || (claveIngresada <= -10000) || (claveIngresada >= 10000))
            {
                printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
                printf(ANSI_bBLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
                while (getchar() != '\n')
                    ;
                validador = scanf("%d", &claveIngresada);
            }
            X = te_crear(claveIngresada);
            l_agregar(L, X);
        }
        printf(ANSI_bGREEN "La lista fue cargada con exito \n");
    }
    else
        printf(ANSI_bGREEN "La lista vacia creada \n");
    return L;
}

Lista cargarListaClavesSinRepetir() // O(n^2)
{
    int tamano, validador, claveIngresada;
    TipoElemento X, X1;
    Lista L;
    L = l_crear(); // O(1)
    printf("Ingrese la cantidad de elementos de la lista: \n");
    validador = scanf("%i", &tamano);
    while ((validador != 1) || (tamano < 0) || (tamano > 99))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese el tamaño del conjunto [1-99] (se truncara si coloca decimales): " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &tamano);
    }
    if (tamano > 0)
    {
        for (int i = 1; i <= tamano; i++)
        {
            printf(ANSI_bBLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
            validador = scanf("%d", &claveIngresada);
            X1 = l_buscar(L, claveIngresada); // O(n)
            while ((validador != 1) || (claveIngresada <= -10000) || (claveIngresada >= 10000) ||
                   (X1 != NULL))
            {
                printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
                printf(ANSI_bBLUE "Ingrese un numero (se truncara si coloca decimales y no se aceptan elementos repetidos): " ANSI_YELLOW, i + 1);
                while (getchar() != '\n')
                    ;
                validador = scanf("%d", &claveIngresada);
                X1 = l_buscar(L, claveIngresada); // O(n)
            }
            X = te_crear(claveIngresada);
            l_agregar(L, X); // O(n) en apuntadores y cursores; O(1) en arreglos
        }
        printf(ANSI_bGREEN "La lista fue cargada con exito \n");
    }
    else
        printf(ANSI_bGREEN "La lista vacia creada \n");
    return L;
}

int menor(Lista lista, int *posicion)
{
    TipoElemento x, menor;
    int posActual = 1;
    Iterador ite = iterador(lista);
    menor = siguiente(ite);
    *posicion = posActual;
    posActual++;
    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        if (x->clave < menor->clave)
        {
            menor = x;
            *posicion = posActual;
        }
        posActual++;
    }
    return menor->clave;
}

int mayor(Lista lista, int *repeticiones)
{
    TipoElemento x, mayor;
    Iterador ite = iterador(lista);
    int cantidad = 1;
    mayor = siguiente(ite);
    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        if (x->clave > mayor->clave)
        {
            mayor = x;
            cantidad = 1;
        }
        else if (x->clave == mayor->clave)
        {
            cantidad++;
        }
    }
    *repeticiones = cantidad;
    return mayor->clave;
}

float promedio(Lista l, int i, float suma)
{
    TipoElemento x;
    if (i >= l_longitud(l))
        return suma / i;
    else
    {
        i++;
        x = l_recuperar(l, i);
        suma += x->clave;
        promedio(l, i, suma);
    }
    return suma;
}

Lista multiplos(Lista l, int n)
{
    TipoElemento x, x1;
    Lista nueva = l_crear();
    Iterador ite = iterador(l);
    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        if ((x->clave % n) == 0)
        {
            x1 = x;
            l_agregar(nueva, x1);
        }
    }
    return nueva;
}

bool esMultiplo(Lista l1, Lista l2, int *escalar)
{
    int e = 0;
    TipoElemento x1, x2;
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    bool resultado = true;
    if (l_longitud(l1) != l_longitud(l2))
        resultado = false;
    else
    {
        x1 = siguiente(ite1);
        x2 = siguiente(ite2);
        if ((x1->clave != 0) && (x2->clave % x1->clave == 0))
        {
            e = x2->clave / x1->clave;
            *escalar = e;
        }
        else
            resultado = false;

        while (hay_siguiente(ite1) && resultado == true)
        {
            x1 = siguiente(ite1);
            x2 = siguiente(ite2);
            if ((x1->clave != 0) && (x2->clave % x1->clave == 0))
            {
                if (e != (x2->clave / x1->clave))
                    *escalar = 0;
            }
            else
                resultado = false;
        }
    }
    return resultado;
}

int ComparaListas(Lista l1, Lista l2)
{
    // 0 = l1 mayor; 1 = l1 menor; 2 = iguales;
    int mayor = 0, menor = 0;
    TipoElemento x1, x2;
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    while (hay_siguiente(ite1) && hay_siguiente(ite2)) // O(n)
    {
        x1 = siguiente(ite1);
        x2 = siguiente(ite2);
        if (x1->clave > x2->clave)
        {
            mayor++;
        }
        else if (x1->clave < x2->clave)
        {
            menor++;
        }
    }
    if (mayor > menor)
    {
        return 0;
    }
    else if (mayor < menor)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

bool sublista(Lista l1, Lista l2) // O(n^2)
{
    TipoElemento x1, x2;
    bool resultado = true;

    Iterador ite2 = iterador(l2);
    bool encontro;
    if (l_es_vacia(l2))
        resultado = true;
    else if (l_es_vacia(l1) && l_es_vacia(l2))
        resultado = true;
    else if (l_longitud(l2) > l_longitud(l1))
        resultado = false;
    else
    {
        while (hay_siguiente(ite2) && (resultado == true)) // O(n)
        {
            x2 = siguiente(ite2);
            encontro = false;
            Iterador ite1 = iterador(l1);
            while (hay_siguiente(ite1) && encontro == false) // O(n)
            {
                x1 = siguiente(ite1);
                if (x1->clave == x2->clave)
                    encontro = true;
            }
            if (encontro == false)
                resultado = false;
        }
    }
    return resultado;
}

// AGREGAR TERMINO A LA LISTA
bool agregarTermino(Lista polinomio, int exponente, float coeficiente)
{
    TipoElemento x;
    bool r;
    if (l_es_llena(polinomio))
        r = false;
    else
    {
        void *valor_coeficiente = malloc(sizeof(float));
        *(float *)valor_coeficiente = coeficiente;
        x = te_crear_con_valor(exponente, valor_coeficiente);
        l_agregar(polinomio, x);
        r = true;
    }
    return r;
}

float calcularX(Lista polinomio, float n)
{
    TipoElemento x;
    float suma = 0;
    float coeficiente;
    Iterador ite = iterador(polinomio);
    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        coeficiente = *(float *)x->valor; // Acceder al valor como float
        suma = suma + (coeficiente * pow(n, x->clave));
    }
    return suma;
}

Lista rango(Lista polinomio, float xMin, float xMax, float intervalo)
{
    Lista laux = l_crear();
    TipoElemento x;
    while (xMin <= xMax)
    {
        struct valoresXY *coord = malloc(sizeof(struct valoresXY));
        coord->X = xMin;
        coord->Y = calcularX(polinomio, xMin);
        x = te_crear_con_valor(0, coord);
        l_agregar(laux, x);
        xMin = xMin + intervalo;
    }
    return laux;
}

void mostrar_polinomio(Lista polinomio)
{
    TipoElemento x;
    struct valoresXY *valores;
    Iterador ite = iterador(polinomio);
    printf(ANSI_GREEN "\t  X\t" ANSI_MAGENTA "|   " ANSI_GREEN "  Y\n");
    printf(ANSI_MAGENTA "      __________|_____________\n");
    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        valores = x->valor; // Acceder al valor como struct valoresXY
        printf(ANSI_YELLOW "\t%.2lf\t" ANSI_MAGENTA "|   " ANSI_YELLOW "%.2lf \n", valores->X, valores->Y);
    }
}