#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "TP6_tabla_hash.h"
#include "listas.h"
#include "tabla_hash.h"
#include "tipo_elemento.h"

int FuncionHash(int n)
{
    return n % NRO_PRIMO;
}

/// @brief Vacía el buffer de entrada.
void vaciar_buffer()
{
    char nada[200];
    fgets(nada, 200, stdin);
}

/// @brief Frena la ejecución del código esperando el ingreso de un carácter.
void pausa()
{
    printf(ANSI_bYELLOW "\n\nPresione una tecla para continuar...." ANSI_RESET);
    getchar();
}

/// @brief Secuencia de escape ANSI que se utiliza para limpiar la pantalla de la terminal y posicionar el cursor en la esquina superior izquierda.
void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

// -------------------------------------------------- PUNTO 5 --------------------------------------------------

/// @brief Función que genera números aleatorios dentro de un rango
/// @param min Rango mínimo
/// @param max Rango máximo
/// @return Numero aleatorio generado
int getRandom(int min, int max)
{
    int n_aleatorio;
    n_aleatorio = min + (rand() % (max - min + 1));
    return n_aleatorio;
}
// NO OLVIDARSE DE USAR SEMILLA UNA VEZ EN LA FUNCION QUE LA LLAMA
// srand(time(NULL)); // Establecer semilla

// -------------------------------------------------- PUNTO 6 --------------------------------------------------

///@brief Funcion que dado un dia, mes y año indica si la fecha es valida
bool validarFecha(unsigned int dia, unsigned int mes, unsigned int anio)
{
    unsigned int dia_maximo;
    bool fecha_correcta = false;

    if (mes >= 1 && mes <= 12)
    {
        switch (mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dia_maximo = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            dia_maximo = 30;
            break;

        case 2:
            if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
                dia_maximo = 29;
            else
                dia_maximo = 28;
        }

        if (dia >= 1 && dia <= dia_maximo)
            fecha_correcta = true;
    }
    return fecha_correcta;
}

// Funciones para pasar la fecha a un mismo string y luego devolver el numero resultado
//  para pasar a la funcion hash
void enteroACadena(unsigned int numero, char *bufer)
{
    sprintf(bufer, "%u", numero);
}

int juntarNumeros(unsigned int dia, unsigned int mes, unsigned int anio)
{
    char cadenadia[3];
    char cadenames[3];
    char cadenaanio[5];
    char fecha[9];
    memset(&fecha, 0, sizeof(fecha));
    enteroACadena(dia, cadenadia);
    enteroACadena(mes, cadenames);
    enteroACadena(anio, cadenaanio);
    strcat(fecha, cadenadia);
    strcat(fecha, cadenames);
    strcat(fecha, cadenaanio);
    int entero = (int)strtol(fecha, NULL, 10);
    return entero;
}

void cargarPersona()
{
    int min, max, validador, dni, dia, mes, anio;
    char nombre[20];
    char apellido[20];
    // Cargar DNI
    printf(ANSI_bMAGENTA "DNI: " ANSI_YELLOW);
    validador = scanf("%d", &dni);
    vaciar_buffer();
    while (validador != 1 || dni < 1 || dni > 99999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "DNI: " ANSI_YELLOW);
        validador = scanf("%d", &dni);
        vaciar_buffer();
    }

    // Cargar nombre
    printf("Nombre: ");
    // scanf();
    vaciar_buffer();
}