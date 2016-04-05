/**
 * Abonnenc Bonhoure 
 * Mars 2016
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "../include/grille.h"
#include "../include/navires.h"
#include "../include/int32io.h"

#define clrscr() printf("\033[H\033[2J")
#define couleur(param) printf("\033[%sm",param)

void joue(Grille g, Grille gc, int n, Liste_Navires l, int i, int j){
	
	clrscr(); //clear de l'écran
	
	if(un_navire_touche(l,i,j,gc)){ // Un navire est touché, on vérifie s'il est coulé.		
		couleur("32");	//Vert
		couleur("5");	//Clignote
		if(un_navire_coule(l,i,j,gc)){
			printf("---!!COULÉ!!---\n");
		} else {
			printf("-----Touché-----\n");
		}
		couleur("0");	//Reset couleur
	} else{
		couleur("31");	//Vert
		couleur("5");	//Clignote
		printf("-----Raté-----\n");
		gc[i][j]='X';
		couleur("0");	//Reset couleur
	}
	
}

int jeu_fini(Liste_Navires l){
	Maillon *tmp = l.tete;
	while(tmp!=NULL && (get_coule(tmp->infos)==1)){
		tmp = tmp->suivant;
	}
	return tmp == NULL;
}
