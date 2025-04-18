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
    int clave, validador, cant;
    bool rta;
    printf(ANSI_bMAGENTA "Cargar la cola: \n");
    c = cargarCola(&cant);
    if (!c_es_vacia(c))
    {
        printf(ANSI_bMAGENTA "Ingrese el elemento a buscar [-999.999 - 999.999]: " ANSI_YELLOW);
        validador = scanf("%d", &clave);
        vaciar_buffer();
        while (validador != 1 || clave < -999999 || clave > 999999)
        {
            printf(ANSI_RED "\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO\n\n" ANSI_RESET);
            pausa();
            printf(ANSI_bBLUE "Ingrese el elemento a buscar [-999.999 - 999.999]: " ANSI_YELLOW);
            validador = scanf("%d", &clave);
            vaciar_buffer();
        }
        rta = buscar(c, clave);
        c_mostrar(c);
        printf("\n");
        if (rta == true)
            printf(ANSI_bGREEN "Se encontró el elemento %i en la cola\n", clave);
        else
        {
            printf(ANSI_RED "No se encontró el elemento en la cola\n");
        }
    }
    printf(ANSI_RESET);
}

/// @brief Punto 2C: Agrega un nuevo elemento en una posición dada (colarse).
void main_borrar()
{
    int cant;
    Cola cola = c_crear();
    cola = cargarCola(&cant);
    TipoElemento X;
    int elemento;
    printf(ANSI_bBLUE "ingrese el elemento que quiere borrar: " ANSI_bYELLOW);
    scanf("%d", &elemento);
    X = te_crear(elemento);
    borrar_elemento(cola, X);
    printf(ANSI_bGREEN);
    c_mostrar(cola);
    printf(ANSI_RESET);
}

/// @brief Punto 2F: Invierte del contenido de una cola sin destruir la cola original.
void main_invertida()
{
    int cant;
    Cola cola = c_crear();
    Cola caux = c_crear();
    Cola cola_invertida = c_crear();
    cola = cargarCola(&cant);
    cola_invertida = invertir(cola, caux, cant);
    printf(ANSI_bGREEN "Cola invertida: \n");
    c_mostrar(cola_invertida);
    printf(ANSI_bGREEN "\nCola original: \n");
    c_mostrar(cola);
    printf(ANSI_RESET);
}

/// @brief Punto 2B: Inserta un elemento en la posición dada
void main_insertar_en_cola()
{
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
    if (c_es_vacia(c))
    {
        c_encolar(c, elemento);
    }
    else
    {
        c = insertar(c, elemento, posi);
    }
    printf(ANSI_GREEN);
    c_mostrar(c);
    printf("\n" ANSI_RESET);
}

/// @brief Punto 2C: Agrega un nuevo elemento en una posición dada (colarse).
void main_eliminar_repeticiones()
{
    Cola c = c_crear();
    int cant, clave;
    c = cargarCola(&cant);
    printf("\n");
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
    }
    else
        printf(ANSI_bRED "No se puede buscar un elemento si la cola esta vacía");
    printf("\n" ANSI_RESET);
    pausa();
    limpiar_pantalla();
}

/// @brief Punto 2D: Contar los elementos de una cola
void main_contador()
{
    int contador, cant;
    Cola c = c_crear();
    c = cargarCola(&cant);
    contador = Longitud(c);
    printf(ANSI_bGREEN "La cantidad de elementos que contiene la pila es de %d" ANSI_RESET, contador);
}

/// @brief Punto 2E: Clona una cola
void main_clonar()
{
    int cant;
    Cola cola = c_crear();
    Cola colaClon = c_crear();
    cola = cargarCola(&cant);
    if (c_es_vacia(cola))
    {
        printf(ANSI_YELLOW "La cola esta vacía, se hara la copia igualmente pero este es solo un aviso\n\n" ANSI_RESET);
    }
    colaClon = copiar_cola(cola);
    printf(ANSI_bMAGENTA "\nCola clonada: \n");
    c_mostrar(colaClon);
    printf(ANSI_bGREEN "\n\nCola original DESPUES de llamar a la función: \n");
    c_mostrar(cola);
    printf("" ANSI_RESET);
    pausa();

    limpiar_pantalla();
}

/// @brief Punto 3: Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos (solo comparar por la clave), sin destruirlas. Utilizar para la resolución del problema una sola cola auxiliar. Determinar la complejidad algorítmica del problema.
void main_punto3()
{
    int cant1, cant2;
    Cola c1, c2;
    c1 = cargarCola(&cant1);
    c2 = cargarCola(&cant2);
    if (!c_es_vacia(c1) || (!c_es_vacia(c2)))
    {
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
    }
    else
    {
        printf(ANSI_RED "Las colas están vacías");
    }
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es lineal O(n^2) porque se utilizan dos ciclos anidados para recorrer ambas colas.");
    pausa();
}

/// @brief Punto 4: Dada una cola de números enteros, no ordenada, construir un algoritmo que permita pasar a otra cola todos los elementos que no se repiten en la primera, sin destruir el contenido de la cola original y dejándola en su estado inicial. Determinar la complejidad algorítmica de la solución.
void main_punto4()
{
    int cant;
    Cola c1, c2 = c_crear();
    c1 = cargarCola(&cant);
    if (!c_es_vacia(c1))
    {
        c2 = norepetidos(c1);
        if (!c_es_vacia(c2))
        {
            printf(ANSI_GREEN "Los elementos no repetidos de la cola son:\n");
            c_mostrar(c2);
        }
        else
        {
            printf(ANSI_RED "La cola no posee elementos no repetidos.");
        }
    }
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es polinomial O(n^a) porque se utilizan tres ciclos anidados para recorrer las colas.");
    pausa();
    printf(ANSI_RESET);
}

/// @brief Punto 5: Dada una cola de valores enteros no repetidos y mayores o iguales a 2, obtener todos los valores que son Divisores Totales o parciales. Se dice que un valor es Divisor Total si permite dividir a todos los demás valores de la cola en forma exacta. Se dice que un divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola (es decir a la mitad de los elementos).
void main_divisores()
{
    int cant;
    Cola cola = c_crear();
    Cola Divisor_total = c_crear();
    Cola Divisor_parcial = c_crear();
    int numero_actual = 2;
    int elemento_mayor_cola = 0; // esta variable se utiliza para que la función termine si el contador numero_actual supera el valor del elemento mayor de la cola
    cola = cargarColaSinRepetidos_divisores(&cant, &elemento_mayor_cola);
    float longitud_cola = cant;
    if (!c_es_vacia(cola))
    {
        while (numero_actual <= 1000 && numero_actual <= elemento_mayor_cola)
        {
            divisores(cola, Divisor_total, Divisor_parcial, numero_actual, longitud_cola);
            numero_actual++;
        }
        printf(ANSI_bGREEN "\nSe muestran solo divisores entre el 2 y el 1000:\n");
        printf("Divisores totales: \n");
        c_mostrar(Divisor_total);
        printf(ANSI_bGREEN "\nDivisores parciales: \n");
        c_mostrar(Divisor_parcial);
    }
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es lineal O(n) porque hay varios ciclos que dependen de la cantidad de elementos de la cola, pero no se encuentran anidados.");
    printf(ANSI_RESET);
}

/// @brief Punto 6: Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas y en qué posición ordinal se encontró cada uno en su estructura. No se deben destruir las estructuras originales. No se deben perderse las estructuras originales.
void main_valores_comunes()
{
    int cantColas, cantPilas;
    Lista l = l_crear();
    printf(ANSI_bCYAN "Cargando la pila: \n");
    Pila p = cargarPilaSinRepetidos(&cantPilas);
    printf(ANSI_bCYAN "Cargando la cola: \n");
    Cola c = cargarColaSinRepetidos(&cantColas);
    pausa();
    limpiar_pantalla();
    p_mostrar(p);
    c_mostrar(c);
    if (p_es_vacia(p) || c_es_vacia(c))
    {
        printf(ANSI_RED "\n Las estructuras no tienen valores comunes ya que al menos una de ellas esta vacía");
        printf(ANSI_RESET);
    }
    else
    {
        l = valoresComunes(p, c);
        mostrarListaConValor(l);
    }
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es lineal O(n^2) porque dentro del ciclo que depende de la pila, se encuentra anidado un ciclo que depende de la lista. Si se considera que ambas estructuras tienen n elementos, la complejidad para retornar la lista seria n^2.");
    pausa();
}

/// @brief Punto 7: Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en cada ventanilla. Un día, dos de los tres empleados que atienden las ventanillas no pueden asistir al trabajo, quedando uno solo para atender a las tres colas. Este empleado decide que, a medida que lleguen los clientes, atenderá por cierta cantidad de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas equitativamente.
void main_ventanillas()
{
    Cola cola1 = c_crear();
    Cola cola2 = c_crear();
    Cola cola3 = c_crear();
    int cant, q;
    printf(ANSI_bMAGENTA "COLA DE LA VENTANILLA 1\n");
    cola1 = cargarColaMayores0(&cant);
    printf(ANSI_bMAGENTA "COLA DE LA VENTANILLA 2\n");
    cola2 = cargarColaMayores0(&cant);
    printf(ANSI_bMAGENTA "COLA DE LA VENTANILLA 3\n");
    cola3 = cargarColaMayores0(&cant);
    printf(ANSI_BLUE "Ingrese la cantidad de tiempo que se quedara en cada cola: " ANSI_YELLOW);
    int validador = scanf("%i", &q);
    vaciar_buffer();
    while (validador != 1 || q <= 0)
    {
        printf(ANSI_RED "\t\t-----ERROR-----\n\n ");
        printf("Por favor SOLO ingresar números mayores a 0\n\n ");
        printf(ANSI_BLUE "Ingrese la cantidad de tiempo que se quedara en cada cola: " ANSI_YELLOW);
        validador = scanf("%i", &q);
        vaciar_buffer();
    }
    ventanillas(q, cola1, cola2, cola3);
    printf(ANSI_bMAGENTA "\nCOMPLEJIDAD ALGORÍTMICA\nLa complejidad de la solución empleada es lineal O(n) porque el bucle depende de la suma de la cantidad de elementos de las colas, dicha suma seria n*3, siendo n la cantidad de elementos de cada cola.");
    pausa();
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
                    // main_borrar();
                    getch();
                    break;
                case 4:
                    main_contador();
                    getch();
                    break;
                case 5:
                    main_clonar();
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
            // getch();
            break;
        case 4:
            main_punto4();
            // getch();
            break;
        case 5:
            main_divisores();
            getch();
            break;
        case 6:
            main_valores_comunes();
            // getch();
            break;
        case 7:
            main_ventanillas();
            // getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}