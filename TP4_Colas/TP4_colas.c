#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TP4_colas.h"
#include "colas.h"
#include "tipo_elemento.h"

int vaciar_buffer(void)
{
    char nada[200];
    fgets(nada, 200, stdin);
    return 0;
}

void pausa()
{
    printf(ANSI_bYELLOW "\nPresione ENTER para continuar...." ANSI_RESET);
    getchar();
}

void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

void intercambiar(Cola c, Cola aux)
{
    TipoElemento x = te_crear(0);
    while (!c_es_vacia(aux))
    {
        x = c_desencolar(aux);
        c_encolar(c, x);
    }
}

// Función genérica para cargar una cola de enteros
Cola cargarCola()
{
    Cola cola = c_crear();
    int cant, valor;
    printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar [0-99]: " ANSI_bYELLOW);
    int validador = scanf("%d", &cant);
    vaciar_buffer();
    while (validador != 1 || cant < 0 || cant >= 100)
    {
        limpiar_pantalla();
        printf(ANSI_bRED "\t\t-------- ERROR --------\n");
        printf("DATO INVALIDO, por favor ingresar un numero entre [0-99]\n\n" ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar [0-99]: " ANSI_bYELLOW);
        validador = scanf("%d", &cant);
        vaciar_buffer();
    }
    for (int i = 0; i < cant; i++)
    {
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999]: " ANSI_bYELLOW, i + 1);
        validador = scanf("%d", &valor);
        vaciar_buffer();
        while (validador != 1 || valor < -999999 || valor > 999999)
        {
            limpiar_pantalla();
            printf(ANSI_bRED "\t\t-------- ERROR --------\n");
            printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999]: " ANSI_bYELLOW, i + 1);
            validador = scanf("%d", &valor);
            vaciar_buffer();
        }
        TipoElemento elemento = te_crear(valor);
        c_encolar(cola, elemento);
    }
    printf(ANSI_bGREEN "");
    c_mostrar(cola); // muestro la pila como quedo cargada
    printf("\n" ANSI_RESET);
    return cola;
}

// PUNTO 2A
bool buscar(Cola c, int clave)
{
    bool res = false;
    Cola caux = c_crear();
    TipoElemento x = te_crear(0);
    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        if (x->clave == clave)
        {
            res = true;
        }
        c_encolar(caux, x);
    }
    intercambiar(c, caux);
    return res;
}

int Longitud(Cola c)
{
    Cola aux = c_crear();
    TipoElemento x = te_crear(0);
    int cont = 0;
    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        cont++;
        c_encolar(aux, x);
    }
    intercambiar(c, aux);
    return cont;
}

// PUNTO 3
bool buscarPos(Cola c, TipoElemento x, int pos)
{
    int cont = 0;
    Cola aux = c_crear();
    TipoElemento x1 = te_crear(0);
    bool bandera = true;
    while (!c_es_vacia(c))
    {
        x1 = c_desencolar(c);
        cont++;
        if (cont == pos)
        {
            if (x1->clave != x->clave)
            {
                bandera = false;
            }
        }
        c_encolar(aux, x1);
    }
    intercambiar(c, aux);
    return bandera;
}

bool Comparar(Cola c1, Cola c2)
{
    Cola caux = c_crear();
    bool bandera = true;
    int pos = 0;
    TipoElemento x1 = te_crear(0);
    if (Longitud(c1) != Longitud(c2))
    {
        return false;
    }
    else
    {
        while (!c_es_vacia(c1))
        {
            x1 = c_desencolar(c1);
            pos++;
            if ((bandera) && (!buscarPos(c2, x1, pos)))
            {
                bandera = false;
            }
            c_encolar(caux, x1);
        }
        intercambiar(c1, caux);
        return bandera;
    }
}

// Punto 4

Cola norepetidos(Cola c)
{
    Cola caux = c_crear(), cresp = c_crear();
    TipoElemento x = te_crear(0);
    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        if (!buscar(c, x->clave))
        {
            if (buscar(caux, x->clave))
            {
                c_encolar(caux, x);
            }
            else
            {
                c_encolar(caux, x);
                c_encolar(cresp, x);
            }
        }
        else
        {
            c_encolar(caux, x);
        }
    }
    intercambiar(c,caux);
    return cresp;
}