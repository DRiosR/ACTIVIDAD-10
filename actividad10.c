// RiosRodriguezDaniel 372800
// 12-oct-23
/*
ACTIVIDAD 10
REALICE EL SIGUIENTE PROGRAMA QUE CONTENGA UN MENÚ.
MENÚ
1.- AGREGAR (AUTOM 10 REGISTROS)
2.- AGREGAR MANUAL
3- ELIMINAR REGISTRO (lógico)
4.- BUSCAR
5- ORDENAR
6.- IMPRIMIR
0.- SALIR
UTILIZAR UN ARREGLO DE 500 REGISTROS
SE DEBERÁ UTILIZAR ESTRUCTURAS CON LOS DATOS BÁSICOS DE UN ALUMNO ( status, Matricula, ApPat, ApMat, Nombre, Edad, Sexo )
Busqueda y Ordenacion por campo MATRICULA
nota: usar librería propia
*/
// R.R.D_act10_1_932
#include <stdio.h>
#include "RRD.h"
#include <time.h>
#include <string.h>
struct registro
{
    char nombre[20];
    char ApPat[20];
    char ApMat[20];
    int matricula;
    int edad;
    char sexo[20];
    char status[20];
};

char hombres[20][10] = {"JUAN", "PEDRO", "CARLOS", "LUIS", "JAVIER", "ANDRES", "ALEJANDRO", "MIGUEL", "JOSE", "ADAN", "JORGE", "GABRIEL", "ROBERTO", "DAVID", "FERNANDO", "RAUL", "EDUARDO", "SERGIO", "ANTONIO", "FRANCISCO"};
char mujeres[20][10] = {"DANIELA", "LAURA", "ANA", "CARMEN", "SOFIA", "ISABEL", "MARTA", "PAULA", "ELENA", "PATRICIA", "LUCIA", "CLARA", "ROSA", "BEATRIZ", "CAROLINA", "JULIA", "TERESA", "SARA", "IRENE", "ADRIANA"};
char apellidos_paternos[20][10] = {"BARRIOS", "RODRIGUEZ", "LOPEZ", "PEREZ", "MARTINEZ", "SANCHEZ", "FERNANDEZ", "GONZALEZ", "RAMIREZ", "TORRES", "MARTIN", "JIMENEZ", "RUIZ", "DIAZ", "SOTO", "GOMEZ", "LOZANO", "CASTRO", "HERRERA", "GARCIA"};
char apellidos_maternos[20][10] = {"SUAREZ", "VILLEGAS", "GUERRERO", "PALACIOS", "FARIAS", "AVILA", "MOLINA", "SALAZAR", "DELGADO", "SANCHEZ", "FLORES", "MORALES", "ROMERO", "OROZCO", "RIVERA", "CASTILLO", "CHAVEZ", "SUAREZ", "VILLEGAS", "GUERRERO"};
char tipos_de_status[4][20] = {"DADO DE BAJA", "BAJA TEMPORAL", "MATRICULADO", "EGRESADO"};
char genero[2][10] = {"HOMBRE", "MUJER"};
void agregarautomaticamente(struct registro personas[], int *numero_persona);
void agregarmanual(struct registro personas[], int *numero_persona);
void eliminarregistro(struct registro personas[], int *numero_persona);
void ordenar(struct registro personas[], int *numero_persona);
void buscar(struct registro personas[], int numero_personas);
void imprimir(struct registro personas[], int num_personas);

int main()
{
    srand(time(NULL));
    struct registro personas[10];

    int menu, i, opc;
    int num_persona = 0;
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
            for (i = 0; i < 4; i++) 
            {
                agregarautomaticamente(personas, &num_persona);
            }
            menu = repetir();
            break;
        case 2:
            agregarmanual(personas, &num_persona);
            menu = repetir();
            break;
        case 3:
            eliminarregistro(personas, &num_persona);
            menu = repetir();
            break;
        case 4:
            buscar(personas, num_persona);
            menu = repetir();
            break;
        case 5:
            ordenar(personas, &num_persona);
            menu = repetir();
            break;
        case 6:
            imprimir(personas, num_persona);
            menu = repetir();
            break;
        }
    } while (menu == 1);
}
void agregarautomaticamente(struct registro personas[], int *numero_persona)
{
    int genero_numero;
    struct registro *persona = &personas[*numero_persona];
    genero_numero = rand() % 2;
    strcpy(persona->sexo, genero[genero_numero]);

    if (genero_numero == 0)
    {
        strcpy(persona->nombre, hombres[rand() % 20]);
    }
    else
    {
        strcpy(persona->nombre, mujeres[rand() % 20]);
    }

    strcpy(persona->ApPat, apellidos_paternos[rand() % 20]);
    strcpy(persona->ApMat, apellidos_maternos[rand() % 20]);

    strcpy(persona->status, tipos_de_status[rand() % 4]);

    persona->matricula = numerorandom(300000, 400000);
    persona->edad = numerorandom(18, 30);
    (*numero_persona)++;
}
void agregarmanual(struct registro personas[], int *numero_persona)
{
    struct registro *persona = &personas[*numero_persona];
    int status, Matricula, Edad, Sexo;
    char nombre[10], ApPat[20], ApMat[20];
    validarletras("INGRESE SU NOMBRES: ", nombre);
    strcpy(persona->nombre, nombre);
    validarletras("INGRESE SU Apellido Paterno: ", ApPat);
    strcpy(persona->ApPat, ApPat);
    validarletras("INGRESE SU Apellido Materno: ", ApMat);
    strcpy(persona->ApMat, ApMat);
    Matricula = validarnumeros("INGRESE SU MATRICULA: ", 1, 400000);
    persona->matricula = Matricula;
    Edad = validarnumeros("INGRESE SU EDAD: ", 18, 30);
    persona->edad = Edad;
    Sexo = validarnumeros("INGRESE SI ES:\n0.-HOMBRE\n1.-MUJER\n", 0, 1);
    strcpy(persona->sexo, genero[Sexo]);
    status = validarnumeros("CUAL SU STATUS:\n0.-DADO DE BAJA\n1.-BAJA TEMPORAL\n2.-MATRICULADO\n3.-EGRESADO\n", 0, 3);
    strcpy(persona->status, tipos_de_status[status]);
    (*numero_persona)++;
}
void eliminarregistro(struct registro personas[], int *numero_persona)
{
    int i, j, matricula, encontrado = 0;
    matricula = validarnumeros("INGRESE LA MATRICULA DEL ALUMNO PARA ELIMINAR SU REGISTRO\n", 0, 400000);
    for (i = 0; i <= *numero_persona; i++)
    {
        if (personas[i].matricula == matricula)
        {
            for (j = i; j <= *numero_persona; j++)
            {
                personas[j] = personas[j + 1];
                encontrado = 1;
            }
            (*numero_persona)--;
        }
    }
    if (encontrado == 0)
    {
        printf("NO SE ENCONTRO MATRICULA\n");
    }
}
void ordenar(struct registro personas[], int *numero_persona)
{
    struct registro temp;

    int i, j;
    for (i = 0; i < *numero_persona; i++)
    {
        for (j = 0; j < *numero_persona - 1; j++)
        {
            if (personas[j].matricula > personas[j + 1].matricula)
            {
                temp = personas[j];
                personas[j] = personas[j + 1];
                personas[j + 1] = temp;
            }
        }
    }
}
void buscar(struct registro personas[], int numero_personas)
{
    int numero_matricula, encoontrado = 0;
    numero_matricula = validarnumeros("INRESE LA MATRICULA\n", 300000, 400000);

    for (int i = 0; i < numero_personas; i++)
    {
        if (personas[i].matricula == numero_matricula)
        {
            printf("Registro %d:\n", i + 1);
            printf("Nombre: %s\n", personas[i].nombre);
            printf("Apellido Paterno: %s\n", personas[i].ApPat);
            printf("Apellido Materno: %s\n", personas[i].ApMat);
            printf("Matrícula: %d\n", personas[i].matricula);
            printf("Edad: %d\n", personas[i].edad);
            printf("Sexo: %s\n", personas[i].sexo);
            printf("Status: %s\n\n\n", personas[i].status);
            encoontrado = 1;
        }
    }
    if (encoontrado == 0)
    {
        printf("NO SE ENCONTRO LA MATRICULA\n\n");
    }
}
void imprimir(struct registro personas[], int numero_personas)
{
    if (numero_personas == 0)
    {
        printf("No hay registros para imprimir.\n");
        return;
    }

    printf("Registros almacenados:\n");
    printf("============================\n");

    for (int i = 0; i < numero_personas; i++)
    {
        printf("Registro %d:\n", i + 1);
        printf("Nombre: %s\n", personas[i].nombre);
        printf("Apellido Paterno: %s\n", personas[i].ApPat);
        printf("Apellido Materno: %s\n", personas[i].ApMat);
        printf("Matricula: %d\n", personas[i].matricula);
        printf("Edad: %d\n", personas[i].edad);
        printf("Sexo: %s\n", personas[i].sexo);
        printf("Status: %s\n", personas[i].status);
        printf("============================\n");
    }
}