#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CHUNK_SIZE_MAX 5

struct  chaine{
   struct chaine* next;
   int chunkSize;
   char chunk [CHUNK_SIZE_MAX];
}; 

typedef struct chaine Chaine;

typedef Chaine* String;



String string_new ( char* mot) {
	int n=0;
	int a=0;
	int moins =0;
	String com = malloc(sizeof(Chaine));
	String second = malloc(sizeof(Chaine));
	for (int i =0; i< strlen(mot);i++){
	   
	   if (a == CHUNK_SIZE_MAX-1 ) {
	   printf("\n");
	     com->next = second;				
	     com = com->next;
	     moins = -5;			
	     n=0;
	   }
	   a = i- moins;
	   printf("%c ",mot[i]);
	   n=i+1;
	   com->chunk[a] = mot[i];
	   com->chunkSize = a;
	   com->next = NULL;
	   
	}
	printf("tets");
	return com;			

}

void afficheElement(char e) {
	printf("%c ",e);	
}

void afficheString(String s) {
	String affiche = s ;
	if ( s!=NULL){
		while( affiche!=NULL) {
		   for (int i =0; i< CHUNK_SIZE_MAX-1;i++){
		     if (affiche->chunk[i]) {
		       afficheElement(affiche->chunk[i]);
		       affiche = affiche->next;
		     }
		   }
		}	
	}
}

int string_length(String s) {
	String courant =s;
	int compteur=0;

	int moins =0;
	while(courant!=NULL){
	    for (int i =0; i< CHUNK_SIZE_MAX-1	;i++){
	       if (courant->chunk[i]){
	          compteur +=1;
	       }
	    
	    }
	 courant = courant->next;
	}
	return compteur;	
 
}

//La compilation fonctionne mais il y a une erreur de segmentataion pour la fonction affiche 
int main() {
   String s = string_new("HELLOaa");
   string_length(s);		
}
