#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "TP3_pilas.h"
#include "pilas.h"
#include "tipo_elemento.h"


int vaciar_buffer(void){
    char nada[200];
    fgets(nada, 200, stdin);
    return 0;
}

void pausa()
{
    printf(ANSI_YELLOW "\npresiones ENTER para continuar...." ANSI_RESET);
    getchar();
}

void limpiar_pantalla()
{
    printf("\033[2J\033[1;1H");
    return;
}

Pila p_intercambiar(Pila pila, Pila pilaAux){
    TipoElemento x = te_crear(0);
    while(!p_es_vacia(pilaAux)){
        x = p_desapilar(pilaAux);
        p_apilar(pila,x);
    }
    free(pilaAux);
    return pila;
}

int longitud_pila(Pila pila){
    int x=0;
    TipoElemento e = te_crear(0);
    Pila paux = p_crear();
    while (!p_es_vacia(pila)){
        e = p_desapilar(pila);
        p_apilar(paux,e);
        x++;
    }
    pila = p_intercambiar(pila,paux);
    return x;
}



// PUNTO 2A
void main_buscar_clave(){
    Pila pila = p_crear();
    int cant,valor,clave;
    bool rta;
    printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar [0-99]: "ANSI_RESET);
    int validador = scanf("%d",&cant);
    vaciar_buffer();
    while (validador != 1 || cant<0 || cant>=100){
        limpiar_pantalla();
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingrasar un numero entre [0-99]\n\n"ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar: "ANSI_RESET);
        validador = scanf("%d",&cant);
        vaciar_buffer();
        
    }
    
    for (int i=0;i<cant;i++){
        printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
        validador = scanf("%d",&valor);
        vaciar_buffer();
        while(validador!=1 || valor<-999999 || valor>999999){
            limpiar_pantalla();
            printf(ANSI_RED"\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
            validador = scanf("%d",&valor); 
            vaciar_buffer();
            
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila,elemento);
        limpiar_pantalla();
    }
    printf(ANSI_bGREEN"");
    p_mostrar(pila);            // muestro la pila como quedo cargada
    printf("\n"ANSI_RESET);
    printf(ANSI_bBLUE"ingrese clave a buscar en la pila: "ANSI_RESET);
    validador = scanf("%d",&clave);
    vaciar_buffer();
    while(validador!=1 || clave<-999999 || clave>999999){
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE"ingrese clave a buscar en la pila: "ANSI_RESET);
        validador = scanf("%d",&clave); 
        vaciar_buffer();
    }

    rta = buscar_c(pila,clave);
    if(rta == true){
        printf(ANSI_bGREEN"La clave fue enconrtada en la pila\n"ANSI_RESET);
    } 

    else{
        printf(ANSI_RED"La clave no fue enconrtada en la pila\n"ANSI_RESET);
    }

    printf(ANSI_bGREEN"");
    p_mostrar(pila);            // la vuelvo a mostrar para que se vea que no se modico durante la llamada a la funcion de busqueda
    printf("\n"ANSI_RESET);

    pausa();
    limpiar_pantalla();
}

// PUNTO 2C
void main_eliminar_por_clave(){
    Pila pila = p_crear();
    int cant,valor,clave;
    printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar [0-99]: "ANSI_RESET);
    int validador = scanf("%d",&cant);
    vaciar_buffer();
    while (validador != 1 || cant<0 || cant>=100){
        limpiar_pantalla();
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingrasar un numero entre [0-99]\n\n"ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar: "ANSI_RESET);
        validador = scanf("%d",&cant);
        vaciar_buffer();
        
    }
    
    for (int i=0;i<cant;i++){
        printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
        validador = scanf("%d",&valor);
        vaciar_buffer();
        while(validador!=1 || valor<-999999 || valor>999999){
            limpiar_pantalla();
            printf(ANSI_RED"\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
            validador = scanf("%d",&valor); 
            vaciar_buffer();
            
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila,elemento);
        limpiar_pantalla();
    }
    printf(ANSI_bGREEN"");
    p_mostrar(pila);            // muestro la pila como quedo cargada
    printf("\n"ANSI_RESET);

    printf(ANSI_bBLUE"ingrese clave a eliminar en la pila: "ANSI_RESET);
    validador = scanf("%d",&clave);
    vaciar_buffer();
    while(validador!=1 || clave<-999999 || clave>999999){
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
        pausa();
        printf(ANSI_bBLUE"ingrese clave a eliminar en la pila: "ANSI_RESET);
        validador = scanf("%d",&clave); 
        vaciar_buffer();
    }
    
    pila = eliminar_por_clave(pila,clave);

    printf(ANSI_bGREEN"");
    p_mostrar(pila);            // la vuelvo a mostrar para confirmar que se hizo bien la eliminacion
    printf("\n"ANSI_RESET);
    pausa();
}

//punto 2F
void main_contador(){
    int contador, cantidad, clave_actual;
    Pila pila = p_crear();
    TipoElemento elemento = te_crear(0);
    printf(ANSI_bBLUE"ingrese la cantidad de elementos a cargar[0-99]: "ANSI_RESET);
    scanf("%d", &cantidad);
    for (int i = 0; i < cantidad; i++)
    {
        printf(ANSI_bBLUE"ingrese el valor para cargar a la pila:"ANSI_RESET);
        scanf("%d", &clave_actual);
        elemento = te_crear(clave_actual);
        p_apilar(pila, elemento);
    }
    
    p_mostrar(pila);

    contador = contar(pila);
    printf(ANSI_bGREEN"la cantidad de elementos que contiene la pila es de %d"ANSI_RESET, contador);
}

// PUNTO 3
void main_compara_pilas(){
    Pila pila = p_crear();
    Pila pila2 = p_crear();
    int cant,valor;
    bool rta;
    printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar en la 1ra Pila[0-99]: "ANSI_RESET);
    int validador = scanf("%d",&cant);
    vaciar_buffer();
    while (validador != 1 || cant<0 || cant>=100){
        limpiar_pantalla();
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingrasar un numero entre [0-99]\n\n"ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar: "ANSI_RESET);
        validador = scanf("%d",&cant);
        vaciar_buffer();
        
    }
    
    for (int i=0;i<cant;i++){
        printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
        validador = scanf("%d",&valor);
        vaciar_buffer();
        while(validador!=1 || valor<-999999 || valor>999999){
            limpiar_pantalla();
            printf(ANSI_RED"\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
            validador = scanf("%d",&valor); 
            vaciar_buffer();
            
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila,elemento);
        limpiar_pantalla();
    }
    
    printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar en la 2da Pila[0-99]: "ANSI_RESET);
    validador = scanf("%d",&cant);
    vaciar_buffer();
    while (validador != 1 || cant<0 || cant>=100){
        limpiar_pantalla();
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingrasar un numero entre [0-99]\n\n"ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar: "ANSI_RESET);
        validador = scanf("%d",&cant);
        vaciar_buffer();
        
    }
    
    for (int i=0;i<cant;i++){
        printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
        validador = scanf("%d",&valor);
        vaciar_buffer();
        while(validador!=1 || valor<-999999 || valor>999999){
            limpiar_pantalla();
            printf(ANSI_RED"\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
            validador = scanf("%d",&valor); 
            vaciar_buffer();
            
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila2,elemento);
        limpiar_pantalla();
    }
    
    if(longitud_pila(pila) != longitud_pila(pila2)){
        printf("Las pilas tiene distintos tamaños entre si, por ende no son iguales\n");
        return;
    }

    printf(ANSI_bGREEN"");
    p_mostrar(pila);
    printf("\n");           // muestro como quedaron cargadas las pilas
    p_mostrar(pila2);
    printf("\n"ANSI_RESET);

    rta = compara_pilas(pila,pila2);
    if(rta == true){
        printf(ANSI_bGREEN"Las 2 pilas son exactamente iguales\n"ANSI_RESET);
        //return;
    }
    else{
       printf(ANSI_RED"Las pilas son distintas una de otra\n"ANSI_RESET);
        //return; 
    }
    printf(ANSI_bGREEN"");
    p_mostrar(pila);
    printf("\n");           // las vuelvo a mostrar para confirmar que no se modificaron luego de llamar a comparar
    p_mostrar(pila2);
    printf("\n"ANSI_RESET);
}

// PUNTO 4
void main_conversor()
{
    int numero, validador, base;
    printf(ANSI_BLUE "Ingrese un numero: " ANSI_YELLOW);
    validador = scanf("%i", &numero);
    while ((validador != 1) || (numero < 0) || (numero > 9999999))
    {
        printf(ANSI_RED "Entrada invalida!\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese un numero: " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &numero);
    }
    printf(ANSI_BLUE "Ingrese la base [2-16]: " ANSI_YELLOW);
    validador = scanf("%i", &base);
    while ((validador != 1) || (base < 0) || (base > 16))
    {
        printf(ANSI_RED "Entrada invalida!\n" ANSI_RESET);
        printf(ANSI_BLUE "Ingrese la base [2-16]: " ANSI_YELLOW);
        while (getchar() != '\n')
            ;
        validador = scanf("%i", &base);
    }
    printf(ANSI_BLUE "%d en base %d es: " ANSI_GREEN, numero, base);
    Pila pila = conversor(numero, base);
    mostrarhex(pila);
    printf(ANSI_BLUE);
}

//PUNTO 5
void main_invertida(){
    int cantidad, clave_actual;
    Pila pila = p_crear();
    Pila pila_invertida = p_crear();
    TipoElemento elemento = te_crear(0);
    
    printf(ANSI_bBLUE"ingrese la cantidad de elementos a cargar[0-99]: "ANSI_RESET);
    scanf("%d", &cantidad);
    
    for (int i = 0; i < cantidad; i++)
    {
        printf(ANSI_bBLUE"ingrese el valor para cargar a la pila:"ANSI_RESET);
        scanf("%d", &clave_actual);
        elemento = te_crear(clave_actual);
        p_apilar(pila, elemento);
    }
    
    printf(ANSI_bGREEN"pila cargada: \n"ANSI_RESET);
    p_mostrar(pila);

    pila_invertida = invertir_pila(pila);

    printf(ANSI_bGREEN"pila original: \n"ANSI_RESET);
    p_mostrar(pila);
    printf(ANSI_bGREEN"pila invertida: \n"ANSI_RESET);
    p_mostrar(pila_invertida);
}

// PUNTO 7 
void main_elemento_en_comun(){
    Pila pila = p_crear();
    Pila pila2 = p_crear();
    int cant,valor;
    printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar en la 1ra Pila [0-99]: "ANSI_RESET);
    int validador = scanf("%d",&cant);
    vaciar_buffer();
    while (validador != 1 || cant<0 || cant>=100){
        limpiar_pantalla();
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingrasar un numero entre [0-99]\n\n"ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar: "ANSI_RESET);
        validador = scanf("%d",&cant);
        vaciar_buffer();
        
    }
    
    for (int i=0;i<cant;i++){
        printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
        validador = scanf("%d",&valor);
        vaciar_buffer();
        while(validador!=1 || valor<-999999 || valor>999999){
            limpiar_pantalla();
            printf(ANSI_RED"\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
            validador = scanf("%d",&valor); 
            vaciar_buffer();
            
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila,elemento);
        limpiar_pantalla();
    }
    
    printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar en la 2da Pila [0-99]: "ANSI_RESET);
    validador = scanf("%d",&cant);
    vaciar_buffer();
    while (validador != 1 || cant<0 || cant>=100){
        limpiar_pantalla();
        printf(ANSI_RED"\t\t-------- ERROR -------- \n");
        printf("DATO INVALIDO, por favor ingrasar un numero entre [0-99]\n\n"ANSI_RESET);
        pausa();
        limpiar_pantalla();
        printf(ANSI_bBLUE"ingrese cantidad de elementos a cargar: "ANSI_RESET);
        validador = scanf("%d",&cant);
        vaciar_buffer();
        
    }
    
    for (int i=0;i<cant;i++){
        printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
        validador = scanf("%d",&valor);
        vaciar_buffer();
        while(validador!=1 || valor<-999999 || valor>999999){
            limpiar_pantalla();
            printf(ANSI_RED"\t\t-------- ERROR -------- \n");
            printf("DATO FUERA DE RANGO, por favor ingrasar un numero entre [-999.999 - 999.999]\n\n"ANSI_RESET);
            pausa();
            limpiar_pantalla();
            printf(ANSI_bBLUE"ingrese clave del elementos a cargar [-999.999 - 999.999]: "ANSI_RESET);
            validador = scanf("%d",&valor); 
            vaciar_buffer();
            
        }
        TipoElemento elemento = te_crear(valor);
        p_apilar(pila2,elemento);
        limpiar_pantalla();
    }

    printf(ANSI_bYELLOW"Pila 1 y 2 ANTES de llamar a la funcion de comparar\n");
    printf(ANSI_bGREEN"");
    p_mostrar(pila);
    printf("\n");           // muestro como quedaron cargadas las pilas
    p_mostrar(pila2);
    printf("\n"ANSI_RESET);

    
    Pila pcomun = p_crear();
    pcomun = elemento_en_comun(pila,pila2);

    if(p_es_vacia(pcomun)){
        printf(ANSI_RED"Ninguno de los elementos de las pilas coincidieron\n");
    }

    else{
    printf(ANSI_YELLOW"Pila con elementos en comun\n");
    p_mostrar(pcomun);
    printf("\n\n"ANSI_RESET);
    }

    printf(ANSI_bYELLOW"Pila 1 y 2 DESPUES de llamar a la funcion de comparar\n");
    printf(ANSI_bGREEN"");
    p_mostrar(pila);
    printf("\n");           // las vuelvo a mostrar para confirmar que no se modificaron luego de llamar a comparar
    p_mostrar(pila2);
    printf("\n"ANSI_RESET);

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
    printf("  8   \n");
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
        scanf("%i", &opcion);
        while (getchar() != '\n')
            ;
        while (opcion < 0 || opcion > 8 || opcion == 1)
        {
            printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
            printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
            scanf("%i", &opcion);
            while (getchar() != '\n')
                ;
        }
        switch (opcion)
        {
        case 2:
            while (!salir1)
            {
                menu_punto2();
                scanf("%i", &opcion);
                while (opcion < 0 || opcion > 6)
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
                    main_buscar_clave();
                    getch();
                    break;
                case 2:

                    getch();
                    break;
                case 3:
                    main_eliminar_por_clave();
                    getch();
                    break;
                case 4:

                    getch();
                    break;
                case 5:
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

            getch();
            break;
        case 7:
            main_elemento_en_comun();
            getch();
            break;
        case 8:

            getch();
            break;
        case 0:
            salir = true;
            break;
        }
    }
    return 0;
}