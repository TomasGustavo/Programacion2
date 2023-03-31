#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP1_Recursividad.h"

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
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (!isalpha(cadena[i])) {
            res = false;
        }
    }
    return res;
}

void main_subconjunto()
{
    char entrada[100];
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

void main_palindromo()
{
    char *cadenaDelUsuario = (char *)calloc(100, sizeof(char));
    bool res;
    int longitud;
    printf("Ingresa una cadena a ver que es: ");
    scanf("%s", cadenaDelUsuario);
    longitud = strlen(cadenaDelUsuario) - 1;
    res = palindromo(cadenaDelUsuario, 0, longitud);
    if (res == true)
    {
        printf("Es palindromo");
    }
    else
    {
        printf("no es palindromo");
    }
}

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
        while (getchar() != '\n') 
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
            printf("menu_principal 2");
            break;
        case 3:
            printf("menu_principal 3");
            break;
        case 4:
            printf("menu_principal 4");
            break;
        case 5:
            printf("menu_principal 5");
            break;
        case 6:
            printf("menu_principal 6");
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