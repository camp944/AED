#ifndef PILHA_H_
#define PILHA_H_
#define MAX 100
#include "base.h"

typedef struct PilhaD PilhaD;
typedef struct Pilha2A Pilha2A;


struct PilhaD{
	
	Bloco *first,*last;
	
};

struct Pilha2A{
	Bloco2A *first,*last;
};


void PDVazia(PilhaD *p);
void PDEmpilha(PilhaD *p,Item i);
void PDDesempilha(PilhaD *p,Item i);
void PDImprime(PilhaD *p);


void PDVazia2A(Pilha2A *p);
void PDEmpilha2A(Pilha2A *p,Item2A i);
void PDDesempilh2Aa(Pilha2A *p,Item2A i);
void PDImprime2A(Pilha2A *p);






#endif
