#include <stdio.h>

int main(void){
	
	printf("1 Kereses\n");
	printf("2 Szoveg hozzaadasa\n");
	printf("3 Szoveg torlese\n");
	printf("4 Fileba kiiras\n");
	printf("5 Filebol beolvasas\n");
	printf("0 Kilepes\n");


	int valasztas;
	scanf("%d", &valasztas);

	switch(valasztas){	
		case 0:
			printf("0");
			break;

		case 1:
			printf("1");
			break;
	
	
		case 2:
			printf("2");
			break;
	
			
		case 3:
			printf("3");
			break;
	
		case 4:
			printf("4");
			break;
	
		case 5:
			printf("5");
			break;
	}	

}
