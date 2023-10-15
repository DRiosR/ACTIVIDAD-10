#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *mayuscula(char cadena[]);
int validarnumeros(char mensaje[], int ri, int rf);
char *validarletras(char mensaje[], char cadena[]);
int contador(char cadena[]);
int Busqueda(int vect[], int n, int num);
void vector(int vect[], int n, int ri, int rs);
void matriz4x4(int matriz[4][4], int ri, int rs);
int repetir();
void imprimirvector(int vec[], int n, char mensaje[]);
void imprimirmatriz(int matriz[][4], int n, int n2, char mensaje[]);
void busquedavector(int vec[], int n);
int numerorandom(int ri, int rs);
void imprimircadena(char cadena[]);

char *mayuscula(char cadena[])
{
    int i, x;
    x = contador(cadena);

    for (i = 0; i < x; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
        }
    }
    return cadena;
}

int validarnumeros(char mensaje[], int ri, int rf)
{
    char menu[100];
    int num, salida = 0, con, i;
    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(menu);
        con = contador(menu);
        for (i = 0; i < con; i++)
        {
            if (menu[i] >= '0' && menu[i] <= '9')
            {
                salida = 1;
                break;
            }
            else
            {
                salida = 0;
                break;
            }
        }
        num = atoi(menu);
        if (num < ri || num > rf)
        {
            printf("INGRESE EL NUMERO OTRA VEZ PORFAVOR\n");
        }
    } while (num < ri || num > rf || salida == 0);
    return num;
}

char *validarletras(char mensaje[], char cadena[])
{
    int x, i, salida;
    printf("%s", mensaje);
    do
    {
        salida = 0;
        fflush(stdin);
        gets(cadena);
        x = contador(cadena);
        mayuscula(cadena);
        for (i = 0; i < x; i++)
        {
            if (cadena[i] >= 'A' && cadena[i] <= 'Z')
            {
                salida = 0;
            }
            else
            {
                printf("CARACTERES INVALIDOS\n");
                salida = 1;
                break;
            }
            if (cadena[i] == ' ' && cadena[i + 1] == ' ')
            {
                printf("CARACTERES INVALIDOS\n");
                salida = 1;
                break;
            }
            if (cadena[i] >= '0' && cadena[i] <= '9')
            {
                printf("CARACTERES INVALIDOS\n");
                salida = 1;
                break;
            }
        }
    } while (salida == 1);
    return cadena;
}

int contador(char cadena[])
{
    int i;
    i = 0;
    while (cadena[i] != 0)
    {
        i++;
    }
    return i;
}

int Busqueda(int vect[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vect[i] == num)
        {
            return i;
        }
    }
    return -1;
}

void vector(int vect[], int n, int ri, int rs)
{
    srand(time(NULL));
    int i, j, x, repe;
    for (i = 0; i < n; i++)
    {
        x = (rs - ri) + 1;
        do
        {
            vect[i] = (rand() % x) + ri;
            repe = 0;
            for (j = 0; j < i; j++)
            {

                if (vect[i] == vect[j])
                {
                    repe = 1;
                }
            }
        } while (repe == 1);
    }
}

void matriz4x4(int matriz[4][4], int ri, int rs)
{
    srand(time(NULL));
    int i, j, x, repe, vec[16];
    x = (rs - ri) + 1;
    for (i = 0; i < 16; i++)
    {
        do
        {
            vec[i] = (rand() % x) + ri;
            repe = 0;
            for (j = 0; j < i; j++)
            {

                if (vec[i] == vec[j])
                {
                    repe = 1;
                }
            }
        } while (repe == 1);
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matriz[i][j] = vec[i * 4 + j];
        }
    }
}

int repetir()
{
    int repetir;
    repetir = validarnumeros("QUIERES HACER OTRA OPCION\nSI=1\nNO=2\n", 1, 2);
    if (repetir == 1)
    {
        return 1;
    }
    else
    {
        printf("FIN DEL POGRAMA");
        return 0;
    }
}

void imprimirvector(int vec[], int n, char mensaje[])
{
    int i;
    printf("%s=", mensaje);
    for (i = 0; i < n; i++)
    {
        printf(" [%1d] ", vec[i]);
    }
    printf("\n");
}

void imprimirmatriz(int matriz[][4], int n, int n2, char mensaje[])
{
    int i, j;
    printf("%s=\n", mensaje);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("  [%3d]  ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ordenarvector(int vec[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

void busquedavector(int vec[], int n)
{
    int i, encontrado = 0;
    int numero;
    numero = validarnumeros("INGRESE EL NUMERO: ", 0, 10000);
    for (i = 0; i < n; i++)
    {
        if (vec[i] == numero)
        {
            printf("El numero %d se encuentra el el lugar [%d]\n", numero, i);
            encontrado = 1;
        }
    }
    if (encontrado == 0)
    {
        printf("El numero no se encuentra en el vector\n");
    }
}

int numerorandom(int ri, int rs)
{
    int x, n;
    x = (rs - ri) + 1;
    n = (rand() % x) + ri;
    return n;
}

void imprimircadena(char cadena[])
{
    int i,n;
    n=contador(cadena);
    for (i = 0; i < n; i++)
    {
        printf("%c", cadena[i]);
    }
    printf(" ");
}