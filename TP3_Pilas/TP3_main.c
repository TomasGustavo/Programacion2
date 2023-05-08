#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP3_pilas.h"
#include "pilas.h"
#include "tipo_elemento.h"

int vaciar_buffer(void)
{
    char nada[200];
    fgets(nada, 200, stdin);
    return 0;
}

void pausa()
{
    printf(ANSI_YELLOW "\nPresione ENTER para continuar...." ANSI_RESET);
    getchar();
}

void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

Pila p_intercambiar(Pila pila, Pila pilaAux)
{
    TipoElemento x = te_crear(0);
    while (!p_es_vacia(pilaAux))
    {
        x = p_desapilar(pilaAux);
        p_apilar(pila, x);
    }
    free(pilaAux);
    return pila;
}

int longitud_pila(Pila pila)
{
    int x = 0;
    TipoElemento e = te_crear(0);
    Pila paux = p_crear();
    while (!p_es_vacia(pila))
    {
        e = p_desapilar(pila);
        p_apilar(paux, e);
        x++;
    }
    pila = p_intercambiar(pila, paux);
    return x;
}

Pila cargar_pila(int *cant)
{
    int valor;
    Pila pila = p_crear();
    printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar [0-99]: " ANSI_YELLOW);
    int validador = scanf("%d", cant);
    vaciar_buffer();
    while (validador != 1 || *cant < 0 || *cant >= 100)
    {
        limpiar_pantalla();
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingresar un numero entre [0-99]\n\n" ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese cantidad de elementos a cargar [0-99]: " ANSI_YELLOW);
        validador = scanf("%d", cant);
        vaciar_buffer();
    }
    for (int i = 0; i < *cant; i++)
    {
        limpiar_pantalla();
        printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999]: " ANSI_YELLOW, i + 1);
        validador = scanf("%d", &valor);
        vaciar_buffer();
        while (validador != 1 || valor < -999999 || valor > 999999)
        {
            limpiar_pantalla();
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE "Ingrese clave del elemento N°%d a cargar [-999.999 - 999.999]: " ANSI_YELLOW, i + 1);
            validador = scanf("%d", &valor);
            vaciar_buffer();
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila, elemento);
    }
    return pila;
}

// PUNTO 2A
void main_buscar_clave()
{
    Pila pila = p_crear();
    int cant, clave;
    bool rta;
    pila = cargar_pila(&cant);
    printf(ANSI_bGREEN);
    p_mostrar(pila); // muestro la pila como quedo cargada
    printf("\n" ANSI_RESET);
    printf(ANSI_bBLUE "Ingrese clave a buscar en la pila: " ANSI_YELLOW);
    int validador = scanf("%d", &clave);
    vaciar_buffer();
    while (validador != 1 || clave < -999999 || clave > 999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese clave a buscar en la pila: " ANSI_YELLOW);
        validador = scanf("%d", &clave);
        vaciar_buffer();
    }
    if (p_es_vacia(pila))
    {
        printf(ANSI_RED "La clave no fue encontrada porque la pila esta vacia\n" ANSI_RESET);
    }
    else
    {
        rta = buscar_c(pila, clave);
        if (rta == true)
        {
            printf(ANSI_bGREEN "La clave fue encontrada en la pila\n" ANSI_RESET);
        }

        else
        {
            printf(ANSI_RED "La clave no fue encontrada en la pila\n" ANSI_RESET);
        }
        printf(ANSI_bGREEN);
        p_mostrar(pila); // la vuelvo a mostrar para que se vea que no se modifico durante la llamada a la función de búsqueda
        printf("\n" ANSI_RESET);
    }
    pausa();
    limpiar_pantalla();
}

// PUNTO 2B
void main_insertar_en_pila()
{
    Pila pila = p_crear();
    int clave, posi, cant;
    pila = cargar_pila(&cant);
    printf(ANSI_bGREEN);
    p_mostrar(pila); // muestro la pila como quedo cargada
    printf("\n" ANSI_RESET);
    printf(ANSI_bBLUE "Ingrese clave del elemento a insertar en la pila: " ANSI_YELLOW);
    int validador = scanf("%d", &clave);
    vaciar_buffer();
    while (validador != 1 || clave < -999999 || clave > 999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese clave a insertar en la pila: " ANSI_YELLOW);
        validador = scanf("%d", &clave);
        vaciar_buffer();
    }
    TipoElemento elemento = te_crear(clave);
    printf(ANSI_bBLUE "Ingrese posición donde se insertara en la pila, entre [1-%d]: " ANSI_YELLOW, cant + 1);
    validador = scanf("%d", &posi);
    vaciar_buffer();
    while (validador != 1 || posi <= 0 || posi > cant + 1)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO INCORRECTO" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese posición donde se insertara en la pila, entre [1-%d]: " ANSI_YELLOW, cant + 1);
        validador = scanf("%d", &posi);
        vaciar_buffer();
    }
    if (p_es_vacia(pila))
    {
        p_apilar(pila, elemento);
    }
    else
    {
        pila = insertar(pila, elemento, posi);
    }
    printf(ANSI_bGREEN);
    p_mostrar(pila); // muestro la pila como quedo después de llamar a la función
    printf("\n" ANSI_RESET);
}

// PUNTO 2C
void main_eliminar_por_clave()
{
    Pila pila = p_crear();
    int cant, clave;
    pila = cargar_pila(&cant);
    printf(ANSI_bGREEN);
    p_mostrar(pila); // muestro la pila como quedo cargada
    printf("\n" ANSI_RESET);
    if (!p_es_vacia(pila))
    {
        printf(ANSI_bBLUE "Ingrese clave a eliminar en la pila: " ANSI_YELLOW);
        int validador = scanf("%d", &clave);
        vaciar_buffer();
        while (validador != 1 || clave < -999999 || clave > 999999)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bBLUE "Ingrese clave a eliminar en la pila: " ANSI_YELLOW);
            validador = scanf("%d", &clave);
            vaciar_buffer();
        }
        bool estado = false;
        pila = eliminar_por_clave(pila, clave, &estado);
        if (estado)
        {
            printf(ANSI_GREEN "Se elimino correctamente el elemento %d\n", clave);
        }
        else
        {
            printf(ANSI_RED "El elemento %d no se encuentra en la pila\n", clave);
        }
        printf(ANSI_bGREEN);
        p_mostrar(pila); // la vuelvo a mostrar para confirmar que se hizo bien la eliminación
        printf("\n" ANSI_RESET);
    }
    pausa();
    limpiar_pantalla();
}

// PUNTO 2D
void main_intercambiar()
{
    Pila pila = p_crear();
    int cant, pos1, pos2;
    pila = cargar_pila(&cant);
    printf(ANSI_bGREEN);
    p_mostrar(pila); // muestro la pila como quedo cargada
    printf("\n" ANSI_RESET);
    if (!p_es_vacia(pila))
    {
        printf(ANSI_bBLUE "Ingrese la primera posición a intercambiar, entre [1-%d]: " ANSI_YELLOW, cant);
        int validador = scanf("%d", &pos1);
        vaciar_buffer();
        while (validador != 1 || pos1 < 1 || pos1 > cant)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bBLUE "Ingrese la primera posición a intercambiar, entre [1-%d]: " ANSI_YELLOW, cant);
            validador = scanf("%d", &pos1);
            vaciar_buffer();
        }
        printf(ANSI_bBLUE "Ingrese la segunda posición a intercambiar, entre [1-%d]: " ANSI_YELLOW, cant);
        validador = scanf("%d", &pos2);
        vaciar_buffer();
        while (validador != 1 || pos2 < 1 || pos2 > cant)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bBLUE "Ingrese la segunda posición a intercambiar, entre [1-%d]: " ANSI_YELLOW, cant);
            validador = scanf("%d", &pos2);
            vaciar_buffer();
        }
        pila = intercambiarPos(pila, pos1, pos2);
        printf(ANSI_bGREEN);
        p_mostrar(pila);
        free(pila);
        printf("\n" ANSI_RESET);
    }
    pausa();
}

// PUNTO 2E
void main_duplicar_pila()
{
    Pila pila = p_crear();
    Pila pila_duplicada = p_crear();
    int cant;
    pila = cargar_pila(&cant);
    if (cant == 0)
    {
        printf(ANSI_RED "Pila vacía, su forma duplicada es vacía\n" ANSI_RESET);
    }
    printf(ANSI_bYELLOW "Pila ANTES de llamar a la función\n\n" ANSI_bGREEN);
    p_mostrar(pila); // muestro la pila como quedo cargada
    pila_duplicada = duplicar_pila(pila);
    printf(ANSI_bYELLOW "Pila DUPLICADA\n\n" ANSI_bGREEN);
    p_mostrar(pila_duplicada); // muestro la pila duplicada
    printf(ANSI_bYELLOW "Pila Original DESPUÉS de llamar a la función\n\n" ANSI_bGREEN);
    p_mostrar(pila); // muestro la pila como quedo después de llamar a la función
    printf("\n" ANSI_RESET);
}

// punto 2F
void main_contador()
{
    int contador, cant;
    Pila pila = p_crear();
    pila = cargar_pila(&cant);
    printf(ANSI_bGREEN "Pila cargada: \n");
    p_mostrar(pila);
    contador = contar(pila);
    printf(ANSI_bGREEN "La cantidad de elementos que contiene la pila es de %d" ANSI_RESET, contador);
}

// PUNTO 3
void main_compara_pilas()
{
    Pila pila = p_crear();
    Pila pila2 = p_crear();
    int cant;
    bool rta;
    printf(ANSI_bGREEN "PILA N°1\n");
    pila = cargar_pila(&cant);
    printf(ANSI_bGREEN "PILA N°2\n");
    pila2 = cargar_pila(&cant);
    if (longitud_pila(pila) != longitud_pila(pila2))
    {
        printf(ANSI_RED "Las pilas tiene distintos tamaños entre si, por ende no son iguales\n" ANSI_RESET);
        return;
    }
    printf(ANSI_bGREEN);
    p_mostrar(pila);
    printf("\n");
    p_mostrar(pila2); // muestro como quedaron cargadas las pilas
    printf("\n" ANSI_RESET);
    rta = compara_pilas(pila, pila2);
    if (rta == true)
    {
        printf(ANSI_bGREEN "Las 2 pilas son exactamente iguales\n" ANSI_RESET);
        // return;
    }
    else
    {
        printf(ANSI_RED "Las pilas son distintas una de otra\n" ANSI_RESET);
        // return;
    }
    printf(ANSI_bGREEN);
    p_mostrar(pila);
    printf("\n");
    p_mostrar(pila2); // las vuelvo a mostrar para confirmar que no se modificaron luego de llamar a comparar
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es O(n) porque hay varios ciclos que dependen de la cantidad de elementos de la pila, pero no se encuentran anidados.");
    printf("\n" ANSI_RESET);
}

// PUNTO 4
void main_conversor()
{
    int numero, validador, base;
    printf(ANSI_BLUE "Ingrese un numero: " ANSI_YELLOW);
    validador = scanf("%i", &numero);
    while ((validador != 1) || (numero < -9999999) || (numero > 9999999))
    {
        printf(ANSI_RED "Entrada invalida!\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese un numero: " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &numero);
    }
    printf(ANSI_BLUE "Ingrese la base [2-16]: " ANSI_YELLOW);
    validador = scanf("%i", &base);
    while ((validador != 1) || (base < 2) || (base > 16))
    {
        printf(ANSI_RED "Entrada invalida!\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese la base [2-16]: " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &base);
    }
    printf(ANSI_BLUE "%d en base %d es: " ANSI_GREEN "%s", numero, base, conversor(numero, base));
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es O(n), ya que se utiliza la pila para almacenar el resultado de la conversion, sin haber ciclos anidados que aumenten la complejidad del ejercicio.");
    printf(ANSI_BLUE);
}

// PUNTO 5
void main_invertida()
{
    int cantidad;
    Pila pila = p_crear();
    Pila pila_invertida = p_crear();
    pila = cargar_pila(&cantidad);
    printf(ANSI_bGREEN "pila cargada: \n");
    p_mostrar(pila);
    pila_invertida = invertir_pila(pila);
    printf(ANSI_bGREEN "pila original: \n");
    p_mostrar(pila);
    printf(ANSI_bGREEN "pila invertida: \n");
    p_mostrar(pila_invertida);
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es O(n) porque hay varios ciclos que dependen de la cantidad de elementos de la pila, pero no se encuentran anidados.");
    printf("" ANSI_RESET);
}

// PUNTO 6
void main_eliminar_ocurrencias()
{
    Pila pila = p_crear();
    int cant, valor;
    pila = cargar_pila(&cant);
    if (p_es_vacia(pila))
    {
        printf(ANSI_RED "Pila vacía" ANSI_RESET);
    }
    else
    {
        printf(ANSI_bBLUE "Ingrese clave del elemento para ELIMINAR todas las ocurrencias en la pila [-999.999 - 999.999]: " ANSI_YELLOW);
        int validador = scanf("%d", &valor);
        vaciar_buffer();
        while (validador != 1 || valor < -999999 || valor > 999999)
        {
            limpiar_pantalla();
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE "Ingrese clave del elemento a cargar [-999.999 - 999.999]: " ANSI_YELLOW);
            validador = scanf("%d", &valor);
            vaciar_buffer();
        }
        TipoElemento elemento = te_crear(valor);
        printf(ANSI_bBLUE "\nElija de que manera se llamara a la función\n\n1- Iterativamente\n2- Recursivamente\nIngresar opción: " ANSI_YELLOW);
        int opc;
        validador = scanf("%d", &opc);
        vaciar_buffer();
        while (validador != 1 || (opc != 1 && opc != 2))
        {
            limpiar_pantalla();
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingresar una opción [1-2]\n\n" ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE "\nElija de que manera se llamara a la función\n\n1- Iterativamente\n2- Recursivamente\nIngresar opción: " ANSI_YELLOW);
            validador = scanf("%d", &opc);
            vaciar_buffer();
        }
        printf(ANSI_bYELLOW "Pila ANTES de llamar a la función\n\n" ANSI_bGREEN);
        p_mostrar(pila); // muestro la pila como quedo cargada
        printf("\n" ANSI_RESET);
        Pila pilaEliminada = p_crear();
        if (opc == 1)
        {
            pilaEliminada = eliminar_ocurrencias(pila, elemento);
        }
        else
        {
            pilaEliminada = eliminar_ocurrencias_recursivo(pila, elemento);
        }
        printf(ANSI_bYELLOW "Pila DESPUÉS de llamar a la función\n\n" ANSI_bGREEN);
        p_mostrar(pila); // muestro la pila como quedo cargada
        printf(ANSI_bYELLOW "Pila con los valores eliminados\n\n" ANSI_bGREEN);
        p_mostrar(pilaEliminada); // muestro la pila como quedo cargada
    }
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada tanto de manera recursiva como iterativa es O(n), ya que si o si en ambas implementaciones, va sacar todos los elementos de la pila para luego compararlos y volver a agregarlos.");
    printf("\n" ANSI_RESET);
}

// PUNTO 7
void main_elemento_en_comun()
{
    Pila pila = p_crear();
    Pila pila2 = p_crear();
    int cant;
    printf(ANSI_bGREEN "PILA N°1\n");
    pila = cargar_pila(&cant);
    printf(ANSI_bGREEN "PILA N°2\n");
    pila2 = cargar_pila(&cant);
    printf(ANSI_bYELLOW "Pila 1 y 2 ANTES de llamar a la función de comparar\n" ANSI_bGREEN);
    p_mostrar(pila);
    printf("\n");
    p_mostrar(pila2); // muestro como quedaron cargadas las pilas
    printf("\n" ANSI_RESET);
    if (p_es_vacia(pila) || p_es_vacia(pila2))
    {
        printf(ANSI_RED "Una de las pilas esta vacía, por ende no van a tener elementos en común" ANSI_RESET);
    }
    else
    {
        Pila pcomun = p_crear();
        pcomun = elemento_en_comun(pila, pila2);
        if (p_es_vacia(pcomun))
        {
            printf(ANSI_RED "Ninguno de los elementos de las pilas coincidieron\n");
        }
        else
        {
            printf(ANSI_YELLOW "Pila con elementos en común\n");
            p_mostrar(pcomun);
            printf("\n\n" ANSI_RESET);
        }
        printf(ANSI_bYELLOW "Pila 1 y 2 DESPUÉS de llamar a la función de comparar\n" ANSI_bGREEN);
        p_mostrar(pila);
        printf("\n");
        p_mostrar(pila2); // las vuelvo a mostrar para confirmar que no se modificaron luego de llamar a comparar
    }
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es O(n^2) porque se utilizan dos ciclos anidados para recorrer ambas pilas, lo que en el peor de los casos, la longitud de ambas seria igual.");
    printf("\n" ANSI_RESET);
}

void mostrar_valores(Pila p1)
{
    TipoElemento x;
    printf(ANSI_GREEN "\tNumero\t" ANSI_MAGENTA "|" ANSI_GREEN " Repeticiones\n");
    printf(ANSI_MAGENTA "      __________|_____________\n");
    while (!p_es_vacia(p1))
    {
        x = p_desapilar(p1);
        printf(ANSI_YELLOW "\t%d\t" ANSI_MAGENTA "|   " ANSI_YELLOW "%d \n", x->clave, *(int *)x->valor);
    }
}

// PUNTO 8
void main_contador_valores()
{
    Pila pila = p_crear();
    int cant;
    pila = cargar_pila(&cant);
    printf(ANSI_bGREEN);
    p_mostrar(pila);
    printf("\n");
    if (!p_es_vacia(pila))
    {
        Pila paux = repetidor(pila);
        printf(ANSI_bBLUE "Los elementos son: \n" ANSI_RESET);
        mostrar_valores(paux);
        printf("\n");
    }
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es O(n^2) porque a pesar que hay varios ciclos que dependen de la cantidad de elementos que posea la pila, solo hay un nivel de anidación, lo que se volvería critico en el peor de los casos, siendo complejidad cuadrática.");
    printf("\n" ANSI_RESET);
}

void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 TP3 PILAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con pilas\n");
    printf("  3   Pilas iguales\n");
    printf("  4   Conversor de base\n");
    printf("  5   Invertir pila\n");
    printf("  6   Eliminar item\n");
    printf("  7   Elementos en común\n");
    printf("  8   Contador de valores\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

void menu_punto2()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                         2   Operaciones con pilas                         |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Buscar elemento\n");
    printf("  2   Insertar elemento\n");
    printf("  3   Eliminar elemento\n");
    printf("  4   Intercambiar elementos\n");
    printf("  5   Duplicar pila\n");
    printf("  6   Contar elementos\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

int main()
{
    bool salir1 = false;
    bool salir = false;
    int opcion;
    while (!salir)
    {
        menu_principal();
        int validador = scanf("%i", &opcion);
        while (validador != 1 || opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            while (getchar() != '\n')
                ;
            validador = scanf("%i", &opcion);
        }
        switch (opcion)
        {
        case 2:
            while (!salir1)
            {
                menu_punto2();
                validador = scanf("%i", &opcion);
                while (validador != 1 || opcion < 0 || opcion > 6)
                {
                    printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
                    printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
                    while (getchar() != '\n')
                        ;
                    validador = scanf("%i", &opcion);
                }
                switch (opcion)
                {
                case 1:
                    main_buscar_clave();
                    // getch();
                    break;
                case 2:
                    main_insertar_en_pila();
                    getch();
                    break;
                case 3:
                    main_eliminar_por_clave();
                    // getch();
                    break;
                case 4:
                    main_intercambiar();
                    // getch();
                    break;
                case 5:
                    main_duplicar_pila();
                    getch();
                    break;
                case 6:
                    main_contador();
                    getch();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            main_compara_pilas();
            getch();
            break;
        case 4:
            main_conversor();
            getch();
            break;
        case 5:
            main_invertida();
            getch();
            break;
        case 6:
            main_eliminar_ocurrencias();
            getch();
            break;
        case 7:
            main_elemento_en_comun();
            getch();
            break;
        case 8:
            main_contador_valores();
            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}