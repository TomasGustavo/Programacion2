#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "TP1_Recursividad.h"

// da verdadero si la cadena es vacía
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

// Pasa todos los caracteres de la cadena a minúscula

void a_minusculas(char *cadena)
{
    int i = 0;

    while (cadena[i] != '\0')
    {
        cadena[i] = tolower(cadena[i]);
        i++;
    }
}

// Valida si todos los elementos de una cadena son números
bool sonNumeros(char *cadena)
{
    int i = 0;
    bool res = true;
    char x = cadena[i];
    if (x == 45)
    {
        i = 1;
    }
    for (i = i; i < strlen(cadena) - 1; i++)
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

bool cadena_larga(char *cadena, int MAX)
{
    if (strlen(cadena) == MAX && cadena[MAX - 1] != '\0' && cadena[MAX - 1] != '\n')
    {
        // La cadena es igual al tamaño máximo del arreglo y no termina con un salto de línea o carácter nulo
        // Esto significa que la cadena es demasiado larga para el arreglo
        return true;
        printf("La cadena es demasiado larga para el arreglo\n");
    }
    else
    {
        // La cadena tiene un tamaño menor o igual al tamaño máximo del arreglo
        // Se elimina el carácter de nueva línea si está presente
        char *newline = strchr(cadena, '\n');
        if (newline != NULL)
        {
            *newline = '\0';
        }
        return false;
        printf("La cadena es valida: %s\n", cadena);
    }
}

// PUNTO 1
void main_palindromo()
{
    int MAX = 100 + 1;
    char *cadenaDelUsuario = (char *)malloc(MAX * sizeof(char));
    bool res;
    int longitud;
    printf(ANSI_BLUE "Ingresa una palabra o expresión de no mas de %d caracteres: " ANSI_YELLOW, MAX - 1);
    while (getchar() != '\n') // Vaciar el buffer de entrada
        ;
    fgets(cadenaDelUsuario, MAX, stdin);
    longitud = strlen(cadenaDelUsuario);
    while ((es_vacia(cadenaDelUsuario)) || (primer_caracter_espacio(cadenaDelUsuario)) ||
           (ultimo_caracter_espacio(cadenaDelUsuario)))
    {
        if (es_vacia(cadenaDelUsuario))
        {
            printf(ANSI_RED "La cadena no puede estar vacía.\n");
            printf(ANSI_BLUE "Ingrese una nueva cadena de no mas de %d caracteres: " ANSI_YELLOW, MAX - 1);
        }
        else if (primer_caracter_espacio(cadenaDelUsuario))
        {
            printf(ANSI_RED "El primer carácter no puede ser espacio.\n");
            printf(ANSI_BLUE "Ingrese una nueva cadena de no mas de %d caracteres: " ANSI_YELLOW, MAX - 1);
        }
        else if (ultimo_caracter_espacio(cadenaDelUsuario))
        {
            printf(ANSI_RED "El ultimo carácter no puede ser espacio.\n");
            printf(ANSI_BLUE "Ingrese una nueva cadena de no mas de %d caracteres: " ANSI_YELLOW, MAX - 1);
        }
        /* else if (cadena_larga(cadenaDelUsuario, MAX))
         {
             printf(ANSI_RED "La cadena es demasiado larga para el arreglo\n");
             printf(ANSI_BLUE "Ingrese una nueva cadena: " ANSI_YELLOW);
         }
          else if (!sonLetras(cadenaDelUsuario))
          {
              printf(ANSI_RED "Solo puede ingresar letras y espacios.\n");
              printf(ANSI_BLUE "Ingrese una nueva cadena: " ANSI_YELLOW);
          } */
        fflush(stdin); // Vaciar el buffer de entrada
        fgets(cadenaDelUsuario, 100, stdin);
    }
    a_minusculas(cadenaDelUsuario);
    // eliminarEspacios(cadenaDelUsuario);
    longitud = strlen(cadenaDelUsuario);
    res = palindromo(cadenaDelUsuario, 0, longitud - 2);
    if (res == true)
    {
        printf(ANSI_GREEN "Es palíndromo" ANSI_BLUE);
    }
    else
    {
        printf(ANSI_RED "No es palíndromo" ANSI_BLUE);
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

    printf(ANSI_BLUE "Ingrese un numero (valor de m) menor a %d (se truncara si coloca decimales): " ANSI_YELLOW, maxM);
    validador = scanf("%i", &m);
    fflush(stdin); // Vaciar el buffer de entrada
    while ((validador != 1) || (m > maxM) || m == '\0' || m == '\n')
    {
        printf(ANSI_RED "ERROR\n");
        printf(ANSI_BLUE "Ingrese un numero (valor de m) menor a %d (se truncara si coloca decimales): " ANSI_YELLOW, maxM);
        while (getchar() != '\n') // Vaciar el buffer de entrada
            ;
        validador = scanf("%i", &m);
    }
    printf(ANSI_BLUE "Ingrese un numero (valor de n) menor a %d (se truncara si coloca decimales): " ANSI_YELLOW, maxN);
    validador = scanf("%i", &n);
    fflush(stdin); // Vaciar el buffer de entrada
    while ((validador != 1) || (n > maxN))
    {
        printf(ANSI_RED "ERROR\n");
        printf(ANSI_BLUE "Ingrese un numero (valor de n) menor a %i (se truncara si coloca decimales): " ANSI_YELLOW, maxN);
        while (getchar() != '\n') // Vaciar el buffer de entrada
            ;
        validador = scanf("%i", &n);
    }
    prod = producto(m, n);
    printf(ANSI_GREEN "El producto de %d x %d es: %lld", m, n, prod);
}

// PUNTO 3
void main_fibo()
{
    int n, validador;
    long long resultado;
    printf(ANSI_BLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW);
    validador = scanf("%i", &n);
    while ((validador != 1) || (n < 0) || (n > 40))
    {
        if (validador != 1)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW);
        }
        else if (n < 0)
        {

            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Ingrese un numero mayor o igual a 0 (se truncara si coloca decimales): " ANSI_YELLOW);
        }
        else if (n > 40)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Ingrese un numero menor o igual a 40 (se truncara si coloca decimales): " ANSI_YELLOW);
        }
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }
    resultado = terminoSerieFibonacci(n);
    printf(ANSI_GREEN "Fibonacci de %d es: %lld", n, resultado);
}

// PUNTO 4
void main_division()
{
    int dividendo, divisor;
    float resultado_4;
    int no_caracter_4, no_caracter_4_1;
    bool error;
    do
    {
        error = false;
        printf(ANSI_BLUE "\nIngrese el dividendo (max dígitos: 4) (se truncara si coloca decimales): " ANSI_YELLOW);
        no_caracter_4 = scanf("%d", &dividendo);
        while (getchar() != '\n')
            ;
        printf(ANSI_BLUE "Ingrese el divisor(max dígitos: 4) (se truncara si coloca decimales): " ANSI_YELLOW);
        no_caracter_4_1 = scanf("%d", &divisor);
        while (getchar() != '\n')
            ;
        if (no_caracter_4 == 0 || no_caracter_4_1 == 0)
        {
            divisor = 0;
            printf(ANSI_RED "\nNo están permitidos los caracteres\n");
            error = true;
        }
        else if (dividendo > 10000 || divisor > 10000 || dividendo < -10000 || divisor < -10000)
        {
            divisor = 0;
            printf(ANSI_RED "\nIngrese como máximo 4 dígitos por favor\n");
            error = true;
        }
        else if (divisor == 0)
        {
            printf(ANSI_RED "No se puede dividir por 0\n");
            error = true;
        }
        printf("Presione ENTER para continuar\n");
        getchar();
    } while (error == true);
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

    printf(ANSI_GREEN "La division de %d / %d es %0.4f", dividendo, divisor, resultado_4);
}

// PUNTO 5
void main_miles()
{
    bool x = false;
    char *cadenaDelUsuario = (char *)calloc(100, sizeof(char));
    int longitud;
    printf(ANSI_BLUE "Ingresa un numero: " ANSI_YELLOW);
    while (getchar() != '\n')
        ;
    fgets(cadenaDelUsuario, 100, stdin);
    while (es_vacia(cadenaDelUsuario) || strlen(cadenaDelUsuario) > 99 || !sonNumeros(cadenaDelUsuario))
    {
        if (es_vacia(cadenaDelUsuario))
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Por favor ingrese un numero: " ANSI_YELLOW);
        }

        else if (strlen(cadenaDelUsuario) > 99)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "El numero debe tener menos de 99 dígitos, ingrese un nuevo numero: " ANSI_YELLOW);
        }

        else if (!sonNumeros(cadenaDelUsuario))
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Solo puede ingresar números, ingrese un nuevo numero: " ANSI_YELLOW);
        }
        fflush(stdin);
        fgets(cadenaDelUsuario, 100, stdin);
    }

    // pasada las validaciones, si el numero es negativo pongo x es true, transforma el '-' en un espacio, lo elimina;
    // Luego trabaja la cadena como si fuera de números positivos.
    if (cadenaDelUsuario[0] == '-')
    {
        x = true;
        cadenaDelUsuario[0] = ' ';
        eliminarEspacios(cadenaDelUsuario);
    }
    eliminar_ceros_izquierda(cadenaDelUsuario);
    longitud = strlen(cadenaDelUsuario) - 2;
    printf(ANSI_GREEN "La cadena con puntos de miles es: " ANSI_YELLOW);
    if (x == true)
    { // si la cadena era negativa, como elimine mas arriba el '-' lo que hago ahora es imprimirlo antes de imprimir la cadena.
        printf("-");
    }
    agregarSeparadorMiles(cadenaDelUsuario, longitud, 3);

    free(cadenaDelUsuario);
    fflush(stdin);
}

// PUNTO 6
void main_chinos()
{
    int n, validador;
    // char *resultado;

    printf(ANSI_BLUE "Ingrese un numero (se truncara si coloca decimales): " ANSI_YELLOW);
    validador = scanf("%i", &n);

    while ((validador != 1) || (n <= 0) || (n > 30))
    {
        if (validador != 1)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Por favor ingrese un numero: " ANSI_YELLOW);
        }
        else if (n <= 0)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Por favor ingrese un numero mayor a 0: " ANSI_YELLOW);
        }
        else if (n > 30)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Por favor ingrese un numero menor a 30: " ANSI_YELLOW);
        }
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }
    printf(ANSI_GREEN "Vista frontal de la delegación nivel %i: \n" ANSI_RESET, n);
    chinos(n);

    /* resultado = chinos(n);
    printf("Resultado: %s", resultado);
    free(resultado);
    resultado = chinos(n);
    printf("Resultado: %s", resultado); */
}

// PUNTO 7

void main_ondas()
{
    char *onda = (char *)calloc(100, sizeof(char));
    printf(ANSI_BLUE "Ingrese una cadena: " ANSI_YELLOW);
    while (getchar() != '\n')
        ;
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
        printf(ANSI_RED "ERROR\n");
        printf(ANSI_RED "La cadena solo puede estar compuesta por 'H/h' o 'L/l'\n");
        printf(ANSI_BLUE "Ingrese una cadena: " ANSI_YELLOW);
        fgets(onda, 100, stdin);
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
    printf(ANSI_GREEN "CADENA VALIDA\n");
    a_minusculas(onda);
    ondaDigital(onda, 0);
}

// PUNTO 8
void main_subconjunto()
{
    int tamano, validador, suma;
    printf(ANSI_BLUE "Ingrese el tamaño del conjunto [1-30] (se truncara si coloca decimales): " ANSI_YELLOW);
    validador = scanf("%i", &tamano);
    while ((validador != 1) || (tamano <= 0) || (tamano > 30))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese el tamaño del conjunto [1-30] (se truncara si coloca decimales): " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &tamano);
    }
    int conjunto[tamano];
    for (int i = 0; i < tamano; i++)
    {
        printf(ANSI_BLUE "Ingrese el valor entero [-999.999/999.999] de la posición %d del conjunto (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
        validador = scanf("%d", &conjunto[i]);
        while ((validador != 1) || (conjunto[i] <= -1000000) || (conjunto[i] >= 1000000))
        {
            printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
            printf(ANSI_BLUE "Ingrese el valor entero [-999.999/999.999] de la posición %d del conjunto (se truncara si coloca decimales): " ANSI_YELLOW, i + 1);
            while (getchar() != '\n')
                ;
            validador = scanf("%d", &conjunto[i]);
        }
    }
    printf(ANSI_BLUE "Ingrese el valor entero [-999.999/999.999] de la suma del subconjunto (se truncara si coloca decimales): " ANSI_YELLOW);
    validador = scanf("%d", &suma);
    while ((validador != 1) || (suma <= -1000000) || (suma >= 1000000))
    {
        printf(ANSI_RED "Entrada invalida.\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese el valor entero [-999.999/999.999] de la suma del subconjunto (se truncara si coloca decimales): " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%d", &suma);
    }
    int subconjunto[tamano];
    int nivel = 0, subconjSize = 0;
    char salidaparcial[1000] = "";
    char *resultado = buscaSumaSubconjunto(tamano, nivel, suma, salidaparcial, conjunto, subconjunto, subconjSize);
    printf(ANSI_GREEN "%s", resultado);
}

// PUNTO 9
void main_divisible_7()
{
    int numero_ej9;
    bool resultado_9;
    int es_numero_ej9;
    printf(ANSI_BLUE "\nIngrese un numero para saber si es divisible por 7 (max de 8 dígitos) (se truncara si coloca decimales): " ANSI_YELLOW);
    es_numero_ej9 = scanf("%d", &numero_ej9);
    while (getchar() != '\n')
        ;
    while (es_numero_ej9 == 0 || numero_ej9 > 99999999 || numero_ej9 < -99999999)
    {
        if (es_numero_ej9 == 0)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_RED "No se permiten caracteres, vuelva a ingresar un dato\n");
        }
        else if (numero_ej9 > 99999999 || numero_ej9 < -99999999)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_RED "Superado el limite de dígitos, vuelva a ingresar un dato\n");
        }
        printf(ANSI_BLUE "\nIngrese un numero para saber si es divisible por 7 (max de 8 dígitos) (se truncara si coloca decimales): " ANSI_YELLOW);
        es_numero_ej9 = scanf("%d", &numero_ej9);
        while (getchar() != '\n')
            ;
    }
    resultado_9 = divisiblePor7(numero_ej9);
    if (resultado_9 == false)
    {
        printf(ANSI_RED "El numero %d no es divisible por 7\n", numero_ej9);
    }
    else if (resultado_9 == true)
    {
        printf(ANSI_GREEN "El numero %d es divisible por 7\n", numero_ej9);
    }
}
// PUNTO 10
void main_bomba()
{
    int *arreglo = calloc(40, sizeof(int));
    int n, b, i, validador;

    // Ingreso del primer valor
    printf(ANSI_BLUE "Ingrese un numero n positivo (explosivo) (se truncara si coloca decimales): " ANSI_YELLOW);
    validador = scanf("%i", &n);

    while ((validador == 0) || (n <= 0) || (n > 75))
    {
        if (validador == 0)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Ingrese un numero n positivo (explosivo) (se truncara si coloca decimales): " ANSI_YELLOW);
        }
        else if (n <= 0 || n > 75)
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Ingrese un numero n (explosivo) mayor a 0 y menor o igual a 75 (se truncara si coloca decimales): " ANSI_YELLOW);
        }
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }

    // Ingreso del segundo valor
    printf(ANSI_BLUE "Ingrese un numero b (bomba) mayor a 1 (se truncara si coloca decimales): " ANSI_YELLOW);
    validador = scanf("%i", &b);

    // Validación del segundo valor
    while ((validador != 1) || (b <= 1))
    {
        if ((validador != 1) || (b <= 1))
        {
            printf(ANSI_RED "ERROR\n");
            printf(ANSI_BLUE "Ingrese un numero b (bomba) mayor a 1 (se truncara si coloca decimales): " ANSI_YELLOW);
        }
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &b);
    }
    i = 0;
    printf(ANSI_GREEN "Explosion(%i,%i) => [", n, b);
    explosion(n, b, arreglo, 0);
    /*  while (arreglo[i] != 0)
      {
          printf("%d ", arreglo[i]);
          i++;
      } */
    printf("]" ANSI_RESET);
    free(arreglo);
}

void menu_principal()
{
    printf("\n");
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