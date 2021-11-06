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
	Tree *left,*right;
};

Tree* Create();
void Insert(Tree **t,Record r);
void Search(Tree **t,Tree **aux,Record r);
void IsInTree(Tree *t,Record r);
void Remove(Tree **t,Record r);
void Antecessor(Tree **t,Tree *aux);

//Impressões

void central(Tree *t);
void pre_ordem(Tree *t);
void pos_ordem(Tree *t);

#endif
