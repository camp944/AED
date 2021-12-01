#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
	int v;
};

struct Tree{
	Record reg;
	int peso;
	Tree *left,*right;
};

Tree* Create();
void Insert_Item(Tree **t,Record r);
void Search(Tree **t,Tree **aux,Record r);
void IsInTree(Tree *t,Record r);
void Remove(Tree **t,Tree **pai,Record r);
void Antecessor(Tree **t,Tree *aux);

//Impress�es

void central(Tree *t);
void pre_ordem(Tree *t);
void pos_ordem(Tree *t);


void rebalance(Tree **t);
int GetPeso(Tree **t);
int GetMaxPeso(int left,int right);

void GiroDireita(Tree **t);
void GiroDuploDireita(Tree **t);
void GiroEsquerda(Tree **t);
void GiroDuploEsquerda(Tree **t);

#endif
