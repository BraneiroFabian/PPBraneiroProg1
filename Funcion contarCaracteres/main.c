#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int id;
    char procesador[51];
    char marca[51];
    float precio;
}eNotebook;
#define TAM 5


int contarCaracteres(char cadena[], char caracter);
int aplicarDescuento(float precio);
void ordenarEstructura(eNotebook x[], int tam);
void mostrarEstructura(eNotebook x[], int tam);
int main()
{

    eNotebook listaNotebooks[TAM]={
    {100,"Intel","Lenovo",50000.00},
    {101,"AMD","Samsung",75000.00},
    {102,"HyperX","TCL",35000.00},
    {103,"Razer","Hitachi",20000.00},
    {104,"Linux","Apple",55000.00}};



    float precioDescuento;
    precioDescuento=aplicarDescuento(500);

    printf("El precio es de %.2f:\n\n ",precioDescuento);
    ordenarEstructura(listaNotebooks,TAM);
    mostrarEstructura(listaNotebooks,TAM);

    return 0;
}


int contarCaracteres(char cadena[], char caracter){
        int contadorCaracteres=0;
        int i=0;
        while(cadena[i]!='\0'){

            if (cadena[i]==caracter){

                contadorCaracteres++;
            }
            i++;
        }
        return contadorCaracteres;

        }

int aplicarDescuento(float precio){

    system("cls");
    float precioDesc;
    int descuento=5;

    descuento=(float)precio*descuento/100;
    precioDesc=precio-descuento;


    return precioDesc;

}
void ordenarEstructura(eNotebook x[], int tam){

    eNotebook auxNotebook;
    for(int i=0;i<TAM-1;i++){
        for(int j=i+1;j<TAM;j++){
            if(strcmp(x[i].marca, x[j].marca)>0){
                auxNotebook=x[i];
                x[i]=x[j];
                x[j]=auxNotebook;
            }else{
                if(strcmp(x[i].marca, x[j].marca)==0 && x[i].precio<x[j].precio){

                    auxNotebook=x[i];
                    x[i]=x[j];
                    x[j]=auxNotebook;
                }
            }
        }
    }
}


void mostrarEstructura(eNotebook x[], int tam){
    printf("ID    PROCESADOR    MARCA     PRECIO\n");
    for(int i=0;i<TAM;i++){
        printf("%5d     %5s    %7s     %5.2f\n",x[i].id,x[i].procesador,x[i].marca,x[i].precio);
    }
}
