#include "linkedListOfMusic.h"	
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void afficheElement(Element e) {
	if (e!=NULL) {
		printf("%s ",((Music*) e)->Name);
		printf("%s ",((Music*) e)->Artist);
		printf("%s ",((Music*) e)->Album);
		printf("%s ",((Music*) e)->Genre);
		printf("%s ",((Music*) e)->Disc_Number);
		printf("%s ",((Music*) e)->Track_Number);
		printf("%s ",((Music*) e)->Year);
	}
}

void detruireElement(Element e)
{
    Music* musique = (Music*)e;
    free(musique);
}


bool equalsElement(Element e1, Element e2)
{
	return !memcmp(e1, e2, sizeof(Music));
}


Music* infosMusique(char* ligne){
    Music* musique = malloc(sizeof(Music));
    char *mot, *ligne_dup = strdup(ligne);
    mot = strsep(&ligne_dup, ",");
    musique->Name = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->Name, mot);

    mot = strsep(&ligne_dup, ",");
    musique->Artist = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->Artist, mot);

    mot = strsep(&ligne_dup, ",");
    musique->Album = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->Album, mot);

    mot = strsep(&ligne_dup, ",");
    musique->Genre = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->Genre, mot);

    mot = strsep(&ligne_dup, ",");
    musique->Disc_Number = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->Disc_Number, mot);

    mot = strsep(&ligne_dup, ",");
    musique->Track_Number = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->Track_Number, mot);

    mot = strsep(&ligne_dup, ",");
    musique->Year = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->Year, mot);
    
    			
    return musique;
}

Liste ListeDeMusiques(FILE* fichier, Liste listeMusique)
{
   				
    		
    while(!feof(fichier))
    {
        char* ligne = calloc(255, sizeof(char));
        fgets(ligne, 255, fichier);

       
        if(strlen(ligne) == 0)
        {
            
            return listeMusique;
        }
        
        listeMusique = ajoutFin_i(infosMusique(ligne), listeMusique);
        free(ligne);
    }
}


Liste triListeParArg(Liste listeMusique, char* arg){
	
    if(estVide(listeMusique)){
        return NULL;
    }

    Liste precedent = listeMusique;
    Liste suivant = NULL;

   
    while(!estVide(precedent)){
        suivant = precedent->suiv;

      
        while(!estVide(suivant))
        {	
            if(!strcmp(arg,"Year")) {
            if(atoi(((Music*)(suivant->val))->Year) < atoi(((Music*)(precedent->val))->Year))
            {
               
                void* tmp;
                tmp = suivant->val;
                suivant->val = precedent->val;
                precedent->val = tmp;
               			
            }
            }
            			
            suivant = suivant->suiv;
        }
        precedent = precedent->suiv;
    }
    return listeMusique;
}
