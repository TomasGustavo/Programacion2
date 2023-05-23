#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TP5_arboles.h"
#include "listas.h"
#include "tipo_elemento.h"

/// @brief Vacía el buffer de entrada.
void vaciar_buffer()
{
    char nada[200];
    fgets(nada, 200, stdin);
}

/// @brief Frena la ejecución del código esperando el ingreso de un carácter.
void pausa()
{
    printf(ANSI_bYELLOW "\n\nPresione una tecla para continuar...." ANSI_RESET);
    getchar();
}

/// @brief Secuencia de escape ANSI que se utiliza para limpiar la pantalla de la terminal y posicionar el cursor en la esquina superior izquierda.
void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

// ----------------------------------------------------------------------------------------------------

/// @brief Función que solicita el ingreso de un número entero o de "." como representación de nulo.
/// @param n Retorna el valor entero
/// @return Retorna verdadero si se ingresa un entero, o falso en caso de nulo.
bool ingresoEntero(int *n)
{
    char s[10];
    bool resultado = true;
    *n = 0;
    printf(ANSI_bMAGENTA "Ingrese una clave numérica o '.' para nulo: " ANSI_YELLOW);
    scanf("%s", s);
    if (s[0] == '.')
    {
        resultado = false;
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if ((s[i] >= '0') && (s[i] <= '9'))
            {
                *n = *n * 10 + (s[i] - 48);
            }
        }
    }
    return resultado;
}

/// @brief Función que carga un (sub)árbol en preorden a partir del nodo padre N recursivamente
/// @param A Arbol binario donde se cargara el nuevo nodo
/// @param N Nodo a cargar
/// @param sa El entero 'sa' indica cómo se enlazará el nuevo valor:
/// • 0: El nuevo nodo (con su TE) se asignará a la raíz de A. En este caso N no es utilizado.
/// • -1: El nuevo nodo (con su TE) se enlazará como hijo izquierdo de N.
/// • 1: El nuevo nodo (con su TE) se enlazará como hijo derecho de N.
void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa)
{
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A))
    {
        b = ingresoEntero(&n);
        if (b)
        {
            X = te_crear(n);

            if (sa == -1)
                N1 = a_conectar_hi(A, N, X);
            else if (sa == 1)
                N1 = a_conectar_hd(A, N, X);
            else
                N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }
    }
}

/// @brief Función que recibe el árbol a ser cargado y llama a la función recursiva que realiza la carga nodo por nodo
/// @param A Arbol binario donde se cargaran los nodos
void cargar_arbol_binario(ArbolBinario A)
{
    Cargar_SubArbol(A, NULL, 0);
}

/// @brief Muestra el arbol "pre orden" a partir de un nodo (de ahi hacia abajo)
/// @param N Nodo del arbol
void mostrar_pre_orden(NodoArbol N)
{
    TipoElemento x;
    if (N == NULL)
    {
        printf(".");
    }
    else
    {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        mostrar_pre_orden(n_hijoizquierdo(N));
        mostrar_pre_orden(n_hijoderecho(N));
    }
}

/// @brief Muestra el arbol "in orden" a partir de un nodo (de ahi hacia abajo)
/// @param N Nodo del arbol
void mostrar_in_orden(NodoArbol N)
{
    TipoElemento x;
    if (N == NULL)
    {
        printf(".");
    }
    else
    {
        mostrar_in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        mostrar_in_orden(n_hijoderecho(N));
    }
}

/// @brief Muestra el arbol "post orden" a partir de un nodo (de ahi hacia abajo)
/// @param N Nodo del arbol
void mostrar_post_orden(NodoArbol N)
{
    TipoElemento x;
    if (N == NULL)
    {
        printf(".");
    }
    else
    {
        mostrar_post_orden(n_hijoizquierdo(N));
        mostrar_post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
    }
}

// ----------------------------------------------------------------------------------------------------

/// @brief Recorre el arbol binario en busca de los nodos hojas
/// @param Q Nodo del arbol (recibe la raíz de arbol)
void buscar_hojas(NodoArbol Q)
{
    TipoElemento x;
    if (!a_es_rama_nula(Q))
    {
        if (a_es_rama_nula(n_hijoizquierdo(Q)) && a_es_rama_nula(n_hijoderecho(Q)))
        {
            x = n_recuperar(Q);
            printf("%d ", x->clave);
        }
        buscar_hojas(n_hijoizquierdo(Q));
        buscar_hojas(n_hijoderecho(Q));
    }
}

/// @brief Muestra los nodos hojas de un arbol
/// @param A Arbol binario cargado de enteros
void hojas(ArbolBinario A)
{
    printf(ANSI_GREEN "Las hojas son: ");
    buscar_hojas(a_raiz(A));
}

/// @brief Recorre el arbol binario en busca de los nodos interiores
/// @param Q Nodo del arbol (recibe la raiz del arbol)
/// @param L Lista vacia que va a contener todos los nodos interiores
/// @param raiz Condicion para ignorar la raiz asi no se guarda como nodo interior
void buscar_nodos(NodoArbol Q, Lista L, bool raiz){
    TipoElemento X;
    if (Q == NULL){
    }
    else{
        if (raiz == false){
        if(n_hijoizquierdo(Q) != NULL || n_hijoderecho(Q) != NULL)
        {
            X = n_recuperar(Q);
            l_agregar(L, X);
        }}
        buscar_nodos(n_hijoizquierdo(Q), L, false);
        buscar_nodos(n_hijoderecho(Q), L, false);
    }
}

/// @brief Funcion que llama a la funcion buscar_nodos
/// @param A Arbol binario cargado de enteros
/// @return Retorna la lista cargada con los nodos interiores
Lista nodos_interiores(ArbolBinario A){
    Lista lista = l_crear();
    bool raiz = true;
    buscar_nodos(a_raiz(A), lista, raiz);
    return lista;
}

/// @brief Funcion que muestra el contenido de la lista por valor
/// @param L Lista cargada de valores
void l_mostrarLista_valor(Lista L){
    TipoElemento X;
    int contador = 1;
    printf("contenido de la lista: ");
    if (l_es_vacia(L))
    {
        printf("la lista esta vacia");
    }
    else{
    while (contador <= l_longitud(L))
    {
        X = l_recuperar(L, contador);
        printf("%p ", X->valor);
        contador++;
    }
    }
    printf("\n");
}

/// @brief Busca todas las ocurrencias del elemento y carga su posicion en una lista
/// @param Q  Nodo del arbol (recibe la raiz del arbol)
/// @param lista Lista vacia que va a contener todas las ocurrencias
/// @param elemento Elemento a buscar
void buscar_ocurrencias(NodoArbol Q, Lista lista, int elemento){
    TipoElemento X;
    if (Q == NULL){
    }
    else{ 
        X = n_recuperar(Q);
        if(elemento == X->clave){
            X->valor = Q;
            l_agregar(lista, X);
        }
        buscar_ocurrencias(n_hijoizquierdo(Q), lista, elemento);
        buscar_ocurrencias(n_hijoderecho(Q), lista, elemento);
    }
}

/// @brief Funcion que llama a la funcion buscar_ocurrencias
/// @param A Arbol Binario cargado de enteros
/// @param elemento Elemento a buscar en el arbol
/// @return Retorna la lista cargada con la posicion del elemento
Lista ocurrencias(ArbolBinario A, int elemento){
    Lista lista = l_crear();
    buscar_ocurrencias(a_raiz(A), lista, elemento);
    return lista;
}

/// @brief Recorre el arbol binario en busca un nodo
/// @param A arbol binario cargado
/// @param actual Nodo actual
/// @param clave clave a buscar en el arbol
/// @param N Nodo encontrado
/// @return Retorna el nodo buscado
void devolver_nodo_aux(ArbolBinario A, NodoArbol actual, int clave, NodoArbol* N){
    if(!a_es_rama_nula(actual)){
        if(n_recuperar(actual)->clave == clave) *N = actual;
        else{
            devolver_nodo_aux(A, n_hijoizquierdo(actual), clave, N);
            devolver_nodo_aux(A, n_hijoderecho(actual), clave, N);
        }
    }
}

/// @brief Funcion que llama a devolver_nodo_aux
/// @param A arbol binario cargado
/// @param clave clave a buscar en el arbol
/// @return Retorna el nodo buscado
NodoArbol devolver_nodo(ArbolBinario A, int clave){
    TipoElemento X = te_crear(0);
    NodoArbol N;
    N = NULL;
    N = n_crear(X);
    NodoArbol R = a_raiz(A);
    devolver_nodo_aux(A,R,clave,&N);
    return N;
}

/// @brief Funcion que busca el nodo padre recursivamente
/// @param A Arbol Binario cargado de enteros
/// @param actual Nodo actual
/// @param padre Parametro que guarda el padre del nodo actual
/// @param clave Clave a buscar en el arbol
/// @param R Nodo donde se va a guardar resultado
/// @return Retorna el nodo padre
void nodo_padre_aux(ArbolBinario A, NodoArbol actual, NodoArbol padre, int clave, NodoArbol* R){
  if(!a_es_rama_nula(actual)){
    if(n_recuperar(actual)->clave == clave) *R = padre;
    else{
        nodo_padre_aux(A,n_hijoizquierdo(actual), actual, clave, R);
        nodo_padre_aux(A, n_hijoderecho(actual), actual, clave, R);
    }
  }
}

/// @brief Funcion que llama a la funcion nodo_padre_aux
/// @param A Arbol Binario cargado de enteros
/// @param clave Clave a buscar en el arbol
/// @return Retorna el nodo padre
NodoArbol nodo_padre(ArbolBinario A, int clave){
    NodoArbol N, R;
    TipoElemento X = te_crear(0);
    N = NULL;
    N = n_crear(X);
    R = a_raiz(A);
    if (n_recuperar(R)->clave == clave) return R;
    else {
        nodo_padre_aux(A,R,NULL,clave,&N);
        return N;
    }
}

/// @brief Funcion que devuelve true si existe el nodo y false si no
/// @param A Arbol Binario cargado de enteros
/// @param actual Nodo actual
/// @param clave Clave a buscar en el arbol
/// @param resultado variable donde se devuelve true o false
/// @return Retorna el nodo padre
void existe_nodo_aux(ArbolBinario A, NodoArbol actual, int clave, bool* resultado){
    if(!a_es_rama_nula(actual)){
        if(n_recuperar(actual)->clave == clave) *resultado = true;
        else{
            existe_nodo_aux(A,n_hijoizquierdo(actual),clave, resultado);
            existe_nodo_aux(A, n_hijoderecho(actual),clave, resultado);
        }
    }
}

/// @brief Funcion que llama a existe_nodo_aux
/// @param A Arbol Binario cargado de enteros
/// @param clave Clave a buscar en el arbol
/// @return Retorna true si existe el nodo y false si no existe
bool existe_nodo(ArbolBinario A, int clave){
    NodoArbol R;
    bool resultado = false;
    R = a_raiz(A);
    if (n_recuperar(R)->clave == clave) return true;
    else {
        existe_nodo_aux(A,R,clave, &resultado);
        return resultado;
    }
}

/// @brief Funcion que llama a nodo_hermano_aux
/// @param A Arbol Binario cargado de enteros
/// @param clave Clave a buscar en el arbol
/// @return Retorna el nodo hermano
NodoArbol nodo_hermano(ArbolBinario A, int clave){
    NodoArbol N = nodo_padre(A, clave);
    if(n_hijoizquierdo(N) == clave) return n_hijoderecho(N);
    else return n_hijoderecho(N);
}

void nivel_aux(NodoArbol actual,int clave, int n , int* resultado){
    TipoElemento X = te_crear(0);
    if(actual != NULL){
        X = n_recuperar(actual);
        if (X->clave == clave){
            *resultado = n;
        } else {
            nivel_aux(n_hijoizquierdo(actual), clave, n+1, resultado);
            nivel_aux(n_hijoderecho(actual), clave, n+1, resultado);
        }
    }
}

int nivel(ArbolBinario A, int clave){
    int N = -1;
    NodoArbol R = a_raiz(A);
    nivel_aux(R, clave, 0, &N);
    return N;
}
