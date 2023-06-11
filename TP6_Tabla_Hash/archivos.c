#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP6_tabla_hash.h"
#include "tabla_hash.h"
#include "archivos.h"

bool buscarAlumnoEnTabla(TablaHash th, int legajo)
{
    TipoElemento x;
    x = th_recuperar(th, legajo);
    if (x != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// OK
void crear_archivo_binario()
{
    FILE *archivo;
    archivo = fopen("alumnos.dat", "wb");
    if (archivo == NULL)
    {
        printf("No se pudo crear el archivo.\n");
        return;
    }
    fclose(archivo);
}

// OK
void alta(TablaHash th)
{
    FILE *archivo;
    archivo = fopen("alumnos.dat", "r+b");
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    TipoElemento x;
    int *posicion = malloc(sizeof(int));
    ;
    int legajo_buscar;
    printf(ANSI_RED "\nIngrese Legajo del alumno: " ANSI_YELLOW);
    scanf("%d", &legajo_buscar);
    vaciar_buffer();

    if (buscarAlumnoEnTabla(th, legajo_buscar))
    {
        x = th_recuperar(th, legajo_buscar);
        posicion = (int *)x->valor; // A CHEQUEAR
        fseek(archivo, *posicion, SEEK_SET);
        fread(alumno, sizeof(struct AlumnoRep), 1, archivo);
        if (!alumno->estado)
        {
            alumno->estado = true;
            fseek(archivo, *posicion, SEEK_SET);
            fwrite(alumno, sizeof(struct AlumnoRep), 1, archivo);
            printf("Alumno existente, se realizo una alta lógica\n");
        }
        else
        {
            printf("El alumno ya se encuentra cargado, no se realizo ningún cambio\n");
        }
    }
    else
    {
        alumno->legajo = legajo_buscar;
        printf(ANSI_GREEN "Ingrese Nombre del alumno: " ANSI_YELLOW);
        fgets(alumno->nombre, 20, stdin);
        printf(ANSI_GREEN "Ingrese Apellido del alumno: " ANSI_YELLOW);
        fgets(alumno->apellido, 20, stdin);
        printf(ANSI_GREEN "Ingrese Domicilio del alumno: " ANSI_YELLOW);
        fgets(alumno->domicilio, 20, stdin);
        printf(ANSI_GREEN "Ingrese Teléfono del alumno: " ANSI_YELLOW);
        scanf("%lld", &alumno->TE);
        alumno->estado = true;
        fseek(archivo, 0, SEEK_END);
        fwrite(alumno, sizeof(struct AlumnoRep), 1, archivo);
        long pos = ftell(archivo);

        *posicion = pos - sizeof(struct AlumnoRep);
        vaciar_buffer();
    }
    fclose(archivo);
    x = te_crear_con_valor(alumno->legajo, posicion);
    th_insertar(th, x);
    mostrarArchivo();
}

// OK
void baja(TablaHash th, int legajo)
{
    FILE *archivo;
    archivo = fopen("alumnos.dat", "r+b");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    TipoElemento x;
    int posicion;
    x = th_recuperar(th, legajo);
    if (x != NULL)
    {
        posicion = *(int *)x->valor; // A CHEQUEAR
        fseek(archivo, posicion, SEEK_SET);
        fread(alumno, sizeof(struct AlumnoRep), 1, archivo);
        alumno->estado = false;
        fseek(archivo, posicion, SEEK_SET);
        fwrite(alumno, sizeof(struct AlumnoRep), 1, archivo);
        printf("Baja lógica correctamente!\n");
    }
    fclose(archivo);
    mostrarArchivo();
}

// OK
void modificar(TablaHash th, int legajo)
{
    FILE *archivo;
    bool salir = false;
    archivo = fopen("alumnos.dat", "r+b");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    int opc, posicion;
    TipoElemento x;
    x = th_recuperar(th, legajo);
    if (x != NULL)
    {
        posicion = *(int *)x->valor; // A CHEQUEAR
        fseek(archivo, posicion, SEEK_SET);
        fread(alumno, sizeof(struct AlumnoRep), 1, archivo);
        if (alumno->estado)
        {
            while (!salir)
            {
                limpiar_pantalla();
                printf("\n");
                printf(ANSI_BLUE "  ============================================================================\n");
                printf(" |                                 Modificaciones de alumnos                                 |\n");
                printf("  ============================================================================\n");
                printf("\n" ANSI_GREEN);
                printf("\nLegajo: %i\n", alumno->legajo);
                printf("Nombre: %s", alumno->nombre);
                printf("Apellido: %s", alumno->apellido);
                printf("Domicilio: %s", alumno->domicilio);
                printf("Teléfono: %lld\n", alumno->TE);
                printf("Estado: %s\n", alumno->estado ? ANSI_GREEN "Activo" : ANSI_RED "Inactivo");
                printf("\n" ANSI_BLUE);
                menu_modificar();
                int validador = scanf("%i", &opc);
                vaciar_buffer();
                while (validador != 1 || opc < 0 || opc > 4)
                {
                    printf(ANSI_RED "Opción incorrecta\n" ANSI_RESET);
                    printf(ANSI_BLUE "  Por favor seleccione una opción: " ANSI_YELLOW);
                    while (getchar() != '\n')
                        ;
                    validador = scanf("%i", &opc);
                }

                switch (opc)
                {
                case 1:
                    printf("Escriba el nuevo nombre: ");
                    fgets(alumno->nombre, 20, stdin);
                    break;
                case 2:
                    printf("Escriba el nuevo apellido: ");
                    fgets(alumno->apellido, 20, stdin);
                    break;
                case 3:
                    printf("Escriba el nuevo domicilio: ");
                    fgets(alumno->domicilio, 20, stdin);
                    break;
                case 4:
                    printf("Escriba el nuevo numero de teléfono: ");
                    scanf("%lld", &alumno->TE);
                    vaciar_buffer();
                    break;
                case 0:
                    salir = true;
                    fclose(archivo);
                    return;
                }
                fseek(archivo, posicion, SEEK_SET);
                fwrite(alumno, sizeof(struct AlumnoRep), 1, archivo);

                fseek(archivo, posicion, SEEK_SET);
                fread(alumno, sizeof(struct AlumnoRep), 1, archivo);
                printf("\nLegajo: %i\n", alumno->legajo);
                printf("Nombre: %s", alumno->nombre);
                printf("Apellido: %s", alumno->apellido);
                printf("Domicilio: %s", alumno->domicilio);
                printf("Teléfono: %lld\n", alumno->TE);
                printf("Estado: %s\n", alumno->estado ? ANSI_GREEN "Activo" : ANSI_RED "Inactivo");
                printf("\n" ANSI_BLUE);
                pausa();
            }
        }
        else
        {
            printf("El legajo se encuentra dado de baja, deberá darlo de alta primero\n");
            return;
        }
    }
    else
    {
        printf("El legajo no existe\n");
        return;
    }
    fclose(archivo);
}

// OK
void mostrarArchivo()
{
    FILE *archivo;
    int posicion;
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    archivo = fopen("alumnos.dat", "rb");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    while (fread(alumno, sizeof(struct AlumnoRep), 1, archivo) == 1)
    {
        printf("\nLegajo: %i\n", alumno->legajo);
        printf("Nombre: %s", alumno->nombre);
        printf("Apellido: %s", alumno->apellido);
        printf("Domicilio: %s", alumno->domicilio);
        printf("Teléfono: %lld\n", alumno->TE);
        printf("Estado: %s\n", alumno->estado ? ANSI_GREEN "Activo" : ANSI_RED "Inactivo" ANSI_YELLOW);
    }
    fclose(archivo);
    pausa();
}

// OK

void menu_modificar()
{
    printf("  1   Modificar Nombre\n");
    printf("  2   Modificar Apellido\n");
    printf("  3   Modificar Domicilio\n");
    printf("  4   Modificar Teléfono\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}