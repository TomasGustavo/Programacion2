#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "TP1_Recursividad.h"

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
           (ultimo_caracter_espacio(cadenaDelUsuario)) || (!sonLetras(cadenaDelUsuario)))
    {
        if (es_vacia(cadenaDelUsuario))
            printf("La cadena no puede estar vacia: ");
        else if (primer_caracter_espacio(cadenaDelUsuario))
            printf("El primer caracter no puede ser espacio: ");
        else if (ultimo_caracter_espacio(cadenaDelUsuario))
            printf("El ultimo caracter no puede ser espacio: ");
        else if (!sonLetras(cadenaDelUsuario))
            printf("Solo puede ingresar letras y espacios: ");
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
        fflush(stdin);
    }
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
// ejercicio 4

float division(int m, int n, int limite_Decimal)
{
    /*esta funcion se encarga de restar en cada sucesion el valor del dividendo(m)
    con el del divisor(n) hasta que el resto sea menor a n  y
    realizara restas sucesivas para los decimales de una manera similar a los enteros*/

    if (n < 0 && m < 0)
    {
        /*como ambos valores son negativos
        se convierten en positivo para el resultado final*/
        m = m * -1;
        n = n * -1;
    }
    else if (n < 0)
    {
        n = n * -1;
    }
    else if (m < 0)
    {
        m = m * -1;
    }

    float resto = m;
    float cociente = 0;
    /*una vez que el resto sea menor a n se divide el resto por el n
    para saber si el cociente(resultado) tiene valores decimales*/
    if (resto == 0)
    {
        cociente = resto;
        return cociente;
    }

    else if (resto < n && limite_Decimal != 0)
    {
        resto = resto * 10;
        if (resto < n && resto > -n)
        {
            /*en caso que el resto siga siendo menor a n,
            esta parte se encarga de solo mover un 0 a la derecha como valor decimal*/
            cociente = division(resto, n, limite_Decimal);
            cociente = cociente * 0.1;
            return cociente;
        }
        else
        {
            cociente = division(resto - n, n, limite_Decimal - 1);
            cociente++;
            cociente = cociente * 0.1; /*esta parte se encarga de desplazar a la parte decimal
            los valores correspondientes a la misma*/
            return cociente;
        }
    }
    else if (limite_Decimal == 0)
    {
        /* si el numero decimal es muy grande el limite_Decimal
        se va a encargar de cortar la funcion con 4 digitos decimales*/
        return cociente;
    }
    else
    {
        cociente = division(m - n, n, limite_Decimal);

        /*luego se usa el cociente como contador una vez retornada la sucesion
        para obtener el resultado segun la cantidad de sucesiones*/
        cociente++;
        return cociente;
    }
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
    // resultado = chinos(n);
    // printf("Resultado: %s", resultado);
    chinos(n);
}

// PUNTO 8
void main_subconjunto()
{
    // char entrada[100];
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
void main_bomba()
{
    int *arreglo = calloc(40, sizeof(int));
    int n, b, i, validador;

    // Ingreso del primer valor
    printf("Ingrese un numero n mayor a 1: ");
    validador = scanf("%i", &n);

    printf("%i", validador);
    // Validacion del primer valor (mayor a 1 ya que si no B deberia ser 0 debido a que tiene que ser menor que N)
    while ((validador == 0) || (n <= 1))
    {
        if (validador == 0)
            printf("Por favor ingrese un numero: ");
        else if (n <= 1)
            printf("Por favor ingrese un numero mayor a 1: ");
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &n);
    }

    // Ingreso del segundo valor
    printf("Ingrese un numero b mayor a 1: ");
    validador = scanf("%i", &b);

    // Validacion del segundo valor
    while ((validador != 1) || (b <= 1) || (n <= b))
    {
        if (validador != 1)
            printf("Por favor ingrese un numero: ");
        else if (b <= 1)
            printf("Por favor ingrese un numero mayor a 1: ");
        else if (n <= b)
            printf("N tiene que ser mayor a B: ");

        while (getchar() != '\n')
            ;
        validador = scanf("%i", &b);
    }

    explosion(n, b, arreglo, 0);
    i = 0;
    while (arreglo[i] != NULL)
    {
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