#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugmalloc.h"
#include "ifinput.h"
#include "jsonloader.h"

int main(void){
	bool mentvevane = true;
	sentinel *lista[256];
	char megallit;
	for (int i = 0; i < 256; i++){
		lista[i] = init();
	}


	int valasztas;
	bool display_content = true;


	do{
		system("@cls || clear");
		printf("_________\n");
		printf("< Hashmap>\n");
		printf("---------\n");					//source: https://github.com/tnalpgge/rank-amateur-cowsay
		printf("        \\   ^__^\n");
		printf("         \\  (oo)\\_______\n");
		printf("            (__)\\       )\\/\\\n");
		printf("                ||----w |\n");
		printf("                ||     ||\n");			/* eredeti program cowsay, windowsosok,
									   linuxon nem letoltottek miatt nem
									   hasznalom a scriptet, csak lemasoltam*/
		if(display_content){
			writer(lista, 256);
		}
		printf("\n\n");
		printf("1 Kereses\n");
		printf("2 Szoveg hozzaadasa\n");
		printf("3 Szoveg torlese\n");
		printf("4 Fileba kiiras\n");
		printf("5 Filebol beolvasas\n");
		printf("6 Osszes torlese\n");
		printf("7 Kiiras ki/bekapcsolasa\n");
		printf("0 Kilepes\n");



		scanf("%d", &valasztas);
		getchar();
		system("@cls || clear");
		char *inp;
		switch(valasztas){
			case 0:
				if(mentvevane == false){
					printf("biztos ki akarsz lepni?[N]/y\n");
					inp = reader();
					if(strcmp(inp, "y") != 0 && strcmp(inp, "Y")  != 0){
						valasztas = 9;
					}
					free(inp);

				}
				break;

			case 1:
                                printf("Mit szeretnel a struktaraban megkeresni?\n");
                                inp = reader();
				if(strlen(inp) != 0){
					printf("%s\n",search(lista, inp) ? "Van benne!" : "Nincs benne!");
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c", &megallit);
				}
				free(inp);
				break;


			case 2:
				printf("Mit szeretnel a struktaraba beletenni?\n");
				inp = reader();
				if(strlen(inp) != 0){
					int error = adder(lista, inp);
					switch(error){
						case 0:
							printf("A felvetel sikerult!\n");
							mentvevane = false;
							break;
						case 1:
							perror("A megadott szoveg mar szerepel.\n");
							free(inp);
							break;
						case 2:
							perror("Memoriafoglalasi hiba.\n");
							free(inp);
							break;
					}
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c", &megallit);
				}
				break;


			case 3:
                                printf("Mit szeretnel a struktarabol torolni?\n");
                                inp = reader();
				if(strlen(inp) != 0){
					if(search(lista, inp) == true){
						deleteonenode(lista, inp);
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
					scanf("%c", &megallit);
				}
				free(inp);
				break;

			case 4:
				printf("Melyik fileba akarsz kiirni?\n");
				inp = reader();
				if(strlen(inp) != 0){
					int error = fwriter(inp, lista, 256);{
						switch(error){
							case 0:
								printf("A kiiras  sikerult!\n");
								mentvevane = true;
								break;
							case 1:
								perror("File megnyitasi hiba!\n");
								break;
							case 2:
								perror("Memoriafoglalasi hiba!\n");
								break;
						}
					}
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c", &megallit);
				}
				free(inp);
				break;

			case 5:
				printf("Melyik filebol akarsz beolvasni?\n");
				inp = reader();
				if(strlen(inp) != 0){
					int error = loader(lista, inp);
					switch(error){
						case 0:
							printf("A beolvasas sikerult!\n");
							mentvevane = false;
							break;
						case 1:
							perror("File megynyitasi hiba!\n");
							break;
						case 2:
							perror("Memoriafoglalasi hiba!\n");
							break;
					}
					printf("Nyomd meg az (ENTER)-t a tovabblepeshez\n");
					scanf("%c", &megallit);
				}
				free(inp);
				break;
			case 6:
				printf("Tenyleg ki akarsz torolni mindent?[N]/y\n");
				inp = reader();
				if(strlen(inp) != 0){
					if(strcmp(inp, "y") == 0){
						deleteallnodes(lista, 256);
						printf("Osszes adat torolve!\n");
						printf("Nyommd meg az (ENTER)-t a tovabblepeshez\n");
						scanf("%c",&megallit);
					}
				}
				free(inp);
				break;
			case 7:
				if(display_content){
					printf("Ki akarod kapcsolni a kiirast?[N]/y\n");
					inp = reader();
					if(strcmp(inp, "y") == 0){
						if(strlen(inp) != 0){
							display_content = false;
						}
					}

				}
				else{
					printf("Be akarod kapcsolni a kiirast?[N]/y\n");
					inp = reader();
					if(strcmp(inp, "y") == 0){
						if(strlen(inp) != 0){
							display_content = true;
						}
					}

				}
				free(inp);
				break;
			default:
				break;
		}
	}
	while (valasztas != 0);
	freeallnodes(lista, 256);
	return 0;
}
