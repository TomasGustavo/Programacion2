#include <stdio.h>
#include <string.h>
#include "TP0_Repaso.h"

void intercambio(struct Jugador *a, struct Jugador *b)
{
    struct Jugador temp = *a;
    *a = *b;
    *b = temp;
}

void mostrarPartidos(struct Jugador equipo[])
{
    int i;
    printf(ANSI_RED "Jugadores ordenados por cantidad de partidos jugados:\n");
    for (i = 0; i < CANT_JUGADORES; i++)
    {
        printf(ANSI_YELLOW "%s \t" ANSI_BLUE "%d \n", equipo[i].nombre, equipo[i].partidosJugados);
    }
    printf(ANSI_RESET "\n");
}

void mostrarEdad(struct Jugador equipo[])
{
    int i;
    printf(ANSI_RED "Jugadores ordenados por edad:\n");
    for (i = 0; i < CANT_JUGADORES; i++)
    {
        printf(ANSI_YELLOW "%s \t" ANSI_BLUE "%d \n", equipo[i].nombre, equipo[i].edad);
    }
    printf(ANSI_RESET "\n");
}

struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[])
{
    int i, j;
    for (i = 0; i < CANT_JUGADORES - 1; i++)
    {
        for (j = 0; j < CANT_JUGADORES - i - 1; j++)
        {
            if (equipo[j].partidosJugados < equipo[j + 1].partidosJugados)
            {
                intercambio(&equipo[j], &equipo[j + 1]);
            }
        }
    }

    return equipo;
}

struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[])
{
    int i, j;
    for (i = 0; i < CANT_JUGADORES - 1; i++)
    {
        for (j = 0; j < CANT_JUGADORES - i - 1; j++)
        {
            if (equipo[j].edad > equipo[j + 1].edad)
            {
                intercambio(&equipo[j], &equipo[j + 1]);
            }
        }
    }
    return equipo;
}

float promedioDePartidosJugados(struct Jugador equipo[], int edad)
{
    int i, count = 0, sum = 0;
    for (i = 0; i < CANT_JUGADORES; i++)
    {
        if (equipo[i].edad == edad)
        {
            count++;
            sum += equipo[i].partidosJugados;
        }
    }
    if (count == 0)
    {
        return 0.0;
    }
    else
    {
        return (float)sum / count;
    }
}

int main()
{
    struct Jugador equipo[] = {
        {"Messi", 34, 800},
        {"Ronaldo", 37, 900},
        {"Neymar Jr.", 29, 500},
        {"Mbappe", 22, 200},
        {"Lewandowski", 33, 700},
        {"Salah", 29, 400},
        {"De Bruyne", 30, 600},
        {"van Dijk", 30, 400},
        {"Ramos", 35, 650},
        {"Neuer", 35, 800},
        {"Davies", 20, 100}};

    int edadDada;
    float promedio;
    mostrarPartidos(jugadoresOrdenadosPorCantDePartidos(equipo));
    mostrarEdad(jugadoresOrdenadosPorEdad(equipo));
    printf(ANSI_RED "ingresar una edad: " ANSI_YELLOW);
    scanf("%d", &edadDada);
    promedio = promedioDePartidosJugados(equipo, edadDada);
    printf(ANSI_RED "El promedio de partidos jugados a los %d años es: %.2f\n" ANSI_RESET, edadDada, promedio);
}
