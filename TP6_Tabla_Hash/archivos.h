#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "TP6_tabla_hash.h"

void crear_txt();

void mostrarArchivo(TablaHash th, FILE * archivo);

void alta(TablaHash th);

void bajas(TablaHash th, int legajo);

void modificar(FILE *archivo,TablaHash th,int legajo);

bool buscarAlumnoEnTabla(TablaHash th, int legajo);

void menu_modificar();

void mostrar_modificacion(FILE *archivo, TablaHash th, int legajo );

#endif //ARCHIVOS_H