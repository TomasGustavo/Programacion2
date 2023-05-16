#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "arbol-binario.h"
#include "tipo_elemento.h"

static const int TAMANIO_MAXIMO = 100;

struct ArbolBinarioRep {
    NodoArbol raiz;
    int cantidad_elementos;
};

/// @brief Crea un arbol binario
/// @return Arbol creado
ArbolBinario a_crear(){
    ArbolBinario nuevo_arbol = (ArbolBinario) malloc(sizeof(struct ArbolBinarioRep));
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;
    return nuevo_arbol;
}

/// @brief Indica si un arbol es vacio o no
/// @param a Arbol
/// @return Retorna true si el arbol esta vacio y false si el arbol no esta vacio
bool a_es_vacio(ArbolBinario a){
    return a->raiz == NULL;
}

/// @brief Indica si el arbol esta lleno
/// @param a Arbol
/// @return Retorna true si el arbol esta lleno y false si el arbol no esta lleno
bool a_es_lleno(ArbolBinario a){
    return (a->cantidad_elementos == TAMANIO_MAXIMO);
}

/// @brief Indica la cantidad de elementos de un arbol
/// @param a Arbol
/// @return Entero con la cantidad de elementos del arbol pasado por parametro
int a_cantidad_elementos(ArbolBinario a){
    return a->cantidad_elementos;
}

/// @brief Indica si una rama es nula
/// @param pa 
/// @return Devuelve true si la rama es nula y false si la rama no es nula
bool a_es_rama_nula(NodoArbol pa) {
    return pa == NULL;
}

/// @brief Devuelve la raiz del arbol
/// @param a Arbol
/// @return Raiz del arbol
NodoArbol a_raiz(ArbolBinario a){
    return a->raiz;
}

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento x){
    if (a->raiz != NULL){
        //aca deberia ser un error, no se puede insertar raiz de un arbol q ya tiene raiz
        return a->raiz;
    } 
    NodoArbol na = n_crear(x);
    a->raiz = na;
    a->cantidad_elementos++;
    return na;
}

NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento x){
    if (pa == NULL){
        return NULL;
    }

    if (pa->hi != NULL){
        //aca deberia devolver error
        return pa->hi;
    }

    NodoArbol na = n_crear(x);
    a->cantidad_elementos++;
    pa->hi = na;
    return na;    
}

NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento x){
    if (pa == NULL){
        return NULL;
    }

    if (pa->hd != NULL){
        //aca deberia devolver error
        return pa->hd;
    }

    NodoArbol na = n_crear(x);
    a->cantidad_elementos++;
    pa->hd = na;
    return na;    
}