/**
 * Abonnenc Bonhoure
 * Mars 2016
 */

#include <stdlib.h>
#include <stdio.h>

/** Grille définit un tableau en 2 dimensions d'entiers. 
 * Ce tableau est de taille indéfinie et sera alloué dynamiquement
 */
typedef char **Grille;


// Fonctions d'affichage de jeux
/**
 * Fonction d'affichage du plateau de jeu du joueur 1.
 * Son plateau comporte les bateaux, en noir
 * ---------------------------------------------------------------------
 * afficher_jeu(G,n) affiche une grille de taille n*n
 * en affichant les indices de lignes et de colonnes
 */
 int afficher_jeu(Grille g, int taille){
	register unsigned int i,j;
	// Affichage des indices de colonnes
	printf("   ");
	for (i = 0; i < taille; i++){
		printf("%3d",i);
	}
	printf("\n");
	
	// Affichage du tableau
	for (i = 0; i < taille; i++){
		printf("%2d  ",i); // indice de ligne
		for (j = 0; j < taille; j++){
			if(g[i][j]=='N'){
				printf("N  ");
			} else {
				if(g[i][j]=='B'){
					printf("   ");
				} else { // Erreur, le charactere n'est ni 'N' ni 'B'
					fprintf(stderr,"afficher_jeu : Caractère invalide\n");
					return 1;
				}
			}
		}
	}
	return 0;
 }
 
 /**
 * Fonction d'affichage de l'état courant du jeu du joueur 2.
 * Les informations peuvent être (T)ouché, (C)oulé, (X) pour raté ou ( )
 * ---------------------------------------------------------------------
 * afficher_jeu(G,n) affiche une grille de taille n*n
 * en affichant les indices de lignes et de colonnes
 */
 int affiche_etat_coules(Grille g, int taille){
	register unsigned int i,j;
	// Affichage des indices de colonnes
	printf("   ");
	for (i = 0; i < taille; i++){
		printf("%3d",i);
	}
	printf("\n");
	
	// Affichage du tableau
	for (i = 0; i < taille; i++){
		printf("%2d  ",i); // indice de ligne
		for (j = 0; j < taille; j++){
			printf("%c  ",g[i][j]);
		}
	}
	return 0;
 }

// Remplissage de la grille
/**
 * Remplit la grille du joueur 1 à partir d'un fichier contenant la 
 * grille, (X pour un bateau, O pour de l'eau)
 * ---------------------------------------------------------------------
 * La grille a déjà été allouée, il suffit de la remplir
 */
void remplir_grille(Grille g, int taille){
	FILE *f;
	register unsigned int i, j;
	int x;
	
	f = fopen("../exemples/partie1.txt","r");
	if(f!=NULL){
		fscanf(f,"%d",&x); // La taille de la grille est en début de fichier
		// Si la taille est bonne, on lit la grille
		if(x==taille){
			for (i = 0; i < taille; i++){
				for (j = 0; j < taille; j++){
					fscanf(f,"%c ",&g[i][j]);
				}
			}
			
		} else{
			fprintf(stderr,"remplir_grille : taille incorrecte\n");
		}
	}
	else{
		fprintf(stderr,"Fichier non ouvert\n");
	}
}
