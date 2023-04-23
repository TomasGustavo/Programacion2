#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TP3_pilas.h"
#include "pilas.h"
#include "tipo_elemento.h"

void IntToBase(Pila pila, int numero, int base)
{
    TipoElemento x;
    int resto;
    if (numero < base)
    {
        x = te_crear(numero);
        p_apilar(pila, x);
    }
    else
    {
        resto = numero % base;
        x = te_crear(resto);
        numero = numero / base;
        IntToBase(pila, numero, base);
        p_apilar(pila, x);
    }
}

Pila conversor(int numero, int base)
{
    Pila pila = p_crear();
    IntToBase(pila, numero, base);
    return pila;
}

void mostrarhex(Pila pila)
{
    Pila Paux = p_crear();
    TipoElemento X = te_crear(0);
    // Recorro la pila desopilándola y pasándola al auxiliar
    while (p_es_vacia(pila) != true)
    {
        X = p_desapilar(pila);
        printf("%x", X->clave);
        p_apilar(Paux, X);
    }
    // Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
    while (p_es_vacia(Paux) != true)
    {
        X = p_desapilar(Paux);
        p_apilar(pila, X);
    }
}