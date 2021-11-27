#include <stdio.h>
#include <stdlib.h>

#include "debugmalloc.h"
#include "adatstruktura.h"

sentinel *init(void){
	sentinel *s = (sentinel *)malloc(sizeof(sentinel));
	Node *first = (Node *)malloc(sizeof(Node));
	Node *last = (Node *)malloc(sizeof(Node));

	first->next = last;

	s->first = first;
	s->last = last;
	return s;
}


bool search(sentinel **lista,char * word){
	int i = word[0];
	Node *iter = lista[i]->first->next;
	while (iter != lista[i]->last){
		if(strcmp(iter->data, word) == 0){
			return true;
		}
		iter = iter->next;
	}
	return false;
}

int adder(sentinel **list, char *string){
	if(search(list, string) == 0){
		int i = string[0];
		Node *iter = list[i]->first->next;
		Node *prev = list[i]->first;
		while(iter != list[i]->last){
			prev = iter;
			iter = iter->next;
		}

		Node *neue = (Node *)malloc(sizeof(Node));
		if(neue == NULL){
			return 2;
		}
		neue->data = string;
		neue->next = iter;
		prev->next = neue;
		return 0;
	}
	else{
		return 1;
	}

}



void freenode(sentinel *s){
	Node *iter = s->first->next;
	while (iter != s->last){
		Node *tmp = iter->next;
		free(iter->data);
		free(iter);
		iter = tmp;
	}
}


void freeallnodes(sentinel **lista,int size){
	for(int i = 0; i < size; i++){
		freenode(lista[i]);
		free(lista[i]->first);
		free(lista[i]->last);
		free(lista[i]);
	}

}


void deleteonenode(sentinel **lista, char *word){
	int i = word[0];
	Node *iter = lista[i]->first->next;
	Node *prev = lista[i]->first;
	while(iter != lista[i]->last){
		if(strcmp(iter->data, word) == 0){
			Node *tmp = iter->next;
			free(iter->data);
			free(iter);
			prev->next = tmp;
			return;
		}
		prev = iter;
		iter = iter->next;
	}
}



void writer(sentinel **lista, int size){
	for(int i = 0; i < size; i++){
		Node *iter = lista[i]->first->next;
		if(iter != lista[i]->last){
			printf("\n[%c]",i);
		}
		while(iter != lista[i]->last){
			printf(" %s",iter->data);
			if(iter->next->next == lista[i]->last){
				printf(",");
			}
			iter = iter->next;
		}
	}
}


void deleteallnodes(sentinel **lista, int size){
	for(int i = 0; i < size; i++){
		Node *iter = lista[i]->first->next;
		if(iter != lista[i]->last){
		}
		while(iter != lista[i]->last){
			Node *tmp = iter->next;
			deleteonenode(lista, iter->data);
			iter = tmp;
		}
	}

}
