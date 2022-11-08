#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

void afficheElement(Element e){
	printf(e);
}

bool equalsElement(Element e1, Element e2){
	return (strcmp(e1,e2)==0);
}		

void detruireElement(Element e) {
	
}

int main(void){
	Liste l,p	;
	l=NULL;
	l = ajoutTete("un",l);
	l = ajoutTete("deux",l);
	l = ajoutTete("trois",l);
	l = ajoutTete("SOLEIL",l);
	afficheListe_i(l);
	
	p = cherche_i("trois",l);
	if(estVide(p))
		printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}
	
	
}
