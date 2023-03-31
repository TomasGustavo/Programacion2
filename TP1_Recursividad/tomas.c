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

float division(int m, int n) {
    bool negativo = false;
    // Caso base
    if(n<0){            // si n es negativo pongo en true la variable y multiplico por -1 n para que funcione la recurvidad.
        n = n*(-1);
        negativo = true;
        if(m<0){
            m = m*(-1);     // pero si m tambien en negativo, lo paso a positivo tambien y vuevlo a poner en false la variable para que al final no multiplique por -1, porque menos por menos = mas
            negativo=false;
        }
    }
    if (m < n) {
        return (float) m / n;  // si el dividendo es menos que el divison retorno la division "real(con ,)" de los 2
    }
    // Caso recursivo
    float cociente = division(m - n, n); // sino llamo recursivamente a la funcion guardandola en la variable
    if(negativo==true){
        return (cociente+1)*(-1);      // si negativo es true multiplico el cociente por -1 para retornar el valor verdadero
    }
    else{                           // retorno el cociente+1 asi en cada llamado le voy sumando las vueltas que dio.
        return cociente+1;
    }
}
// ejercicio 5

void AgregarMiles(char* str, int len) {
    bool x;
    
    //si el largo es menos o igual a 3 solo retorna
    if (len <= 3) {
        return;
    }

    // recursivamente agrega un punto cada 3 digitos
    
    AgregarMiles(str, len - 3);
    memmove(&str[len - 2], &str[len - 3], 3*(len/2)+2);
    if(len>=7){
        str[len-2] = '.';
    }
    else{
        str[len-3] = '.'; 
    }    
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

void ondaDigital(char *onda, int i){

    if ((i > 0) && (onda[i] != onda[i-1])){
           printf("│");
    }
    
    if((onda[i])== 'H') {
        printf("¯") ; 
    } else {
        printf("_");
        }
        
    if (i < (strlen(onda) -1)) {
        ondaDigital(onda,i+1);
    }
}


// ejercicio 8
void subconjuntoQueSumanN(int *cadena,int size,int n,int index,int * temp,int j){
    
    if (index==size){
        int s=0;
        for (int i=0;i<j;i++){
            s+=temp[i];
        }
        if (s==n){
            printf("{");
            for(int i=0;i<j;i++){
                printf("%i",temp[i]);
                if(i!=j-1){
                    printf(",");
                }
            }
            printf("}");
        }
        return;
    }
    temp[j]=cadena[index];
    subconjuntoQueSumanN(cadena,size,n,index+1,temp,j+1);
    subconjuntoQueSumanN(cadena,size,n,index+1,temp,j);
}
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

void explosion(int n, int b,int*array,int i){
    int n1,n2;
    

    if(n>b){
        n1 = n/b;
        n2 = n - n1;
        
        if(n1>b){
            return explosion(n1,b,array,i);
        }
        else{
           array[i]=n1;
            i++;
        }
        if(n2>b){
            return explosion(n2,b,array,i);
        }
        else{
            array[i]= n2;
            i++;
        }
    }
            
}



