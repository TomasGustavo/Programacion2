#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TP5_arboles.h"
#include "listas.h"
#include "colas.h"
#include "tipo_elemento.h"
#include "arbol-binario.h"
#include "arbol-binario-busqueda.h"
#include "arbol-avl.h"
#include <time.h>
// #include <sys/time.h>

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
    vaciar_buffer();
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
    printf(ANSI_bCYAN "\nArbol en pre orden:");
    mostrar_pre_orden(a_raiz(A));
    printf("\n\n");
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
void buscar_nodos(NodoArbol Q, Lista L, bool raiz)
{
    TipoElemento X;
    if (Q == NULL)
    {
    }
    else
    {
        if (raiz == false)
        {
            if (n_hijoizquierdo(Q) != NULL || n_hijoderecho(Q) != NULL)
            {
                X = n_recuperar(Q);
                l_agregar(L, X);
            }
        }
        buscar_nodos(n_hijoizquierdo(Q), L, false);
        buscar_nodos(n_hijoderecho(Q), L, false);
    }
}

/// @brief Funcion que llama a la funcion buscar_nodos
/// @param A Arbol binario cargado de enteros
/// @return Retorna la lista cargada con los nodos interiores
Lista nodos_interiores(ArbolBinario A)
{
    Lista lista = l_crear();
    bool raiz = true;
    buscar_nodos(a_raiz(A), lista, raiz);
    return lista;
}

/// @brief Funcion que muestra el contenido de la lista por valor
/// @param L Lista cargada de valores
void l_mostrarLista_valor(Lista L)
{
    TipoElemento X;
    int contador = 1;
    printf("contenido de la lista: ");
    if (l_es_vacia(L))
    {
        printf("la lista esta vacia");
    }
    else
    {
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
void buscar_ocurrencias(NodoArbol Q, Lista lista, int elemento)
{
    TipoElemento X;
    if (Q == NULL)
    {
    }
    else
    {
        X = n_recuperar(Q);
        if (elemento == X->clave)
        {
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
Lista ocurrencias(ArbolBinario A, int elemento)
{
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
void devolver_nodo_aux(ArbolBinario A, NodoArbol actual, int clave, NodoArbol *N)
{
    if (!a_es_rama_nula(actual))
    {
        if (n_recuperar(actual)->clave == clave)
            *N = actual;
        else
        {
            devolver_nodo_aux(A, n_hijoizquierdo(actual), clave, N);
            devolver_nodo_aux(A, n_hijoderecho(actual), clave, N);
        }
    }
}

/// @brief Funcion que llama a devolver_nodo_aux
/// @param A arbol binario cargado
/// @param clave clave a buscar en el arbol
/// @return Retorna el nodo buscado
NodoArbol devolver_nodo(ArbolBinario A, int clave)
{
    TipoElemento X = te_crear(0);
    NodoArbol N;
    N = NULL;
    N = n_crear(X);
    NodoArbol R = a_raiz(A);
    devolver_nodo_aux(A, R, clave, &N);
    return N;
}

/// @brief Funcion que busca el nodo padre recursivamente
/// @param A Arbol Binario cargado de enteros
/// @param actual Nodo actual
/// @param padre Parametro que guarda el padre del nodo actual
/// @param clave Clave a buscar en el arbol
/// @param R Nodo donde se va a guardar resultado
/// @return Retorna el nodo padre
void nodo_padre_aux(ArbolBinario A, NodoArbol actual, NodoArbol padre, int clave, NodoArbol *R)
{
    if (!a_es_rama_nula(actual))
    {
        if (n_recuperar(actual)->clave == clave)
            *R = padre;
        else
        {
            nodo_padre_aux(A, n_hijoizquierdo(actual), actual, clave, R);
            nodo_padre_aux(A, n_hijoderecho(actual), actual, clave, R);
        }
    }
}

/// @brief Funcion que llama a la funcion nodo_padre_aux
/// @param A Arbol Binario cargado de enteros
/// @param clave Clave a buscar en el arbol
/// @return Retorna el nodo padre
NodoArbol nodo_padre(ArbolBinario A, int clave)
{
    NodoArbol N, R;
    TipoElemento X = te_crear(0);
    N = NULL;
    N = n_crear(X);
    R = a_raiz(A);
    if (n_recuperar(R)->clave == clave)
        return NULL;
    else
    {
        nodo_padre_aux(A, R, NULL, clave, &N);
        return N;
    }
}

/// @brief Funcion que devuelve true si existe el nodo y false si no
/// @param A Arbol Binario cargado de enteros
/// @param actual Nodo actual
/// @param clave Clave a buscar en el arbol
/// @param resultado variable donde se devuelve true o false
/// @return Retorna el nodo padre
void existe_nodo_aux(ArbolBinario A, NodoArbol actual, int clave, bool *resultado)
{
    if (!a_es_rama_nula(actual))
    {
        if (n_recuperar(actual)->clave == clave)
            *resultado = true;
        else
        {
            existe_nodo_aux(A, n_hijoizquierdo(actual), clave, resultado);
            existe_nodo_aux(A, n_hijoderecho(actual), clave, resultado);
        }
    }
}

/// @brief Funcion que llama a existe_nodo_aux
/// @param A Arbol Binario cargado de enteros
/// @param clave Clave a buscar en el arbol
/// @return Retorna true si existe el nodo y false si no existe
bool existe_nodo(ArbolBinario A, int clave)
{
    NodoArbol R;
    bool resultado = false;
    R = a_raiz(A);
    if (n_recuperar(R)->clave == clave)
        return true;
    else
    {
        existe_nodo_aux(A, R, clave, &resultado);
        return resultado;
    }
}

/// @brief Funcion que llama a nodo_hermano_aux
/// @param A Arbol Binario cargado de enteros
/// @param clave Clave a buscar en el arbol
/// @return Retorna el nodo hermano
NodoArbol nodo_hermano(ArbolBinario A, int clave)
{
    if (n_recuperar(a_raiz(A))->clave == clave)
    {
        return NULL;
    }
    NodoArbol N = nodo_padre(A, clave);
    if (n_recuperar(n_hijoizquierdo(N))->clave == clave)
        return n_hijoderecho(N);
    else
        return n_hijoderecho(N);
}

/// @brief Indica el nivel en el que se encuentra la clave pasada
/// @param A Arbol binario cargado
/// @param clave clave a buscar
/// @param n contador de niveles
/// @param resultado parametro que devuelve el resultado
/// @return Devuelve el nivel en el que se encuentra la clave
void nivel_aux(NodoArbol actual, int clave, int n, int *resultado)
{
    TipoElemento X = te_crear(0);
    if (actual != NULL)
    {
        X = n_recuperar(actual);
        if (X->clave == clave)
        {
            *resultado = n;
        }
        else
        {
            nivel_aux(n_hijoizquierdo(actual), clave, n + 1, resultado);
            nivel_aux(n_hijoderecho(actual), clave, n + 1, resultado);
        }
    }
}

/// @brief Funcion que llama a nive_aux
/// @param A Arbol binario cargado
/// @param clave clave a buscar
/// @return Devuelve el nivel en el que se encuentra la clave
int nivel(ArbolBinario A, int clave)
{
    int N = -1;
    NodoArbol R = a_raiz(A);
    nivel_aux(R, clave, 0, &N);
    return N;
}

void nodos_nivel_aux(ArbolBinario A, NodoArbol Q, int nivel_clave, Lista *lista)
{
    if (!a_es_rama_nula(Q))
    {
        TipoElemento x = n_recuperar(Q);
        int nivel_actual = nivel(A, x->clave);
        if (nivel_actual == nivel_clave)
        {
            l_agregar(*lista, x);
        }
        nodos_nivel_aux(A, n_hijoizquierdo(Q), nivel_clave, lista);
        nodos_nivel_aux(A, n_hijoderecho(Q), nivel_clave, lista);
    }
}

Lista nodos_nivel(ArbolBinario A, int clave)
{
    int nivel_clave = nivel(A, clave);
    Lista lista = l_crear();
    nodos_nivel_aux(A, a_raiz(A), nivel_clave, &lista);
    return lista;
}

/// @brief Resuelve la altura. 'C' cuenta los pasos desde la raíz a cada nodo
/// @param Q Nodo actual
/// @param C Cantidad de pasos actual
/// @param H Cantidad de pasos en la hoja anterior
void altura(NodoArbol Q, int C, int *H)
{
    if (a_es_rama_nula(Q))
    {
        if (C > *H) // cada vez que llega a la hoja pregunta si la cantidad de pasos fue mayor que la de la hoja anterior
        {
            *H = C;
        }
    }
    else
    {
        altura(n_hijoizquierdo(Q), C + 1, H);
        altura(n_hijoderecho(Q), C + 1, H);
    }
}

/// @brief Dado un nodo, indica la altura del mismo
/// @param Q Nodo actual
/// @return Retorna la altura del nodo
int nodo_altura(NodoArbol Q)
{
    int H = 0;
    altura(Q, 0, &H);
    return H;
}

/// @brief Funcion que recorre el arbol n-ario y cuenta la cantidad de hojas
/// @param N nodo actual
/// @param cantidad variable que devuelve la cantidad de nodos hoja
/// @return Retorna la cantidad de nodos hoja del arbol
void hojas_nario_aux(NodoArbol N, int *cantidad)
{
    if (!a_es_rama_nula(N))
    {
        if (a_es_rama_nula(n_hijoizquierdo(N)))
            *cantidad = *cantidad + 1;
        else
            hojas_nario_aux(n_hijoizquierdo(N), cantidad);
        hojas_nario_aux(n_hijoderecho(N), cantidad);
    }
}

/// @brief Funcion que llama a hojas_nario_aux
/// @param A Arbol n-ario cargado como binario
/// @return Retorna la cantidad de nodos hoja del arbol
int hojas_nario(ArbolBinario A)
{
    int cantidad = 0;
    NodoArbol N = a_raiz(A);
    hojas_nario_aux(N, &cantidad);
    return cantidad;
}

/// @brief Funcion que devuelve true si los arboles son similares y false si no
/// @param N1 Nodo actual del arbol 1
/// @param N2 Nodo actual del arbol 2
/// @return Retorna true si son arboles similares y false si no
void arbol_similar_aux(NodoArbol N1, NodoArbol N2, bool *rta)
{
    if ((a_es_rama_nula(N1) && a_es_rama_nula(N2)) || *rta == false)
    {
    }
    else
    {
        if ((a_es_rama_nula(N1) && !a_es_rama_nula(N2)) || (!a_es_rama_nula(N1) && a_es_rama_nula(N2)))
            *rta = false;
        else
        {
            arbol_similar_aux(n_hijoizquierdo(N1), n_hijoizquierdo(N2), rta);
            arbol_similar_aux(n_hijoderecho(N1), n_hijoderecho(N2), rta);
        }
    }
}

/// @brief Funcion que llama a arbol_similar_aux
/// @param A1 Arbol n-ario cargado como binario
/// @param A2 Arbol n-ario cargado como binario
/// @return Retorna true si son arboles similares y false si no
bool arbol_similar(ArbolBinario A1, ArbolBinario A2)
{
    bool rta = true;
    if (a_es_vacio(A1) && a_es_vacio(A2))
        return true;
    if ((a_es_vacio(A1) && !a_es_vacio(A2)) || (!a_es_vacio(A1) && a_es_vacio(A2)))
        return false;
    NodoArbol N1 = a_raiz(A1);
    NodoArbol N2 = a_raiz(A2);
    arbol_similar_aux(N1, N2, &rta);
    return rta;
}

/// @brief Funcion que devuelve el padre de un nodo
/// @param A Arbol n-ario cargado como binario
/// @param clave clave del nodo a buscar
/// @return Retorna true si son arboles similares y false si no
void padre_nario_aux(NodoArbol actual, NodoArbol padre, int clave, NodoArbol *R)
{
    if (!a_es_rama_nula(actual))
    {
        if (n_recuperar(actual)->clave == clave)
            *R = padre;
        else
        {
            padre_nario_aux(n_hijoizquierdo(actual), actual, clave, R);
            padre_nario_aux(n_hijoderecho(actual), padre, clave, R);
        }
    }
}

/// @brief Funcion que llama a padre_nario_aux
/// @param A Arbol n-ario cargado como binario
/// @param clave clave del nodo a buscar
/// @return Retorna true si son arboles similares y false si no
NodoArbol padre_nario(ArbolBinario A, int clave)
{
    NodoArbol N, R;
    TipoElemento X = te_crear(0);
    N = NULL;
    N = n_crear(X);
    R = a_raiz(A);
    if (n_recuperar(R)->clave == clave)
        return NULL;
    padre_nario_aux(R, NULL, clave, &N);
    return N;
}

void hermanos_nario_aux(NodoArbol actual, int clave, Lista *L)
{
    if (!a_es_rama_nula(actual))
    {
        if (n_recuperar(actual)->clave == clave)
        {
        }
        else
        {
            TipoElemento X = n_recuperar(actual);
            l_agregar(*L, X);
        }
        hermanos_nario_aux(n_hijoderecho(actual), clave, L);
    }
}

/// @brief Funcion que llama hermanos_nario_auz
/// @param A Arbol n-ario cargado como binario
/// @param clave clave del nodo a buscar
/// @return Retorna una lista con los hermanos del nodo
Lista hermanos_nario(ArbolBinario A, int clave)
{
    NodoArbol N;
    Lista L = l_crear();
    TipoElemento X = te_crear(0);
    N = n_crear(X);
    N = padre_nario(A, clave);
    hermanos_nario_aux(n_hijoizquierdo(N), clave, &L);
    return L;
}

/// @brief Recorre los arboles binarios para comparar si son equivalentes
/// @param Q1 Nodo del arbol (recibe la raiz del arbol)
/// @param Q2 Nodo del arbol (recibe la raiz del arbol)
/// @param equivalentes bandera que indica si los arboles son equivalentes
void comparar_equivalencia(NodoArbol Q1, NodoArbol Q2, int *equivalentes)
{
    TipoElemento X1;
    TipoElemento X2;
    if (Q1 == NULL && Q2 == NULL)
    {
    }
    else
    {
        X1 = n_recuperar(Q1);
        X2 = n_recuperar(Q2);
        if (Q1 == NULL || Q2 == NULL)
        {
            *equivalentes = 0;
        }
        else if (X1->clave == X2->clave)
        {
            comparar_equivalencia(n_hijoizquierdo(Q1), n_hijoizquierdo(Q2), equivalentes);
            comparar_equivalencia(n_hijoderecho(Q1), n_hijoderecho(Q2), equivalentes);
        }
        else
        {
            *equivalentes = 0;
        }
    }
}
/// @brief Funcion que llama a la funcion comparar_equivalencia
/// @param A1 Arbol binario cargado de enteros
/// @param A2 Arbol binario cargado de enteros
/// @return Retorna una bandera que indica si los arboles son equivalentes
int arbol_equivalentes(ArbolBinario A1, ArbolBinario A2)
{
    int equivalentes = 1;
    comparar_equivalencia(a_raiz(A1), a_raiz(A2), &equivalentes);
    return equivalentes;
}

/// @brief Indica el nivel en el que se encuentra la clave pasada
/// @param A Arbol binario cargado
/// @param clave clave a buscar
/// @param n contador de niveles
/// @param resultado parametro que devuelve el resultado
/// @return Devuelve el nivel en el que se encuentra la clave
void nivel_nario_aux(NodoArbol actual, int clave, int n, int *resultado)
{
    TipoElemento X = te_crear(0);
    if (actual != NULL)
    {
        X = n_recuperar(actual);
        if (X->clave == clave)
        {
            *resultado = n;
        }
        else
        {
            nivel_nario_aux(n_hijoizquierdo(actual), clave, n + 1, resultado);
            nivel_nario_aux(n_hijoderecho(actual), clave, n, resultado);
        }
    }
}

/// @brief Funcion que llama a nivel_nario_aux
/// @param A Arbol binario cargado
/// @param clave clave a buscar
/// @return Devuelve el nivel en el que se encuentra la clave
int nivel_nario(ArbolBinario A, int clave)
{
    int N = -1;
    NodoArbol R = a_raiz(A);
    nivel_nario_aux(R, clave, 0, &N);
    return N;
}

/// @brief Funcion que llama a nodos_internos_nario_auz
/// @param A Arbol binario cargado
/// @return Devuelve una lista con los nodos internos del arbol n-ario
void nodos_internos_nario_aux(ArbolBinario A, NodoArbol actual, Lista *L)
{
    if (!a_es_rama_nula(actual))
    {
        if (!a_es_rama_nula(n_hijoizquierdo(actual)) && n_recuperar(a_raiz(A))->clave != n_recuperar(actual)->clave)
        {
            TipoElemento X = n_recuperar(actual);
            l_agregar(*L, X);
        }
        nodos_internos_nario_aux(A, n_hijoizquierdo(actual), L);
        nodos_internos_nario_aux(A, n_hijoderecho(actual), L);
    }
}

/// @brief Funcion que llama a nodos_internos_nario_auz
/// @param A Arbol binario cargado
/// @return Devuelve una lista con los nodos internos del arbol n-ario
Lista nodos_internos_nario(ArbolBinario A)
{
    NodoArbol N = a_raiz(A);
    Lista L = l_crear();
    nodos_internos_nario_aux(A, N, &L);
    return L;
}

/// @brief Funcion indica si todas las hojas del arbol estan al mismo nivel
/// @param A Arbol binario cargado
/// @return Devuelve true si todas las hojas estan al mismo nivel y false si no
void nivel_hojas_nario_aux(ArbolBinario A, NodoArbol actual, Lista *L)
{
    if (!a_es_rama_nula(actual))
    {
        if (a_es_rama_nula(n_hijoizquierdo(actual)))
        {
            TipoElemento X = n_recuperar(actual);
            int nivel = nivel_nario(A, X->clave);
            TipoElemento X1 = te_crear(nivel);
            l_agregar(*L, X1);
        }
        nivel_hojas_nario_aux(A, n_hijoizquierdo(actual), L);
        nivel_hojas_nario_aux(A, n_hijoderecho(actual), L);
    }
}

/// @brief Funcion que llama a nivel_hojas_nario
/// @param A Arbol binario cargado
/// @return Devuelve true si todas las hojas estan al mismo nivel y false si no
bool nivel_hojas_nario(ArbolBinario A)
{
    Lista l = l_crear();
    NodoArbol R = a_raiz(A);
    bool res = true;
    TipoElemento X, X1;
    nivel_hojas_nario_aux(A, R, &l);
    Iterador ite = iterador(l);
    if (!l_es_vacia(l))
    {
        X = siguiente(ite);
        while (hay_siguiente(ite) && res != false)
        {
            X1 = siguiente(ite);
            if (X->clave != X1->clave)
                res = false;
        }
    }
    else
        res = false;
    return res;
}

Lista anchura_nario(ArbolBinario A)
{
    Lista L;
    Cola C;
    NodoArbol N, N1;
    TipoElemento X, X1;
    if (!a_es_vacio(A))
    {
        L = l_crear();
        C = c_crear();
        N = a_raiz(A);
        X = te_crear_con_valor(0, N);
        c_encolar(C, X);
        while (!c_es_vacia(C))
        {
            X = c_desencolar(C);
            N = (NodoArbol)X->valor;
            l_agregar(L, n_recuperar(N));
            if (!a_es_rama_nula(n_hijoizquierdo(N)))
            {
                N1 = n_hijoizquierdo(N);
                X1 = te_crear_con_valor(0, N1);
                c_encolar(C, X1);
            }
            while (!a_es_rama_nula(n_hijoderecho(N1)))
            {
                N1 = n_hijoderecho(N1);
                X = te_crear_con_valor(0, N1);
                c_encolar(C, X);
            }
        }
    }
    return L;
}

/// @brief Resuelve la altura. 'C' cuenta los pasos desde la raíz a cada nodo
/// @param Q Nodo actual
/// @param C Cantidad de pasos actual
/// @param H Cantidad de pasos en la hoja anterior
void altura_nario_aux(NodoArbol Q, int C, int *H)
{
    if (a_es_rama_nula(Q))
    {
        if (C > *H) // cada vez que llega a la hoja pregunta si la cantidad de pasos fue mayor que la de la hoja anterior
        {
            *H = C;
        }
    }
    else
    {
        altura_nario_aux(n_hijoizquierdo(Q), C + 1, H);
        altura_nario_aux(n_hijoderecho(Q), C, H);
    }
}

/// @brief Dado un nodo, indica la altura del mismo
/// @param Q Nodo actual
/// @return Retorna la altura del nodo
int altura_nario(NodoArbol Q)
{
    int H = 0;
    altura_nario_aux(Q, 0, &H);
    return H;
}

// -------------------------------------------------- PUNTO 10 --------------------------------------------------

/// @brief Función que genera numeros aleatorios dentro de un rango
/// @param min Rango minimo
/// @param max Rango maximo
/// @return Numero aleatorio generado
int getRandom(int min, int max)
{
    int n_aleatorio;
    n_aleatorio = min + (rand() % (max - min + 1));
    return n_aleatorio;
}

/*int getRandomMejorado(int min, int max)
{
    int n_aleatorio;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec * 1000000 + tv.tv_usec);

    n_aleatorio = rand()% max + min;
 return n_aleatorio;
}*/

/// @brief Función que carga un (sub)árbol AVL y BB en preorden de forma aleatoria con las mismos nodos en ambos arboles
/// @param A_BB Arbol Binario de Busqueda a cagar la serie aleatoria
/// @param A_AVL Arbol AVL a cargar la serie aleatoria
/// @param min Valor minimo del rango aleatorio
/// @param max Valor maximo del rango aleatorio
void cargar_nodos_AVL_ABB(ArbolBinarioBusqueda A_BB, ArbolAVL A_AVL, int min, int max)
{
    TipoElemento X;
    int n_aleatorio;
    if (!abb_es_lleno(A_BB) && !avl_es_lleno(A_AVL))
    {
        n_aleatorio = getRandom(min, max);
        X = te_crear(n_aleatorio);
        avl_insertar(A_AVL, X);
        abb_insertar(A_BB, X);
    }
}

/// @brief Resuelve la altura. 'C' cuenta los pasos desde la raíz a cada nodo
/// @param Q Nodo actual
/// @param C Cantidad de pasos actual
/// @param H Cantidad de pasos en la hoja anterior
void altura_avl_aux(NodoArbol Q, int C, int *H)
{
    if (avl_es_rama_nula(Q))
    {
        if (C > *H) // cada vez que llega a la hoja pregunta si la cantidad de pasos fue mayor que la de la hoja anterior
        {
            *H = C;
        }
    }
    else
    {
        altura_avl_aux(n_hijoizquierdo(Q), C + 1, H);
        altura_avl_aux(n_hijoderecho(Q), C + 1, H);
    }
}

/// @brief Calcula la altura del arbol
/// @param A_AVL Arbol AVL cargado
/// @return Altura del arbol
int altura_avl(ArbolAVL A_AVL)
{
    int H = 0;
    altura_avl_aux(avl_raiz(A_AVL), 0, &H);
    return H;
}

/// @brief Resuelve la altura. 'C' cuenta los pasos desde la raíz a cada nodo
/// @param Q Nodo actual
/// @param C Cantidad de pasos actual
/// @param H Cantidad de pasos en la hoja anterior
void altura_bb_aux(NodoArbol Q, int C, int *H)
{
    if (abb_es_rama_nula(Q))
    {
        if (C > *H) // cada vez que llega a la hoja pregunta si la cantidad de pasos fue mayor que la de la hoja anterior
        {
            *H = C;
        }
    }
    else
    {
        altura_bb_aux(n_hijoizquierdo(Q), C + 1, H);
        altura_bb_aux(n_hijoderecho(Q), C + 1, H);
    }
}

/// @brief Calcula la altura del arbol
/// @param A_BB Arbol BB cargado
/// @return Altura del arbol
int altura_bb(ArbolBinarioBusqueda A_BB)
{
    int H = 0;
    altura_bb_aux(abb_raiz(A_BB), 0, &H);
    return H;
}

/// @brief Funcion que repite 'repeticiones' veces el proceso de carga del arbol AVL y BB
/// @param repeticiones Cantidad de repeticiones
/// @param min Valor minimo del rango aleatorio
/// @param max Valor maximo del rango aleatorio
void cargar_repeticiones_AVL_BB(int repeticiones, int nodos, int min, int max)
{
    int altura_minima_avl, altura_maxima_avl, altura_suma_avl = 0, altura_actual_avl;
    int altura_minima_bb, altura_maxima_bb, altura_suma_bb = 0, altura_actual_bb;
    float altura_media_avl, altura_media_bb;
    srand(time(NULL)); // Establecer semilla
    // Se ejecuta el proceso de carga de arboles 1 vez, para poder guardar los valores minimos y maximos iniciales

    ArbolAVL A_AVL = avl_crear();
    ArbolBinarioBusqueda A_BB = abb_crear();
    for (int i = 1; i <= nodos; i++) // Repite n veces el proceso de carga de los nodos
    {
        cargar_nodos_AVL_ABB(A_BB, A_AVL, min, max);
    }
    // Estadisticas iniciales del arbol AVL
    altura_actual_avl = altura_avl(A_AVL);
    altura_minima_avl = altura_actual_avl;
    altura_maxima_avl = altura_actual_avl;
    altura_suma_avl += altura_actual_avl;
    // Estadisticas iniciales del arbol BB
    altura_actual_bb = altura_bb(A_BB);
    altura_minima_bb = altura_actual_bb;
    altura_maxima_bb = altura_actual_bb;
    altura_suma_bb += altura_actual_bb;
    free_avl(avl_raiz(A_AVL));
    free_abb(abb_raiz(A_BB));

    // Se ejecuta el proceso de carga de arboles n-1
    for (int i = 1; i < repeticiones; i++)
    {
        ArbolAVL A_AVL = avl_crear();
        ArbolBinarioBusqueda A_BB = abb_crear();
        for (int i = 1; i <= nodos; i++) // Repite n veces el proceso de carga de los nodos
        {
            cargar_nodos_AVL_ABB(A_BB, A_AVL, min, max);
        }
        // Estadisticas del arbol AVL
        altura_actual_avl = altura_avl(A_AVL);
        if (altura_minima_avl > altura_actual_avl)
        {
            altura_minima_avl = altura_actual_avl;
        }
        if (altura_maxima_avl < altura_actual_avl)
        {
            altura_maxima_avl = altura_actual_avl;
        }
        altura_suma_avl += altura_actual_avl;
        // Estadisticas del arbol BB
        altura_actual_bb = altura_bb(A_BB);
        if (altura_minima_bb > altura_actual_bb)
        {
            altura_minima_bb = altura_actual_bb;
        }
        if (altura_maxima_bb < altura_actual_bb)
        {
            altura_maxima_bb = altura_actual_bb;
        }
        altura_suma_bb += altura_actual_bb;
        free_avl(avl_raiz(A_AVL));
        free_abb(abb_raiz(A_BB));
    }
    altura_media_avl = altura_suma_avl / repeticiones;
    altura_media_bb = altura_suma_bb / repeticiones;
    printf(ANSI_GREEN "\nSe cargaron los arboles AVL y BB %d veces, las estadisticas son:\n", repeticiones);
    printf(ANSI_GREEN "La altura minima del arbol AVL es: " ANSI_YELLOW "%d\n", altura_minima_avl);
    printf(ANSI_GREEN "La altura maxima del arbol AVL es: " ANSI_YELLOW "%d\n", altura_maxima_avl);
    printf(ANSI_GREEN "La altura media del arbol AVL es: " ANSI_YELLOW "%.2f\n\n", altura_media_avl);
    printf(ANSI_GREEN "La altura minima del arbol BB es: " ANSI_YELLOW "%d\n", altura_minima_bb);
    printf(ANSI_GREEN "La altura maxima del arbol BB es: " ANSI_YELLOW "%d\n", altura_maxima_bb);
    printf(ANSI_GREEN "La altura media del arbol BB es: " ANSI_YELLOW "%.2f\n", altura_media_bb);
}

void free_avl(NodoArbol Q)
{
    if (avl_es_rama_nula(Q))
    {
        return;
    }

    free_avl(n_hijoizquierdo(Q));
    free_avl(n_hijoderecho(Q));
    free(Q);
    Q = NULL;
}

void free_abb(NodoArbol Q)
{
    if (abb_es_rama_nula(Q))
    {
        return;
    }

    free_abb(n_hijoizquierdo(Q));
    free_abb(n_hijoderecho(Q));
    free(Q);
    Q = NULL;
}

void BToAVL_aux(NodoArbol n_AB, ArbolAVL *A_AVL)
{
    TipoElemento X;
    if (!a_es_rama_nula(n_AB))
    {
        X = n_recuperar(n_AB);
        avl_insertar(*A_AVL, X);
        BToAVL_aux(n_hijoizquierdo(n_AB), A_AVL);
        BToAVL_aux(n_hijoderecho(n_AB), A_AVL);
    }
}

ArbolAVL BToAVL(ArbolBinario AB)
{
    ArbolAVL A_AVL = avl_crear();
    BToAVL_aux(a_raiz(AB), &A_AVL);
    return A_AVL;
}