/**
 * Abonnenc Bonhoure
 * Mars 2016
 */

#include <stdlib.h>
#include <stdio.h>

#include "../include/grille.h"
#include "../include/navires.h"
#include "../include/jeu.h"

#define DEBUG

/**
 * Fonction principale de jeu
 */
int main(int argc, char* argv[]){
	Grille g, gc; // Grilles du J1 et du J2
	int taille;
	
	// A t'on des paramètres ?
	if(argc!=3){
		fprintf(stderr,"Veuillez entrer la taille du tableau ET le fichier de partie en paramètre\n");
		return 1;
	}
	// On récupère la taille des grilles
	taille = atoi(argv[1]);
	
	// Allocation des grilles
	g=allouer_grille(taille);
	gc=allouer_grille(taille);
	
	remplir_grille(g,taille,argv[2]);
	remplir_etat(gc,taille);
	
	#ifdef DEBUG
	afficher_jeu(g,taille);
	#endif
	
	gc[5][2]='A';
	affiche_etat_coules(gc,taille);
	
	Liste_Navires l;
	l=cree_liste_navires(g,taille);
	
	#ifdef DEBUG
	afficher_liste_navire(l);
	afficher_grille(g,taille);
	#endif
	
	int ic,jc;
	while(!jeu_fini(l)){
		printf("Tir en (x) (y) ? ");
		scanf("%d %d",&ic,&jc);
		joue(g,gc,taille,l,ic,jc);
		affiche_etat_coules(gc,taille);
	}
	
	return 0;
}
