#include <stdio.h>
#include "RRD.h"
#include <time.h>
#include <string.h>
struct registro
{
    char nombre[20];
    char apellido_paterno[20];
    char apellido_materno[20];
    int matricula;
    int edad;
    char sexo;
    char status[20];
};

char hombres[20][10] = {"JUAN", "PEDRO", "CARLOS", "LUIS", "JAVIER", "ANDRES", "ALEJANDRO", "MIGUEL", "JOSE", "ADAN", "JORGE", "GABRIEL", "ROBERTO", "DAVID", "FERNANDO", "RAUL", "EDUARDO", "SERGIO", "ANTONIO", "FRANCISCO"};
char mujeres[20][10] = {"DANIELA", "LAURA", "ANA", "CARMEN", "SOFIA", "ISABEL", "MARTA", "PAULA", "ELENA", "PATRICIA", "LUCIA", "CLARA", "ROSA", "BEATRIZ", "CAROLINA", "JULIA", "TERESA", "SARA", "IRENE", "ADRIANA"};
char apellidos_paternos[20][10] = {"BARRIOS", "RODRIGUEZ", "LOPEZ", "PEREZ", "MARTINEZ", "SANCHEZ", "FERNANDEZ", "GONZALEZ", "RAMIREZ", "TORRES", "MARTIN", "JIMENEZ", "RUIZ", "DIAZ", "SOTO", "GOMEZ", "LOZANO", "CASTRO", "HERRERA", "GARCIA"};
char apellidos_maternos[20][10] = {"SUAREZ", "VILLEGAS", "GUERRERO", "PALACIOS", "FARIAS", "AVILA", "MOLINA", "SALAZAR", "DELGADO", "SANCHEZ", "FLORES", "MORALES", "ROMERO", "OROZCO", "RIVERA", "CASTILLO", "CHAVEZ", "SUAREZ", "VILLEGAS", "GUERRERO"};
char status[4][20] = {"DADO DE BAJA", "BAJA TEMPORAL", "MATRICULADO", "EGRESADO"};

void agregarautomaticamente();
void agregarmanual();
void eliminarregistro();
void ordenar();
void buscar();
void imprimir();
int main()
{
    srand(time(NULL));
    int menu;
    int opc;
    struct registro personas[10];
    int num_persona=0;
    int matricula;
    int buscar_matricula;
    
    do
    {
        menu = 0;
        opc = validarnumeros("MENU\n1.AGREGAR (AUTOM 10 REGISTROS)\n2.-AGREGAR MANUAL\n3.-ELIMINAR REGISTRO\n4.-BUSCAR \n5.-ORDENAR\n6.-IMPRIMIR\n0.-SALIR\n", 0, 6);
        switch (opc)
        {
        case 0:
            system("cls");
            printf("FIN DEL PROGRAMA");
            break;
        case 1:
            agregarautomaticamente();
            menu = repetir();
            break;
        case 2:
            agregarmanual();
            menu = repetir();
            break;
        case 3:

            menu = repetir();
            break;
        case 4:

            menu = repetir();
            break;
        case 5:

            menu = repetir();
            break;
        case 6:

            menu = repetir();
            break;
        }
    } while (menu == 1);
}
void agregarautomaticamente()
{
    int status, Matricula, ApPat, ApMat, Nombre, Edad, Sexo;
    Sexo = numerorandom(1, 2); // 1. Hombre  2. Mujer

    if (Sexo == 1)
    {
        Nombre = numerorandom(1, 20);
        ApPat = numerorandom(1, 20);
        ApMat = numerorandom(1, 20);
        printf("\nRegistro de %s %s %s\n", hombres[Nombre], apellidos_paternos[ApPat], apellidos_maternos[ApMat]);
    }
    else
    {
        Nombre = numerorandom(1, 20);
        ApPat = numerorandom(1, 20);
        ApMat = numerorandom(1, 20);
        printf("\nRegistro de %s %s %s\n", mujeres[Nombre], apellidos_paternos[ApPat], apellidos_maternos[ApMat]);
    }
    status = numerorandom(1, 2);
    if (status == 1)
    {
        printf("status: En linea\n");
        Matricula = numerorandom(300000, 400000);
        printf("matricula: %d\n", Matricula);
        Edad = numerorandom(18, 30);
        printf("Edad: %d\n", Edad);
        if (Sexo == 1)
        {
            printf("sexo: Hombre\n\n");
        }
        else
        {
            printf("sexo: Mujer\n\n");
        }
    }
    else
    {
        printf("status: Dado de baja\n\n");
    }
}
void agregarmanual()
{
    int status, Matricula, Edad, Sexo;
    char nombre[10], ApPat[20], ApMat[20];
    validarletras("INGRESE SU NOMBRES: ", nombre);
    validarletras("INGRESE SU Apellido Paterno: ", ApPat);
    validarletras("INGRESE SU Apellido Materno: ", ApMat);
    imprimircadena(nombre);
    imprimircadena(ApPat);
    imprimircadena(ApMat);
    printf("\n");
    /*
        Sexo = validarnumeros("INGRESE SI ES:\n1.-HOMBRE\n2.-MUJER\n", 1, 2);
        validarnumeros("CUAL SU STATUS:\n1.-En linea\n2.-Dado de baja\n", 1, 2);

        if (status == 1)
        {
            printf("status: En linea\n");
            Matricula = numerorandom(300000, 400000);
            printf("matricula: %d\n", Matricula);
            Edad = numerorandom(18, 30);
            printf("Edad: %d\n", Edad);
            if (Sexo == 1)
            {
                printf("sexo: Hombre\n\n");
            }
            else
            {
                printf("sexo: Mujer\n\n");
            }
        }
        else
        {
            printf("status: Dado de baja\n\n");
        }
        */
}
void eliminarregistro()
{
}
void buscar()
{
}
void imprimir(struct registro *personas, int num_personas)
{
    if (num_personas == 0)
    {
        printf("No hay registros para imprimir.\n");
        return;
    }

    printf("Registros almacenados:\n");
    for (int i = 0; i < num_personas; i++)
    {
        printf("Registro %d:\n", i + 1);
        printf("Nombre: %s\n", personas[i].nombre);
        printf("Apellido Paterno: %s\n", personas[i].apellido_paterno);
        printf("Apellido Materno: %s\n", personas[i].apellido_materno);
        printf("Matrícula: %d\n", personas[i].matricula);
        printf("Edad: %d\n", personas[i].edad);
        printf("Sexo: %c\n", personas[i].sexo);
        printf("Estado: %s\n", personas[i].status);
    }
}
