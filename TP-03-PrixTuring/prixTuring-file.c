/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c
 Exécution
 ./prixTuring < turingWinners.txt > out.txt
 Tests
 diff out.txt turingWinners.txt
 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */

typedef struct {

	int annee;
	char* nom;
	char* sujet;
} Info;	
	
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

void readWinners(Info infos[51]) {
	
	int n =0;
	
	while (n <= 50) {

		infos[n].annee = scanLineAsInt();
		infos[n].nom = scanLine();
		infos[n].sujet = scanLine();
		n++;
	}	

	

}

void afficheWinners(Info infos[51]) {

	int n =0;

	while (n <= 49) {

		printf("%i\n",infos[n].annee);
		printf("%s\n",infos[n].nom);
		printf("%s\n",infos[n].sujet);

		n++;
	}	

	

}

void sortTuringWinnersByYear () {
	Info infos[51];
	readWinners(infos);
	int i,j,c;
	char * o;
	char * k;
	for(i=0;i<50;i++){
   	 for(j=i+1;j<50;j++){
        	if ( infos[i].annee > infos[j].annee ) {
          	  c = infos[i].annee;
          	  o = infos[i].nom;
          	  k = infos[i].sujet;
          	  infos[i].annee = infos[j].annee;
          	  infos[i].nom = infos[j].nom;
          	  infos[i].sujet = infos[j].sujet;
          	  infos[j].annee = c;
          	  infos[j].nom = o;
          	  infos[j].sujet = k ;	
          	  
        }
        }
        }
        afficheWinners (infos);
}

void addNewWinner(Info infos[] ) {

	int annee;
		char gagnants[100];
		char travaux[100];
		printf("Entrer une annee:");
		scanf("%i",&annee);
		printf("Entrer le(s) gagnants :");
		scanf("%s",gagnants);
		printf("Nature des travaux : ");
		scanf("%s",travaux);
	

	       

	//afficheWinners (infos);
}
//void fonction (FILE* f) {
//		printf("Nature des travaux :");	
//	Info infos[50];
//
//	int n =0;
//
//	while (n < 50) {
//		printf("Nature des travaux :");	
//		
//		
		
//	}	
//	afficheWinners(infos);
	
//}


int main(int argc, char* argv[]) {
	//sortTuringWinnersByYear();	
	//printf("Nature des travaux : ");	
	//char fileName[] = "turingWinners.txt";
	//FILE* f;
	//f = fopen(fileName,"r");
	//printf("Nature des travaux : ");
		
	//fonction(f);
	//if ( !strcmp(argv[1],"infosAnnee")) {
	//	infosAnnee(atoi(argv[2]));
	//}
	Info infos[51];
	readWinners( infos);
		

	for(int i=0;i<argc;i++){
		printf("%s",argv[i]);
	}
	if ( !strcmp(argv[1],"addNewWinner")) {
		
		addNewWinner(infos);
	}


	//infosAnnee(a);
	
	//afficheWinners(infos);
	

	return EXIT_SUCCESS;

}

