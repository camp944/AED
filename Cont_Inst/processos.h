#ifndef PROCESSOS_H_
#define PROCESSOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 10
#define MAX_TAM 100




typedef struct contador
{
	int vet_pos[MAX_TAM];
	int tamanho,soma;
	int cont_steps;
	
}contador;


void menu_inicial();
void menu();

void inicio(int matriz[MAX][MAX],int tamanho,contador *c);
void reinicio(int matriz[MAX][MAX],contador *c);
void andar(int matriz[MAX][MAX],contador *c);
void imprimir_posicao(contador *c);
void imprimir_matriz(contador *c,int matriz[MAX][MAX]);
void imprirmir_resultados(contador *c);


#endif
