#include "linkedListOfMusic.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>




					

int main(void){
  char* pathFichier = "music.csv";
    Liste listeMusique = NULL;
    Liste listeMusiqueTri = NULL;
    FILE* fichier = fopen(pathFichier, "r");
    
    listeMusique = ListeDeMusiques(fichier, listeMusique);
    // l'utilité du parametre et de definir des autres critere de tri par la suite
    listeMusiqueTri= triListeParArg(listeMusique, "Year");
    afficheListe_i(listeMusique);
    free(fichier);
}											
