#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "resgate.h"
#define MAX_TAM 10
#define MAX_NAME 30
#define MAX 5

void printDisco(int discoF[MAX_TAM][MAX_NAME])
{
	int contador_linhas=1,contador_colunas=1;
	printf("\n\n\n");

	
	while(contador_linhas<discoF[0][0]+1)
	{
		contador_colunas=1;
		printf("Linha A%d  ",contador_linhas);
		while(contador_colunas<discoF[0][contador_linhas])
		{
			printf(" %d  ",discoF[contador_linhas][contador_colunas]);
			contador_colunas++;
		}
		printf("\n");
		contador_linhas++;
	}
	
	printf("\n\n\n");
	            
}

void Inicio(fila *f)
{
	f->pos_new=0;
	f->pos_old=0;
	f->full=0;
}

void Read_txt(char discoI[MAX_TAM][MAX_NAME],FILE *arquivo,int discoF[MAX_TAM][MAX_NAME],int n_linhas)
{
	n_linhas=0;
	char leitor[30],token1[10];
	char *token;
	int contador_linhas=0;
	
	while((fgets(leitor,30,arquivo)!=NULL))
	{
		strcpy(discoI[contador_linhas],leitor);
		contador_linhas++;
		n_linhas=n_linhas+1;
		
	}
	contador_linhas=0;
	
	while(contador_linhas<n_linhas)
	{
		printf("\n");
		int contador_colunas=0;
		token=strtok(discoI[contador_linhas],", ");
		while(token!=NULL)
		{
			if(contador_colunas==0)
			{
				contador_colunas++;
				token=strtok(NULL,", ");
			}
			else
			{
				strcpy(token1,token);
				discoF[contador_linhas+1][contador_colunas]=atoi(token1);
				token=strtok(NULL,", ");
				contador_colunas++;
			}
			
			
		}
		
		
		discoF[0][contador_linhas+1]=contador_colunas;
		contador_linhas++;
	}
	discoF[0][0]=contador_linhas;
	

	
}

void InQueue(fila *f,item a)
{
		if(f->full==0)
		{
			f->elements[f->pos_new]=a;
			f->full++;
		}
		else
		{
			if(f->pos_new<4)
			{	f->pos_new++;
				f->elements[f->pos_new]=a;
				f->full++;
				
			}
			else
			{
				f->pos_new=0;
				f->elements[f->pos_new]=a;
				f->full++;
				
			}
		}
	
	
}

item OutQueue(fila *f)
{
	item a;
	a=f->elements[f->pos_old];
	if(f->pos_old<4)
	{
		f->pos_old++;
	}
	else
	{
		f->pos_old=0;
	}
	f->full--;
	
	
	return a;
}

TP GetDisco(int discoF[MAX_TAM][MAX_NAME],int linha,int a,fila *f)
{
	TP transportador;
	transportador.passageiro.pos_disc[0]=-1;
	int contador_colunas=0;
	int cont=0;
	int x=0;
	transportador.passageiro.valor=x;
	
	while(cont<5)
	{
		if((f->elements[cont].valor==a)&&(f->elements[cont].pos_disc[1]==linha))
		{
			transportador.passageiro.valor=-2;
		}
		cont++;
	}
		
	if(transportador.passageiro.valor!=-2)
	{
		while(contador_colunas<discoF[0][linha])
		{
			if(discoF[linha][contador_colunas]==a)
			{
				
				transportador.passageiro.valor=discoF[linha][contador_colunas];
				discoF[linha][contador_colunas]=x;
				transportador.passageiro.pos_disc[0]=contador_colunas;
				transportador.passageiro.pos_disc[1]=linha;
				
								
			}
			
				
			
		
			contador_colunas++;
			
		}
	}
	else
	{
		printf("\n\n         O VALOR JA ESTA NA MEMORIA\n\n");
	}	
	

	
	
	return transportador;
}

void FullQueue(fila *f, int discoF[MAX_TAM][MAX_NAME])
{ 
	item b;
	b=OutQueue(f);
	discoF[b.pos_disc[1]][b.pos_disc[0]]=b.valor;
	
	
}

void printFila(fila *f)
{
	printf(" \n          ");
	int cont_new=f->pos_new,cont_old=f->pos_old;
	if(f->pos_new>f->pos_old)
	{
		while(cont_old<=cont_new)
		{
			printf(" %d",f->elements[cont_old].valor);
			cont_old++;
		}
	}
	else
	{
		if(f->pos_old==f->pos_new)
		{
			printf(" %d",f->elements[cont_old].valor);
		}
		else
		{
			while(cont_old<5)
			{
				printf(" %d",f->elements[cont_old].valor);
				cont_old++;
			}
			
			cont_old=0;
			
			while(cont_old<=cont_new)
			{
				printf(" %d",f->elements[cont_old].valor);
				cont_old++;
			}
		}
	}
	
	printf("\n");
}

