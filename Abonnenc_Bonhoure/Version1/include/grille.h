#ifndef GRILLE_H
#define GRILLE_H

typedef char **Grille;

int afficher_jeu(Grille g, int taille);
 
int affiche_etat_coules(Grille g, int taille);

Grille allouer_grille(int taille);

void remplir_grille(Grille g, int taille);

void remplir_etat(Grille g, int taille);

#endif
