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
	printf("Le joueur 1 a placé ses navires, état de sa grille :\n");
	// Affichage des indices de colonnes
	printf("  ");
	for (i = 0; i < taille; i++){
		printf("%2d",i);
	}
	printf("\n");
	
	// Affichage du tableau
	for (i = 0; i < taille; i++){
		printf("%2d ",i); // indice de ligne
		for (j = 0; j < taille; j++){
			if(g[i][j]=='N'){
				printf("N ");
			} else {
				if(g[i][j]=='B'){
					printf("  ");
				} else { // Erreur, le charactere n'est ni 'N' ni 'B'
					fprintf(stderr,"afficher_jeu : Caractère invalide (%c)\n",g[i][j]);
					return 1;
				}
			}
		}
		printf("\n");
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
	printf("  ");
	for (i = 0; i < taille; i++){
		printf("%2d",i);
	}
	printf("\n");
	
	// Affichage du tableau
	for (i = 0; i < taille; i++){
		printf("%2d ",i); // indice de ligne
		for (j = 0; j < taille; j++){
			printf("%c ",g[i][j]);
		}
		printf("\n");
	}
	return 0;
 }
 
 
// Allouer la grille
/**
 * Alloue une grille de taille n*n passée en paramètre. 
 * Elle est supposées vide en début de fonction
 * ---------------------------------------------------------------------
 * allouer_grille(g,n) allour une grille g de taille n*n
 */
Grille allouer_grille(int taille){
	unsigned int i;
	Grille g;
	// création du tableau de tableau (tableau de pointeurs)
	g = malloc( taille * sizeof(int*));
	// Allouer chaque case du tableau (qui est un tableau)
	for (i = 0; i < taille; i++){
		g[i] = malloc( taille * sizeof(int));
	}
	return g;
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
		fscanf(f,"%d\n",&x); // La taille de la grille est en début de fichier
		// Si la taille est bonne, on lit la grille
		if(x==taille){
			for (i = 0; i < taille; i++){
				for (j = 0; j < taille; j++){
					fscanf(f,"%c ",&g[i][j]);
				}
			}
			
		} else{
			fprintf(stderr,"remplir_grille : Taille incorrecte\n");
			exit(1);
		}
	}
	else{
		fprintf(stderr,"remplir_grille : Fichier non ouvert\n");
		exit(1);
	}
	fclose(f);
}

/**
 * Remplit la grille du joueur 2 avec des espaces
 * ---------------------------------------------------------------------
 * La grille a déjà été allouée, il suffit de la remplir
 */
void remplir_etat(Grille g, int taille){
	register unsigned int i, j;
	for (i = 0; i < taille; i++){
		for (j = 0; j < taille; j++){
			g[i][j]=' ';
		}
	}
}
