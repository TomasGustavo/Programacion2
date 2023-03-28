#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int ValidarStringAlfa(char cadena[]){
    int i=0;

    while(cadena[i]){
        if(!isalpha(cadena[i])){  // si el char no es alfabetico retorna 1 que es falso.
            return 1;
        }
        //printf("%c\n",cadena[i]);
        i++;
    }
    return 0;
    
}  

int ValidarCadenaNum (int cadena[]){
    int i=0;

    while(cadena[i]){              
        if (!isdigit(cadena[i])){ // si algun elemento de la cadena no es un numero retorna 1 que es falso
            return 1;
        }
        i++;
    }
    return 0;
}

int* CambiarSigno(int* cadena, int opc){
    int i=0;
    while(cadena[i]){
        if(opc == 1 && cadena[i]<0){                // si  opc ==1 cambio los numeros negativo a positivos
            cadena[i]= cadena[i]*(-1);
        }
        else if(opc == 0 && cadena[i]>0){ 
            cadena[i]= cadena[i]*(-1);               // si opc ==0 cambio los numeros positivos a negativos
        }
        i++;
    }

    return cadena;
}

int LargoCadena(void *cadena){

    int largo = strlen(cadena);

    return largo;
}

char* MayuscMinusc(char* cadena, int opc){      // intento de funcion de pasar un string a todos mayusc o minus
    int i=0;                                      // no me anda el toupper o tolower no se porque.
    

    while (cadena[i]){                              // recorre la cadena hasta el caracter nulo '\0'
        if (opc == 1){
           //printf("%c",cadena[i]);       
           cadena[i] = toupper(cadena[i]);          // si opc == 1 paso el char de la posicion i a mayusc.
                                                  
                
        }
        else if (opc==0){
           
            cadena[i] = tolower(cadena[i]);         // si opc == 0 paso el char de la posicion i a minusc.
            
                
        }
        i++;
    }
    
    return cadena;
}

void mostrarcadenaChar(char *cadena){
    int i = 0;
    int largo = LargoCadena(cadena);

    for (i=0;i<largo;i++){
        printf("%c",cadena[i]);
    }
    printf("\n");
}
void mostrarcadenaNum(int cadena[]){
    int i = 0;

    while(cadena[i]){
        printf("%d ",cadena[i]);
        i++;    
    }
    printf("\n");
}

void cargarString(char* cadena){
    int i=0;

    printf("ingresar datos: ");
    scanf("%s",cadena);
    
}

int main(){
    char *cadena = (char*) malloc(sizeof(char)*35);
    
    cargarString(cadena);
    //int cadenaNum [15]={1,-2,3,-4,5,6,7,8,-9};
    //int *ptr = cadenaNum;
     
    /*int result;
    result = ValidarStringAlfa(cadena);

    if(result == 0){
        printf("cadena con caracteres correctos\n");
    }
    else{
        printf("hay al menos 1 caracter incorrecto en la cadena.\n");
    }
    */
   //mostrarcadenaNum(ptr);
   //ptr = CambiarSigno(cadenaNum,1);
   //mostrarcadenaNum(ptr);
   mostrarcadenaChar(cadena);
   cadena = MayuscMinusc(cadena,1);
   mostrarcadenaChar(cadena);
    /*char* x = "a";
    printf("%c",*x);
    x = toupper(*x);
    printf("%c",x);*/
    free(cadena);
}
