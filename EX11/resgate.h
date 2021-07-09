#ifndef RESGATE_H_
#define RESGATE_H_
#include <stdio.h>
#include <conio.h>
#define MAX_TAM 10
#define MAX_NAME 30
#define MAX 5

typedef struct item
{
	int valor,pos_disc[2];
}item;

typedef struct fila
{
	item elements[MAX];
	int pos_old,pos_new;
	int full;
	
}fila;

typedef struct TP
{
	item passageiro;
		
}TP;

void printDisco(int discoF[MAX_TAM][MAX_NAME];);
void Inicio(fila *f);
void Read_txt(char discoI[MAX_TAM][MAX_NAME],FILE *arquivo,int discoF[MAX_TAM][MAX_NAME],int n_linhas);
void InQueue(fila *f,item a);
TP GetDisco(int discoF[MAX_TAM][MAX_NAME],int linha,int a,fila *f);
item OutQueue(fila *f);
void FullQueue(fila *f,int discoF[MAX_TAM][MAX_NAME]);

#endif
