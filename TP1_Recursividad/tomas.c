#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tomas.h"
#include "validacionRecursividadTomas.c"



// ejercicio 1
bool palindromo(char* cadena,int inicio, int final){
    int i=0;

    if (inicio==final || inicio>final){         //si la cadena tiene 1 solo caracter o ya la recorri entera ==> palindromo
        return true;
    }
    else if (cadena[inicio]== cadena[final]){       // comparo primer char con el ultimo 
        return palindromo(cadena,inicio+1,final-1); // si es true, vuelvo a llamar a la funcion sumando var inicio y restando var final para ir recorriendo la cadena
    }
    else{
        return false;   // si no se cumplio ninguna de las anteriores condicones entonces no era palindromo
    }
}

// ejercicio 2

int producto(int m,int n){
    int resultado=0;
    bool negativo = false;
    
    if(n<0){
        n*(-1);
        negativo=true;      // si n es negativo le cambio el signo para poder usar recursividad restando n
    }
    
    
    if(m==0 || n==0){  // si m o n son iguales a 0 devuelve 0
        resultado=0;
    }
    else{
        resultado = m + producto(m,n-1);        // sino llamo de vuelta a la funcion con n-1
    }
    if(negativo==true){
        resultado = resultado*(-1);
        return resultado;
    }
    return resultado;
}





