#include "pilas.h"
#include "tipo_elemento.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 100;
struct PilaRep
{
    TipoElemento *valores;
    unsigned int tope;
};

Pila p_crear()
{
    Pila nueva_pila = (Pila)malloc(sizeof(struct PilaRep));
    nueva_pila->valores = calloc((TAMANIO_MAXIMO + 1), sizeof(TipoElemento));
    nueva_pila->tope = 0;
    return nueva_pila;
}

void p_apilar(Pila pila, TipoElemento elemento)
{
    if (p_es_llena(pila))
    {
        return;
    }
    pila->tope++;
    pila->valores[pila->tope] = elemento;
}

TipoElemento p_desapilar(Pila pila)
{
    if (p_es_vacia(pila))
    {
        return NULL;
    }
    TipoElemento elemento = pila->valores[pila->tope];
    pila->tope--;
    return elemento;
}

TipoElemento p_tope(Pila pila)
{
    if (p_es_vacia(pila))
    {
        return NULL;
    }
    return pila->valores[pila->tope];
}

bool p_es_vacia(Pila pila)
{
    return (pila->tope <= 0);
}

bool p_es_llena(Pila pila)
{
    return (pila->tope == TAMANIO_MAXIMO);
}

void p_mostrar(Pila pila)
{
    if (p_es_vacia(pila))
    {
        printf("La pila esta vacía\n");
        return;
    }
    Pila paux = p_crear();
    TipoElemento X = te_crear(0);
    printf("Contenido de la pila: ");
    // Recorro la pila desapilandola y pasandola a la auxiliar
    while (p_es_vacia(pila) != true)
    {
        X = p_desapilar(pila);
        printf("% d", X->clave);
        p_apilar(paux, X);
    }
    // Recorre la pila auxiliar para pasarla a la original
    while (p_es_vacia(paux) != true)
    {
        X = p_desapilar(paux);
        p_apilar(pila, X);
    }
}
