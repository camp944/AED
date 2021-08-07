#ifndef BASE_H
#define BASE_H
#define MAX 100

typedef struct Item Item;
typedef struct Item1C Item1C;
typedef struct Item2A Item2A;
typedef struct Bloco Bloco;
typedef struct Bloco1C Bloco1C;
typedef struct Bloco2A Bloco2A;


struct Item{
	int val;
};

struct Item1C{
	char caract[MAX];
	
};

struct Item2A{
	char caractere;
};

struct Bloco{
	Item dado;
	Bloco *prox;
};

struct Bloco1C{
	Item1C dado;
	Bloco1C *prox;
};

struct Bloco2A{
	Item2A dado;
	Bloco2A *prox;
};

#endif
