#ifndef NAVIRES_H
#define NAVIRES_H

/**
 * Abonnenc Bonhoure 
 * Mars 2016
 */

typedef struct _Maillon Maillon;
typedef struct _Liste_Navires Liste_Navires;

/**
 * Structure Maillon
 * 4 entiers précisant les coordonnées de début et de fin d'un navire
 * 1 entier indiquant si le navire est coulé (1) ou non (0)
 */ 
typedef struct _Maillon {
	int xDeb;
	int yDeb;
	int xFin;
	int yFin;
	int coule;
	Maillon *suivant;
} Maillon;

/**
 * Structure de liste de navires (Maillon)
 * Un pointeur vers un Maillon de début
 * Un pointeur vers un Maillon de fin
 */
typedef struct _Liste_Navires {
	Maillon *tete;
	Maillon *queue;
} Liste_Navires;

/**
 * Fonction initialisant et retournant une liste de navires vide
 */
Liste_Navires liste_vide() ;

/**
 * Créé un nouveau maillon à partir de coordonnées
 */
Maillon *nouveau(int ideb, int ifin, int jdeb, int jfin);

/**
 * 
 */
void insertion(Liste_Navires *l, int ideb, int ifin, int jdeb, int jfin) ;

/**
 * Renvoie vrai si la liste contient :
 * 	1 porte-avion (6 cases)
 * 	2 croiseurs (4 cases)
 * 	3 contre-torpilleurs (3 cases)
 * 	4 torpilleurs (2 cases)
 */
int liste_valide (Liste_Navires l);

Liste_Navires cree_liste_navires(Grille g, int n);

void afficher_liste_navire(Liste_Navires l);

/**
 * Renvoie 1 si le navire du maillon m est coulé par un tir en (ic,jc)
 */
int navire_coule(Maillon *m, int ic, int jc, Grille gc);

/**
 * Renvoie 1 si un navire de la liste l est coulé par un tir en (ic,jc)
 */
int un_navire_coule(Liste_Navires l, int ic, int jc, Grille gc);

/**
 * Renvoie 1 si un navire de la liste l est touché par un tir en (ic,jc)
 */
int un_navire_touche(Liste_Navires l, int ic, int jc, Grille gc);

#endif
