#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ifinput.h"
#include "jsonloader.h"

int main(void){
	bool mentvevane = true;
	Sentry *lista[256];
	for (int i = 0; i < 256; i++){
		lista[i] = init();
	}


	int valasztas;

	
	do{
		system("clear");
		system("cowsay Hashmap");
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
		system("clear");
		char *inp;
		switch(valasztas){
			case 0:
				if(mentvevane == false){
					char kilepes;
					printf("biztos ki akarsz lepni?[N]/y\n");
					scanf("%c", &kilepes);
					if(kilepes != 'y'){
						valasztas = 9;
					}
				}
				break;

			case 1:
                                printf("Mit szeretnel a struktaraban megkeresni?\n");
                                inp = reader();
				if(strlen(inp) != 0){
					printf("%s\n",search(lista, inp) ? "Van benne!" : "Nincs benne!");
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c");
				}
				break;
	
	
			case 2:
				printf("Mit szeretnel a struktaraba beletenni?\n");
				inp = reader();
				if(strlen(inp) != 0){
					int error = adder(lista, inp);
					switch(error){
						case 0:
							printf("A felvetel sikerult!\n"); //TODO fileirasnal returnöljön erteket ha hiba van 
							mentvevane = false;
							break;
						case 1:
							printf("A megadott szoveg mar szerepel.\n");
							break;
						case 2:
							printf("Memoriafoglalasi hiba.\n");
							break;
					}
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c");
				}
				break;
	
			
			case 3:
                                printf("Mit szeretnel a struktarabol torolni?\n");
                                inp = reader();
				if(strlen(inp) != 0){
					if(search(lista, inp) == true){	
						deleter(lista, inp);
						if(search(lista, inp) == false){
							printf("Sikeres a torles!\n");
							mentvevane = true;
						}
						else{
							printf("Sikertelen a torles\n");
						}
					}
					else{
						printf("Nincs bennt a megadott adat amiatt nem tudod torolni!\n");
					}
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c");
				}
				break;
		
			case 4:
				printf("Melyik fileba akarsz kiirni?\n");
				inp = reader();
				if(strlen(inp) != 0){
					fwriter(inp, lista, 256);
					mentvevane = true;
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c");
				}
				break;
	
			case 5:
				printf("Melyik filebol akarsz beolvasni?\n");
				inp = reader();
				if(strlen(inp) != 0){
					loader(lista, inp);
					mentvevane = false;
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c");
				}
				break;
		}
	}
	while (valasztas != 0);
	freeall(lista, 256);
	return 0;	

}
