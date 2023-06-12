#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

/// @brief Retorna el hijo izquierdo
/// @param N Recibe un nodo del cual queremos obtener el hijo izquierdo
/// @return Hijo izquierdo del Nodo dado
NodoArbol n_hijoizquierdo(NodoArbol N)
{
    if (N == NULL)
    {
        return NULL;
    }
    else
    {
        return N->hi;
    }
}

/// @brief Retorna el hijo derecho
/// @param N Recibe un nodo del cual queremos obtener el hijo derecho
/// @return Hijo derecho del Nodo dado
NodoArbol n_hijoderecho(NodoArbol N)
{
    if (N == NULL)
    {
        return NULL;
    }
    else
    {
        return N->hd;
    }
}

/// @brief RCrea un nodo
/// @param te Tipo elemento con los datos que va a contener el nodo
/// @return Nodo creado
NodoArbol n_crear(TipoElemento te)
{
    NodoArbol na = (NodoArbol)malloc(sizeof(struct NodoArbolRep));
    na->datos = te;
    na->hi = NULL;
    na->hd = NULL;
    na->FE = 0;
    return na;
}

/// @brief Recupera el tipo elemento de un nodo o NULL si no existe
/// @param N Recibe un nodo a recuperar
/// @return Retorna el tipo elemento de un nodo o NULL si no existe
TipoElemento n_recuperar(NodoArbol N)
{
    TipoElemento x = te_crear(0);
    if (N == NULL)
    {
        return NULL;
    }
    else
    {
        x = N->datos;
        return x;
    }
}
