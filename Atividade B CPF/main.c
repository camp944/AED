#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "operacoes.h"
#define MAX 100



int main(){
	
	
	int i,cont=0,gerar=0,opc=1;
	Pagina *p[10]={CreateTree(),CreateTree(),CreateTree(),CreateTree(),CreateTree(),CreateTree(),CreateTree(),CreateTree(),CreateTree(),CreateTree()};
	record r;
	char nomes[1000][MAX];
	long long int Cpfs[1000],CPF_Buscador;
	
	printf("\n\tDESEJA GERAR UM NOVO CONJUNTO DE CPFs ALEATORIOS? (SIM->1 NAO->QUALQUER VALOR) ");
	scanf("%d",&gerar);
	
	if(gerar==1){geraCPF();}
	
	Cria_vetor(nomes,Cpfs);
	Insere_Conjunto(nomes,Cpfs,p);
	
	while(opc!=0)
	{
		printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		printf("\t@                                      @\n");
		printf("\t@                  MENU                @\n");
		printf("\t@                                      @\n");
		printf("\t@           PESQUISAR CPF -> 1         @\n");
		printf("\t@         ADICIONAR PESSOA -> 2        @\n");
		printf("\t@          REMOVER PESSOA -> 3         @\n");
		printf("\t@        ENCERRAR PROGRAMA -> 0        @\n");
		printf("\t@                                      @\n");
		printf("\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		
		printf("\n\tINSIRA A OPCAO DESEJADA -> ");
		scanf("%d",&opc);
		
		if(opc==1)
		{
			printf("\n\tINSIRA O CPF QUE DESEJA BUSCAR -> ");
			scanf("%lld",&CPF_Buscador);

			Buscador(CPF_Buscador,p);
		}
		if(opc==2)
		{
			printf("\n\tINSIRA O CPF DA PESSOA QUE DESEJA ADICIONAR AO BANCO -> ");
			scanf("%lld",&r.key);
			fflush(stdin);
			
			printf("\tINSIRA O NOME DA PESSOA QUE DESEJA ADICIONAR AO BANCO -> ");
			gets(r.nome);
			fflush(stdin);
			
			Add(r,p);
		}
		if(opc==3)
		{
			printf("\n\tINSIRA O CPF DA PESSOA QUE DESEJA REMOVER DO BANCO -> ");
			scanf("%lld",&CPF_Buscador);
			fflush(stdin);
			r.key=CPF_Buscador;
			Delet(r,p);
		}
		if(opc==0)
		{
			printf("\n\t     [PROGRAMA ENCERRADO!]\n\n\n\n");
		}
		if(opc>3||opc<0)
		{
			printf("\n\t[ERRO]: OPCAO NAO DISPONIVEL!\n ");
		}
		
	}
	
	

	system("pause");	
 	
	return 0;
}
