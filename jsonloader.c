#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jsonloader.h"
#include "datastructure.h"


void loader(Sentry **lista,char *name){
	sprintf(name, "%s.json",name);
	FILE *fp = fopen(name, "rt");
	if(fp == NULL){
		perror("Nem sikerult a file beolvasasa ");
	}
	else{
	int size = 2;						//first char + \0
	char *stream = (char *)malloc(size * sizeof(char));
	if(stream == NULL){
		printf("A memoriafoglalas nem sikerult!\n");
		return;
	}
	sprintf(stream, "%s", "");

	char c = fgetc(fp);
	if (c != '{'){
		printf("A file rossz formatumu!\n");
		return;
	}
	while (1){
		c = fgetc(fp);
		if (feof(fp)){
			break;
		}
		if (c != '{' && c != '}' && c != '"' && c != ' ' && c != '\n'){
			size ++;
			stream = (char *)realloc(stream, size * sizeof(char));
			if(stream == NULL){
				printf("A memoriafoglalas nem sikerult!\n");
				return;
			}
			int len = strlen(stream);
			stream[len] = c;
			stream[len+1] = '\0';
		}
	}


	char **data = (char **)malloc(1 * sizeof(char*));		
	if(data == NULL){
		printf("A memoriafoglalas nem sikerult!\n");
		return;
	}
	int counter = 0;
	char *token = strtok(stream, ",");

	while(token != NULL){
		data = (char **)realloc(data, (counter+1)*sizeof(char*));
		data[counter] = token;
		counter ++;
		token = strtok(NULL, ",");

	}


	for(int i = 0; i < counter; i++){
		char *touple = strtok(data[i], ":");
		int helper = 0;
		while (touple != NULL){
			if (helper % 2 == 0 ){
			}
			else{
				char *tmp;
				tmp = touple;
				adder(lista, tmp);

			}
			helper ++;
			touple = strtok(NULL, ":");
		}
	}
	fclose(fp);
	printf("A file beolvasasa sikerult!\n");
	}
}

void fwriter(char *file, Sentry **lista, int size){
	char *test = (char *)malloc(sizeof(char)*2);
	if(test == NULL){
		printf("Memoriafoglalas nem sikerult!\n");
	}
	sprintf(test, "%s", "{");
	for(int i = 0; i < size; i++){
		Node *iter = lista[i]->first->next;
		while(iter != lista[i]->last){
			char *tmp = (char *)malloc(sizeof(char)*(strlen(iter->data)+10));
			sprintf(tmp, "\"%c\": \"%s\", ",iter->data[0], iter->data);
			test = (char *)realloc(test, sizeof(char)*(strlen(test)+1+strlen(tmp)));
			strcat(test, tmp);
			iter = iter->next;
		}
	}

	test[strlen(test)-2] = '}';
	sprintf(file, "%s.json", file);	
	FILE *fp = fopen(file, "wt");
	if(fp == NULL){
		perror("Nem sikerult megnyitni a filet!\n");
	}
	fprintf(fp, "%s", test);
	fclose(fp);

}


/*
void fwriter(char *file, char *data){
	FILE *fp = fopen(file, "wt");
	fprintf(fp, "{%s}", data);
	fclose(fp);

}

int main(void){
//	loader();
	writer("alma.json", "\"s\": \"schiman\"");
	return 0;
}
*/
