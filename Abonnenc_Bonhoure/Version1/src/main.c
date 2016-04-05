/**
 * Abonnenc Bonhoure
 * Mars 2016
 */

#include <stdlib.h>
#include <stdio.h>

#include "../include/grille.h"
#include "../include/navires.h"
#include "../include/jeu.h"

//#define DEBUG

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
	
	printf("Bienvenue dans la Version 1 de la Bataille Navale.\n");
	
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
	
	Liste_Navires l;
	l=cree_liste_navires(g,taille);
	if(!(liste_valide(l))){
		fprintf(stderr,"Nombre de navires invalides.\n");
		fprintf(stderr,"Il faut \n1 porte-avion (6 cases)\n2 croiseurs (4 cases)\n3 contre-torpilleurs (3 cases)\n4 torpilleurs (2 cases)\n");
		return 0;
	}
	
	#ifdef DEBUG
	afficher_liste_navire(l);
	#endif
	
	affiche_etat_coules(gc,taille);
	int ic,jc;
	while(!jeu_fini(l)){
		ic = -1;
		while(ic>=taille || jc >= taille || ic < 0 || jc <0){
			printf("Tir en ?  (ligne colonne)  ");
			scanf("%d %d",&ic,&jc);
		}
		joue(g,gc,taille,l,ic,jc);
		affiche_etat_coules(gc,taille);
		#ifdef DEBUG
		afficher_liste_navire(l);
		#endif
	}
	printf("// Jeu fini ! :D //\n");
	
	return 0;
}
