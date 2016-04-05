#ifndef JEU_H
#define JEU_H

/**
 * Fonction qui joue une attaque en (i,j) et affiche le résultat.
 * Raté, Touché, Coulé
 * ---------------------------------------------------------------------
 * Jouer une attaque a pour effet de modifier la grille donnée
 */
void joue(Grille g, Grille gc, int n, Liste_Navires l, int i, int j);

/**
 * Renvoie 1 si tout les bateaux ont été coulés
 * --------------------------------------------
 * les bateaux sont parcourus un a un et on vérifie que le champ coule est vrai pour tous
 */
int jeu_fini(Liste_Navires l);

#endif
