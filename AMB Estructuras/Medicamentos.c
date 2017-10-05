#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medicamentos.h"

void cargarMedicamentos(eMedicamento lista[], int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        if(lista[i].estado==0)
        {
            printf("Ingrese codigo: ");
            scanf("%d", &lista[i].codigo);
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(lista[i].descripcion);
            printf("Ingrese precio: ");
            scanf("%f", &lista[i].precio);
            printf("Ingrese laboratorio: ");
            fflush(stdin);
            gets(lista[i].laboratorio);

            lista[i].estado = 1;

            break;
        }

    }
}
void mostraTodosMedicamentos(eMedicamento lista[], int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarMedicamento(lista[i]);
        }

    }
}
void mostrarMedicamento(eMedicamento med)
{
    printf("%d--%s--%f--%s\n", med.codigo, med.descripcion, med.precio, med.laboratorio);
}

void ordenarMedicamentos(eMedicamento lista[], int tam)
{
    int i, j;
    eMedicamento auxMedicamento;

    for(i=0; i<tam-1; i++)
    {

        for(j=i+1; j<tam; j++)
        {

            if(stricmp(lista[i].laboratorio, lista[j].laboratorio)>0)
            {
                auxMedicamento=lista[i];
                lista[i]=lista[j];
                lista[j]=auxMedicamento;

            }
            else if(stricmp(lista[i].laboratorio, lista[j].laboratorio)==0)
            {
                if(stricmp(lista[i].descripcion, lista[j].descripcion)>0)
                {
                    auxMedicamento=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxMedicamento;
                }
            }
        }
    }
}

void inicializarMedicamentos(eMedicamento lista[], int tam)
{
    int codigo[]= {1,2,3,4};
    char descripcion[][50]= {"Valium","Ibuprofeno","Diclofenac","lala"};
    float precio[]= {5,10,7,8};
    char laboratorio[][30]= {"Bago","Bayer","Roemer","Bago"};
    int estado[]= {1,1,1,1};

    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].codigo = codigo[i];
        lista[i].precio = precio[i];
        lista[i].estado = estado[i];
        strcpy(lista[i].descripcion,descripcion[i]);
        strcpy(lista[i].laboratorio,laboratorio[i]);
    }




}

void funmodificar(eMedicamento lista[], int t)
{
    int i,flag  = 0;
    int buscarCodigo;
    char auxLaboratorio[100];
    char respuestapregunta;

    printf("Ingrese codigo: ");
    scanf("%d", &buscarCodigo);
    for(i=0; i<t; i++)
    {
        if (buscarCodigo == lista[i].codigo)
        {
            flag=1;
            mostrarMedicamento(lista[i]);
            printf("Ingrese el nuevo labotorio: ");
            fflush(stdin);
            gets(auxLaboratorio);
            printf("Esta seguro/a de querer cambiar el laboratorio? s/n ");
            fflush(stdin);
            scanf("%c",&respuestapregunta);
            if (respuestapregunta == 's')
            {
                strcpy(lista[i].laboratorio,auxLaboratorio);
                printf("Se modifico el laboratorio\n");
            }
            else
            {
                printf("No se modifico el laboratorio\n");
            }
        }

    }
    if (flag != 0)
    {
        printf("El codigo ingresado es inexistente\n");
    }
}

void funbaja(eMedicamento lista[], int t)
{
    int i,flag  = 0;
    int buscarCodigo;
    char respuestapregunta;

    printf("Ingrese codigo: ");
    scanf("%d", &buscarCodigo);
    for(i=0; i<t; i++)
    {
        if (buscarCodigo == lista[i].codigo)
        {
            flag=1;
            mostrarMedicamento(lista[i]);
            printf("Esta seguro/a de querer dar de baja el medicamento? s/n ");
            fflush(stdin);
            scanf("%c",&respuestapregunta);
            if (respuestapregunta == 's')
            {
                lista[i].estado = 0;
                printf("Se dio de baja el medicamento\n");
            }
            else
            {
                printf("No se dio de baja el medicamento\n");
            }
        }

    }
    if (flag != 0)
    {
        printf("El codigo ingresado es inexistente\n");
    }
}

