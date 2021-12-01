#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#define MAX 15



int main() {

	int valores_insert1[13]={10,2,7,5,3,9,16,4,11,1,6,23,14};
	int valores_insert2[11]={78,44,67,92,22,110,16,54,23,32,37};
	int valores_remove[5]={10,5,4,11,6};
	int contador1=0,contador2=0;
	Tree *t1=Create();
	Tree *t2=Create();
	

	Record r;
	for(contador1=0;contador1<13;contador1++)
	{
		r.key=valores_insert1[contador1];
		r.v=1;
		Insert_Item(&t1,r);
	}
	for(contador2=0;contador2<11;contador2++)
	{
		r.key=valores_insert2[contador2];
		r.v=1;
		Insert_Item(&t2,r);
	}
	
	rebalance(&t1);
	rebalance(&t2);


	printf("\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\t\t@                               @\n");
	printf("\t\t@           Arvore 1            @\n");
	printf("\t\t@                               @\n");
	printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\t");

	central(t1);
	printf("\n\n");
	
	printf("\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\t\t@                               @\n");
	printf("\t\t@           Arvore 2            @\n");
	printf("\t\t@                               @\n");
	printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\t");

	central(t2);
	printf("\n\n");


	printf("\n\n\t\t[REMOCAO DOS VALORES DA ARVORE 1]\n");
	for(contador2=0;contador2<5;contador2++)
	{
		
		r.key=valores_remove[contador2];
		Remove(&t1,&t1,r);

		
	}
	printf("\n\n\t\t[REMOCAO DOS VALORES DA ARVORE 2]\n\n");
	for(contador2=0;contador2<5;contador2++)
	{
		printf("\t\t");
		r.key=valores_remove[contador2];
		Remove(&t2,&t2,r);

		
	}
	rebalance(&t1);
	rebalance(&t2);

	printf("\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\t\t@                                          @\n");
	printf("\t\t@           Arvore 1 apos remocao          @\n");
	printf("\t\t@                                          @\n");
	printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\t");

	central(t1);
	printf("\n\n");
	
	printf("\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("\t\t@                                          @\n");
	printf("\t\t@           Arvore 2 apos remocao          @\n");
	printf("\t\t@                                          @\n");
	printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\t");

	central(t2);
	printf("\n\n");
	

	system("pause");
	return 0;
}
