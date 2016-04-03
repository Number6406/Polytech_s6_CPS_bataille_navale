#ifndef JEU_H
#define JEU_H

/**
 * Fonction qui joue une attaque en (i,j) et affiche le résultat.
 * Raté, Touché, Coulé
 */
void joue(Grille g, Grille gc, int n, Liste_Navires l, int i, int j);

/**
 * Renvoie 1 si tout les bateaux ont été coulés
 */
int jeu_fini(Liste_Navires l);

#endif
