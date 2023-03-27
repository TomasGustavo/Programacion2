#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "TP1_Recursividad.h"

char *mafia(int N)
{
    char *result;
    if (N == 1)
    {
        result = "(-.-)";
    }
    else if (N > 1)
    {
        char *subResult = mafia(N - 1);
        int length = strlen(subResult);
        result = (char *)malloc((length + 6) * sizeof(char));
        sprintf(result, ANSI_RED "(-.%s.-)" ANSI_BLUE, subResult);
    }

    return result;
}

void print_chinese(int level)
{
    int color = rand() % 7 + 31; // generar un código de color aleatorio entre 31 y 37
    if (level == 1)
    {
        printf("\033[%dm%s\033[0m", color, "(-.-)");
    }
    else
    {
        printf("\033[%dm%s", color, "(-.");
        print_chinese(level - 1);
        printf("\033[%dm%s", color, ".-)");
    }
}

int main()
{
    int level;
    printf("Ingrese nivel de mafia: ");
    scanf("%d", &level);
    srand(time(NULL)); // genera números aleatorios
    print_chinese(level);
    printf("\n");
    return 0;
}