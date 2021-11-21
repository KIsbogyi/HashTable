#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jsonloader.h"
#include "datastructure.h"


void loader(Sentry **lista,char *name){
	FILE *fp = fopen(name, "rt");
	int size = 2;						//first char + \0
	char *stream = (char *)malloc(size * sizeof(char));

	char c = fgetc(fp);
	if (c != '{'){
		stream[0] = c;
		stream[0+1] = '\0';
	}
	while (1){
		c = fgetc(fp);
		if (feof(fp)){
			break;
		}
		if (c != '{' && c != '}' && c != '"' && c != ' ' && c != '\n'){
			size ++;
			stream = (char *)realloc(stream, size * sizeof(char));
			stream[strlen(stream)] = c;
			stream[strlen(stream)+1] = '\0';
		}
	}


	char **data = (char**)malloc(100 * sizeof(char*));
	int counter = 0;
	char *token = strtok(stream, ",");

	while(token != NULL){
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
}

void fwriter(char *file, Sentry **lista, int size){
	char *test = (char *)malloc(sizeof(char)*2);
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
	FILE *fp = fopen(file, "wt");
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
