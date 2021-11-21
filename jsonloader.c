#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jsonloader.h"
#include "datastructure.h"


void loader(Sentry **lista,char *name){
	FILE *fp = fopen(name, "rt");
	char stream[400] = "";

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
				char *tmp = (char *)malloc(sizeof(char*));
				tmp = touple;
				adder(lista, tmp);
			}
			helper ++;
			touple = strtok(NULL, ":");
		}
	}
	fclose(fp);
}

void fwriter(char *file, char *data){
	FILE *fp = fopen(file, "wt");
	fprintf(fp, "{%s}", data);
	fclose(fp);
	
}

/*
int main(void){
//	loader();
	writer("alma.json", "\"s\": \"schiman\"");
	return 0;
}
*/

