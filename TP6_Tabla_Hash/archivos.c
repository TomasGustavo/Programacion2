#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TP6_tabla_hash.h"
#include "tabla_hash.h"
#include "archivos.h"

/// @brief Elimina los espacios a la izquierda de una cadena
/// @param cadena string a modificar
void eliminar_espacios_izquierda(char *cadena)
{
    while (cadena[0] == ' ')
    {
        for (int j = 0; j < strlen(cadena); j++)
        {
            cadena[j] = cadena[j + 1];
        }
    }
}

/// @brief Valida si todos los elementos de una cadena son letras o espacios, de ser así, elimina todos los espacios a su izquierda
/// @param cadena string a evaluar
/// @return true si es valida, false si no lo es
bool validarCadenaAlfa(char* cadena) {
    int i = 0;
    
    while (cadena[i] != '\0') {
        if (!isalpha(cadena[i]) && !isspace(cadena[i])) {
            return false;
        }
        i++;
    }

    eliminar_espacios_izquierda(cadena);
    
    return true;
}

/// @brief corrobora si la cadena solo contiene espacios
/// @param cadena string a evaluar
/// @return true si son solo espacios, false si no lo son
bool soloEspacios (const char* cadena){
    int i = 0;

    while(cadena[i] != '\0'){
        if (!isspace(cadena[i])){
            return false;
        }
        i++;
           
    }
    return true;
    
}

/// @brief valida si el string es valido, si es valido lo de vuelve tal cual, sino pide reingresar dato.
/// @param cadena string a evaluar
/// @param atributo atributo del alumno que recibe ("nombre","apellido", etc.)
void validarString(char *cadena, char atributo[]){
    while(!validarCadenaAlfa(cadena)  || soloEspacios(cadena)){
        if(!validarCadenaAlfa(cadena)){
            printf(ANSI_bRED"\t\t-----ERROR-----\n");
            printf(ANSI_bRED"Por favor solo ingresar caracteres alfabéticos\n");
            printf(ANSI_GREEN "Ingrese %s del alumno: ",atributo);
            printf(ANSI_YELLOW"");
            fgets(cadena, 20, stdin);
            cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea 
        }
        else{
            printf(ANSI_bRED"\t\t-----ERROR-----\n");
            printf(ANSI_bRED"Por favor de no ingresar solo espacios\n");
            printf(ANSI_GREEN "Ingrese %s del alumno: ",atributo);
            printf(ANSI_YELLOW"");
            fgets(cadena, 20, stdin);
            cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el carácter de nueva línea 
        }
        
    }
}

void continuar()
{
    printf(ANSI_bMAGENTA "\nPresione 'Y' si desea ver el archivo.dat, cualquier otra tecla para omitir: " ANSI_YELLOW);
    int opcion = getchar();
    vaciar_buffer();
    if (toupper(opcion) == 'Y')
    {
        mostrarArchivo();
    }
    else
    {
        pausa();
    }
}

/// @brief Busca si N° de legajo se encuentra cargado en la tabla hash
/// @param th Tabla Hash utilizada como índice para accesos directo al archivo
/// @param legajo N° de legajo a buscar
/// @return Si el legajo se encuentra retorna verdadero, caso contrario devuelve falso
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

/// @brief Crea el archivo binario
void crear_archivo_binario()
{
    FILE *archivo;
    archivo = fopen("alumnos.dat", "wb");
    if (archivo == NULL)
    {
        printf(ANSI_RED "\nNo se pudo crear el archivo.\n" ANSI_RESET);
        pausa();
        return;
    }
    fclose(archivo);
}

/// @brief Realiza un alta física de los datos del alumno, si se encuentra dado de baja, realiza un alta lógica
/// @param th Tabla Hash utilizada como índice para accesos directo al archivo
void alta(TablaHash th)
{
    FILE *archivo;
    archivo = fopen("alumnos.dat", "r+b");
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    TipoElemento x;
    int *posicion = malloc(sizeof(int));
    int legajo_buscar;
    printf(ANSI_RED "\nIngrese legajo del alumno: " ANSI_YELLOW);
    int validador = scanf("%d", &legajo_buscar);
    vaciar_buffer();
    while(validador != 1 || legajo_buscar < 1 || legajo_buscar > 999999){
        if(validador!=1){
            printf(ANSI_bRED"\t\t-----ERROR-----\n");
            printf(ANSI_bRED"Por favor solo ingresar números, ingresar legajo nuevamente [1 - 999.999]: ");
            validador = scanf("%d", &legajo_buscar);
            vaciar_buffer();
        }
        else{
            printf(ANSI_bRED"\t\t-----ERROR-----\n");
            printf(ANSI_bRED"Dato fuera de rango, ingresar legajo nuevamente [1 - 999.999]: ");
            validador = scanf("%d", &legajo_buscar);
            vaciar_buffer();
        }    
    }
    if (buscarAlumnoEnTabla(th, legajo_buscar))
    {
        x = th_recuperar(th, legajo_buscar);
        posicion = (int *)x->valor;
        fseek(archivo, *posicion, SEEK_SET);
        fread(alumno, sizeof(struct AlumnoRep), 1, archivo);
        if (!alumno->estado)
        {
            alumno->estado = true;
            fseek(archivo, *posicion, SEEK_SET);
            fwrite(alumno, sizeof(struct AlumnoRep), 1, archivo);
            printf(ANSI_GREEN "\nAlumno existente, se realizo una alta lógica\n" ANSI_RESET);
        }
        else
        {
            printf(ANSI_RED "\nEl alumno ya se encuentra cargado, no se realizo ningún cambio\n" ANSI_RESET);
        }
    }
    else
    {
        alumno->legajo = legajo_buscar;
        printf(ANSI_GREEN "Ingrese Nombre del alumno: " ANSI_YELLOW);
        fgets(alumno->nombre, 20, stdin);
        alumno->nombre[strcspn(alumno->nombre, "\n")] = '\0'; // Eliminar el carácter de nueva línea
        validarString(alumno->nombre,"Nombre");
        printf(ANSI_GREEN "Ingrese Apellido del alumno: " ANSI_YELLOW);
        fgets(alumno->apellido, 20, stdin);
        alumno->apellido[strcspn(alumno->apellido, "\n")] = '\0'; // Eliminar el carácter de nueva línea
        validarString(alumno->apellido,"Apellido");
        printf(ANSI_GREEN "Ingrese Domicilio del alumno: " ANSI_YELLOW);
        fgets(alumno->domicilio, 20, stdin);
        alumno->domicilio[strcspn(alumno->domicilio, "\n")] = '\0'; // Eliminar el carácter de nueva línea
        validarString(alumno->domicilio,"Domicilio");
        printf(ANSI_GREEN "Ingrese Teléfono del alumno: " ANSI_YELLOW);
        validador = scanf("%lld", &alumno->TE);
        vaciar_buffer();
        while(validador!=1 || alumno->TE <= 0 || alumno->TE>999999999999){
            if(validador!=1){
                printf(ANSI_bRED"\t\t-----ERROR-----\n");
                printf(ANSI_bRED"Por favor solo ingresar números, ingresar teléfono nuevamente: ");
                validador = scanf("%lld", &alumno->TE);
                vaciar_buffer();
            }
            else{
                printf(ANSI_bRED"\t\t-----ERROR-----\n");
                printf(ANSI_bRED"numero de teléfono demasiado largo, por favor ingresar menos de 12 dígitos\n");
                printf(ANSI_bRED"ingresar teléfono nuevamente: ");
                validador = scanf("%lld", &alumno->TE);
                vaciar_buffer();
            }    
        }
        alumno->estado = true;
        fseek(archivo, 0, SEEK_END);
        fwrite(alumno, sizeof(struct AlumnoRep), 1, archivo);
        long pos = ftell(archivo);
        *posicion = pos - sizeof(struct AlumnoRep);
        vaciar_buffer();
        x = te_crear_con_valor(alumno->legajo, posicion);
        th_insertar(th, x);
        printf(ANSI_GREEN "\nAlumno cargado correctamente\n" ANSI_RESET);
    }
    fclose(archivo);
    continuar();
}

/// @brief Realiza un baja lógica de los datos del alumno
/// @param th Tabla Hash utilizada como índice para accesos directo al archivo
/// @param legajo N° de legajo a buscar
void baja(TablaHash th, int legajo)
{
    FILE *archivo;
    archivo = fopen("alumnos.dat", "r+b");
    if (archivo == NULL)
    {
        printf(ANSI_RED "No se pudo abrir el archivo.\n" ANSI_RESET);
        pausa();
        return;
    }
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    TipoElemento x;
    int posicion;
    x = th_recuperar(th, legajo);
    if (x != NULL)
    {
        posicion = *(int *)x->valor;
        fseek(archivo, posicion, SEEK_SET);
        fread(alumno, sizeof(struct AlumnoRep), 1, archivo);
        alumno->estado = false;
        fseek(archivo, posicion, SEEK_SET);
        fwrite(alumno, sizeof(struct AlumnoRep), 1, archivo);
        printf(ANSI_GREEN "Baja lógica correctamente!\n" ANSI_RESET);
    }
    fclose(archivo);
    continuar();
}

/// @brief Permite modificar todos los datos asociados a un legajo
/// @param th Tabla Hash utilizada como índice para accesos directo al archivo
/// @param legajo N° de legajo a buscar
void modificar(TablaHash th, int legajo)
{
    FILE *archivo;
    bool salir = false;
    archivo = fopen("alumnos.dat", "r+b");
    if (archivo == NULL)
    {
        printf(ANSI_RED "No se pudo abrir el archivo.\n" ANSI_RESET);
        pausa();
        return;
    }
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    int opc, posicion;
    TipoElemento x;
    x = th_recuperar(th, legajo);
    if (x != NULL)
    {
        posicion = *(int *)x->valor;
        fseek(archivo, posicion, SEEK_SET);
        fread(alumno, sizeof(struct AlumnoRep), 1, archivo);
        if (alumno->estado)
        {
            while (!salir)
            {
                limpiar_pantalla();
                printf("\n");
                printf(ANSI_BLUE "  ============================================================================\n");
                printf(" |                         Modificaciones de alumnos                          |\n");
                printf("  ============================================================================\n");
                printf("\n");
                printf(ANSI_GREEN "  DATOS DEL ALUMNO:\n");
                printf(ANSI_bMAGENTA "  Legajo: " ANSI_YELLOW "%i\n", alumno->legajo);
                printf(ANSI_bMAGENTA "  Nombre: " ANSI_YELLOW "%s\n", alumno->nombre);
                printf(ANSI_bMAGENTA "  Apellido: " ANSI_YELLOW "%s\n", alumno->apellido);
                printf(ANSI_bMAGENTA "  Domicilio: " ANSI_YELLOW "%s\n", alumno->domicilio);
                printf(ANSI_bMAGENTA "  Teléfono: " ANSI_YELLOW "%lld\n", alumno->TE);
                printf(ANSI_bMAGENTA "  Estado: %s\n", alumno->estado ? ANSI_GREEN "Activo" : ANSI_RED "Inactivo");
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
                    printf(ANSI_BLUE "\nEscriba el nuevo nombre: " ANSI_YELLOW);
                    fgets(alumno->nombre, 20, stdin);
                    alumno->nombre[strcspn(alumno->nombre, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                    validarString(alumno->nombre,"Nombre");
                    break;
                case 2:
                    printf(ANSI_BLUE "\nEscriba el nuevo apellido: " ANSI_YELLOW);
                    fgets(alumno->apellido, 20, stdin);
                    alumno->apellido[strcspn(alumno->apellido, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                    validarString(alumno->apellido,"Apellido");
                    break;
                case 3:
                    printf(ANSI_BLUE "\nEscriba el nuevo domicilio: " ANSI_YELLOW);
                    fgets(alumno->domicilio, 20, stdin);
                    alumno->domicilio[strcspn(alumno->domicilio, "\n")] = '\0'; // Eliminar el carácter de nueva línea
                    validarString(alumno->domicilio,"Domicilio");
                    break;
                case 4:
                    printf(ANSI_BLUE "\nEscriba el nuevo numero de teléfono: " ANSI_YELLOW);
                    scanf("%lld", &alumno->TE);
                    vaciar_buffer();
                    while(validador!=1 || alumno->TE <= 0){
                        if(validador!=1){
                            printf(ANSI_bRED"\t\t-----ERROR-----\n");
                            printf(ANSI_bRED"Por favor solo ingresar números, ingresar teléfono nuevamente: ");
                            validador = scanf("%lld", &alumno->TE);
                            vaciar_buffer();
                        }
                        else{
                            printf(ANSI_bRED"\t\t-----ERROR-----\n");
                            printf(ANSI_bRED"Dato fuera de rango, ingresar teléfono nuevamente: ");
                            validador = scanf("%lld", &alumno->TE);
                            vaciar_buffer();
                        }    
                    }
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
                printf(ANSI_GREEN "\nAlumno cargado correctamente\n" ANSI_RESET);
                printf(ANSI_GREEN "\nDATOS DEL ALUMNO MODIFICADO:\n");
                printf(ANSI_bMAGENTA "Legajo: " ANSI_YELLOW "%i\n", alumno->legajo);
                printf(ANSI_bMAGENTA "Nombre: " ANSI_YELLOW "%s\n", alumno->nombre);
                printf(ANSI_bMAGENTA "Apellido: " ANSI_YELLOW "%s\n", alumno->apellido);
                printf(ANSI_bMAGENTA "Domicilio: " ANSI_YELLOW "%s\n", alumno->domicilio);
                printf(ANSI_bMAGENTA "Teléfono: " ANSI_YELLOW "%lld\n", alumno->TE);
                printf(ANSI_bMAGENTA "Estado: %s\n", alumno->estado ? ANSI_GREEN "Activo" : ANSI_RED "Inactivo" ANSI_BLUE);
                pausa();
            }
        }
        else
        {
            printf(ANSI_RED "\nEl legajo se encuentra dado de baja, deberá darlo de alta primero\n" ANSI_RESET);
        }
    }
    else
    {
        printf(ANSI_RED "\nEl legajo no existe\n" ANSI_RESET);
    }
    fclose(archivo);
    pausa();
}

/// @brief Muestra todos los registros del archivo binario
void mostrarArchivo()
{
    FILE *archivo;
    int posicion;
    Alumno alumno = (Alumno)malloc(sizeof(struct AlumnoRep));
    archivo = fopen("alumnos.dat", "rb");
    fseek(archivo, 0, SEEK_END);
    long tamanio = ftell(archivo);
    if ((archivo == NULL) || (tamanio == 0))
    {
        printf(ANSI_RED "No se pudo abrir el archivo.\n" ANSI_RESET);
        pausa();
        return;
    }
    limpiar_pantalla();
    printf(ANSI_bCYAN "\nCONTENIDO ALMACENADO EN archivo.dat\n");
    fseek(archivo, 0, SEEK_SET);
    while (fread(alumno, sizeof(struct AlumnoRep), 1, archivo) == 1)
    {
        printf(ANSI_bMAGENTA "\nLegajo: " ANSI_YELLOW "%i\n", alumno->legajo);
        printf(ANSI_bMAGENTA "Nombre: " ANSI_YELLOW "%s\n", alumno->nombre);
        printf(ANSI_bMAGENTA "Apellido: " ANSI_YELLOW "%s\n", alumno->apellido);
        printf(ANSI_bMAGENTA "Domicilio: " ANSI_YELLOW "%s\n", alumno->domicilio);
        printf(ANSI_bMAGENTA "Teléfono: " ANSI_YELLOW "%lld\n", alumno->TE);
        printf(ANSI_bMAGENTA "Estado: %s\n", alumno->estado ? ANSI_GREEN "Activo" : ANSI_RED "Inactivo" ANSI_BLUE);
    }
    fclose(archivo);
    pausa();
}

void menu_modificar()
{
    printf(ANSI_BLUE "\n");
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