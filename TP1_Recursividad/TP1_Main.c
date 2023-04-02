#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "TP1_Recursividad.c"

//da verdadero si la cadena es vacia
bool es_vacia(char* cadena) {
    if (cadena[0] == '\0' || cadena[0] == '\n') { // Si el primer carácter es el carácter nulo, la cadena es vacía
        return true;
    }
    else {
        return false;
    }
}

bool primer_caracter_espacio(char* cadena) {

    if (cadena[0] == ' ') { // Si el primer carácter es el carácter es espacio, la cadena es invalida
        return true;
    }
    else {
        return false;
    }
}

bool ultimo_caracter_espacio(char* cadena) {
    int len = strlen(cadena)-2;
    if (cadena[len] == ' ') { // Si el ultimo carácter es el carácter es espacio, la cadena es invalida
        return true;
    }
    else {
        return false;
    }
}


// Elimina los espacios de una cadena
void eliminarEspacios(char* cadena) {
    int i, j;
    int n = strlen(cadena);
    for (i = 0; i < n; i++) {
        if (cadena[i] == ' ') {
            for (j = i; j < n; j++) {
                cadena[j] = cadena[j+1];
            }
            n--;
            i--;
        }
    }
}

// Valida si todos los elementos de una cadena son letras
bool sonLetras(char* cadena) {
    bool res = true;
    for (int i = 0; i<strlen(cadena)-1; i++) {
        if ((!isalpha(cadena[i])) && (cadena[i] != ' ')) {
            res = false;
        }
    }
    return res;
}

//Pasa todos los caracteres de la cadena a minuscula

void a_minusculas(char* cadena) {
    int i = 0;

    while (cadena[i] != '\0') { 
        cadena[i] = tolower(cadena[i]); 
        i++; 
    }
}

// PUNTO 1
void main_palindromo()
{
    char *cadenaDelUsuario = (char *)calloc(100, sizeof(char));
    bool res;
    int longitud, c;
    printf("Ingresa una palabra o expresion: ");
    fflush(stdin);
    fgets(cadenaDelUsuario, 100, stdin);
    
    
    while ((es_vacia(cadenaDelUsuario)) || (primer_caracter_espacio(cadenaDelUsuario)) ||
    (ultimo_caracter_espacio(cadenaDelUsuario)) || (!sonLetras(cadenaDelUsuario))){
        if (es_vacia(cadenaDelUsuario)) printf("La cadena no puede estar vacia: ");
        else if (primer_caracter_espacio(cadenaDelUsuario)) printf("El primer caracter no puede ser espacio: ");
        else if (ultimo_caracter_espacio(cadenaDelUsuario)) printf("El ultimo caracter no puede ser espacio: ");
        else if (!sonLetras(cadenaDelUsuario)) printf("Solo puede ingresar letras y espacios: ");
        //printf("presione enter\n");
       
        fgets(cadenaDelUsuario, 100, stdin);
    }
    
    a_minusculas(cadenaDelUsuario);
    eliminarEspacios(cadenaDelUsuario);
    longitud = strlen(cadenaDelUsuario);
    res = palindromo(cadenaDelUsuario, 0, longitud-2);
    if (res == true)
    {
        printf("Es palindromo");
    }
    else
    {
        printf("no es palindromo");
    }
}

// PUNTO 2
void main_producto(){
    int m, n, validador;
    long long prod;

    printf("Ingrese un numero: ");
    validador = scanf("%i", &m);
    printf("%i %i", validador, m);
    while ((validador != 1) || (m > INT_MAX)){
        if (validador != 1 ) printf("Por favor ingrese un numero: ");
        else if (m > INT_MAX) printf("Por favor ingrese un numero menor a %i: ", INT_MAX);
        while (getchar() != '\n');
        validador = scanf("%i", &m);
    }

    printf("Ingrese otro numero: ");
    validador = scanf("%i", &n);

    while ((validador != 1) || (n > INT_MAX)){
        if (validador != 1 ) printf("Por favor ingrese un numero: ");
        else if (n > INT_MAX) printf("Por favor ingrese un numero menor a %i: ", INT_MAX);
        while (getchar() != '\n');
        validador = scanf("%i", &n);
    }

    prod = producto(m,n);
    printf("Resultado: %lld", prod);
}

// PUNTO 3
void main_fibo(){
    int n, validador;
    long long resultado;
    printf("Ingrese un numero: ");
    validador = scanf("%i", &n);

    while ((validador != 1) || (n < 0) || (n > 40)){
        if (validador != 1 ) printf("Por favor ingrese un numero: ");
        else if (n < 0) printf("Por favor ingrese un numero mayor o igual a 0: ");
        else if (n > 40) printf("Por favor ingrese un numero menor o igual a 40: ");
        while (getchar() != '\n');
        validador = scanf("%i", &n);
    }
    resultado = terminoSerieFibonacci(n);
     printf("Resultado: %lld", resultado);
}

// PUNTO 6
void main_chinos(){
    int n, validador;
    char* resultado;

    printf("Ingrese un numero: ");
    validador = scanf("%i", &n);

    while ((validador != 1) || (n <=0) || (n > 30)){
        if (validador != 1 ) printf("Por favor ingrese un numero: ");
        else if (n <=0) printf("Por favor ingrese un numero mayor a 0: ");
        else if (n > 30) printf("Por favor ingrese un numero menor a 30: ");
        while (getchar() != '\n');
        validador = scanf("%i", &n);
    }
    resultado = chinos(n);

     printf("Resultado: %s", resultado);
}
          
//PUNTO 8
void main_subconjunto()
{
    //char entrada[100];
    int tamano, suma;

    printf("Ingrese el tamano del conjunto: ");
    // fgets(entrada, 100, stdin);
    // entrada[strcspn(entrada, "\n")] = '\0';
    scanf("%d", &tamano);
    while (tamano <= 0)
    {
        printf("Entrada invalida. Ingrese un valor entero positivo para el tamano del conjunto: ");
        scanf("%d", &tamano);
    }

    int ent[tamano];
    for (int i = 0; i < tamano; i++)
    {
        printf("Ingrese el valor %d del conjunto: ", i + 1);
        scanf("%d", &ent[i]);
        while (ent[i] <= 0)
        {
            printf("Entrada invalida. Ingrese un valor entero para el valor %d del conjunto: ", i + 1);
            scanf("%d", &ent[i]);
        }
    }

    printf("Ingrese el valor de la suma deseada: ");
    scanf("%d", &suma);
    while (suma <= 0)
    {
        printf("Entrada invalida. Ingrese un valor entero positivo para la suma deseada: ");
        scanf("%d", &suma);
    }
    int subset[tamano];
    int nivel = 0, subsetSize = 0;
    char salidaparcial[1000];
    strcpy(salidaparcial, "");
    char *resultado = buscaSumaSubconjunto(tamano, nivel, suma, salidaparcial, ent, subset, subsetSize);
    printf("%s", resultado);

}

// Función principal8
/* void main()
{

    // Validación de la opción ingresada
    int opcion;
    opcion = getch();
    while (toupper((char)opcion) != 'S' && toupper((char)opcion) != 'N')
    {
        printf("  La opcion que ingreso es incorrecta.\n");
        printf("  Presione cualquier tecla para volver a ingresar una opcion . . .\n");
        opcion = getch();
    }
    printf("%c", opcion);
} */

/*   // Validación de la opción ingresada
   char input[100];
   int i = 0;
   printf("Ingrese un texto: ");
   scanf("%s", &input); // Leer la entrada del usuario
   while (input[i])
   { // Mientras haya caracteres en la cadena
       if (!isalpha(input[i]))
       { // Si el carácter no es una letra
         // if (!isdigit(input[i]))
         // { // Si el carácter no es una numero
           printf("Error: se ingresó un carácter que no valido.\n");
           printf("Ingrese un texto: ");
           scanf("%s", &input); // Leer la entrada del usuario
           i = 0;
       }
       i++;
   }
   printf("La entrada es válida.\n");
}*/


// PUNTO 10
void main_bomba(){
    int* arreglo = calloc(40, sizeof(int));
    int n, b, i, validador;
    
    //Ingreso del primer valor
    printf("Ingrese un numero n mayor a 1: ");
    validador = scanf("%i", &n);

    printf("%i", validador);
    //Validacion del primer valor (mayor a 1 ya que si no B deberia ser 0 debido a que tiene que ser menor que N)
    while ((validador == 0 ) || (n <=1)){
        if (validador == 0 ) printf("Por favor ingrese un numero: ");
        else if (n <=1) printf("Por favor ingrese un numero mayor a 1: ");
        while (getchar() != '\n');
        validador = scanf("%i", &n);
    }

    //Ingreso del segundo valor
    printf("Ingrese un numero b mayor a 1: ");
    validador = scanf("%i", &b);

    //Validacion del segundo valor
    while ((validador != 1) || (b <=1) || (n <= b)){
        if (validador != 1) printf("Por favor ingrese un numero: ");
        else if (b <= 1)  printf("Por favor ingrese un numero mayor a 1: ");
        else if (n <= b) printf("N tiene que ser mayor a B: ");
        
        while (getchar() != '\n');
        validador = scanf("%i", &b);
    }

    explosion(n,b,arreglo,0);
    i = 0;
    while (arreglo[i] != NULL) {
        printf("%d ", arreglo[i]);
        i++;
    }

    free(arreglo);
}

void menu_principal()
{
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                             TP1 RECURSIVIDAD                              |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Palíndromo\n");
    printf("  2   Producto a partir de sumas sucesivas\n");
    printf("  3   Termino de la serie de Fibonacci\n");
    printf("  4   Cociente a partir de restas sucesivas\n");
    printf("  5   Punto de los miles\n");
    printf("  6   Mafia china\n");
    printf("  7   Onda digital\n");
    printf("  8   Subconjunto\n");
    printf("  9   Divisible por 7\n");
    printf("  10  Numero explosivo\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

int main()
{
    bool salir = false;
    int opcion;

    while (!salir)
    {
        menu_principal();
        scanf("%i", &opcion);
        while (opcion < 0 || opcion > 10)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            while (getchar() != '\n');
            scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 1:
            main_palindromo();
            getch();
            break;
        case 2:
            main_producto();
            getch();
            break;
        case 3:
            main_fibo();
            getch();
            break;
        case 4:
            printf("menu_principal 4");
            break;
        case 5:
            printf("menu_principal 5");
            break;
        case 6:
            main_chinos();
            getch();
            break;
        case 7:
            printf("menu_principal 7");
            break;
        case 8:
            main_subconjunto();
            getch();
            break;
        case 9:
            printf("menu_principal 8");
            break;
        case 10:
            main_bomba();
            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}