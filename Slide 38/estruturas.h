#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#define MAX 100

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	double key;
	char word[MAX];
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

double Get_word_value(char word[MAX],char caracteres_m[27],char caracteres_M[27],int primos[26]);

//Impressões

void central(Tree *t);
void pre_ordem(Tree *t);
void pos_ordem(Tree *t);

#endif
