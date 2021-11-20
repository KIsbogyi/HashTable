#include <stdio.h>
#include <stdlib.h>


#include "ifinput.h"

char *reader(void){
	char *word = (char *)malloc(sizeof(char *)); 
	char tmp;
	int counter = 1;
	
	do{
			scanf("%c", &tmp);
			if(tmp != '\n'){
			word = (char *)realloc(word, counter * sizeof(char *));		//TODO van e max input
											//mi a vélemeny a relloc egyenkentrol
			word[counter-1] = tmp;
			counter ++;
			}
		
	}
	while(tmp != '\n');
	word[counter-1] = '\0';
	return word;
}
