#include <stdio.h>
#include <math.h>
#include "TP0_Repaso.h"

int dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp)
{
    int estado;
    float distancia;
    distancia = sqrt(pow((xp - xc), 2) + pow((yp - yc), 2));
    if (distancia == rc)
    {
        estado = (EN_CIRCUNFERENCIA);
    }
    else if (distancia > rc)
    {
        estado = (EXTERNO);
    }
    else
    {
        estado = (INTERNO);
    }
    return estado;
}

void main()
{
    int xc, yc, rc, xp, yp, estado;
    printf("Ingrese la coordenada X del centro: ");
    scanf("%d", &xc);
    printf("Ingrese la coordenada Y del centro: ");
    scanf("%d", &yc);
    printf("Ingrese el radio del centro: ");
    scanf("%d", &rc);
    printf("Ingrese la coordenada del punto X: ");
    scanf("%d", &xp);
    printf("Ingrese la coordenada del punto Y: ");
    scanf("%d", &yp);
    estado = dondeEstaElPunto(xc, yc, rc, xp, yp);
    if (estado == EN_CIRCUNFERENCIA)
    {
        printf("Pertenece a la circunferencia");
    }
    else if (estado == EXTERNO)
    {
        printf("Esta fuera de la circunferencia");
    }
    else
    {
        printf("Esta dentro de la circunferencia");
    }
}