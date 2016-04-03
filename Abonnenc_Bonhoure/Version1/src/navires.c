#include <stdlib.h>
#include <stdio.h>
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

void afficher_liste_navire(Liste_Navires l){
	Maillon *m = l.tete;
	while(m!=NULL){
		printf("Maillon (%d,%d) --> (%d,%d)\nCoulé : %d\n",m->xDeb,m->xFin,m->yDeb,m->yFin,m->coule);
		m = m->suivant;
	}
}


/**
 * Renvoie 1 si le navire du maillon m est coulé par un tir en (ic,jc)
 */
int navire_coule(Maillon *m, int ic, int jc, Grille gc){
	if(m!=NULL){
		if(m->xDeb==m->xFin){ // Bateau Vertical
			if(ic!=m->xDeb) {return 0;} // Si le tir n'est pas sur le bateau renvoyer faux
			// Sinon verifier que l'on touche la derniere case non touchée
			int j;
			int coule = 1;
			j = m->yDeb;
			while(j<=m->yFin && coule){
				coule = coule &&((gc[m->xDeb][j]=='T') || (jc==j)); // Déjà touché ou touché maintenant !
				j++;
			}
			if(coule){ // Changer les cases du tableau
				for(j=m->yDeb; j<=m->yFin;j++){
					gc[m->xDeb][j]='C';
				}
			}
			return coule;
		} else { // Bateau Horizontal
			if(jc!=m->yDeb) {return 0;} // Si le tir n'est pas sur le bateau renvoyer faux
			// Sinon verifier que l'on touche la derniere case non touchée
			int i;
			int coule = 1;
			i = m->xDeb;
			while(i<=m->xFin && coule){
				coule = coule &&((gc[i][m->yDeb]=='T') || (ic==i)); // Déjà touché ou touché maintenant !
				i++;
			}
			if(coule){ // Changer les cases du tableau
				for(i=m->xDeb; i<=m->xFin;i++){
					gc[i][m->yDeb]='C';
				}
			}
			return coule;
		}
	} 
	return 0;
}

/**
 * Renvoie 1 si un navire de la liste l est coulé par un tir en (ic,jc)
 */
int un_navire_coule(Liste_Navires l, int ic, int jc, Grille gc){
	Maillon* tmp = l.tete;
	while(tmp != NULL && !(navire_coule(tmp,ic,jc,gc))){
		tmp = tmp->suivant;
	}
	return tmp!=NULL;
}

/**
 * Renvoie 1 si le navire du maillon m est touché par un tir en (ic,jc)
 */
int navire_touche(Maillon *m, int ic, int jc, Grille gc){
	if(m!=NULL){
		if((m->xDeb <= ic) && (ic <= m->xFin) && (m->yDeb <= jc) && (jc <= m->yFin)){
			gc[ic][jc]='T';	
			return 1;
		}		
	}
	return 0;
}

/**
 * Renvoie 1 si un navire de la liste l est touché par un tir en (ic,jc)
 */
int un_navire_touche(Liste_Navires l, int ic, int jc, Grille gc){
	Maillon* tmp = l.tete;
	while(tmp != NULL && !(navire_touche(tmp,ic,jc,gc))){
		tmp = tmp->suivant;
	}
	return tmp!=NULL;
}

