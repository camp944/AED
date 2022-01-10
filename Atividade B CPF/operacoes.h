#ifndef OPERACOES_H
#define OPERACOES_H
#define MAX 100
#include "estruturas.h"

void geraCPF();
void Cria_vetor(char nomes[1000][MAX],long long int cpfs[1000]);
void Insere_Conjunto(char nomes[1000][MAX],long long int Cpfs[1000],Pagina *p[10]);
void Buscador(long long int key,Pagina *p[10]);
void Pesquisa(Pagina **p,long long int key);
void Add(record r,Pagina *p[10]);
void Delet(record r,Pagina *p[10]);





#endif
