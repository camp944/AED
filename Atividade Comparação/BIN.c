#include <stdlib.h>
#include <stdio.h>
#include "BIN.h"

BIN* Create_BIN()
{
	return NULL;
}

void Insert_BIN(BIN **t,RecordBIN r)
{
	if(*t==NULL)
	{
		*t=(BIN*)malloc(sizeof(BIN));
		(*t)->left=NULL;
		(*t)->right=NULL;
		(*t)->reg=r;
	}
	else
	{
		if(r.key<(*t)->reg.key)
		{
			Insert_BIN(&(*t)->left,r);
		}
		if(r.key>(*t)->reg.key)
		{
			Insert_BIN(&(*t)->right,r);
		}
	}
}



int Buscador_BIN(BIN **t,RecordBIN r,int verificador)
{
	if(*t==NULL)
	{
		verificador=-1;
		return verificador;
	}
	if((*t)->reg.key>r.key)
	{
		verificador=Buscador_BIN(&(*t)->left,r,verificador);
		return verificador;
		
		
	}
	if((*t)->reg.key<r.key)
	{
		verificador=Buscador_BIN(&(*t)->right,r,verificador);
		return verificador;
	}
	
	verificador=1;
	return verificador;
}

