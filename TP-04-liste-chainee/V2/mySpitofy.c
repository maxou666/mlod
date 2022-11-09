#include "linkedListOfMusic.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void afficheElement(Element e) {
	printf("%s ",((Music*) e)->Name);
	printf("%s ",((Music*) e)->Artist);
	printf("%s ",((Music*) e)->Album);
	printf("%s ",((Music*) e)->Genre);
	printf("%i ",((Music*) e)->Disc_Number);
	printf("%i ",((Music*) e)->Track_Number);
	printf("%i ",((Music*) e)->Year);
}

					

int main(void){
    Music  musique;
    Liste l=NULL;	
     musique.Name="tr";
    musique.Artist="tr";
    musique.Album="tr";
    musique.Genre="tr";			
    musique.Disc_Number=2;
    musique.Track_Number=1;
    musique.Year=45	;
    l = creer( &musique);
    afficheListe_i(l);		
    //afficheElement(&musique);	
}										
