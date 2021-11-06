#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#define MAX 100

int main() {
	
	
	char caracteres_m[27]={"abcdefghijklmnopqrstuvwxyz"},caracteres_M[27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"},palavra[MAX];
	int valor_caract[26]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}, contador_palavras,opc=1;
	Record r;
	Tree *arvore=Create(),*aux;
	strcpy(palavra," ");
	
	for(contador_palavras=0;contador_palavras<30;contador_palavras++)
	{
		while(strlen(palavra)<4)
		{	printf("Insira a palavra %d (minimo de 3 letras) -> ",contador_palavras+1);
			gets(palavra);
		}
		r.key=Get_word_value(palavra,caracteres_m,caracteres_M,valor_caract);
		r.v=1;
		strcpy(r.word,palavra);
		Insert(&arvore,r);
		strcpy(palavra," ");	
	}
	
	
	printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\t@                             @\n");
	printf("\t@           Pre Ordem         @\n");
	printf("\t@                             @\n");
	printf("\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	
	printf("\n\t Elementos da arvore \n\t{");
	pre_ordem(arvore);
	printf("}\n");

	
	
	
	printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\t@                             @\n");
	printf("\t@           Pos Ordem         @\n");
	printf("\t@                             @\n");
	printf("\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	
	printf("\n\t Elementos da arvore \n\t{");
	pos_ordem(arvore);
	printf("}\n");
	
	
	
	printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\t@                             @\n");
	printf("\t@            Central          @\n");
	printf("\t@                             @\n");
	printf("\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	
	printf("\n\t Elementos da arvore \n\t{");
	central(arvore);
	printf("}\n");
	
	while(opc!=0)
	{
		scanf("%d",&opc);
		
		if(opc==1)
		{
			strcpy(palavra," ");
			printf("\n\nInsira a palavra de busca (minimo de 3 letras) -> ");
			while(strlen(palavra)<4)
			{
				printf("\n\nInsira a palavra de busca -> ");
				gets(palavra);
			}
			r.key=Get_word_value(palavra,caracteres_m,caracteres_M,valor_caract);
			strcpy(r.word,palavra);
			Search(&arvore,&aux,r);
		}
	}
	
	
	system("pause");
	
	return 0;
}
