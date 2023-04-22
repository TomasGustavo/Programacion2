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
    while(temp->clave != x && !p_es_vacia(p)){      // saco elementos la pila hasta que coicida con el elemento a buscar o hasta que este vacia
        temp = p_desapilar(p);
        p_apilar(paux,temp);
    }
    if(temp->clave == x){    // si coinciden los elementos retorno true, sino salio del ciclo porqeu se vacio lo que significa que no encontro el elemento
        rta = true;
    }
    else{
        rta = false;
    }
    while(!p_es_vacia(paux)){       // vuelvo a poner en orden todos los elementos que saque en la pila original
        temp = p_desapilar(paux);
        p_apilar(p,temp);
    }
    free(paux);     // libero la memoria que use para la pila auxiliar
    return rta;
}

// PUNTO 2C 
Pila eliminar_por_clave(Pila pila, int clave){
    TipoElemento temp = te_crear(0);
    Pila paux = p_crear();
    temp = p_desapilar(pila);
    p_apilar(paux,temp);
    while(temp->clave != clave && !p_es_vacia(pila)){
        temp = p_desapilar(pila);
        p_apilar(paux,temp);
    }
    
    if(temp->clave == clave){
        temp = p_desapilar(paux); // desapilo una vez, que es el elemento a eliminar
        
        while(!p_es_vacia(paux)){     // recorro la pila auxiliar hasta vaciar apilando los datos que saque en la pila original
            temp = p_desapilar(paux);
            p_apilar(pila,temp);
        }
        free(paux);
        return pila;
    }

    else{
        while(!p_es_vacia(paux)){     // recorro la pila auxiliar hasta vaciar apilando los datos que saque en la pila original
            
            temp = p_desapilar(paux);
            p_apilar(pila,temp);
        }
        free(paux);
        return pila;
    }
    
    
    
}

// PUNTO 3
bool compara_pilas(Pila p1, Pila p2){
    bool rta = true;
    TipoElemento x1 = te_crear(0);
    TipoElemento x2 = te_crear(0);
    Pila pAux = p_crear();

    while(!p_es_vacia(p1)){
        x1 = p_desapilar(p1);
        x2 = p_desapilar(p2);
        if(x1->clave != x2->clave){
            rta = false;
        }
        p_apilar(pAux,x1);
        p_apilar(pAux,x2);
    }

    while(!p_es_vacia(pAux)){
        x2 = p_desapilar(pAux);
        x1 = p_desapilar(pAux);
        p_apilar(p2,x2);
        p_apilar(p1,x1);
    }
    return rta;
}
