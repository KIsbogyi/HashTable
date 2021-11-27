#ifndef TEST_H

#define TEST_H

#include <stdbool.h>



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

void init(Strazsa *s);
void initLordHelmet(ListaElem *l);
void kiir(Strazsa *s);
void insertLordHelmet(ListaElem *s, char *szo);
void test(Strazsa *s, char *szo);
void szabaditsfel(Strazsa *s);
bool megkeres(Strazsa *s, char *szo);
void keytorlo(Strazsa *s, char *szo);
void torol(Strazsa *s, char *szo);
void deleter(Strazsa *s, char *szo);


#endif
