#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "recursividad_valen.h"

// PUNTO 2
int producto(int m, int n){
    int resultado;
    bool negativo = false;

    /*Si n es negativo, lo convierte a positivo para que funcione la recursion,
     pero el boolean lo recuerda para mas adelante */

    if (n < 0){
        n = n * (-1);
        negativo = true;
    }

    /*Si n es 0 (caso base) devuelve 0 y si es mayor, vuelve
    a llamar a la funcion con n-1 (tiede al caso base)*/
    if (n==0){
        resultado = 0;
    }
    else{
        resultado = m + producto(m, n-1);
    }

    /*si n era negativo al entrar a la funcion, ahora multiplica al resultado 
    por -1*/
    if (negativo == true){
        resultado = resultado * (-1);
    }

    
    return resultado;
}

//PUNTO 3
int terminoSerieFibonacci(int num){
    int resultado;
    if (num <= 1) resultado = num;
    else resultado = terminoSerieFibonacci(num-1) + terminoSerieFibonacci(num-2);  
    return resultado;
}

//PUNTO 6
char *chinos(int n){
    char* cadena;
    char *cadenaAnt;
    int longitud;

    if (n==1){
        cadena = (char*) malloc(6 * sizeof(char));
        strcpy(cadena, "(-.-)");
    } else {
        cadenaAnt = chinos(n - 1);
        longitud = strlen(cadenaAnt) + 7;
        cadena = (char*) malloc(sizeof(char) * longitud);
        sprintf(cadena, "(-.%s.-)", cadenaAnt);
    }
    
    return cadena;
}

//PUNTO 7
void ondaDigitalAux(char* onda,char* cadena, int i, int j){
    char guionAlto = 'a';
    char guionBajo = 95;
    char barra = 'b'; 
    char letrah = 'h';

        if ((i > 0) && (onda[i] != onda[i-1])){
            cadena[j] = barra;
            if((onda[i])== letrah) {
                j++;
                cadena[j] = guionAlto;
            } else {
                j++;
                cadena[j] = guionBajo;
            }
        } else {
            if((onda[i])== letrah) {
                cadena[j] = guionAlto;
            } else {
                cadena[j] = guionBajo;
            }
        }

    
        if (i < (strlen(onda) -1)) {
            ondaDigitalAux(onda,cadena, i+1,j+1);
        }
  
}

char* ondaDigital(char *onda){
    int longitud = strlen(onda);
    char* resultado = (char*) calloc(longitud, sizeof(char));

    ondaDigitalAux(onda, resultado, 0,0);
    return resultado;
}


int main (){
    /* MAIN PUNTO 2 
    int prod, m, n;
    printf("Ingrese un numero: ");
    scanf("%i", &m);
    printf("Ingrese otro numero");
    scanf("%i", &n);

    prod = producto(m,n);
    printf("Resultado: %i", prod);
    return 0;
    */
    
    /*MAIN PUNTO 3
      int resultado, n;
    printf("Ingrese un numero: ");
    scanf("%i", &n);
    resultado = terminoSerieFibonacci(n);
     printf("Resultado: %i", resultado);
     */
  
    /* MAIN PUNTO 6
    int n;
    char* resultado;

    printf("Ingrese un numero: ");
    scanf("%i", &n);
    resultado = chinos(n);

     printf("Resultado: %s", resultado);
    */
 
    char *cadenaDelUsuario = (char*) calloc(100, sizeof(char));
    char *cadenaDeRespuesta = (char*) calloc(100 ,sizeof(char));

    printf("Ingresa una cadena: ");
    scanf("%s", cadenaDelUsuario); 
    cadenaDeRespuesta = ondaDigital(cadenaDelUsuario);
    printf("La cadena que ingresaste es: %s", cadenaDeRespuesta);

    return 0;
}

