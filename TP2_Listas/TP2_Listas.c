#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP2_Listas.h"
#include "tipo_elemento.h"
#include "listas.h"

Lista cargarListaClaves(){
    int tamano, validador, claveIngresada;
    TipoElemento X;
    Lista L;

    L = l_crear();
    printf("Ingrese la cantidad de elementos de la lista: \n");
    validador = scanf("%i", &tamano);

    while ((validador != 1) || (tamano < 0) || (tamano > 99))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese el tamaño del conjunto [1-99] (se truncara si coloca decimales): " ANSI_YELLOW);
        while (getchar() != '\n');
        validador = scanf("%i", &tamano);
    }

    if (tamano > 0){
            for (int i = 1; i <= tamano; i++){
                printf(ANSI_bBLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
                validador = scanf("%d", &claveIngresada);
                while ((validador != 1) || (claveIngresada <= -10000) || (claveIngresada >= 10000))
                {
                    printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
                    printf(ANSI_bBLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
                    while (getchar() != '\n');
                    validador = scanf("%d", &claveIngresada);
                }
                X = te_crear(claveIngresada);
                l_agregar(L,X);
            }
            printf(ANSI_bGREEN "La lista fue cargada con exito \n");
    } else printf(ANSI_bGREEN "La lista vacia creada \n");

    return L;
}


int menor (Lista lista, int * posicion){
    TipoElemento x, menor;
    int posActual = 1;
    Iterador ite = iterador(lista);
    menor = siguiente(ite);
    posActual++;
    while (hay_siguiente(ite)){
        x = siguiente(ite);
        if (x->clave < menor->clave){
            menor = x;
            *posicion = posActual;
        }
        posActual++;
    }

    return menor->clave;
}

int mayor (Lista lista, int * repeticiones) {
    TipoElemento x, mayor;
    Iterador ite = iterador(lista);
    int cantidad = 1;
    mayor = siguiente(ite);

    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        if (x->clave > mayor->clave){
            mayor = x;
            cantidad = 1;
        } else if (x->clave == mayor->clave){
            cantidad++;
        }
    }

    *repeticiones = cantidad;
    return mayor->clave;
    
}

float promedio (Lista l, int i, float suma){
    TipoElemento x;
    if (i >= l_longitud) return suma/i;
    else {
        i++;
        x = l_recuperar(l,i);
        suma += x->clave;
        promedio(l, i, suma);
    }
    return suma;
}

Lista multiplos (Lista l, int n){
    TipoElemento x,x1;
    Lista nueva = l_crear();
    Iterador ite = iterador(l);
    while (hay_siguiente(ite))
    {
        x = siguiente(ite);
        if ((x->clave % n) == 0){
            x1 = x;
            l_agregar(nueva,x1);
        }
    }
    return nueva;
}

bool esMultiplo (Lista l1, Lista l2, int * escalar){
    int e = 0;
    TipoElemento x1, x2;
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    bool resultado = true;

    if (l_longitud(l1) != l_longitud(l2)) resultado = false;
    else {
        x1 = siguiente(ite1);
        x2 = siguiente(ite2);
        if ((x1->clave != 0) && (x2->clave % x1->clave == 0)){
            e = x2->clave / x1->clave;
            *escalar = e;
        } else resultado = false;

        while (hay_siguiente(ite1) && resultado == true) {
            x1 = siguiente(ite1);
            x2 = siguiente(ite2);
            if ((x1->clave != 0) && (x2->clave % x1->clave == 0)){
                if (e != (x2->clave / x1->clave)) *escalar = 0;
            } else resultado = false;
            
        }
    }
    return resultado;
}

bool sublista (Lista l1, Lista l2){
    TipoElemento x1,x2;
    bool resultado = true;
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    bool encontro;

    if (l_es_vacia(l2)) resultado = true;
    else if (l_es_vacia(l1) && l_es_vacia(l2)) resultado = true;
    else if (l_longitud(l2) > l_longitud(l1)) resultado = false;
    else{
        while (hay_siguiente(ite2) && (resultado == true))
        {
            x2 = siguiente(ite2);
            encontro = false;
            while (hay_siguiente(ite1) && encontro == false)
            {
                x1 = siguiente(ite1);
                if (x1->clave == x2->clave) encontro = true;
            }
            if (encontro == false) resultado = false;
        }
    }
    return resultado;
}