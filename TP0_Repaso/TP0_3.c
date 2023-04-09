#include <stdio.h>
#include <math.h>
#include "TP0_Repaso.h"

#define ANSI_RED "\e[31m"
#define ANSI_GREEN "\e[32m"
#define ANSI_YELLOW "\e[33m"
#define ANSI_BLUE "\e[34m"
#define ANSI_MAGENTA "\e[35m"
#define ANSI_CYAN "\e[36m"
#define ANSI_bRED "\e[91m"
#define ANSI_bGREEN "\e[92m"
#define ANSI_bYELLOW "\e[93m"
#define ANSI_bBLUE "\e[94m"
#define ANSI_bMAGENTA "\e[95m"
#define ANSI_bCYAN "\e[96m"
#define ANSI_RESET "\e[0m"

int dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p)
{
    int ubicacion;
    float distancia;
    distancia = sqrt(pow((p.x - centroC.x), 2) + pow((p.y - centroC.y), 2));
    if (distancia == rc)
    {
        ubicacion = (EN_CIRCUNFERENCIA);
    }
    else if (distancia > rc)
    {
        ubicacion = (EXTERNO);
    }
    else
    {
        ubicacion = (INTERNO);
    }
    return ubicacion;
}

void main()
{
    struct Punto circunferencia;
    struct Punto punto;
    int rc, ubicacion;
    printf(ANSI_BLUE "Ingrese la coordenada X del circulo: " ANSI_RED);
    scanf("%d", &circunferencia.x);
    printf(ANSI_BLUE "Ingrese la coordenada Y del circulo: " ANSI_RED);
    scanf("%d", &circunferencia.y);
    printf(ANSI_BLUE "Ingrese el radio del centro: " ANSI_RED);
    scanf("%d", &rc);
    printf(ANSI_BLUE "Ingrese la coordenada del punto X: " ANSI_RED);
    scanf("%d", &punto.x);
    printf(ANSI_BLUE "Ingrese la coordenada del punto Y: " ANSI_RED);
    scanf("%d", &punto.y);
    ubicacion = dondeEstaElPuntoBis(circunferencia, rc, punto);
    if (ubicacion == EN_CIRCUNFERENCIA)
    {
        printf(ANSI_bGREEN "Pertenece a la circunferencia" ANSI_RESET);
    }
    else if (ubicacion == EXTERNO)
    {
        printf(ANSI_bRED "Esta fuera de la circunferencia" ANSI_RESET);
    }
    else
    {
        printf(ANSI_bGREEN "Esta dentro de la circunferencia" ANSI_RESET);
    }
}