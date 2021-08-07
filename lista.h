#ifndef LISTA_H
#define LISTA_H
#include "base.h"

typedef struct Lista Lista;
typedef struct ListaC ListaC;


struct Lista
{
	Bloco *primeiro;
	Bloco *ultimo;
};

struct ListaC
{
	Bloco1C *primeiro;
	Bloco1C *ultimo;
};


void LVazia(Lista *l);
void LInserir(Lista *l, Item i);
void LRemove(Lista *l,Item i);
void LImprime(Lista *l);

void LCVazia(ListaC *l);
void LCInserir(ListaC *l, Item1C i);
void LCRemove(ListaC *l,Item1C i);
void LCImprime(ListaC *l);


#endif
