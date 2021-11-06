#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"




int main(int argc, char** argv) {
	
	Tree *arvore=Create();
	Record r;
	int valores_add[13]={12,7,13,23,11,3,4,8,10,99,1,17,9},valores_rem[4]={23,11,12,8},contador=0;
	printf("\n\t Elementos inseridos \n\t{");
	for(contador=0;contador<13;contador++)
	{
		r.key=valores_add[contador];
		Insert(&arvore,r);
		printf(" %d");
		
	}
	printf("}\n",valores_add[contador]);
	
	for(contador=0;contador<4;contador++)
	{
		printf("%d ",valores_rem[contador]);
		r.key=valores_rem[contador];
		Remove(&arvore,r);
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
	
	
	system("pause");
	return 0;
}
