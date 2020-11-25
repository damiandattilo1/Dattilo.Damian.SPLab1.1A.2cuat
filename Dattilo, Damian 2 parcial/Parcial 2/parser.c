#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "string.h"

#define BUFFER 1000

/** \brief Parsea los datos de los paises desde el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param listaPaises LinkedList*
 * \return int
 *
 */

int parser_BicicletasTexto(FILE* pFile , LinkedList* listaBicicletas)
{
    int retorno = -1;
    char bufferId[BUFFER];
    char bufferNombre[BUFFER];
    char bufferTipo[BUFFER];
    char bufferTiempo[BUFFER];
    eBici* pBici;
    int total=0;
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            total+=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferTipo,bufferTiempo);

            pBici = bici_newParametros(bufferId,bufferNombre,bufferTipo,bufferTiempo);

            if(pBici != NULL)
            {
                ll_add(listaBicicletas,pBici);
                retorno = 0;
            }
        }
        printf("\nSe cargaron %d datos\n\n", total);
    }
    return retorno;
}
