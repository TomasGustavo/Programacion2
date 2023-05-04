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
// ----
    if (numero < 0) {
        numero = 256 + numero;
    }
// ----
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
        p_apilar(pila, x);
        IntToBase(pila, numero, base);
    }
}

char *conversor(int numero, int base)
{
    char *resultado = (char *)calloc(256, sizeof(char));
    Pila pila = p_crear();
    TipoElemento X = te_crear(0);
 if (numero < 0) {
        numero = 256 + numero;
    }
IntToBase(pila, numero, base);
    int indice = 0; // Índice de la posición actual en el buffer de resultados (string)
    // Recorro la pila desopilándola y pasándola al auxiliar
    while (p_es_vacia(pila) != true)
    {
        X = p_desapilar(pila);
        if (X->clave <= 9)
        {
            *(resultado + indice) = 48 + X->clave;
        }
        else
        {
            *(resultado + indice) = 55 + X->clave; // Convierte los n° entre 10 y 15 a letra
        }
        indice++;
    }
    return resultado;
}

/*char *conversor(int numero, int base)
{
    Pila pila = p_crear();
    if (numero < 0)
    {
        numero = numero * -1;
        IntToBase(pila, numero, base);
        char *resultado = (char *)calloc(256, sizeof(char));
        *(resultado + 0) = 45;
        strcat(resultado + 1, mostrarhex(pila));
        return resultado;
    }
    else
    {
        IntToBase(pila, numero, base);
        return mostrarhex(pila);
    }
} */

// PUNTO 2A
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

// PUNTO 2B
Pila insertar(Pila p, TipoElemento elem, int posi)
{
    TipoElemento x = te_crear(0);
    Pila Paux = p_crear();
    int contador = 0;
    bool bandera = false;
    int largoP = contar(p);
    // cuenta que resta el tamaño de elementos de la pila - (posición pasada -1)
    // para saber la cantidad de elementos que tengo que sacar para insertar el nuevo elemento
    int posicionOrdinal = largoP - (posi - 1);

    // recorro mientras p no este vacía y la bandera sea falsa, apilo en pila auxiliar los elementos que saco
    // y sumo la cantidad de vueltas que da hasta que coincide con la posición a insertar y pongo la bandera en true para que salga del while
    while (!p_es_vacia(p) && !bandera)
    {
        x = p_desapilar(p);
        p_apilar(Paux, x);
        contador++;
        if (contador == posicionOrdinal)
        {
            bandera = true;
        }
    }

    // apila el elemento pasado por parámetro en la posición deseada y vuelvo a poner el resto de elementos de p
    p_apilar(p, elem);
    while (!p_es_vacia(Paux))
    {
        x = p_desapilar(Paux);
        p_apilar(p, x);
    }

    return p;
}

// PUNTO 2C
Pila eliminar_por_clave(Pila pila, int clave, bool *estado)
{
    TipoElemento temp = te_crear(0);
    Pila paux = p_crear();
    temp = p_desapilar(pila);
    p_apilar(paux, temp);

    // recorro comparando la clave de cada posición con la clave pasada y que la pila nose vacía
    while (temp->clave != clave && !p_es_vacia(pila))
    {
        temp = p_desapilar(pila);
        p_apilar(paux, temp);
    }

    if (temp->clave == clave) // si con algún elemento hubo coincidencia de claves
    {
        *estado = true;
        temp = p_desapilar(paux); // desapilo una vez, que es el elemento a eliminar

        while (!p_es_vacia(paux))
        { // recorro la pila auxiliar hasta vaciar apilando los datos que saque en la pila original
            temp = p_desapilar(paux);
            p_apilar(pila, temp);
        }
        free(paux);
        return pila;
    }

    else
    {
        while (!p_es_vacia(paux))
        { // recorro la pila auxiliar hasta vaciar apilando los datos que saque en la pila original

            temp = p_desapilar(paux);
            p_apilar(pila, temp);
        }
        free(paux);
        return pila;
    }
}

// PUNDO 2D
Pila intercambiarPos(Pila p, int pos1, int pos2)
{
    Pila paux = p_crear();
    TipoElemento x = te_crear(0);
    TipoElemento primero = te_crear(0);
    TipoElemento segundo = te_crear(0);
    int i = 1;

    if (pos1 == pos2)
    {
        return p;
    }
    else
    {
        // Recorro la pila guardando los valores en las posiciones a intercambiar y la guardo en la auxiliar
        while (!p_es_vacia(p))
        {
            x = p_desapilar(p);
            if (i == pos1)
            {
                primero = x;
            }
            else if (i == pos2)
            {
                segundo = x;
            }
            p_apilar(paux, x);
            i++;
        }
        i--;
        // Recorro la pila auxiliar intercambiando los elementos
        while (!p_es_vacia(paux))
        {
            x = p_desapilar(paux);
            if (i == pos1)
            {
                p_apilar(p, segundo);
            }
            else if (i == pos2)
            {
                p_apilar(p, primero);
            }
            else
            {
                p_apilar(p, x);
            }
            i--;
        }
        return p;
    }
}

// PUNTO 2E
Pila duplicar_pila(Pila pila)
{
    TipoElemento x = te_crear(0);
    Pila Paux = p_crear();
    Pila Pila_duplicada = p_crear();

    // saca todos los elementos de una pila y los guarda en una auxiliar
    while (!p_es_vacia(pila))
    {
        x = p_desapilar(pila);
        p_apilar(Paux, x);
    }
    // vuelve a llenar la pila original pero cada elemento lo guarda 2 veces
    while (!p_es_vacia(Paux))
    {
        x = p_desapilar(Paux);
        p_apilar(pila, x);
        p_apilar(Pila_duplicada, x);
    }
    return Pila_duplicada;
}

// PUNTO 3
bool compara_pilas(Pila p1, Pila p2)
{
    bool rta = true;
    TipoElemento x1 = te_crear(0);
    TipoElemento x2 = te_crear(0);
    Pila pAux = p_crear();

    // desapilo las 2 pilas y comparo elemento a elemento de la misma posición y apilo en 1 pila auxiliar
    // pasando 1ro el elemento de pila1 y luego el de pila2 ,si alguna es falsa retorno false
    while (!p_es_vacia(p1) && (rta))
    {
        x1 = p_desapilar(p1);
        x2 = p_desapilar(p2);
        if (x1->clave != x2->clave)
        {
            rta = false;
            p_apilar(p2, x2);
            p_apilar(p1, x1);
        }
        else
        {
            p_apilar(pAux, x1);
        }
    }

    // vuelvo a apilar las pilas originales, arrancado por la pila 2 y luego pila 1
    // porque fue como me quedaron los elementos del desapile anterior
    while (!p_es_vacia(pAux))
    {
        x1 = p_desapilar(pAux);
        p_apilar(p2, x1);
        p_apilar(p1, x1);
    }
    return rta;
}

int contar(Pila pila)
{
    Pila paux = p_crear();
    TipoElemento X = te_crear(0);
    int contador_elementos;
    while (p_es_vacia(pila) != true)
    {
        X = p_desapilar(pila);
        contador_elementos++;
        p_apilar(paux, X);
    }

    while (p_es_vacia(paux) != true)
    {
        X = p_desapilar(paux);
        p_apilar(pila, X);
    }
    return contador_elementos;
}

Pila invertir_pila(Pila pila)
{
    Pila paux = p_crear();
    Pila pila_invertida = p_crear();
    TipoElemento X = te_crear(0);
    while (p_es_vacia(pila) != true)
    {
        X = p_desapilar(pila);
        p_apilar(paux, X);
        p_apilar(pila_invertida, X);
    }

    while (p_es_vacia(paux) != true)
    {
        X = p_desapilar(paux);
        p_apilar(pila, X);
    }
    return pila_invertida;
}

// PUNTO 6
Pila eliminar_ocurrencias(Pila pila, TipoElemento elemento)
{
    Pila Paux = p_crear();
    Pila nueva_p = p_crear();
    TipoElemento x = te_crear(0);

    // recorro la pila y comparo cada elemento de esta con el pasado por parámetro, si coincide lo elimino
    // sin antes haberlo guardado para no modificar la pila original.
    while (!p_es_vacia(pila))
    {
        x = p_desapilar(pila);
        p_apilar(Paux, x);
        if (x->clave != elemento->clave)
        {
            p_apilar(nueva_p, x);
        }
    }

    // vuelvo a apilar la pila como estaba originalmente.
    while (!p_es_vacia(Paux))
    {
        x = p_desapilar(Paux);
        p_apilar(pila, x);
    }
    // retorno la pila con los elementos eliminados.
    return nueva_p;
}

// PUNTO 6 recursivo
Pila eliminar_ocurrencias_recursivo(Pila pila, TipoElemento elemento)
{
    Pila nueva_p = p_crear();
    TipoElemento x = te_crear(0);

    // caso base: pila vacía
    if (p_es_vacia(pila))
    {
        return nueva_p;
    }

    // caso recursivo: desapilo el elemento del tope y llamo de vuelta a la función
    x = p_desapilar(pila);
    nueva_p = eliminar_ocurrencias_recursivo(pila, elemento);

    // cuando ya saco todos los elementos de la pila original los comparo uno a uno con el elemento a eliminar
    // si no coinciden los apilo en la nueva pila a retornar
    if (x->clave != elemento->clave)
    {
        p_apilar(nueva_p, x);
    }
    // coincidan o no el elemento x con el elemento a eliminar, guardo de todas formar los elementos que saque
    // de la pila pasada por parámetro para no perderla
    p_apilar(pila, x);

    return nueva_p;
}

// PUNTO 7
Pila elemento_en_comun(Pila p1, Pila p2)
{
    Pila pAux1 = p_crear();
    Pila pAux2 = p_crear();
    Pila pComun = p_crear();
    TipoElemento x1 = te_crear(0);
    TipoElemento x2 = te_crear(0);

    while (!p_es_vacia(p1))
    { // saco un elemento de la pila 1 y lo guarda en la aux 1
        x1 = p_desapilar(p1);
        p_apilar(pAux1, x1);
        while (!p_es_vacia(p2))
        { // saco todos los elementos de a uno de la pila 2, los guarda en aux 2 y comparo con el elemento que saque de la pila 1
            x2 = p_desapilar(p2);
            p_apilar(pAux2, x2);
            if (x1->clave == x2->clave)
            { // si coinciden guardo el elemento en la pila a retornar
                p_apilar(pComun, x1);
            }
        }
        while (!p_es_vacia(pAux2))
        { // pongo en el orden original la pila 2 para volver a compararla con el siguiente elemento de pila 1
            x2 = p_desapilar(pAux2);
            p_apilar(p2, x2);
        }
    }
    while (!p_es_vacia(pAux1))
    { // pongo en el orden original la pila 1
        x1 = p_desapilar(pAux1);
        p_apilar(p1, x1);
    }

    free(pAux1); // libero la memoria utilizada para las pilas auxiliares
    free(pAux2);

    return pComun;
}

// PUTO 8

Pila repetidor(Pila p1)
{
    Pila pResult = p_crear();
    Pila pAux = p_crear();
    Pila psec = p_crear();
    TipoElemento x1, x2, x3;
    int contador = 1;
    x1 = p_desapilar(p1);
    p_apilar(pAux, x1);

    while (!p_es_vacia(p1))
    {
        x2 = p_desapilar(p1);
        if (x1->clave == x2->clave)
        {
            contador++;
            p_apilar(pAux, x2);
        }
        else
        {
            p_apilar(pAux, x2);
            p_apilar(psec, x2);
        }
    }
    void *valor_contador = malloc(sizeof(int));
    *(int *)valor_contador = contador;
    x3 = te_crear_con_valor(x1->clave, valor_contador);
    p_apilar(pResult, x3);
    while (p_es_vacia(pAux) != true)
    {
        x2 = p_desapilar(pAux);
        p_apilar(p1, x2);
    }

    while (p_es_vacia(pAux) && !p_es_vacia(psec))
    {
        contador = 1;
        x1 = p_desapilar(psec);
        while (!p_es_vacia(psec))
        {
            x2 = p_desapilar(psec);
            if (x1->clave == x2->clave)
            {
                contador++;
            }
            else
            {
                p_apilar(pAux, x2);
            }
        }
        void *valor_contador = malloc(sizeof(int));
        *(int *)valor_contador = contador;
        x3 = te_crear_con_valor(x1->clave, valor_contador);
        p_apilar(pResult, x3);
        while (p_es_vacia(pAux) != true)
        {
            x2 = p_desapilar(pAux);
            p_apilar(psec, x2);
        }
    }

    return (pResult);
    free(valor_contador);
}
