#ifndef GRILLE_H
#define GRILLE_H


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
int afficher_jeu(Grille g, int taille);
 
 /**
 * Fonction d'affichage de l'état courant du jeu du joueur 2.
 * Les informations peuvent être (T)ouché, (C)oulé, (X) pour raté ou ( )
 * ---------------------------------------------------------------------
 * affiche_etat_coules(G,n) affiche une grille de taille n*n
 * en affichant les indices de lignes et de colonnes
 */
int affiche_etat_coules(Grille g, int taille);
 
// Allouer la grille
/**
 * Alloue une grille de taille n*n passée en paramètre. 
 * Elle est supposées vide en début de fonction
 * ---------------------------------------------------------------------
 * allouer_grille(g,n) allour une grille g de taille n*n
 */
Grille allouer_grille(int taille);

// Remplissage de la grille
/**
 * Remplit la grille du joueur 1 à partir d'un fichier contenant la 
 * grille, (X pour un bateau, O pour de l'eau)
 * ---------------------------------------------------------------------
 * La grille doit être déjà allouée, il suffit de la remplir
 */
void remplir_grille(Grille g, int taille, char *nomfich);

/**
 * Remplit la grille du joueur 2 avec des espaces
 * ---------------------------------------------------------------------
 * La grille doit être déjà allouée, il suffit de la remplir
 */
void remplir_etat(Grille g, int taille);

#endif
