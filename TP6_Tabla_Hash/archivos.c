#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP6_tabla_hash.h"
#include "tabla_hash.h"

void crear_txt(){
    FILE *archivo;
    archivo=fopen("alumnos.dat","w");
    fclose(archivo);
}

void alta(TablaHash th){
    FILE *archivo = fopen("alumnos.dat","r+b");

    Alumno alumno = (Alumno) malloc (sizeof(struct AlumnoRep));
    PosicionEstado pe = (PosicionEstado) malloc (sizeof(struct PosicionEstadoRep));
    printf("Ingrese Legajo del alumno: ");
    scanf("%d",&(alumno->legajo));
    vaciar_buffer();
    
    if(buscarAlumnoEnTabla(th,alumno->legajo)){
        if(!pe->estado){
            pe->estado = true;
            printf("Alumno existente, se realizo una alta lógica");
        }
        else{
             printf("El alumno ya se encuentra cargado, no se realizo ningún cambio");
        }
    }
    else{
        printf("Ingrese Dni del alumno: ");
        scanf("%d",&alumno->dni);
        vaciar_buffer();
        printf("Ingrese Nombre del alumno: ");
        fscanf(&alumno->nombre,20,stdin);
        vaciar_buffer();
        printf("Ingrese Apellido del alumno: ");
        fscanf(&alumno->apellido,20,stdin);
        vaciar_buffer();
        pe->estado = true;

        fseek(archivo, 0, SEEK_END);
        long pos = ftell(archivo);
        fwrite(&alumno,sizeof(Alumno),1,archivo);
        pe->posicion = pos - sizeof(struct AlumnoRep);
    }
    
    fclose(archivo);
    TipoElemento x = te_crear_con_valor(alumno->legajo,pe->posicion);
    th_insertar(th,x);
}

void bajas(TablaHash th, int legajo){
    
    PosicionEstado pe = (PosicionEstado) malloc (sizeof(struct PosicionEstadoRep));
    TipoElemento x;

    x = th_recuperar(th,legajo);

    if(x != NULL){
        pe = x->valor;
        pe->estado = false;
    
        th_eliminar(th,legajo);
        x = te_crear_con_valor(legajo,pe);
        th_insertar(th,x);

        printf("Baja dada correctamente!");
    }

}

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

}


bool buscarAlumnoEnTabla(TablaHash th, int legajo) { 
    TipoElemento x;

    x = th_recuperar(th,legajo);
    if(x != NULL){
        return true;
    }
    else{
        return false;
    }
    
}

bool buscarAlumnoArchivo(FILE* archivo, int legajo) {
    Alumno alumno = (Alumno) malloc (sizeof(struct AlumnoRep));
    int encontrado = 0;
    
    rewind(archivo);
    
    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1) {
        if (alumno->legajo == legajo) {
            printf("Legajo: %d, DNI: %d, Nombre: %s, Apellido: %s\n",
                alumno->legajo, alumno->dni, alumno->nombre, alumno->apellido);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        return false;
    }
    else{
        return true;
    }
}

void menu_modificar(){
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

void modificar_nombre(){

}