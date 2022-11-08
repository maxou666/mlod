#include "linkedList.h"	
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
		Liste cell =malloc(sizeof(Cellule));
		if (cell!=NULL){
	  		cell->val = v;	
	  		cell ->suiv = NULL;
	  	}
	return cell; 			
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	  Liste element =creer(v);
	  element->suiv = l;
	  l = element;
	  	  
	return l;
}




// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	if(!estVide(l)){
		Liste cellule_courante =l;
		while (cellule_courante !=NULL) {
			afficheElement(cellule_courante->val);
			cellule_courante =cellule_courante->suiv;
		}
	}
}

// version recursive
void afficheListe_r(Liste l) {
	if(!estVide(l)){
	
		
			afficheElement(l->val);	
			afficheListe_r ( l->suiv) ;	
	}
}


	
// Détruit tous les éléments de la liste l
// version itérative

void detruire_i(Liste l) {
	
		Liste cellule_courante,cellule_suivante =l;
		while (!estVide(cellule_courante)) {
		cellule_suivante= cellule_courante->suiv;
			detruireElement(cellule_courante->val);
			free (cellule_courante);
			cellule_suivante = cellule_suivante;
		}
	
}

// version récursive
void detruire_r(Liste l) {

	if(!estVide(l)){
		
		detruireElement(l->val);	
		detruire_r(l->suiv);
		free(l);
	}
	
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste ajout =creer (v);
	Liste p =l;
	if (estVide(p)){
	   return ajout;
	   
	}
	while(!estVide(p->suiv)){
		p = p->suiv;
	}
	p->suiv = ajout;			
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	
	
	if (estVide(l)){
	   return creer (v);
	   
	}
	else{
	   l->suiv = ajoutFin_r(v, l->suiv);
	}
	
	return l;
}

// compare deux elements


// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) 	{
	Liste courant = l;
	while(!estVide(courant)) {
	  if (equalsElement(v, courant->val)){
	    return courant;
	  }
	  else {
	    courant= courant->suiv;
	  }
	}
	return NULL;
	}

// version récursive
Liste cherche_r(Element v,Liste l) {
	Liste courant = l;
	if ( estVide(l) ){
		return NULL;
	}
	if (equalsElement(v, courant->val)){
	    return courant;
	  }
	cherche_r(v,courant->suiv);								
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste courant = l;
	Liste res=NULL;
	
	while (!estVide(courant)) {
		
		if(courant!=cherche_r(v,l))	 {
		   res = ajoutFin_r(courant->val, res);		
		}	
	courant = courant->suiv;			
	}
	return res;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	
	
	
	

								
}


void afficheEnvers_r(Liste l) {
	Liste envers= NULL;
	
	while (!estVide(l)) {
	 envers = ajoutTete (l->val,envers);
	 l = l->suiv;	
	 		
	}
	afficheListe_r(envers);		
	
	
}

  

