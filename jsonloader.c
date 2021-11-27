#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "debugmalloc.h"
#include "jsonloader.h"

typedef struct ret{
	int error;
	char *stream;
}ret;



int freader(char **string, char *name) {
    strcat(name, ".json");
    FILE *fp = fopen(name, "rt");
    if (fp == NULL) {
        return 1;
    } else {
        int size = 2;           					//first char + \0
	char *stream = (char *)malloc(2 * sizeof(char));
        if (stream == NULL) {
            return 2;
        }
        sprintf(stream, "%s", "");

        char c = fgetc(fp);
        if (c != '{') {
            return 1;
        }
        while (1) {
            c = fgetc(fp);
            if (feof(fp)) {
                break;
            }
            if (c != '{' && c != '}' && c != '"' && c != ' ' && c != '\n') {
                size++;
                stream = (char *) realloc(stream, size * sizeof(char));
                if (stream == NULL) {
                    return 2;
                }
                int len = strlen(stream);
                stream[len] = c;
                stream[len + 1] = '\0';
            }
        }
        fclose(fp);
    	*string = stream; 
    }
    return 0;
}

int dataprocession(char *stream, sentinel **lista){
	char **data = (char **)malloc(1 * sizeof(char*));
	if(data == NULL){
		return 2;
	}
	int counter = 0;
	char *token = strtok(stream, ",");

	while(token != NULL){
		data = (char **)realloc(data, (counter+1)*sizeof(char*));
		if(data == NULL){
			return 2;
		}
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
				char *temp = (char *)malloc(sizeof(char)*strlen(touple)+1);
				strcpy(temp, touple);
				adder(lista, temp);

			}
			helper ++;
			touple = strtok(NULL, ":");
		}
	}
	free(stream);
	free(data);
	return 0;

}

int loader(sentinel **lista, char *name){
	char **stream = (char **)malloc(sizeof(char*)*1);
	int error;
	error = freader(stream, name);
	error = dataprocession(*stream, lista);
	free(stream);
	return error;
}

int fwriter(char *file, sentinel **lista, int size){
	char *word = (char *)malloc(sizeof(char)*2);
	if(word == NULL){
		return 2;
	}
	sprintf(word, "%s", "{");
	for(int i = 0; i < size; i++){
		Node *iter = lista[i]->first->next;
		while(iter != lista[i]->last){
			char *tmp = (char *)malloc(sizeof(char)*(strlen(iter->data)+10));
			if(tmp == NULL){
				return 2;
			}
			sprintf(tmp, "\"%c\": \"%s\", ",iter->data[0], iter->data);
			word = (char *)realloc(word, sizeof(char)*(strlen(word)+1+strlen(tmp)));
			if(word == NULL){
				return 2;
			}
			strcat(word, tmp);
			iter = iter->next;
			free(tmp);
		}
	}

	word[strlen(word)-2] = '}';
	strcat(file, ".json");
	FILE *fp = fopen(file, "wt");
	if(fp == NULL){
		return 1;
	}
	fprintf(fp, "%s", word);
	free(word);
	fclose(fp);
	return 0;

}


