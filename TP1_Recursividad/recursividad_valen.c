#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "recursividad_valen.h"








//PUNTO 5 
void agregarSeparadorMiles(char *cadena, int longitud, int contador){

    if (longitud == 0) {
        printf("%c",cadena[longitud]);
    } else {
        if (contador == 1) {
            agregarSeparadorMiles(cadena, longitud-1, 3);
            printf(".");
            printf("%c",cadena[longitud]);
        } else {
            agregarSeparadorMiles(cadena, longitud-1, contador - 1);
            printf("%c",cadena[longitud]);
        }
    }
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

//PUNTO 7 CON PRINTF QUE MUESTRA BIEN LOS CARACTERES DE LA ONDA
void ondaDigitalPrint(char *onda, int i){

    if ((i > 0) && (onda[i] != onda[i-1])){
           printf("│");
    }
    
    if((onda[i])== 'h') {
        printf("¯") ; 
    } else {
        printf("_");
        }
        
    if (i < (strlen(onda) -1)) {
        ondaDigitalPrint(onda,i+1);
    }
}

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
    
    */
 
    /* MAIN PUNTO 7A
    char *cadenaDelUsuario = (char*) calloc(100, sizeof(char));
    char *cadenaDeRespuesta = (char*) calloc(100 ,sizeof(char));

    printf("Ingresa una cadena: ");
    scanf("%s", cadenaDelUsuario); 
    cadenaDeRespuesta = ondaDigital(cadenaDelUsuario);
   printf("La onda es: %s", cadenaDeRespuesta);

    return 0;
    */

   /* Main Punto 7B
       char *cadenaDelUsuario = (char*) calloc(100, sizeof(char));

    printf("Ingresa una cadena: ");
    scanf("%s", cadenaDelUsuario); 
    ondaDigitalPrint(cadenaDelUsuario,0);
   */

    /* PUNTO 1 MAIN
    char *cadenaDelUsuario = (char*) calloc(100, sizeof(char));
    bool res;
    int longitud;

    printf("Ingresa una cadena a ver que es: ");
    scanf("%s", cadenaDelUsuario); 
    longitud = strlen(cadenaDelUsuario) -1;
    res = palindromo(cadenaDelUsuario, 0, longitud);

    if (res == true) {
        printf("Es palindromo");
    } else {
        printf("no es palindromo");
    }
    */

   /* MAIN PUNTO 5
   char *cadenaDelUsuario = (char*) calloc(100, sizeof(char));
    int longitud;

    printf("Ingresa una cadena de numeros: ");
    scanf("%s", cadenaDelUsuario); 
    longitud = strlen(cadenaDelUsuario) -1;
    printf("La cadena rta es: ");
    agregarSeparadorMiles(cadenaDelUsuario, longitud, 3);
    
   */




