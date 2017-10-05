#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LAB 3
#define MED 5
#define CLI 10

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idLaboratorio;//PK
    char razonSocial[25];
    char direccion[50];
    char telefono[20];
} eLaboratorio;

typedef struct
{
    int idMedicamento;//PK
    char descripcion[50];
    float precio;
    int idLaboratorio;//FK
    int stock;
    eFecha fechaElaboracion;
    eFecha fechaVencimiento;
} eMedicamento;

typedef struct
{
    int idCliente;//
    char nombre[50];
    int idMedicamento;//FK
} eCliente;

void inicializarLaboratorios(eLaboratorio[], int);
void inicializarMedicamentos(eMedicamento[], int);
void inicializarClientes(eCliente[], int);

void mostrarMedicamentos(eMedicamento[], int);
void mostrarClientes(eCliente clientes[], int sizeCli, eMedicamento medicamento[], int sizeMed);

void relacionaMedicamento(eMedicamento medicamento[], int TMed, int clientemed);
void clientescompIbu(eMedicamento medi[], int TMed, eCliente cliente[], int TCli);
void clieCompMedic(eMedicamento medi[], int TMed, eCliente cliente[], int TCli);

int main()
{
    eLaboratorio listaLaboratorios[LAB];
    eMedicamento listaMedicamentos[MED];
    eCliente listaClientes[CLI];


    inicializarLaboratorios(listaLaboratorios, LAB);
    inicializarMedicamentos(listaMedicamentos, MED);
    inicializarClientes(listaClientes, CLI);


    mostrarMedicamentos(listaMedicamentos, MED);
    printf("\n***************************************************\n");
    mostrarClientes(listaClientes, CLI,listaMedicamentos, MED);
    printf("\n***************************************************\n");
    clientescompIbu(listaMedicamentos,MED,listaClientes,CLI);



    return 0;
}

void inicializarLaboratorios(eLaboratorio laboratorios[], int sizeLab)
{
    int id[]= {1,2,3};
    char razon[][30]= {"Roemers","Bago","Bayer"};
    char direccion[][30]= {"mitre 750","Belgrano 788","Sarmiento 1258"};
    char telefono[][30]= {"12345","678910","1112131415"};
    int i;

    for(i=0; i<sizeLab; i++)
    {
        laboratorios[i].idLaboratorio=id[i];
        strcpy(laboratorios[i].razonSocial, razon[i]);
        strcpy(laboratorios[i].direccion, direccion[i]);
        strcpy(laboratorios[i].telefono, telefono[i]);
    }
}

void inicializarMedicamentos(eMedicamento medicamentos[], int sizeMed)
{

    int id[]= {100,101,102,103,104};
    char descripcion[][30]= {"Ibuprofeno","Tafirol","Diclofenac","Bayaspirina", "Mejoralito"};
    float precio[]= {60,85,105,15,28};
    int laboratorio[]= {1,1,2,3,3,1};
    int stock[]= {3,2,3,10,0};
    eFecha elaboracion[]= {{22,9,2017},{15,2,2016},{10,6,2016},{22,9,2017},{5,10,2000}};
    eFecha vencimiento[]= {{22,9,2030},{5,12,2017},{30,8,2019},{3,12,2020},{12,8,2005}};
    int i;

    for(i=0; i<sizeMed; i++)
    {
        medicamentos[i].idMedicamento=id[i];
        strcpy(medicamentos[i].descripcion, descripcion[i]);
        medicamentos[i].precio = precio[i];
        medicamentos[i].idLaboratorio=laboratorio[i];
        medicamentos[i].stock = stock[i];
        medicamentos[i].fechaElaboracion=elaboracion[i];
        medicamentos[i].fechaVencimiento=vencimiento[i];

    }
}
void inicializarClientes(eCliente clientes[], int sizeCli)
{

    int id[]= {111,222,333,444,555,666,777,888,999,101010};
    char nombre[][30]= {"Geronimo","Adalberto","Inocencia","Felipe","Lucrecia","Ermenegildo","Efigenia","Dora","Anastacia","Armando"};
    int medicamento[]= {104,100,101,101,101,102,103,101,101,100};
    int i;

    for(i=0; i<sizeCli; i++)
    {
        clientes[i].idCliente=id[i];
        strcpy(clientes[i].nombre, nombre[i]);
        clientes[i].idMedicamento=medicamento[i];
    }
}

void mostrarMedicamentos(eMedicamento medicamentos[], int sizeMed)
{
    int i;
    printf("ID\t%10s\tPRECIO\tLAB\tSTOCK\tF. ELAB\t\tF.VTO\n", "DESCRIPCION");
    for(i=0; i<sizeMed; i++)
    {
        printf("%d\t%10s\t%.2f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\n", medicamentos[i].idMedicamento
               ,medicamentos[i].descripcion, medicamentos[i].precio, medicamentos[i].idLaboratorio
               ,medicamentos[i].stock, medicamentos[i].fechaElaboracion.dia, medicamentos[i].fechaElaboracion.mes
               ,medicamentos[i].fechaElaboracion.anio,medicamentos[i].fechaVencimiento.dia
               ,medicamentos[i].fechaVencimiento.mes,medicamentos[i].fechaVencimiento.anio);
    }

}
void mostrarClientes(eCliente clientes[], int sizeCli, eMedicamento medicamento[], int sizeMed)
{
    int i;
    printf("ID\t%10s\tMEDICAMENTO\n", "NOMBRE");
    for(i=0; i<sizeCli; i++)
    {
        printf("%d\t%10s", clientes[i].idCliente, clientes[i].nombre);
        relacionaMedicamento(medicamento,sizeMed, clientes[i].idMedicamento);
    }
}

void relacionaMedicamento(eMedicamento medicamento[], int TMed, int clientemed)
{
    int i;
    for (i=0; i<TMed; i++)
    {
        if (clientemed == medicamento[i].idMedicamento)
        {
            printf("\t%s\n",medicamento[i].descripcion);
            break;
        }
    }
}

void clientescompIbu(eMedicamento medi[], int TMed, eCliente cliente[], int TCli)
{
    int i,j;
    int auxIDMed;
    printf("Los clientes que compraron Ibuprofeno fueron:\n");
    for (i=0; i<TMed; i++)
    {
        if (stricmp("Ibuprofeno",medi[i].descripcion)==0)
        {
            auxIDMed = medi[i].idMedicamento;
            break;
        }
    }

    for (j=0; j<TCli; j++)
    {
        if (auxIDMed == cliente[j].idMedicamento)
        {
            printf("%s\n",cliente[j].nombre);
        }
    }

}

void clieCompMedic(eMedicamento medi[], int TMed, eCliente cliente[], int TCli)
{
    int i,j;
    int auxMed[5]={};
    for (i=0; i<TMed; i++)
    {
        for (j=0; j<TCli; i++)
        {
            if ((cliente[j].idMedicamento,medi[i].descripcion)==0)
            {
                 auxMed[i]+=1;
            }
        }
    }
}
