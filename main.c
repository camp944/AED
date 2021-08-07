#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"
#include "ex2.h"
#include "ex3.h"

void menu()
{
	printf("\n\n\n");
	printf("      ##############################################\n");
	printf("      #                                            #\n");
	printf("      #                    MENU                    #\n");
	printf("      #                                            #\n");
	printf("      #          RESOLVER O EXERCICIO 1 -> 1       #\n");
	printf("      #        	 RESOLVER O EXERCICIO 2 -> 2       #\n");
	printf("      #          RESOLVER O EXERCICIO 3 -> 3       #\n");
	printf("      #           ENCERRAR O PROGRAMA -> 0         #\n");
	printf("      #                                            #\n");
	printf("      ##############################################\n\n\n");
}

int main() {
	
	int selectEx,selectLet;
	
	selectEx=1;
	selectLet=1;
	
	while(selectEx!=0)
	{
	 	menu();
	 	printf("      ->");
		scanf("%d",&selectEx);
		
		selectLet=1;
		
		if(selectEx==0)
		{
			break;
		}
		if(selectEx==1)
		{
			while(selectLet!=0)
			{
				menuEx1();
				printf("      ->");
				scanf("%d",&selectLet);
				
				if(selectLet==0)
				{
					break;
				}
				if(selectLet==1)
				{
					resolve1A();
				}
				if(selectLet==2)
				{
					resolve1B();
				}
				if(selectLet==3)
				{
					resolve1C();
				}
			}
		}
		if(selectEx==2)
		{
			while(selectLet!=0)
			{
				menuEx2();
				printf("      ->");
				scanf("%d",&selectLet);
				
				if(selectLet==0)
				{
					break;
				}
				if(selectLet==1)
				{
					resolve2A();
				}
				if(selectLet==2)
				{
					resolve2B();
				}
				if(selectLet==3)
				{
					resolve2C();
				}
			}			
		}
		if(selectEx==3)
		{
			while(selectLet!=0)
			{
				menuEx3();
				printf("      ->");
				scanf("%d",&selectLet);
				
				if(selectLet==0)
				{
					break;
				}
				if(selectLet==1)
				{
					resolve3A();
				}
				if(selectLet==2)
				{
					resolve3B();
				}
			}
		}
	}
		
	return 0;
}
