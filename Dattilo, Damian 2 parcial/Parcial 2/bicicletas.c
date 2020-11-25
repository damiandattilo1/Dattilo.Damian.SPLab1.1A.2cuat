#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "bicicletas.h"
#include "string.h"

int listarBicis(LinkedList* listaBicis)
{

    int todoOk=0;
    int tam=ll_len(listaBicis);
    eBici* auxBici;
    int flag=0;

    if(listaBicis != NULL && tam > 0 )
    {
        todoOk=1;

        printf("***Listado de bicicletas***\n");
        printf(" ID               NOMBRE               TIPO                 TIEMPO\n");
        printf("------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            auxBici=(eBici*)ll_get(listaBicis, i);
            if(auxBici!= NULL)
            {
                listarBici(auxBici);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\nERROR No hay bicicletas\n\n");
        }
    }

    return todoOk;
}

void listarBici(eBici* unaBici)
{
    printf("%d     %5s        %5s      %5d\n", unaBici->id, unaBici->nombre, unaBici->tipo, unaBici->tiempo);
}

eBici* bici_new()
{
    return (eBici*)malloc((sizeof(eBici)));
}

eBici* bici_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr)
{
    eBici* auxBici=NULL;

    auxBici=bici_new();
    if(auxBici!=NULL)
    {
        auxBici->id=atoi(idStr);
        strcpy((auxBici->nombre),nombreStr);
        strcpy((auxBici->tipo), tipoStr);
        auxBici->tiempo=atoi(tiempoStr);
    }

    return auxBici;
}

int bici_setId(eBici* auxBici, int id)
{
    int retorno=-1;

    if(auxBici !=NULL && id>=0)
    {
        auxBici->id=id;
        retorno=0;
    }
    return retorno;
}

int bici_setNombre(eBici* auxBici, char* nombre)
{
    int retorno=-1;

    if(auxBici !=NULL && nombre!=NULL)
    {
        strcpy(auxBici->nombre, nombre);
        retorno=0;
    }
    return retorno;
}

int bici_setTipo(eBici* auxBici, char* tipo)
{
    int retorno=-1;

    if(auxBici !=NULL && tipo!=NULL)
    {
        strcpy(auxBici->tipo, tipo);
        retorno=0;
    }
    return retorno;
}

int bici_setTiempo(eBici* auxBici, int tiempo)
{
    int retorno=-1;

    if(auxBici !=NULL && tiempo>=0)
    {
        auxBici->tiempo=tiempo;
        retorno=0;
    }
    return retorno;
}



void* aleatorios(void* elemento)
{
    eBici* auxBici;
    auxBici=(eBici*)elemento;

    auxBici->tiempo= (50+rand()%((120+1)-50));

    return elemento;
}

int tipo(void* elemento)
{
    int retorno=0;
    char tipo[]="BMX";
    eBici* auxBici;
    auxBici=(eBici*)elemento;

    if(!strcmp((auxBici->tipo), tipo))
    {
        retorno=1;
    }
    return retorno;
}


int orden(void* elementoI, void* elementoJ)
{
    int retorno = -1;
    eBici* auxI;
    eBici* auxJ;
    if(elementoI!=NULL && elementoJ!=NULL)
    {
        auxI=(eBici*)elementoI;
        auxJ=(eBici*)elementoJ;

        if((auxI->tiempo)>(auxJ->tiempo))
        {
            retorno=1;
        }
        else if((auxI->tiempo)==(auxJ->tiempo))
        {
            retorno=0;
        }
    }
    return retorno;
}
