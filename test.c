#include <stdio.h>
#include <stdlib.h>

#include "debugmalloc.h"
typedef struct ListaElem{
	char key;
	struct ListaElem *kov, *elozo;
	struct LordHelmet *elso, *vege;
}ListaElem;

typedef struct LordHelmet{
	char *szoveg;
	struct LordHelmet *kov, *elozo;
}LordHelmet;



typedef struct Strazsa{
	ListaElem *elso;
	ListaElem *vege;
}Strazsa;


void init(Strazsa *s){
	ListaElem *l1 = (ListaElem *)malloc(sizeof(ListaElem));
	ListaElem *u1 = (ListaElem *)malloc(sizeof(ListaElem));

	l1->kov = u1;
	u1->elozo = l1;

	s->elso = l1;
	s->vege = u1;
}

void initLordHelmet(ListaElem *l){
	LordHelmet *lo1 = (LordHelmet *)malloc(sizeof(ListaElem));
	LordHelmet *lo2 = (LordHelmet *)malloc(sizeof(ListaElem));
	
	lo1->kov = lo2;
	lo2->elozo = lo1;

	l->elso = lo1;
	l->vege = lo2;
}


void kiir(Strazsa *s){
	ListaElem *mozgo = s->elso->kov;
	while(mozgo != s->vege){
		printf("[%c]\n", mozgo->key);
		mozgo = mozgo->kov;
	}
}

void test(Strazsa *s, char *szo){
	ListaElem *mozgo = s->elso->kov;
	while(mozgo != s->vege && mozgo->key < szo[0] ){
		mozgo = mozgo->kov;
	}
	
	ListaElem *uj = (ListaElem *)malloc(sizeof(ListaElem));
	uj->key = szo[0];
	uj->kov = mozgo->elozo;
	uj->kov = mozgo;


	mozgo->elozo->kov = uj;

}

void szabaditsfel(Strazsa *s){
	ListaElem *mozgo = s->elso->kov;
	while (mozgo != s->vege){
		ListaElem *tmp = mozgo->kov;
		free(mozgo);
		mozgo = tmp;
	}
	free(s->elso);
	free(s->vege);
}

int main(void){
	Strazsa s;
	init(&s);
	test(&s, "alma");
	test(&s, "kapa");
	kiir(&s);
	szabaditsfel(&s);
	return 0;
}
