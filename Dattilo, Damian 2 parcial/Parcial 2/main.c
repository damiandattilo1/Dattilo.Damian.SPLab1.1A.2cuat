#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "bicicletas.h"

#define DESC 0
#define ASC 1


int imprimirMenu();

int main()
{
    srand (time(NULL));  // ALEATORIO
    char salir='n';
    LinkedList* listaBicicletas=ll_newLinkedList();
    LinkedList* listaBicicletasAleatorio;
    LinkedList* listaBicisAscendente;
    LinkedList* listaBicisTipo;
    int flagCargar=0;
    int flagAleatorio=0;
    int flagAscendente=0;
    do
    {
        switch(imprimirMenu())
        {
            case 1:
                controller_CargarTexto("bicicletas.csv", listaBicicletas);
                flagCargar=1;
                break;
            case 2:
                if(flagCargar==1 && flagAleatorio==1)
                {
                    controller_ListarBicicletas(listaBicicletasAleatorio);
                }
                else if(flagCargar==1)
                {
                    controller_ListarBicicletas(listaBicicletas);
                }
                else
                {
                    printf("\nERROR, debe hacer la carga de los datos\n\n");
                }
                break;
            case 3:
                if(flagCargar==1)
                {
                    listaBicicletasAleatorio=ll_map(listaBicicletas, aleatorios);
                    flagAleatorio=1;
                }
                else
                {
                    printf("\nERROR, debe hacer la carga de los datos\n\n");
                }
                break;
            case 4:
                if(flagAleatorio==1)
                {
                    listaBicisTipo=ll_filter(listaBicicletasAleatorio, tipo);
                    controller_ListarBicicletas(listaBicisTipo);
                    controller_Guardar("bicisTipo.csv", listaBicisTipo);
                }
                else
                {
                    printf("\nERROR, se debe crear la lista aleatoria\n\n");
                }
                break;
            case 5:
                if(flagAleatorio==1)
                {
                    listaBicisAscendente=listaBicicletasAleatorio;
                    ll_sort(listaBicisAscendente, orden, ASC);
                    controller_ListarBicicletas(listaBicisAscendente);
                    flagAscendente=1;
                }
                else
                {
                    printf("\nERROR, se debe crear la lista aleatoria\n\n");
                }
                break;
            case 6:
                if(flagAscendente==1)
                {
                    controller_Guardar("posiciones.csv", listaBicisAscendente);
                }
                else
                {
                    printf("\nERROR, se debe crear la lista ascendente\n\n");
                }
                break;
            case 7:
                salir='s';
                break;
            default:
                printf("\nERROR: No es una opcion valida\n\n");
                break;
        }
        system("pause");
        system("cls");
    }while(salir!='s');

    return 0;
}

int imprimirMenu()
{
    int opcion;

    printf("************MENU******************\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar tiempos\n");
    printf("4. Filtrar por tipo\n");
    printf("5: Mostrar posiciones\n");
    printf("6: Guardar posiciones\n");
    printf("7. Salir\n\n");
    printf("Elija una opcion: ");

    scanf("%d", &opcion);

    return opcion;
}
