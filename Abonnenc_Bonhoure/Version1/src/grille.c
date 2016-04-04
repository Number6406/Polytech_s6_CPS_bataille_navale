/**
 * Abonnenc Bonhoure
 * Mars 2016
 */

#include <stdlib.h>
#include <stdio.h>

typedef char **Grille;

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

 int affiche_etat_coules(Grille g, int taille){
	register unsigned int i,j;
	// Affichage des indices de colonnes
	printf("Etat du jeu pour le joueur 2:\n");
	printf("  ");
	for (i = 0; i < taille; i++){
		printf("%2d",i);
	}
	printf("\n");
	
	// Affichage du tableau
	for (i = 0; i < taille; i++){
		printf("%2d ",i); // indice de ligne
		for (j = 0; j < taille; j++){
			printf("%c ",g[i][j]); // Affiche le contenu de la grille (qui est déjà T,X,C ou ' ')
		}
		printf("\n");
	}
	return 0;
 }
 

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


void remplir_grille(Grille g, int taille, char *nomfich){
	register unsigned int i, j;
	int x;
	FILE *f;
	f = fopen(nomfich,"r");
	if(f!=NULL){
		fscanf(f,"%d\n",&x); // La taille de la grille est en début de fichier
		// Si la taille est égale à celle fournie en paramètre, on lit la grille
		if(x==taille){
			for (i = 0; i < taille; i++){ // Ligne
				for (j = 0; j < taille; j++){ // Colonne
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

void remplir_etat(Grille g, int taille){
	register unsigned int i, j;
	for (i = 0; i < taille; i++){
		for (j = 0; j < taille; j++){
			g[i][j]=' ';
		}
	}
}
