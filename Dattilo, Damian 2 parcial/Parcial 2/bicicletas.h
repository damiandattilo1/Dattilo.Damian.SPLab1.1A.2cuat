#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED


typedef struct
{
    int id;
    char nombre[20];
    char tipo[20];
    int tiempo
}eBici;


#endif // PAISES_H_INCLUDED

int listarBicis(LinkedList* listaBicis);

void listarBici(eBici* unaBici);

eBici* bici_new();

eBici* bici_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr);

int bici_setId(eBici* auxBici, int id);

int bici_setNombre(eBici* auxBici, char* nombre);

int bici_setTipo(eBici* auxBici, char* tipo);

int bici_setTiempo(eBici* auxBici, int tiempo);

void* aleatorios(void* elemento);

int tipo(void* elemento);

int orden(void* elementoI, void* elementoJ);
