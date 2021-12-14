#ifndef RN_H
#define RN_H

typedef struct RecordRN RecordRN;
typedef struct RN RN;

struct RecordRN{
	float key;
	int v;
};

struct RN{
	RecordRN reg;
	int cor;
	RN *left,*right;
};

RN* Create_RN();
void Insert_RN(RN **t,RecordRN r);

int Buscador_RN(RN **t,RecordRN r,int verificador);

void GiroDireitaRN(RN **t);
void GiroEsquerdaRN(RN **t);
void TrocaCor(RN **t);
int CorRN(RN *t);


#endif
