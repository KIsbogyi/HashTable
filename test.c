#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "debugmalloc.h"
typedef struct ListaElem{
	char key;
	struct ListaElem *kov, *elozo;
	struct LordHelmet *kezdo, *vegzo;
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

	l->kezdo = lo1;
	l->vegzo = lo2;
}


void kiir(Strazsa *s){
	ListaElem *mozgo = s->elso->kov;
	while(mozgo != s->vege){
		printf("[%c] ", mozgo->key);
		LordHelmet *futtato = mozgo->kezdo->kov;
		while(futtato != mozgo->vegzo){
			printf("%s, ", futtato->szoveg);
			futtato = futtato->kov;
		}
		mozgo = mozgo->kov;
	}
}

void insertLordHelmet(ListaElem *s, char *szo){
        LordHelmet *mozgo = s->kezdo->kov;
        while(mozgo != s->vegzo && mozgo->szoveg != szo){
                mozgo = mozgo->kov;
        }

        LordHelmet *uj = (LordHelmet *)malloc(sizeof(LordHelmet));
        uj->szoveg = szo;
        uj->elozo = mozgo->elozo;
        uj->kov = mozgo;

        mozgo->elozo->kov = uj;
        mozgo->elozo = uj;

}


void test(Strazsa *s, char *szo){
	ListaElem *mozgo = s->elso->kov;
	while(mozgo != s->vege && mozgo->key < szo[0]){
		mozgo = mozgo->kov;
	}
	
	if((mozgo->key) != szo[0]){
		ListaElem *uj = (ListaElem *)malloc(sizeof(ListaElem));
		uj->key = szo[0];
		uj->elozo = mozgo->elozo;
		uj->kov = mozgo;

	
		initLordHelmet(uj);
		insertLordHelmet(uj, szo);

		mozgo->elozo->kov = uj;
		mozgo->elozo = uj;
	}
	else{
	insertLordHelmet(mozgo,szo);
	}

}

void szabaditsfel(Strazsa *s){
	ListaElem *mozgo = s->elso->kov;
	while (mozgo != s->vege){
		LordHelmet *futtato = mozgo->kezdo->kov;
		while(futtato != mozgo->vegzo){
			LordHelmet *temp = futtato->kov;
			free(futtato);
			futtato = temp;
		}
		free(mozgo->kezdo);
		free(mozgo->vegzo);
		ListaElem *tmp = mozgo->kov;
		free(mozgo);
		mozgo = tmp;
	}
	free(s->elso);
	free(s->vege);
}

bool megkeres(Strazsa *s, char *szo){
        ListaElem *mozgo = s->elso->kov;
        while(mozgo != s->vege){
		if (mozgo->key == szo[0]){
	       		LordHelmet *futtato = mozgo->kezdo->kov;
                	while(futtato != mozgo->vegzo){
				if (futtato->szoveg == szo){
					return true;
				}
                        	futtato = futtato->kov;
                	}
		}
                mozgo = mozgo->kov;
        }
	return false;
}


void keytorlo(Strazsa *s, char *szo){
	ListaElem *mozgo = s->elso->kov;
	ListaElem *tmp;
        while(mozgo != s->vege){
		if (mozgo->key == szo[0]){
	       		LordHelmet *futtato = mozgo->kezdo->kov;
			if (futtato == mozgo->vegzo){
				mozgo->elozo->kov = mozgo->kov;
				mozgo->kov->elozo = mozgo->elozo;
				printf("%c", mozgo->key);
				tmp = mozgo->kov;
				free(mozgo->vegzo);
				free(mozgo->kezdo);	
				free(mozgo);
			}
			else{
				tmp = mozgo->kov;
			}
		}
		else{
		tmp = mozgo->kov;

		}
                mozgo = tmp;
        }
}


void torol(Strazsa *s, char *szo){
        ListaElem *mozgo = s->elso->kov;
        while(mozgo != s->vege){
		if (mozgo->key == szo[0]){
	       		LordHelmet *futtato = mozgo->kezdo->kov;
                	while(futtato != mozgo->vegzo){
				if (futtato->szoveg == szo){
					futtato->elozo->kov = futtato->kov;
					futtato->kov->elozo = futtato->elozo;
					free(futtato);
					break;
				}
                        	futtato = futtato->kov;
                	}
		}
                mozgo = mozgo->kov;
        }
}


void deleter(Strazsa *s, char *szo){
	torol(s, szo);
	keytorlo(s, szo);
}

int main(void){
	Strazsa s;
	init(&s);
	test(&s, "geza");
	test(&s, "alma");
	test(&s, "agyag");
	test(&s, "kapa");
	test(&s, "kari");
	test(&s, "alpesi");		//TODO: kihasznalni a duplan lancolt listat
	test(&s, "gagyi"); 		//TODO: abc sorrend a vödrös hashben
	kiir(&s);			//TODO: ","-t kivenni a felsorolas vegen
	deleter(&s, "geza");
	deleter(&s, "gagyi");
	printf("\n");
	kiir(&s);
	printf("\n%d", megkeres(&s, "kari")); 
	szabaditsfel(&s);
	return 0;
}
