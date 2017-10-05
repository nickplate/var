#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
#define TAM 3

int mostrarmenu(char[]);

int main()
{
    int codigo[TAM] = {0};
    char descrip[TAM][50];
    int stock[TAM];
    float precio[TAM];
    char seguir = 's';
    int i;
    int j;
    char auxchar[50];
    int auxint;
    float auxfloat;
    int opcionA;

    while (seguir=='s')
    {
        opcionA = mostrarmenu("1 - Alta de Producto\n2 - Motrar Producto\n3 - Ordenar por descripcion\n5 - Salir\nIngrese la opcion a usar: ");
        switch (opcionA)
        {
        case 1:
            for (i=0; i<TAM; i++)
            {
                if (codigo [i] == 0)
                {
                    printf("Ingrese el codigo del producto: ");
                    scanf ("%d",&codigo[i]);
                    printf("Ingrese la descripcion del producto: ");
                    fflush(stdin);
                    gets (descrip[i]);
                    printf("Ingrese el stock del producto: ");
                    scanf ("%d",&stock[i]);
                    printf("Ingrese el precio del producto: ");
                    scanf ("%f",&precio[i]);
                    break;
                }
            }
            system("pause");
            system("cls");
            break;
        case 2:
            for (i=0; i<TAM; i++)
            {
                if (codigo[i] != 0)
                {
                    printf("Codigo: %d -- Nombre: %s -- Stock: %d -- Precio: $%f\n", codigo[i],descrip[i],stock[i],precio[i]);

                }
            }
            system("pause");
            system("cls");
            break;
        case 3:
            for (i=0; i<(TAM-1); i++)
            {
                for (j=i+1; j<TAM; j++)
                {
                    if (stricmp(descrip[i],descrip[j])>0)
                    {
                        strcpy(auxchar,descrip[i]);
                        strcpy(descrip[i],descrip[j]);
                        strcpy(descrip[j],auxchar);

                        auxint=codigo[i];
                        codigo[i]=codigo[j];
                        codigo[j]= auxint;

                        auxint=stock[i];
                        stock[i]=stock[j];
                        stock[j]= auxint;

                        auxfloat=precio[i];
                        precio[i]=precio[j];
                        precio[j]= auxfloat;

                    }
                }
            }
            system("cls");
            break;

        case 5:
            seguir = 'n';
            break;

        }
    }


    return 0;
}

int mostrarmenu(char texto[])
{
    int opcion;
    printf(texto);
    scanf("%d",&opcion);
    return opcion;
}
