#pragma once

#include "linkedList.h"	
#include <stdio.h>
#include <stdbool.h>


typedef struct  {
	char* Name;
	char* Artist;
	char* Album;
	char* Genre;			
	char* Disc_Number;
	char* Track_Number;
	char* Year;
} Music;		

Music* infosMusique(char* ligne);

Liste ListeDeMusiques(FILE* fichier, Liste listeMusique);

Liste triListeParArg(Liste listeMusique, char* arg);


