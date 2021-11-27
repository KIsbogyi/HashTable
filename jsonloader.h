#ifndef JSONLOADER_H

#define JSONLOADER_H

#include "adatstruktura.h"
int loader(sentinel **lista,char *name);
int fwriter(char *file, sentinel **lista, int size);
int freader(char **stream, char *name);
int dataprocession(char *stream, sentinel **lista);
#endif
