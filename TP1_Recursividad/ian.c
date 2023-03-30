#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ian.h"

//ejercicio 2
int producto(int m, int n){
if (n == 0){
    return 0;   
}
else if(n==1){
return m;
}
else{
return (m + producto(m, n-1));
}
}//falta validacion de datos

//ejercicio 3

int terminoSeridFibonacci(int num){
if(num<=1){
return num;
}
else{
return terminoSeridFibonacci(num - 1) + terminoSeridFibonacci(num - 2);
}
}


//ejercicio 4

float division(int m, int n, int limite_Decimal){ 
/*esta funcion se encarga de restar en cada sucesion el valor del dividendo(m) 
con el del divisor(n) hasta que el resto sea menor a n*/ 
float resto = m;  
float cociente = 0;

/*si n es menor a 0 y m mayor a 0, se intercambian los signos entre m y n 
para que funcione la recursion correctamente*/
if (n < 0 && m > 0){
    n = n * -1;
    m = m * -1;
}

/*una vez que el resto sea menor a n se divide el resto por el n 
para saber si el cociente(resultado) tiene valores decimales*/ 
else if (resto < n && limite_Decimal != 0)
{       
        
        resto = resto * 10;
        cociente = division(resto-n, n, limite_Decimal - 1);
        cociente++;
        cociente = cociente * 0.1; /*esta parte se encarga de desplazar a la parte decimal 
        los valores correspondientes a la misma*/
        return cociente;
        
}
else if (limite_Decimal == 0){
    /* si el numero decimal es muy grande el limite_Decimal 
    se va a encargar de cortar la funcion con 4 digitos decimales*/
    return cociente;
}
else {
cociente = division(m-n, n, limite_Decimal);

/*luego se usa el cociente como contador una vez retornada la sucesion 
para obtener el resultado segun la cantidad de sucesiones*/ 
cociente++;  
return cociente;
}
}


//ejercicio 9
bool divisiblePor7(int n){
    bool condicion;
    int cifra_derecha;
    int numero_izquierda;
    if (n < 0)
    {
        n = n * -1;
    }
    
    if(n < 70){
        if (n % 7 == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        cifra_derecha = n % 10; //calculos para obtener la cifra derecha
        numero_izquierda = n / 10;
        cifra_derecha = cifra_derecha * 2;
        numero_izquierda = numero_izquierda - cifra_derecha;
        condicion = divisiblePor7(numero_izquierda);
        return condicion;
    }
}


int main(){
    //ejercicio 2
    /*
    int m, n, resultado_2;
    printf("ingrese el primer numero: ");
    scanf("%d", &m);
    printf("ingrese el segundo numero: ");
    scanf("%d", &n);
    resultado_2 = producto(m, n);
    printf("%d * %d = %d", m, n, resultado_2); */
    
    //ejercicio 3 
    /*
    int numero, fibo;
    printf("\ningrese numero para calcular fibonacci: ");
    scanf("%d", &numero);
    fibo = terminoSeridFibonacci(numero);
    printf("fibonacci de %d = %d", numero, fibo); 
    printf("\n")*/
    
    //ejercicio 4
    int dividendo, divisor; 
    float resultado_4;
    while (divisor == 0)
    {
        printf("\ningrese el dividendo: ");
        scanf("%d", &dividendo);
        printf("ingrese el divisor: ");
        scanf("%d", &divisor);
        if (divisor == 0)
        {
            printf("no se puede dividir por 0\n");
        }     
    }
    resultado_4 = division(dividendo, divisor, 5);
    printf("%d / %d = %0.4f", dividendo, divisor, resultado_4);
    
    
    //ejercicio 9
    int numero_ej9;
    bool resultado_9;
    printf("ingrese un numero para saber si es divisble por 7: ");
    scanf("%d", &numero_ej9);
    resultado_9 = divisiblePor7(numero_ej9);
    if (resultado_9 == false)
    {
        printf("el numero %d no es divisible por 7", numero_ej9);
    }
    else if (resultado_9 == true){
        printf("el numero %d es divisible por 7", numero_ej9);
    }   

}





