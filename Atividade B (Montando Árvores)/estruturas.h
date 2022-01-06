#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define M 2
#define MM (M*2)

#define TRUE 1
#define FALSE 0

typedef struct record record;
typedef struct Pagina Pagina;

struct record
{
	int key;
};

struct Pagina
{
	int n;
	record r[MM];
	Pagina *p[MM+1];
};

Pagina* CreateTree();

void Inicia(Pagina **p);

void InsereNaPagina(Pagina *p, Pagina *pdir, record r);
void InsereFix(Pagina **p, Pagina **pr, record r, record *rr, int *Overflow);
void Insere(Pagina **p, record r);

void RemoveFix(Pagina *p, Pagina *pai, int PosPai, int *underflow);
void Antecessor(Pagina *p, int i, Pagina *pai, int *underflow);
void Remove(Pagina **p, int key, int *underflow);
void Retira(Pagina **p, int key);

void Imprime(Pagina **p, int lvl);

#endif
