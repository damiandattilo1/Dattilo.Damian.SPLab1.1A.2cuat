#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"
#include "string.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_CargarTexto(char* path , LinkedList* listaBicicletas)
{
    FILE* pArchivo = fopen(path,"r");
    int todoOk=0;
    if(listaBicicletas != NULL && path != NULL)
    {
        parser_BicicletasTexto(pArchivo,listaBicicletas);
        todoOk=1;
    }
    fclose(pArchivo);
    return todoOk;
}


/** \brief Listar paises
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListarBicicletas(LinkedList* listaBicis)
{
    int todoOk=0;
    if(listarBicis(listaBicis)==1)
    {
        todoOk=1;
    }
    return todoOk;
}

int controller_Guardar(char* path, LinkedList* this)
{
    int retorno=-1;
    FILE* pFile;
    int tam;
    int auxId;
    char auxNombre[25];
    char auxTipo[20];
    int auxTiempo;
    eBici* pBici=NULL;
    tam=ll_len(this);

    if(path != NULL && this != NULL)
    {
        pFile=fopen(path,"w");

        if(pFile != NULL)
        {
            fprintf(pFile,"id,nombre,tipo,tiempo\n");

            for(int i=0; i<tam; i++)
            {
                pBici=(eBici*)ll_get(this,i);

                if(pBici != NULL)
                {
                    fprintf(pFile,"%d,%s,%s,%d\n",pBici->id, pBici->nombre, pBici->tipo, pBici->tiempo);
                    retorno=0;

                }
            }
            fclose(pFile);
        }
    }
    return retorno;
}
