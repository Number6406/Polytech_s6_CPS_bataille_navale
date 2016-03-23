#ifndef GRILLE_H
#define GRILLE_H

typedef char **Grille;

int afficher_jeu(Grille g, int taille);
 
int affiche_etat_coules(Grille g, int taille);

void allouer_grille(Grille g, int n);

void remplir_grille(Grille g, int taille);

#endif
