#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TP4_colas.h"
#include "colas.h"
#include "pilas.h"
#include "listas.h"
#include "tipo_elemento.h"

struct posicionesPC
{
    int p;
    int c;
};

/// @brief Vacía el buffer de entrada.
void vaciar_buffer()
{
    char nada[200];
    fgets(nada, 200, stdin);
}

/// @brief Frena la ejecución del código esperando el ingreso de un carácter.
void pausa()
{
    printf(ANSI_bYELLOW "\nPresione una tecla para continuar...." ANSI_RESET);
    getchar();
}

/// @brief Secuencia de escape ANSI que se utiliza para limpiar la pantalla de la terminal y posicionar el cursor en la esquina superior izquierda.
void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

/// @brief Pasa los elementos de una cola (auxiliar) a otra cola. Especialmente util para no destruir la cola original.
/// @param C Cola donde se desea pasar los elementos.
/// @param CAux Cola auxiliar, se pierde al finalizar el ciclo.
void c_intercambiar(Cola C, Cola CAux)
{
    TipoElemento x = te_crear(0);
    while (!c_es_vacia(CAux))
    {
        x = c_desencolar(CAux);
        c_encolar(C, x);
    }
}

/// @brief Pasa los elementos de una pila (auxiliar) a otra pila. Especialmente util para no destruir la pila original.
/// @param p Pila donde se desea pasar los elementos.
/// @param aux Pila auxiliar, se pierde al finalizar el ciclo.
void p_intercambiar(Pila P, Pila PAux)
{
    TipoElemento x = te_crear(0);
    while (!p_es_vacia(PAux))
    {
        x = p_desapilar(PAux);
        p_apilar(P, x);
    }
}

/// @brief Función genérica para cargar una cola de enteros y mostrarla al finalizar
/// @param cant Retorna por referencia la cantidad de elementos de la cola
/// @return Cola cargada con números enteros
Cola cargarCola(int *cant)
{
    Cola cola = c_crear();
    int valor;
    printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar [0-99]: " ANSI_bYELLOW);
    int validador = scanf("%d", cant);
    vaciar_buffer();
    while (validador != 1 || *cant < 0 || *cant >= 100)
    {
        limpiar_pantalla();
        printf(ANSI_bRED "\t\t-------- ERROR --------\n");
        printf("DATO INVALIDO\n\n" ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar [0-99]: " ANSI_bYELLOW);
        validador = scanf("%d", cant);
        vaciar_buffer();
    }
    for (int i = 0; i < *cant; i++)
    {
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999]: " ANSI_bYELLOW, i + 1);
        validador = scanf("%d", &valor);
        vaciar_buffer();
        while (validador != 1 || valor < -999999 || valor > 999999)
        {
            limpiar_pantalla();
            printf(ANSI_bRED "\t\t-------- ERROR --------\n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
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
/// @brief Informar si un elemento dado se encuentra en la cola.
/// @param c Cola cargada
/// @param clave Numero entero a buscar
/// @return Si el elemento forma parte de la cola devuelve verdadero, de lo contrario devuelve falso
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
    c_intercambiar(c, caux);
    return res;
}

/// @brief Función genérica para cargar una cola de enteros no repetidos y mostrarla al finalizar
/// @return Cola cargada con números enteros no repetidos
Cola cargarColaSinRepetidos(int *cant)
{
    Cola cola = c_crear();
    int valor;
    bool esRepetido = false;
    printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar [0-99]: " ANSI_bYELLOW);
    int validador = scanf("%d", cant);
    vaciar_buffer();
    while (validador != 1 || *cant < 0 || *cant >= 100)
    {
        limpiar_pantalla();
        printf(ANSI_bRED "\t\t-------- ERROR --------\n");
        printf("DATO INVALIDO\n\n" ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar en la cola [0-99]: " ANSI_bYELLOW);
        validador = scanf("%d", cant);
        vaciar_buffer();
    }
    for (int i = 0; i < *cant; i++)
    {
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999] (no debe estar repetido): " ANSI_bYELLOW, i + 1);
        validador = scanf("%d", &valor);
        if (c_es_vacia(cola))
            esRepetido = false;
        else
            esRepetido = buscar(cola, valor);
        vaciar_buffer();
        while (validador != 1 || valor < -999999 || valor > 999999 || esRepetido)
        {
            limpiar_pantalla();
            printf(ANSI_bRED "\t\t-------- ERROR --------\n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999]: " ANSI_bYELLOW, i + 1);
            validador = scanf("%d", &valor);
            if (c_es_vacia(cola))
                esRepetido = false;
            else
                esRepetido = buscar(cola, valor);
            vaciar_buffer();
        }
        TipoElemento x = te_crear(valor);
        c_encolar(cola, x);
    }
    printf(ANSI_bGREEN "");
    c_mostrar(cola); // muestro la cola como quedo cargada
    printf("\n" ANSI_RESET);
    return cola;
}

bool buscar_c(Pila p, int x)
{
    TipoElemento temp = te_crear(0);
    bool rta;
    Pila paux = p_crear();
    temp = p_desapilar(p);
    p_apilar(paux, temp);
    while (temp->clave != x && !p_es_vacia(p))
    { // saco elementos la pila hasta que coincida con el elemento a buscar o hasta que este vacía
        temp = p_desapilar(p);
        p_apilar(paux, temp);
    }
    if (temp->clave == x)
    { // si coinciden los elementos retorno true, sino salió del ciclo porque se vació lo que significa que no encontró el elemento
        rta = true;
    }
    else
    {
        rta = false;
    }
    while (!p_es_vacia(paux))
    { // vuelvo a poner en orden todos los elementos que saque en la pila original
        temp = p_desapilar(paux);
        p_apilar(p, temp);
    }
    free(paux); // libero la memoria que use para la pila auxiliar
    return rta;
}

void mostrarListaConValor(Lista l)
{
    TipoElemento x;
    struct posicionesPC *pos;
    Iterador ite = iterador(l);
    printf(ANSI_YELLOW "\n Lista: ");
    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        pos = x->valor; // Acceder al valor como struct valoresXY
        printf(ANSI_YELLOW "%i:%i:%i, ", x->clave, pos->p, pos->c);
    }
}

/// @brief Función genérica para cargar una pila de enteros no repetidos y mostrarla al finalizar
/// @return Pila cargada con números enteros no repetidos
Pila cargarPilaSinRepetidos(int *cant)
{
    Pila pila = p_crear();
    int valor;
    bool esRepetido = false;
    printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar en la pila [0-99]: " ANSI_bYELLOW);
    int validador = scanf("%d", cant);
    vaciar_buffer();
    while (validador != 1 || *cant < 0 || *cant >= 100)
    {
        limpiar_pantalla();
        printf(ANSI_bRED "\t\t-------- ERROR --------\n");
        printf("DATO INVALIDO\n\n" ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar [0-99]: " ANSI_bYELLOW);
        validador = scanf("%d", cant);
        vaciar_buffer();
    }
    for (int i = 0; i < *cant; i++)
    {
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999] (no debe estar repetido): " ANSI_bYELLOW, i + 1);
        validador = scanf("%d", &valor);
        if (p_es_vacia(pila))
            esRepetido = false;
        else
            esRepetido = buscar_c(pila, valor);
        vaciar_buffer();
        while (validador != 1 || valor < -999999 || valor > 999999 || esRepetido)
        {
            limpiar_pantalla();
            printf(ANSI_bRED "\t\t-------- ERROR --------\n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999]: " ANSI_bYELLOW, i + 1);
            validador = scanf("%d", &valor);
            if (p_es_vacia(pila))
                esRepetido = false;
            else
                esRepetido = buscar_c(pila, valor);
            vaciar_buffer();
        }
        TipoElemento x = te_crear(valor);
        p_apilar(pila, x);
    }
    printf(ANSI_bGREEN "");
    p_mostrar(pila); // muestro la pila como quedo cargada
    printf("\n" ANSI_RESET);
    return pila;
}

// PUNTO 2B
/// @brief Inserta un elemento en la posición dada
/// @param c Cola cargada
///@param x Elemento a insertar
///@param pos Posición en la que se quiere insertar el elemento
/// @return Nueva cola con  el elemento insertado
Cola insertar(Cola c, TipoElemento x, int pos)
{
    Cola caux = c_crear();
    TipoElemento x1 = te_crear(0);
    int i = 1;
    while (!c_es_vacia(c))
    {
        x1 = c_desencolar(c);
        if (i == pos)
        {
            c_encolar(caux, x);
            i++;
        }
        c_encolar(caux, x1);
        i++;
    }
    c_intercambiar(c, caux);
    return c;
}

// PUNTO 2C
/// @brief Elimina todas las repeticiones del elemento dado
/// @param c Cola cargada
/// @param clave Clave a eliminar
/// @param estado Devuelve true si se encontró el elemento a eliminar y false si no se encontró
/// @return Cantidad de elementos que posee la cola
Cola eliminarTodas(Cola c, int clave, bool *estado)
{
    Cola caux = c_crear();
    TipoElemento x = te_crear(0);
    *estado = false;
    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        if (x->clave != clave)
        {
            c_encolar(caux, x);
            *estado = true;
        }
    }
    c_intercambiar(c, caux);
    return c;
}

/// @brief Informa la longitud que posee la cola
/// @param c Cola cargada
/// @return Cantidad de elementos que posee la cola
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
    c_intercambiar(c, aux);
    return cont;
}

// punto 2C
void borrar_elemento(Cola cola, TipoElemento elemento)
{
    Cola caux = c_crear();
    TipoElemento X;
    while (c_es_vacia(cola) != true)
    {
        X = c_desencolar(cola);
        if (X->clave != elemento->clave)
        {
            c_encolar(caux, X);
        }
    }
    while (c_es_vacia(caux) != true)
    {
        X = c_desencolar(caux);
        c_encolar(cola, X);
    }
}

/// @brief Busca el elemento dado en la posición indicada
/// @param c Cola cargada
/// @param x TipoElemento a buscar
/// @param pos Posición (entero) a buscar
/// @return Si el elemento se encuentra en la posición brindada, devuelve verdadero, de lo contrario devuelve falso
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
    c_intercambiar(c, aux);
    return bandera;
}

// punto 2E
/// @brief Crea una copia de una cola sin perder la original
/// @param c Cola cargada
/// @return Devuelve la cola clonada
Cola copiar_cola(Cola cola){
    Cola c = c_crear();
    Cola cAux = c_crear();
    TipoElemento x = te_crear(0);
    while(!c_es_vacia(cola)){
        x = c_desencolar(cola);
        c_encolar(c,x);
        c_encolar(cAux,x);
    }

    while(!c_es_vacia(cAux)){
        x = c_desencolar(cAux);
        c_encolar(cola,x);
    }
    free(cAux);

    return c;
}

//Punto 2F
Cola invertir(Cola cola, Cola caux, int longitud){
    Cola cola_invertida = c_crear();
    TipoElemento X = te_crear(0);
    if (longitud == 1)
    {
        X = c_desencolar(cola);
        c_encolar(caux, X);
        c_encolar(cola_invertida, X);
        return cola_invertida;
    }

    if (c_es_vacia(cola) != true)
    {
        X = c_desencolar(cola);
        c_encolar(caux, X);
        cola_invertida = invertir(cola, caux, longitud - 1);
        c_encolar(cola_invertida, X);
        while (c_es_vacia(caux) != true)
        {
            X = c_desencolar(caux);
            c_encolar(cola, X);
        }
    }

    return cola_invertida;
}
// PUNTO 3
/// @brief Determina si el contenido de 2 colas son iguales tanto en posición como en datos (comparando  la clave), sin destruirlas.
/// @param c1 Cola N°1 cargada
/// @param c2 Cola N°2 cargada
/// @return Si ambas colas son iguales, devuelve verdadero, de lo contrario devuelve falso
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
        c_intercambiar(c1, caux);
        return bandera;
    }
}

// Punto 4

/// @brief  Permite pasar todos los elementos que no se repiten de una cola (no ordenada de números enteros) a otra cola.
/// @param c Cola no ordenada cargada
/// @return Cola con los elementos no repetidos
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
    c_intercambiar(c, caux);
    return cresp;
}

// Punto 5
void divisores(Cola cola, Cola Divisor_total, Cola Divisor_parcial, int numero_actual, float longitud_cola)
{
    int contador_divisores = 0;
    Cola caux = c_crear();
    TipoElemento X = te_crear(0);
    float mitad_longitud = longitud_cola / 2;
    while (c_es_vacia(cola) != true)
    {
        X = c_desencolar(cola);
        if (X->clave % numero_actual == 0)
        {
            contador_divisores++;
        }
        c_encolar(caux, X);
    }
    while (c_es_vacia(caux) != true)
    {
        X = c_desencolar(caux);
        c_encolar(cola, X);
    }
    if (contador_divisores == longitud_cola)
    {
        X = te_crear(numero_actual);
        c_encolar(Divisor_total, X);
    }
    else if (contador_divisores >= mitad_longitud)
    {
        X = te_crear(numero_actual);
        c_encolar(Divisor_parcial, X);
    }
    return;
}

// PUNTO 6
/// @brief  Dada una pila y una cola devuelve una lista con los valores comunes y su posición en la estructura original
/// @param p Pila cargada sin repetidos
/// @param c Cola cargada sin repetidos
/// @return Lista con los elementos comunes y sus posiciones en la estructura original
Lista valoresComunes(Pila p, Cola c)
{
    Pila paux = p_crear();
    Cola caux = c_crear();
    Lista l = l_crear();
    TipoElemento x1 = te_crear(0);
    TipoElemento x2 = te_crear(0);
    int pc;
    int pp = 1;
    while (!p_es_vacia(p))
    {
        x1 = p_desapilar(p);
        pc = 1;
        while (!c_es_vacia(c))
        {
            x2 = c_desencolar(c);
            if (x1->clave == x2->clave)
            {
                int elemento = x2->clave;
                struct posicionesPC *pos = malloc(sizeof(struct posicionesPC));
                pos->p = pp;
                pos->c = pc;
                TipoElemento x3 = te_crear_con_valor(elemento, pos);
                l_agregar(l, x3);
            }
            pc++;
            c_encolar(caux, x2);
        }
        p_apilar(paux, x1);
        pp++;
        c_intercambiar(c, caux);
    }
    p_intercambiar(p, paux);
    return l;
}