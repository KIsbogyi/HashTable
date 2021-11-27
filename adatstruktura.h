#ifndef ADATSTRUKTURA_H

#define ADATSTRUKTURA_H

#include <stdbool.h>

typedef struct Node{
        char *data;
        struct Node *next;
}Node;

typedef struct sentinel{
        struct Node *first;
        struct Node *last;
}sentinel;

sentinel *init(void);
int adder(sentinel **list, char *string);
void freenode(sentinel *s);
void freeallnodes(sentinel **lista, int meret);
bool search(sentinel **lista, char *word);
void deleteonenode(sentinel **lista, char *word);
void writer(sentinel **lista, int size);
void deleteallnodes(sentinel **lista, int size);
#endif
