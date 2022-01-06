#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"



int main() {
	
	
	int i,Valores_to_Insert[5]={01,33,99,54,13},Valores_to_Remove[7]={55,91,07,01,9,40,80};
	Pagina *p=CreateTree();
	record r;
	
	Inicia(&p);//VALORES INICIAIS SÃO INSERIDOS {7,9,10,12,22,31,40,55,61,74,80,85,91,98}
	printf("\n\n\t[INICIO]\n\n");
	Imprime(&p,0);
	
	printf("\n\n\t[INSERINDO VALORES]");
	
	for(i=0;i<5;i++)//OS NOVOS VALORES SAO INSERIDOS {01,33,99,54,13}
	{
		r.key=Valores_to_Insert[i];
		Insere(&p,r);
		printf("\n\n\n[VALOR %d INSERIDO]\n",r.key);
		Imprime(&p,0);
	}
	
	printf("\n\n\t[REMOVENDO VALORES]");
	for(i=0;i<7;i++)//OS NOVOS VALORES SAO INSERIDOS {01,33,99,54,13}
	{
	
		Retira(&p,Valores_to_Remove[i]);
		printf("\n\n\n[VALOR %d REMOVIDO]\n",Valores_to_Remove[i]);
		Imprime(&p,0);
	}
	
	
	return 0;
}
