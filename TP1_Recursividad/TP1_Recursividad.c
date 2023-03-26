#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "TP1_Recursividad.h"

// Función principal
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

int main()
{

    // Validación de la opción ingresada
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
}S