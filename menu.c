#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ifinput.h"
#include "jsonloader.h"

int main(void){
	Sentry *lista[256];
	for (int i = 0; i < 256; i++){
		lista[i] = init();
	}


	int valasztas;

	
	do{
		writer(lista, 256);
		printf("\n\n");
		printf("1 Kereses\n");
		printf("2 Szoveg hozzaadasa\n");
		printf("3 Szoveg torlese\n");
		printf("4 Fileba kiiras\n");
		printf("5 Filebol beolvasas\n");
		printf("0 Kilepes\n");

		
	
		scanf("%d", &valasztas);
		getchar();
		char *inp;
		switch(valasztas){
			case 0:
				printf("0");
				break;

			case 1:
                                printf("Mit szeretnel a struktaraban megkeresni?\n");
                                inp = reader();
				printf("%s\n\n", inp);
				printf("%d\n",search(lista, inp));
				break;
	
	
			case 2:
				printf("Mit szeretnel a struktaraba beletenni?\n");
				inp = reader();
				adder(lista, inp);
				break;
	
			
			case 3:
                                printf("Mit szeretnel a struktarabol torolni?\n");
                                inp = reader();	
				deleter(lista, inp);
				break;
		
			case 4:
				printf("Melyik fileba akarsz kiirni?\n");
				inp = reader();
				fwriter(inp, lista, 256);
				break;
	
			case 5:
				printf("Melyik filebol akarsz beolvasni?\n");
				inp = reader();
				loader(lista, inp);
				break;
		}
	}
	while (valasztas != 0);
	freeall(lista, 256);
	return 0;	

}
