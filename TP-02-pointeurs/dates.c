#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum  { Janvier, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre ,Decembre} Mois;

typedef struct { 
	int jour ;
	Mois mois;
	int annee ;
} Date;

void initialiseDate( Date *a) {

	scanf ( "%d", &a->jour);  
	
	scanf ( "%d", &a->mois);  

	scanf ( "%d", &a->annee);  

}
Date creerDateParCopie() {
	Date a;
	initialiseDate(&a); 
	return a;
	
}

void afficheDate(Date *a) {

	
	printf("Nous sommes le %d/ %d/ %d",a->jour,a->mois,a->annee);

}

Date* newDate() {
	Date* d= malloc(sizeof(Date)) ;
	initialiseDate(d);
	
return d ;
		
}

int main() {
	Date *date;
	date = newDate();
	afficheDate(date);
	//...
	free(date);		
}
