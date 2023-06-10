#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP6_tabla_hash.h"
#include "tabla_hash.h"
#include "archivos.h"

void crear_txt()
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

void alta(TablaHash th)
{
    FILE *archivo = fopen("alumnos.dat", "r+b");

    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    PosicionEstado pe = (PosicionEstado)malloc(sizeof(struct PosicionEstadoRep));
    printf("Ingrese Legajo del alumno: ");
    scanf("%d", &(alumno->legajo));
    vaciar_buffer();

    if (buscarAlumnoEnTabla(th, alumno->legajo))
    {
        if (!pe->estado)
        {
            pe->estado = true;
            printf("Alumno existente, se realizo una alta lógica");
        }
        else
        {
            printf("El alumno ya se encuentra cargado, no se realizo ningún cambio");
        }
    }
    else
    {
        printf("Ingrese Nombre del alumno: ");
        fgets(alumno->nombre, 20, stdin);
        vaciar_buffer();
        printf("Ingrese Apellido del alumno: ");
        fgets(alumno->apellido, 20, stdin);
        vaciar_buffer();
        printf("Ingrese Domicilio del alumno: ");
        fgets(alumno->domicilio, 20, stdin);
        vaciar_buffer();
        printf("Ingrese Telefono del alumno: ");
        scanf("%d", &alumno->TE);
        vaciar_buffer();
        pe->estado = true;

        fseek(archivo, 0, SEEK_END);
        fwrite(alumno, sizeof(struct AlumnoRep), 1, archivo);
        long pos = ftell(archivo);

        pe->posicion = pos - sizeof(struct AlumnoRep);
    }

    fclose(archivo);
    TipoElemento x = te_crear_con_valor(alumno->legajo,pe);
    th_insertar(th, x);

    mostrarArchivo(th, archivo);
    pausa();
}

void bajas(TablaHash th, int legajo)
{

    PosicionEstado pe = (PosicionEstado)malloc(sizeof(struct PosicionEstadoRep));
    TipoElemento x;

    x = th_recuperar(th, legajo);

    if (x != NULL)
    {
        pe = x->valor;
        pe->estado = false;

        th_eliminar(th, legajo);
        x = te_crear_con_valor(legajo, pe);
        th_insertar(th, x);

        printf("Baja dada correctamente!");
    }
}

void modificar(FILE *archivo, TablaHash th, int legajo)
{
    archivo = fopen("alumnos.dat", "r+b");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    PosicionEstado pe = (PosicionEstado)malloc(sizeof(struct PosicionEstadoRep));
    int opc;
    TipoElemento x;

    x = th_recuperar(th, legajo);
    if (x != NULL)
    {
        pe = (PosicionEstado)x->valor;
    }
    if (pe->estado != false)
    {
        fseek(archivo, pe->posicion, SEEK_SET);
        fread(alumno, sizeof(Alumno), 1, archivo);
        menu_modificar();
        scanf("%d", &opc);
        vaciar_buffer();
        switch (opc)
        {
        case 1:
            //memset(&alumno->nombre, 0, sizeof(alumno->nombre));
            printf("escriba el nuevo nombre\n");
            fgets(alumno->nombre, 20, stdin);
            vaciar_buffer();
            break;
        case 2:
            memset(&alumno->apellido, 0, sizeof(alumno->nombre));
            printf("escriba el nuevo apellido\n");
            fgets(alumno->apellido, 20, stdin);
            vaciar_buffer();
            break;
        case 3:
            memset(&alumno->domicilio, 0, sizeof(alumno->nombre));
            printf("escriba el nuevo domicilio\n");
            fgets(alumno->domicilio, 20, stdin);
            vaciar_buffer();
            break;
        case 4:
            alumno->TE = 0;
            printf("escriba el nuevo numero de telefono\n");
            scanf("%d", &alumno->TE);
            vaciar_buffer();
            break;
        default:
            break;
        }
        fseek(archivo, pe->posicion, SEEK_CUR);
        fwrite(alumno, sizeof(Alumno), 1, archivo);
        fclose(archivo);
        vaciar_buffer();
        mostrarArchivo(th, archivo);
    }
}

/* MOdificar VIEJO
void modificar(FILE *archivo,TablaHash th,int legajo){
    FILE *archivo = fopen("alumnos.dat","r+b");
    Alumno alumno = (Alumno) malloc (sizeof(struct AlumnoRep));
    PosicionEstado pe = (PosicionEstado) malloc (sizeof(struct PosicionEstadoRep));
    int opc;
    TipoElemento x;

    x = th_recuperar(th,legajo);
    pe = x->valor;
    if (x != NULL && pe->estado!= false){

        fseek(archivo,pe->posicion,SEEK_SET);
        fread(&alumno,sizeof(Alumno),1,archivo);

    }

    flcose(archivo);



    /*rewind(archivo);

    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1) {
        if (alumno->legajo == legajo) {
            menu_modificar();
            scanf("%d",&opc);
            vaciar_buffer();
            switch (opc)
            {
            case 1:

                break;
            case 2:
                // modificar apellido
                break;
            case 3:
                // modificar dni
                break;
            default:
                break;
            }

        }
    }*/

void mostrarArchivo(TablaHash th, FILE *archivo)
{

    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    archivo = fopen("alumnos.dat", "rb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    while (fread(alumno, sizeof(struct AlumnoRep), 1, archivo) == 1)
    {
        printf("Legajo: %i \n", alumno->legajo);
        printf("Apellido: %s \n", alumno->apellido);
        printf("Nombre: %s \n", alumno->nombre);
        printf("Domicilio: %s \n", alumno->domicilio);
        printf("Telefono: %i \n", alumno->TE);
    }
    vaciar_buffer();
    fclose(archivo);
}

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

bool buscarAlumnoArchivo(FILE *archivo, int legajo)
{
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    int encontrado = 0;

    rewind(archivo);

    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1)
    {
        if (alumno->legajo == legajo)
        {
            printf("Legajo: %d, Nombre: %s, Apellido: %s\n",
                   alumno->legajo, alumno->nombre, alumno->apellido);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void mostrar_modificacion(FILE *archivo, TablaHash th, int legajo)
{
    archivo = fopen("alumnos.dat", "rb");
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    PosicionEstado pe = (PosicionEstado)malloc(sizeof(struct PosicionEstadoRep));
    int opc;
    TipoElemento x;

    x = th_recuperar(th, legajo);
    pe = (PosicionEstado)x->valor;
    fseek(archivo, pe->posicion, SEEK_SET);
    fread(&alumno, sizeof(Alumno), 1, archivo);
    printf("legajo\tapellido\tnombre\tdomicilio\ttelefono\n");
    printf("%d\t", alumno->legajo);
    for (int i = 0; i < sizeof(alumno->apellido); i++)
    {
        printf("%c", alumno->apellido[i]);
    }
    for (int i = 0; i < sizeof(alumno->nombre); i++)
    {
        printf("%c", alumno->nombre[i]);
    }
    for (int i = 0; i < sizeof(alumno->domicilio); i++)
    {
        printf("%c", alumno->domicilio[i]);
    }
    printf("%d\n", alumno->TE);
    fclose(archivo);
}

void menu_modificar()
{
    printf("\n");
    printf(ANSI_BLUE "  ============================================================================\n");
    printf(" |                                 Modificaciones de alumnos                                 |\n");
    printf("  ============================================================================\n");
    printf("\n");
    printf("  1   Modificar Nombre\n");
    printf("  2   Modificar Apellido\n");
    printf("  3   Modificar dni\n");
    printf("\n");
    printf("  0   Salir\n");
    printf("\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n");
    printf("  Por favor seleccione una opción: " ANSI_YELLOW);
}

void modificar_nombre()
{
}