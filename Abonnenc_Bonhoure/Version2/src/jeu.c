/**
 * Abonnenc Bonhoure 
 * Mars 2016
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "../include/grille.h"
#include "../include/navires.h"
#include "../include/int32io.h"

void joue(Grille g, Grille gc, int n, Liste_Navires l, int i, int j){
	
	if(un_navire_touche(l,i,j,gc)){ // Un navire est touché, on vérifie s'il est coulé.
		if(un_navire_coule(l,i,j,gc)){
			printf("---!!COULÉ!!---\n");
		} else {
			printf("-----Touché-----\n");
		}
	} else{
		printf("-----Raté-----\n");
		gc[i][j]='X';
	}
	
}

int jeu_fini(Liste_Navires l){
	Maillon *tmp = l.tete;
	while(tmp!=NULL && (get_coule(tmp->infos)==1)){
		tmp = tmp->suivant;
	}
	return tmp == NULL;
}
