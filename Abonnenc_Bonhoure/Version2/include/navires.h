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
 * 1 booléen indiquant si le navire est coulé (1) ou non (0)
 */ 
typedef struct _Maillon {
	int32_t infos;
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
 * Fonction retournant une liste de navires vide
 */
Liste_Navires liste_vide() ;

/**
 * Affichage d'une liste de navires (pour le deboggage)
 */
 void afficher_liste_navire(Liste_Navires l);

/**
 * Créé et alloue un nouveau maillon à partir des coordonnées fournies
 */
Maillon *nouveau(int ideb, int jdeb ,int ifin, int jfin);

/**
 * Renvoie vrai si la liste contient :
 * 	1 porte-avion (6 cases)
 * 	2 croiseurs (4 cases)
 * 	3 contre-torpilleurs (3 cases)
 * 	4 torpilleurs (2 cases)
 */
int liste_valide (Liste_Navires l);

/**
 * Insertion d'un nouveau maillon en fin de liste de navires.
 */
void insertion(Liste_Navires *l, int ideb, int ifin, int jdeb, int jfin) ;

/**
 * Crée une liste de navires à partir d'une grille
 * ---------------------------------------------------------------------
 * Cette fonction renvoie une liste de navires contenant tout les
 * navires de la grille passée en paramètres.
 * Elle ne s'occupe pas de vérfier que leur nombre et leur taille
 * correspond aux régles de la Bataille Navale (cf liste_valide)
 */
Liste_Navires cree_liste_navires(Grille g, int n);

/**
 * Renvoie 1 si le navire du maillon m est coulé par un tir en (ic,jc)
 * ---------------------------------------------------------------------
 * Cette fonction modifie également l'état de la grille si le navire 
 * est coulé
 */
int navire_coule(Maillon *m, int ic, int jc, Grille gc);

/**
 * Renvoie 1 si un navire de la liste l est coulé par un tir en (ic,jc)
 * ---------------------------------------------------------------------
 * Cela se faitpar un parcoursde la liste en appelant la fonction 
 * ci-dessus
 */
int un_navire_coule(Liste_Navires l, int ic, int jc, Grille gc);

/**
 * Renvoie 1 si un navire de la liste l est touché par un tir en (ic,jc)
 */
int un_navire_touche(Liste_Navires l, int ic, int jc, Grille gc);

#endif
