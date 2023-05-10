#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP4_colas.h"
#include "colas.h"
#include "pilas.h"
#include "listas.h"
#include "tipo_elemento.h"

/// @brief Punto 2A: Informar si un elemento dado se encuentra en la cola.
void main_buscarElemento()
{
    Cola c;
    int clave, validador;
    bool rta;
    printf(ANSI_bMAGENTA "Cargar la cola: \n");
    c = cargarCola();
    if (!c_es_vacia(c))
    {

        printf(ANSI_bMAGENTA "Ingrese el elemento a buscar [-999.999 - 999.999]: \n" ANSI_YELLOW);
        validador = scanf("%d", &clave);
        vaciar_buffer();
        while (validador != 1 || clave < -999999 || clave > 999999)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bBLUE "Ingrese el elemento a buscar [-999.999 - 999.999]: \n" ANSI_YELLOW);
            validador = scanf("%d", &clave);
            vaciar_buffer();
        }

        rta = buscar(c, clave);
        c_mostrar(c);

        if (rta == true)
            printf(ANSI_bGREEN "Se encontró el elemento %i en la cola\n", clave);
        else
        {
            printf(ANSI_RED "No se encontró el elemento en la cola\n");
        }
    }
    printf(ANSI_RESET);
}
//punto 2C
void main_borrar(){
    Cola cola = c_crear();
    cola = cargarCola();
    TipoElemento X;
    int elemento;
    printf(ANSI_bBLUE"ingrese el elemento que quiere borrar: "ANSI_bYELLOW);
    scanf("%d",&elemento);
    X = te_crear(elemento);
    borrar_elemento(cola, X);
    printf(ANSI_bGREEN"");
    c_mostrar(cola);
    printf(ANSI_RESET"");
}

//punto 2F
void main_invertida(){
    Cola cola = c_crear();
    Cola caux = c_crear();
    Cola cola_invertida = c_crear();
    TipoElemento X;
    cola = cargarCola();
    int longitud_cola = 0;
     while (c_es_vacia(cola)!= true)//esta seccion solo encuentra el 
    {                              //elemento mayor de la cola (para limitar la funcion) y la longitud en flotante 
    
        X = c_desencolar(cola);
        longitud_cola++;
        c_encolar(caux, X);
    }
    while (c_es_vacia(caux) != true)
    {
        X = c_desencolar(caux);
        c_encolar(cola , X);
    }
    cola_invertida = invertir(cola,caux , longitud_cola);
    printf(ANSI_bGREEN"cola invertida: \n");
    c_mostrar(cola_invertida);
    printf(ANSI_bGREEN"\ncola original: \n");
    c_mostrar(cola);
} 

/// @brief Punto 2b: Inserta un elemento en la posicion dada
void main_insertar_en_cola(){
    Cola c = c_crear();
    int clave, posi, cant;
    c = cargarCola(&cant);
    printf(ANSI_bGREEN);
    printf("\n" ANSI_RESET);
    printf(ANSI_bBLUE "Ingrese clave del elemento a insertar en la cola: " ANSI_YELLOW);
    int validador = scanf("%d", &clave);
    vaciar_buffer();
    while (validador != 1 || clave < -999999 || clave > 999999)
    {
        printf(ANSI_RED "\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE "Ingrese clave a insertar en la cola: " ANSI_YELLOW);
        validador = scanf("%d", &clave);
        vaciar_buffer();
    }
    TipoElemento elemento = te_crear(clave);
    printf(ANSI_bBLUE "Ingrese posición donde se insertara en la cola, entre [1-%d]: " ANSI_YELLOW, cant + 1);
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
    if (c_es_vacia(c)){
        c_encolar(c, elemento);
    } else {
        c = insertar(c, elemento, posi);
    }
    c_mostrar(c);
    printf("\n" ANSI_RESET);
}

/// @brief Punto 2c: Eliminar todas las repeticiones de un elemento dado
void main_eliminar_repeticiones(){
    Cola c = c_crear();
    int cant, clave;
    c = cargarCola(&cant);
    printf(ANSI_bGREEN);
    printf("\n" ANSI_RESET);
    if (!c_es_vacia(c))
    {
        printf(ANSI_bBLUE "Ingrese clave a eliminar en la cola: " ANSI_YELLOW);
        int validador = scanf("%d", &clave);
        vaciar_buffer();
        while (validador != 1 || clave < -999999 || clave > 999999)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingresar un numero entre [-999.999 - 999.999]\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bBLUE "Ingrese clave a eliminar en la cola: " ANSI_YELLOW);
            validador = scanf("%d", &clave);
            vaciar_buffer();
        }
        bool estado;
        c = eliminarTodas(c, clave, &estado);
        if (estado)
        {
            printf(ANSI_GREEN "Se elimino correctamente el elemento %d\n", clave);
        }
        else
        {
            printf(ANSI_RED "El elemento %d no se encuentra en la cola\n", clave);
        }
        printf(ANSI_bGREEN);
        c_mostrar(c); // la vuelvo a mostrar para confirmar que se hizo bien la eliminación
        printf("\n" ANSI_RESET);
    } else printf(ANSI_bRED "No se puede buscar un elemento si la cola esta vacia");
    printf("\n" ANSI_RESET);
    pausa();
    limpiar_pantalla();
}

/// @brief Punto 2d: Contar los elementos de una cola
void main_contador()
{
    int contador, cant;
    Cola c = c_crear();
    c = cargarCola(&cant);
    contador = Longitud(c);
    printf(ANSI_bGREEN "La cantidad de elementos que contiene la pila es de %d" ANSI_RESET, contador);
}

/// @brief Punto 3: Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos (solo comparar por la clave), sin destruirlas. Utilizar para la resolución del problema una sola cola auxiliar. Determinar la complejidad algorítmica del problema.
void main_punto3()
{
    Cola c1, c2;
    c1 = cargarCola();
    c2 = cargarCola();
    if (Comparar(c1, c2))
    {
        printf(ANSI_GREEN "Las colas son iguales\n");
        printf(ANSI_GREEN "Cola 1\n");
        c_mostrar(c1);
        printf("\n");
        printf(ANSI_GREEN "Cola 2\n");
        c_mostrar(c2);
    }
    else
    {
        printf(ANSI_RED "Las colas no son iguales\n");
        printf(ANSI_GREEN "Cola 1\n");
        c_mostrar(c1);
        printf("\n");
        printf(ANSI_GREEN "Cola 2\n");
        c_mostrar(c2);
    }
    printf(ANSI_RESET);
}

/// @brief Punto 4: Dada una cola de números enteros, no ordenada, construir un algoritmo que permita pasar a otra cola todos los elementos que no se repiten en la primera, sin destruir el contenido de la cola original y dejándola en su estado inicial. Determinar la complejidad algorítmica de la solución.
void main_punto4()
{
    Cola c1, c2 = c_crear();
    c1 = cargarCola();
    if (!c_es_vacia(c1))
    {
        c2 = norepetidos(c1);
        printf(ANSI_GREEN "Los elementos no repetidos de la cola son:\n");
        c_mostrar(c2);
    }
    printf(ANSI_RESET);
}

//Punto 5
void main_divisores(){
    Cola cola = c_crear();
    Cola caux = c_crear();
    Cola Divisor_total = c_crear();
    Cola Divisor_parcial = c_crear();
    TipoElemento X;
    int numero_actual = 2;
    int elemento_mayor_cola = 0;
    float longitud_cola = 0;
    cola = cargarCola();
    while (c_es_vacia(cola)!= true)//esta seccion solo encuentra el 
    {                              //elemento mayor de la cola (para limitar la funcion) y la longitud en flotante 
    
        X = c_desencolar(cola);
        if (X->clave > elemento_mayor_cola)
        {
            elemento_mayor_cola = X->clave;
        }
        longitud_cola++;
        c_encolar(caux, X);
    }
    while (c_es_vacia(caux) != true)
    {
        X = c_desencolar(caux);
        c_encolar(cola , X);
    }
    while (numero_actual <= 100 || numero_actual < elemento_mayor_cola)
    {
        divisores(cola, Divisor_total, Divisor_parcial, numero_actual, longitud_cola);
        numero_actual++;
    }
    printf(ANSI_bGREEN"Divisores totales: \n");
    c_mostrar(Divisor_total);
    printf("\n");
    printf(ANSI_bGREEN"\nDivisores parciales: \n");
    c_mostrar(Divisor_parcial);
    printf(ANSI_RESET"");
}

//  PUNTO 6
void main_valores_comunes(){
    int cantColas, cantPilas;
    Lista l = l_crear();
    printf(ANSI_bCYAN"Cargando la pila: \n");
    Pila p = cargarPilaSinRepetidos(&cantPilas);
    printf(ANSI_bCYAN"Cargando la cola: \n");
    Cola c = cargarColaSinRepetidos(&cantColas);
    pausa();
    limpiar_pantalla();
    p_mostrar(p);
    c_mostrar(c);
    if (p_es_vacia(p) || c_es_vacia(c)){
        printf(ANSI_RED"\n Las estructuras no tienen valores comunes ya que al menos una de ellas esta vacia");
        printf(ANSI_RESET);
    } 
    else {
        l = valoresComunes(p,c);
        mostrarListaConValor(l);
    }
}


/// @brief Menu principal del TP de Colas
void menu_principal()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 TP4 COLAS                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  2   Operaciones con colas\n");
    printf("  3   Colas iguales\n");
    printf("  4   Elementos no repetidos\n");
    printf("  5   Divisores\n");
    printf("  6   Lista con valores comunes\n");
    printf("  7   Cola de clientes\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

/// @brief Menu del Punto 2: Operaciones con cola
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
    printf("  4   Contar los elementos\n");
    printf("  5   Realizar una copia\n");
    printf("  6   Invertir\n");
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
        while (getchar() != '\n')
            ;
        while (validador != 1 || opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            validador = scanf("%i", &opcion);
            while (getchar() != '\n')
                ;
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
                    main_buscarElemento();
                    getch();
                    break;
                case 2:
                    main_insertar_en_cola();
                    getch();
                    break;
                case 3:
                    main_eliminar_repeticiones();
                    //main_borrar();
                    getch();
                    break;
                case 4:
                    main_contador();
                    getch();
                    break;
                case 5:

                    getch();
                    break;
                case 6:
                    main_invertida();
                    getch();
                    break;
                case 0:
                    salir1 = true;
                }
            }
            break;
            menu_principal();
        case 3:
            main_punto3();
            getch();
            break;
        case 4:
            main_punto4();
            getch();
            break;
        case 5:
            main_divisores();
            getch();
            break;
        case 6:
            main_valores_comunes();
            getch();
            break;
        case 7:

            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}