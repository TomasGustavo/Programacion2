#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "TP1_Recursividad.h"
// #include "TP1_Recursividad.c"

// da verdadero si la cadena es vacia
bool es_vacia(char *cadena)
{
    if (cadena[0] == '\0' || cadena[0] == '\n')
    { // Si el primer carácter es el carácter nulo, la cadena es vacía
        return true;
    }
    else
    {
        return false;
    }
}

bool primer_caracter_espacio(char *cadena)
{

    if (cadena[0] == ' ')
    { // Si el primer carácter es el carácter es espacio, la cadena es invalida
        return true;
    }
    else
    {
        return false;
    }
}

bool ultimo_caracter_espacio(char *cadena)
{
    int len = strlen(cadena) - 2;
    if (cadena[len] == ' ')
    { // Si el ultimo carácter es el carácter es espacio, la cadena es invalida
        return true;
    }
    else
    {
        return false;
    }
}

// Elimina los espacios de una cadena
void eliminarEspacios(char *cadena)
{
    int i, j;
    int n = strlen(cadena);
    for (i = 0; i < n; i++)
    {
        if (cadena[i] == ' ')
        {
            for (j = i; j < n; j++)
            {
                cadena[j] = cadena[j + 1];
            }
            n--;
            i--;
        }
    }
}

// Valida si todos los elementos de una cadena son letras
bool sonLetras(char *cadena)
{
    bool res = true;
    for (int i = 0; i < strlen(cadena) - 1; i++)
    {
        if ((!isalpha(cadena[i])) && (cadena[i] != ' '))
        {
            res = false;
        }
    }
    return res;
}

// Pasa todos los caracteres de la cadena a minuscula

void a_minusculas(char *cadena)
{
    int i = 0;

    while (cadena[i] != '\0')
    {
        cadena[i] = tolower(cadena[i]);
        i++;
    }
}

// Valida si todos los elementos de una cadena son numeros
bool sonNumeros(char *cadena)
{
    bool res = true;
    for (int i = 0; i < strlen(cadena) - 1; i++)
    {
        if (!isdigit(cadena[i]))
        {
            res = false;
        }
    }
    return res;
}

// Elimina los ceros a la izquierda de una cadena
void eliminar_ceros_izquierda(char *cadena)
{
    while (cadena[0] == '0')
    {
        for (int j = 0; j < strlen(cadena); j++)
        {
            cadena[j] = cadena[j + 1];
        }
    }
}

// PUNTO 1
void main_palindromo()
{
    char *cadenaDelUsuario = (char *)calloc(100, sizeof(char));
    bool res;
    int longitud;
    printf("Ingresa una palabra o expresion: ");
    fflush(stdin);
    fgets(cadenaDelUsuario, 100, stdin);

    while ((es_vacia(cadenaDelUsuario)) || (primer_caracter_espacio(cadenaDelUsuario)) ||
           (ultimo_caracter_espacio(cadenaDelUsuario)) || (!sonLetras(cadenaDelUsuario)))
    {
        if (es_vacia(cadenaDelUsuario))
            printf("La cadena no puede estar vacia, ingrese una nueva cadena: ");
        else if (primer_caracter_espacio(cadenaDelUsuario))
            printf("El primer caracter no puede ser espacio, ingrese una nueva cadena: ");
        else if (ultimo_caracter_espacio(cadenaDelUsuario))
            printf("El ultimo caracter no puede ser espacio, ingrese una nueva cadena: ");
        else if (!sonLetras(cadenaDelUsuario))
            printf("Solo puede ingresar letras y espacios, ingrese una nueva cadena: ");
        // printf("presione enter\n");

        fgets(cadenaDelUsuario, 100, stdin);
    }

    a_minusculas(cadenaDelUsuario);
    // eliminarEspacios(cadenaDelUsuario);
    longitud = strlen(cadenaDelUsuario);
    res = palindromo(cadenaDelUsuario, 0, longitud - 2);
    if (res == true)
    {
        printf("Es palindromo");
    }
    else
    {
        printf("no es palindromo");
    }
    free(cadenaDelUsuario);
}

// PUNTO 2
void main_producto()
{
    int m, n, validador;
    long long prod;
    int maxM = 999999;
    int maxN = 999;

    printf("Ingrese un numero: ");
    validador = scanf("%i", &m);
    fflush(stdin);
    // printf("%i %i", validador, m);
    while ((validador != 1) || (m > maxM) || m == '\0' || m == '\n')
    {
        if (validador != 1)
            printf("Por favor ingrese un numero: ");
        else if (m > maxM)
            printf("Por favor ingrese un numero menor a %i: ", maxM);
        else if (m == '\0')
            printf("Por favor ingrese un numero un numero valido: ");
        else if (m == '\n')
            printf("Por favor ingrese un numero un numero valido: ");
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &m);
    }

    printf("Ingrese otro numero: ");
    validador = scanf("%i", &n);
    fflush(stdin);
    while ((validador != 1) || (n > maxN))
    {
        if (validador != 1)
            printf("Por favor ingrese un numero: ");
        else if (n > maxN)
            printf("Por favor ingrese un numero menor a %i: ", maxN);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }

    prod = producto(m, n);
    printf("Resultado: %lld", prod);
}

// PUNTO 3
void main_fibo()
{
    int n, validador;
    long long resultado;
    printf("Ingrese un numero: ");
    validador = scanf("%i", &n);

    while ((validador != 1) || (n < 0) || (n > 40))
    {
        if (validador != 1)
            printf("Por favor ingrese un numero: ");
        else if (n < 0)
            printf("Por favor ingrese un numero mayor o igual a 0: ");
        else if (n > 40)
            printf("Por favor ingrese un numero menor o igual a 40: ");
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }
    resultado = terminoSerieFibonacci(n);
    printf("Resultado: %lld", resultado);
}

// PUNTO 4
void main_division()
{
    int dividendo, divisor;
    float resultado_4;
    int no_caracter_4, no_caracter_4_1;
    while (divisor == 0)
    {
        // system("cls");
        printf("\nIngrese el dividendo(max digitos: 4): ");
        no_caracter_4 = scanf("%d", &dividendo);
        printf("Ingrese el divisor(max digitos: 4): ");
        no_caracter_4_1 = scanf("%d", &divisor);
        fflush(stdin);
        if (no_caracter_4 == 0 || no_caracter_4_1 == 0)
        {
            divisor = 0;
            printf("\nNo estan permitidos los caracteres y los numeros flotantes\n");
        }
        else if (dividendo > 10000 || divisor > 10000 || dividendo < -10000 || divisor < -10000)
        {
            divisor = 0;
            printf("\nIngrese como maximo 4 digitos por favor\n");
        }
        else if (divisor == 0)
        {
            printf("No se puede dividir por 0\n");
        }
        printf("presione ENTER para continuar\n");
        // while(getchar() != '\n');
        getchar();
        resultado_4 = division(dividendo, divisor, 5);
        /*si ambos (dividendo y divisor) eran negativos se deja el resultado positivo*/
        if (dividendo < 0 && divisor < 0)
        {
            resultado_4 = resultado_4 * 1;
        }
        /*si el dividendo o el divisor eran negativos se le aplica el resultado negativo a el resultado*/
        else if (dividendo < 0 || divisor < 0)
        {
            resultado_4 = resultado_4 * -1;
        }

        printf("%d / %d = %0.4f", dividendo, divisor, resultado_4);
        getchar();
    }
}

// PUNTO 5
void main_miles()
{
    char *cadenaDelUsuario = (char *)calloc(100, sizeof(char));
    int longitud;

    printf("Ingresa un numero: ");
    fflush(stdin);
    fgets(cadenaDelUsuario, 100, stdin);

    while (es_vacia(cadenaDelUsuario) || strlen(cadenaDelUsuario) > 99 || !sonNumeros(cadenaDelUsuario))
    {
        if (es_vacia(cadenaDelUsuario))
            printf("Por favor ingrese un numero: ");
        else if (strlen(cadenaDelUsuario) > 99)
            printf("El numero debe tener menos de 99 digitos, ingrese un nuevo numero: ");
        else if (!sonNumeros(cadenaDelUsuario))
            printf("Solo puede ingresar numeros, ingrese un nuevo numero: ");
        fgets(cadenaDelUsuario, 100, stdin);
    }

    eliminar_ceros_izquierda(cadenaDelUsuario);
    longitud = strlen(cadenaDelUsuario) - 2;
    printf("La cadena con puntos de miles es: ");
    agregarSeparadorMiles(cadenaDelUsuario, longitud, 3);
    free(cadenaDelUsuario);
    fflush(stdin);
}

// PUNTO 6
void main_chinos()
{
    int n, validador;
    char *resultado;

    printf("Ingrese un numero: ");
    validador = scanf("%i", &n);

    while ((validador != 1) || (n <= 0) || (n > 30))
    {
        if (validador != 1)
            printf("Por favor ingrese un numero: ");
        else if (n <= 0)
            printf("Por favor ingrese un numero mayor a 0: ");
        else if (n > 30)
            printf("Por favor ingrese un numero menor a 30: ");
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }
    /*resultado = chinos(n);

    printf("Resultado: %s", resultado);
    free(resultado);
    // resultado = chinos(n);
    // printf("Resultado: %s", resultado); */
    chinos(n);
}

// PUNTO 7

void main_ondas()
{
    char *onda = (char *)calloc(100, sizeof(char));
    printf("Ingrese una cadena: ");
    fgets(onda, 100, stdin);
    bool validador = true;
    // a_minusculas(onda);
    for (int i = 0; i < strlen(onda) - 1; i++)
    {
        if ((onda[i] != 'h' && onda[i] != 'H') && (onda[i] != 'l' && onda[i] != 'L'))
        {
            validador = false;
        }
    }
    if (onda[0] == '\n')
    {
        validador = false;
    }
    while (validador == false)
    {
        printf("Datos invalidos, la cadena solo puede estar compuesta por 'H/h' o 'L/l'\n");
        printf("Ingrese nuevamente: ");
        fgets(onda, 100, stdin);
        // a_minusculas(onda);
        validador = true;
        for (int i = 0; i < strlen(onda) - 1; i++)
        {
            if ((onda[i] != 'h' && onda[i] != 'H') && (onda[i] != 'l' && onda[i] != 'L'))
            {
                validador = false;
            }
        }
        if (onda[0] == '\n')
        {
            validador = false;
        }
    }
    printf("CADENA VALIDA\n");
    a_minusculas(onda);
    ondaDigital(onda, 0);
}

// PUNTO 8
void main_subconjunto()
{
    int tamano, validador, suma;
    printf("Ingrese el tamaño del conjunto [1-30]: ");
    validador = scanf("%i", &tamano);
    while ((validador != 1) || (tamano <= 0) || (tamano > 30))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf("Ingrese el tamaño del conjunto [1-30]: ");
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &tamano);
    }
    int conjunto[tamano];
    for (int i = 0; i < tamano; i++)
    {
        printf("Ingrese el valor entero de la posicion %d del conjunto: ", i + 1);
        validador = scanf("%d", &conjunto[i]);
        while ((validador != 1) || (conjunto[i] <= 0))
        {
            printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
            printf("Ingrese el valor entero de la posicion %d del conjunto: ", i + 1);
            while (getchar() != '\n')
                ;
            validador = scanf("%d", &conjunto[i]);
        }
    }
    printf("Ingrese el valor entero de la suma del subconjunto: ");
    validador = scanf("%d", &suma);
    while ((validador != 1) || (suma <= 0))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf("Ingrese el valor entero de la suma del subconjunto: ");
        while (getchar() != '\n')
            ;
        validador = scanf("%d", &suma);
    }
    int subconjunto[tamano];
    int nivel = 0, subconjSize = 0;
    char salidaparcial[1000] = "";
    char *resultado = buscaSumaSubconjunto(tamano, nivel, suma, salidaparcial, conjunto, subconjunto, subconjSize);
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

// PUNTO 9
void main_divisible_7()
{
    int numero_ej9;
    bool resultado_9;
    int es_numero_ej9;
    while (es_numero_ej9 == 0 || numero_ej9 > 99999999 || numero_ej9 < -99999999)
    {
        printf("\ningrese un numero para saber si es divisible por 7 (max de 8 digitos): ");
        es_numero_ej9 = scanf("%d", &numero_ej9);
        fflush(stdin);
        if (es_numero_ej9 == 0)
        {
            printf("No se permiten caracteres, vuelva a ingresar un dato\n");
        }
        else if (numero_ej9 > 99999999 || numero_ej9 < -99999999)
        {
            printf("Superado el limite de digitos, vuelva a ingresar un dato\n");
        }
        printf("presione ENTER para continuar\n");
        while (getchar() != '\n')
            ;
    }
    resultado_9 = divisiblePor7(numero_ej9);
    if (resultado_9 == false)
    {
        printf("el numero %d no es divisible por 7\n", numero_ej9);
    }
    else if (resultado_9 == true)
    {
        printf("el numero %d es divisible por 7\n", numero_ej9);
    }
}
// PUNTO 10
void main_bomba()
{
    int *arreglo = calloc(40, sizeof(int));
    int n, b, i, validador;

    // Ingreso del primer valor
    printf("Ingrese un numero n positivo: ");
    validador = scanf("%i", &n);

    while ((validador == 0) || (n <= 0))
    {
        if (validador == 0)
            printf("Por favor ingrese un numero: ");
        else if (n <= 0)
            printf("Por favor ingrese un numero mayor a 0: ");
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }

    // Ingreso del segundo valor
    printf("Ingrese un numero b mayor a 1: ");
    validador = scanf("%i", &b);

    // Validacion del segundo valor
    while ((validador != 1) || (b <= 1))
    {
        if (validador != 1)
            printf("Por favor ingrese un numero: ");
        else if (b <= 1)
            printf("Por favor ingrese un numero mayor a 1: ");

        while (getchar() != '\n')
            ;
        validador = scanf("%i", &b);
    }

    explosion(n, b, arreglo, 0);
    i = 0;
    printf("explosion(%i,%i) => [", n, b);
    while (arreglo[i] != NULL)
    {
        printf("%d ", arreglo[i]);
        i++;
    }
    printf("]");
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
            while (getchar() != '\n')
                ;
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
            main_division();
            getch();
            break;
        case 5:
            main_miles();
            getch();
            break;
        case 6:
            main_chinos();
            getch();
            break;
        case 7:
            main_ondas();
            getch();
            break;
        case 8:
            main_subconjunto();
            getch();
            break;
        case 9:
            main_divisible_7();
            getch();
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