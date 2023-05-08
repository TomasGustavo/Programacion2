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
/// @param c Cola donde se desea pasar los elementos.
/// @param aux Cola auxiliar, se pierde al finalizar el ciclo.
void intercambiar2(Cola c, Cola aux)
{
    TipoElemento x = te_crear(0);
    while (!c_es_vacia(aux))
    {
        x = c_desencolar(aux);
        c_encolar(c, x);
    }
}

/// @brief Pasa los elementos de una cola (auxiliar) a otra cola. Especialmente util para no destruir la cola original.
/// @param caux Cola auxiliar, se pierde al finalizar el ciclo.
/// @return Cola donde se desea pasar los elementos, debe pasarse como referencia (puntero)
Cola intercambiar(Cola caux)
{
    Cola cresult = c_crear();
    TipoElemento x = te_crear(0);
    while (!c_es_vacia(caux))
    {
        x = c_desencolar(caux);
        c_encolar(cresult, x);
    }
    return cresult;
}

//

/// @brief Función genérica para cargar una cola de enteros y mostrarla al finalizar
/// @return Cola cargada con números enteros
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
        printf("DATO INVALIDO\n\n" ANSI_RESET);
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
    intercambiar2(c, caux);
    //*c = intercambiar(caux);
    c_mostrar(c);
    return res;
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
    // intercambiar(c, aux);
    c = intercambiar(aux);
    return cont;
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
    // intercambiar(c, aux);
    c = intercambiar(aux);
    return bandera;
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
        // intercambiar(c1, caux);
        c1 = intercambiar(caux);
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
    // intercambiar(c,caux);
    c = intercambiar(caux);
    return cresp;
}

//Punto 5
void divisores(Cola cola, Cola Divisor_total, Cola Divisor_parcial, int numero_actual, float longitud_cola){
    int contador_divisores = 0;
    Cola caux = c_crear();
    TipoElemento X = te_crear(0);
    float mitad_longitud = longitud_cola / 2;
    while (c_es_vacia(cola)!= true)
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
        c_encolar(cola , X);
    }
    if (contador_divisores == longitud_cola)
    {
        X = te_crear(numero_actual);
        c_encolar(Divisor_total, X);
    }
    else if (contador_divisores >= mitad_longitud){
        X = te_crear(numero_actual);
        c_encolar(Divisor_parcial, X);
    }
    return;
}