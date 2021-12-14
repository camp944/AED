#ifndef GERAVALORES_H
#define GERAVALORES_H
#define MAX 100000
#include "BIN.h"
#include "AVL.h"
#include "RN.h"

typedef struct Pesquisador Pesquisador;
typedef struct Dado Dado;

struct Dado{
	double tempo_medio,tempo_total;
	int Encontrados;
	
};

struct Pesquisador{
	Dado d[3][3];
	int n[3];
};


void geraValores_Insert();
void geraValores_Search();
double Insere_valores_AVL(AVL **t,int n);
double Insere_valores_Binaria(BIN **t,int n);
double Insere_valores_RN(RN **t,int n);
Dado pesquisa_BIN(BIN **t,int n);
Dado pesquisa_AVL(AVL **t,int n);
Dado pesquisa_RN(RN **t,int n);


#endif
