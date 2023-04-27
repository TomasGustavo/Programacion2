#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TP4_colas.h"
#include "colas.h"
#include "tipo_elemento.h"

Cola cargarCola(){
    Cola cola = c_crear();
    int cant, valor, clave;
    bool rta;
    printf(ANSI_bBLUE "ingrese cantidad de elementos a cargar [0-99]: " ANSI_RESET);
    int validador = scanf("%d", &cant);
    vaciar_buffer();
    while (validador != 1 || cant < 0 || cant >= 100)
    {
        limpiar_pantalla();
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingresar un numero entre [0-99]\n\n" ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE "ingrese cantidad de elementos a cargar: " ANSI_RESET);
        validador = scanf("%d", &cant);
        vaciar_buffer();
    }

    for (int i = 0; i < cant; i++)
    {
        printf(ANSI_bBLUE "ingrese clave del elementos a cargar [-999.999 - 999.999]: " ANSI_RESET);
        validador = scanf("%d", &valor);
        vaciar_buffer();
        while (validador != 1 || valor < -999999 || valor > 999999)
        {
            limpiar_pantalla();
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE "ingrese clave del elementos a cargar [-999.999 - 999.999]: " ANSI_RESET);
            validador = scanf("%d", &valor);
            vaciar_buffer();
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila, elemento);
        limpiar_pantalla();
    }
    printf(ANSI_bGREEN "");
    p_mostrar(pila); // muestro la pila como quedo cargada
    printf("\n" ANSI_RESET);
}
