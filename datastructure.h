#ifndef ADATSTRUKTURA_H

#define ADATSTRUKTURA_H

#include <stdbool.h>

typedef struct Node{
        char *data;
        struct Node *next;
}Node;

typedef struct Sentry{
        struct Node *first;
        struct Node *last;
}Sentry;

Sentry *init(void);
int adder(Sentry **list, char *string);
void freeer(Sentry *s);
void freeall(Sentry **lista, int meret);
bool search(Sentry **lista, char *word);
void deleter(Sentry **lista, char *word);
void writer(Sentry **lista, int size);

#endif
