#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP3_pilas.h"
#include "pilas.h"
#include "tipo_elemento.h"

// PUNTO 2A
bool buscar_c (Pila p, int x){
    TipoElemento temp = te_crear(0);
    bool rta;
    Pila paux = p_crear();
    temp = p_desapilar(p);
    p_apilar(paux,temp);
    while(temp->clave != x && !p_es_vacia(p)){
        temp = p_desapilar(p);
        p_apilar(paux,temp);
    }
    if(temp->clave == x){
        rta = true;
    }
    else{
        rta = false;
    }
    while(!p_es_vacia(paux)){
        temp = p_desapilar(paux);
        p_apilar(p,temp);
    }
    return rta;
}