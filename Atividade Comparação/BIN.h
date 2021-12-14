#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct RecordBIN RecordBIN;
typedef struct BIN BIN;

struct RecordBIN{
	float key;
	int v;
};

struct BIN{
	RecordBIN reg;
	BIN *left,*right;
};

BIN* Create_BIN();
void Insert_BIN(BIN **t,RecordBIN r);
int Buscador_BIN(BIN **t,RecordBIN r,int verificador);



#endif
