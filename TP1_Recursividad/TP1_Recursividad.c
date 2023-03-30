#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include "TP1_Recursividad.h"
#include "recursividad_valen.h"

// PUNTO 8 - SUBCONJUNTO

char *buscaSumaSubconjunto(int tamano, int nivel, int suma, char *salidaparcial, int *ent, int *subset, int subsetSize)
{
    int i;
    char *salida = (char *)malloc(sizeof(char) * 1000);
    strcpy(salida, "");

    if (tamano == nivel)
    {
        if (suma == 0)
        {
            strcat(salida, "{");
            for (i = 0; i < subsetSize; i++)
            {
                char temp[10];
                sprintf(temp, "%d ", subset[i]);
                strcat(salida, temp);
            }
            strcat(salida, "}\n");
            strcpy(salidaparcial, salida);
        }
        return salidaparcial;
    }

    strcpy(salida, buscaSumaSubconjunto(tamano, nivel + 1, suma, salidaparcial, ent, subset, subsetSize));
    salidaparcial[0] = '\0';
    subset[subsetSize] = ent[nivel];
    subsetSize++;
    strcat(salida, buscaSumaSubconjunto(tamano, nivel + 1, suma - ent[nivel], salidaparcial, ent, subset, subsetSize));
    return salida;
}

int main_subconjunto()
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
    return 0;
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

void main()
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
            printf("menu_principal 8");
            break;
        case 0:
            salir = true;
            break;
        }
    }
}