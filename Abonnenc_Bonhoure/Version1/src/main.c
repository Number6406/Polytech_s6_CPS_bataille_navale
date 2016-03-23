/**
 * Abonnenc Bonhoure
 * Mars 2016
 */

#include <stdlib.h>
#include <stdio.h>

#include "../include/grille.h"

/**
 * Fonction principale de jeu
 */
int main(int argc, char* argv[]){
	Grille g, gc; // Grilles du J1 et du J2
	int taille;
	
	// A t'on des paramètres ?
	if(argc!=2){
		fprintf(stderr,"Veuillez entrer la taille du tableau en paramètre");
		return 1;
	}
	// On récupère la taille des grilles
	taille = atoi(argv[1]);
	
	// Allocation des grilles
	g=NULL;
	gc=NULL;
	allouer_grille(g,taille);
	allouer_grille(gc,taille);
	
	
	
	return 0;
}
