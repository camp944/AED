#ifndef AVL_H
#define AVL_H

typedef struct RecordAVL RecordAVL;
typedef struct AVL AVL;

struct RecordAVL{
	float key;
	int v;
};

struct AVL{
	RecordAVL reg;
	int peso;
	AVL *left,*right;
};

AVL* Create_AVL();
void Insert_AVL(AVL **t,RecordAVL r);
int Buscador_AVL(AVL **t,RecordAVL r,int verificador);

//Impress�es
void pos_ordem(AVL *t);

int GetPeso(AVL **t);
int GetMaxPeso(int left,int right);

void GiroDireita(AVL **t);
void GiroDuploDireita(AVL **t);
void GiroEsquerda(AVL **t);
void GiroDuploEsquerda(AVL **t);

#endif
