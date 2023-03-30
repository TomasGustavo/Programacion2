#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tomas.h"
#include "validacionRecursividadTomas.c"



// ejercicio 1
bool palindromo(char* cadena,int inicio, int final){
    

    if (inicio==final || inicio>final){         //si la cadena tiene 1 solo caracter o ya la recorri entera ==> palindromo
        return true;
    }
    else if (cadena[inicio]== cadena[final-1]){       // comparo primer char con el ultimo 
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
        n = n*(-1);
        negativo=true;      // si n es negativo le cambio el signo para poder usar recursividad restando n
    }
    
    
    if(m==0 || n==0){  // si m o n son iguales a 0 devuelve 0
        resultado=0;
    }
    else{
        resultado = m + producto(m,n-1);        // sino llamo de vuelta a la funcion con n-1
    }
    if(negativo==true){
        resultado = resultado*(-1);     // si n era negativo vuelvo a multiplicar por (-1) el resultado para dejarlo con el signo que va
        return resultado;
    }
    return resultado;
}


// ejercicio 3

int terminoSerieFibonacci(int num){
    if (num <= 1){
        return num;
    }
    else{
        return terminoSerieFibonacci(num-1) + terminoSerieFibonacci(num-2);
    }
}

// ejercicio 4

// ejercicio 5

void agregarSeparadorMiles(char *string[], int largo){

    if (largo <= 3){         // si el largo de la cadena es 3 o menos no hago nada, retorno.
        return;
    }

    /* llamo recursivamente a la funcion restandole 3 al largo de la cadena para que ponga bien el punto
       uso memmove para mover la cadena 3 espacio hacia la derecha: le paso 1ro la posicion a partir de la cual copiar, la posicion donde voy a empezar a compiar los datos y la cantidad de datos (bytes) a copiar
       y por ultimo agrego en la posicion largo el punto, largo= largo-3 entonces pone el punto en el "espacio vacio" que quedo despues de hacer el desplazamiento con memmove.

    */
    agregarSeparadorMiles(string, largo-3);
    memmove(string+largo+1,string+largo-2,3);
    string[largo]=".";
}

// ejercicio 6
/**/
char *chinos(int n){
    char* cadena;
    char* cadenaAnterior;
    if(n==1){                       // si n==1 pido memoria para la cadena y copio el chino.
        cadena= (char*) malloc(sizeof(char)*6);
        strcpy(cadena, "(-.-)");
    }
    else if (n>1){                  // si n>1 llamo a la funcion y guardo el resultado en cadena anterior
        cadenaAnterior = chinos(n-1);
        cadena = (char*) malloc(sizeof(char)*LargoCadena(cadenaAnterior)+7);    // pido memoria para cadena por el largo de la cadena anterior + 7, 7 es el espacio de memoria que ocupa cada dibujo de un chino.
        sprintf(cadena,"(-.%s.-)",cadenaAnterior); // sprintf acumula datos en el buffer, los guardo en el string cadena poniendo medio chino,todas las cadenas anteriores y medio chino mas.
    }

    return cadena;
}

// ejercicio 7

// se puede hacer mas bonito y sin tantos if's. dejarlo mas limpio
/*char *ondaDigital(char* onda, char* resultado, int j,  int i){

    if (LargoCadena(onda)==0){
        return;
    }
    
    if(onda[i]=="L" && onda[i-1]!="H"){
        resultado[j]="_";
        i++;
        j++;
    }
    else if (onda[i]=="L" && onda[i-1]=="H"){
        resultado[j]="|";
        resultado[j+1]="_";
        i++;
        j+=2;
    }
    if(onda[i]=="H" && onda[i-1]!="L"){
        resultado[j]="-";
        i++;
        j++;
    }
    else if (onda[i]=="H" && onda[i-1]=="L"){
        resultado[j]="|";
        resultado[j+1]="-";
        i++;
        j+=2;
    }

    if(i<LargoCadena(onda)-1){
        ondaDigital(onda,resultado,j,i);
    }
    

}
*/

// ejercicio 8

// ejercicio 9

bool divisiblePor7(int n){
    int ultimoDigito;
    int resto;

    if (n<70){              // si n<70 dejo de llamar a la funcion y me fijo si al aplicarle modulo de 7 da 0, si si = true, sino = false
        if(n%7==0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        ultimoDigito = n%10;    // "saco" el ultimo digito, lo guardo y lo multiplico x2
        ultimoDigito = ultimoDigito*2;
        resto = n/10;           // al resto que me queda de dividir n por 10 le resto ese ultimo digito y llamo de vuelta a la funcion pasando el nuevo numero.p
        resto -= ultimoDigito;
        return divisiblePor7(resto);
    }

}




