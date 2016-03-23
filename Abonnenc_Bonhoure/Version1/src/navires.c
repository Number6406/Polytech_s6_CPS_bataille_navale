#include <stdlib.h>
#include "../include/grille.h"

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
Liste_Navires liste_vide() {
	//Allocation dynamique de mémoire 
	Liste_Navires l;
	l.tete = NULL;
	l.queue = NULL;
	return l;
}

/**
 * Créé un nouveau maillon à partir de coordonnées
 */
Maillon *nouveau(int ideb, int ifin, int jdeb, int jfin) {
	Maillon *m = (Maillon*)malloc(sizeof(Maillon));
	m->xDeb = ideb;
	m->xFin = ifin;
	m->yDeb = jdeb;
	m->yFin = jfin;
	m->coule = 0;
	
	return m;
}

/**
 * 
 */
void insertion(Liste_Navires *l, int ideb, int ifin, int jdeb, int jfin) {
	Maillon *m = nouveau(ideb, ifin, jdeb, jfin);
	
	if(l->queue == NULL) { //S'il n'y a pas de queue, alors la liste est vide
		l->tete = m; //Insertion du maillon en tete
	} else {
		l->queue->suivant = m; //L'ancien dernier maillon de la liste pointe sur le nouveau maillon
	}
	
	l->queue = m; //La queue de la liste pointe désormais sur le nouveau maillon
}

Liste_Navires cree_liste_navires(Grille g, int n) {
	int i, j;
	int i2, j2;
	
	Liste_Navires liste = liste_vide();
	
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(g[i][j] == 'N') {
				g[i][j] = 'P';
				if(g[i][j+1] == 'N') {
					j2 = j++;
					while(j2<n && g[i][j2] == 'N') { g[i][j2++] = 'P'; }
					insertion(&liste, i, j, i, j2);
				} else if(g[i+1][j] == 'N') {
					i2 = i++;
					while(i2<n && g[i2][j] == 'N') { g[i2][j] = 'P'; }
				}
			}
		}
	}
	
	return liste;
	
}