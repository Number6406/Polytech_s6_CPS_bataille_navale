#include <stdlib.h>
#include <stdio.h>
#include "../include/grille.h"
#include "../include/navires.h"


/**
 * Fonction qui joue une attaque en (i,j) et affiche le résultat.
 * Raté, Touché, Coulé
 */
void joue(Grille g, Grille gc, int n, Liste_Navires l, int i, int j){
	
	if(un_navire_touche(l,i,j,gc)){
		if(un_navire_coule(l,i,j,gc)){
			printf("-----COULÉ-----\n");
		} else {
			printf("-----Touché-----\n");
		}
	} else{
		printf("-----Raté-----\n");
	}
	
}

int jeu_fini(Liste_Navires l){
	Maillon *tmp = l.tete;
	while(tmp!=NULL && (tmp->coule==1)){
		tmp = tmp->suivant;
	}
	return tmp == NULL;
}
