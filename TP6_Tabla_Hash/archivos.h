#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "TP6_tabla_hash.h"

void crear_archivo_binario();

void alta(TablaHash th);

void baja(TablaHash th, int legajo);

void modificar(TablaHash th, int legajo);

void mostrarArchivo();

void menu_modificar();

#endif // ARCHIVOS_H