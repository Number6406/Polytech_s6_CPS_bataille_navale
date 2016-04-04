/**
 * Abonnenc Bonhoure 
 * Mars 2016
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "../include/grille.h"


typedef struct _Maillon Maillon;
typedef struct _Liste_Navires Liste_Navires;

typedef struct _Maillon {
	int xDeb;
	int yDeb;
	int xFin;
	int yFin;
	int coule;
	Maillon *suivant;
} Maillon;

typedef struct _Liste_Navires {
	Maillon *tete;
	Maillon *queue;
} Liste_Navires;

Liste_Navires liste_vide() {
	Liste_Navires l;
	l.tete = NULL;
	l.queue = NULL;
	return l;
}

void afficher_liste_navire(Liste_Navires l){
	Maillon *m = l.tete;
	printf("AFFICHAGE DE LISTE\n");
	while(m!=NULL){
		printf("Maillon (%d,%d) --> (%d,%d) | Coulé : %d\n",m->xDeb,m->yDeb,m->xFin,m->yFin,m->coule);
		m = m->suivant;
	}
}

Maillon *nouveau(int ideb, int jdeb ,int ifin, int jfin) {
	Maillon *m = (Maillon*)malloc(sizeof(Maillon));
	m->xDeb = ideb;
	m->yDeb = jdeb;
	m->xFin = ifin;
	m->yFin = jfin;
	m->coule = 0;
	
	return m;
}



/** Fonction locale.
 * Renvoie la taille du navire contenu dans le maillon
 */
int taille_navire(Maillon *m){
	if (m!=NULL){
		if(m->xDeb==m->xFin){return (m->yFin - m->yDeb) +1;}
		return (m->xFin - m->xDeb) +1;
	}
	else{
		fprintf(stderr,"taille_navire : navire inexistant\n");
		return 0;
	}
}

int liste_valide (Liste_Navires l){
	Maillon *tmp = l.tete;
	int pa,cr,ct,tp; // Variables pour compter le nombre de bateaux
	pa = 0;
	cr = 0;
	ct = 0;
	tp = 0;
	while(tmp!=NULL){ // On traite tout les navires de la liste
		switch (taille_navire(tmp)) {
			case 6 : pa++;
					break;
			case 4 : cr++;
					break;
			case 3 : ct++;
					break;
			case 2 : tp++;	
					break;
			default : fprintf(stderr,"liste_valide : taille de navire invalide (%d) Tailles OK : 2,3,4 ou 6.\n",taille_navire(tmp));
					return 0;
		}
		tmp = tmp->suivant;
	}
	return (pa==1)&&(cr==2)&&(ct==3)&&(tp==4);
}

void insertion(Liste_Navires *l, int ideb, int jdeb, int ifin, int jfin) {
	Maillon *m = nouveau(ideb,jdeb,ifin,jfin);
	
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
	Grille parcouru = allouer_grille(n);
	Liste_Navires liste = liste_vide();
	
	// Initialiser à non parcouru pour toutes les cases
	for(i=0; i<n;i++){
		for(j=0;j<n;j++){
			parcouru[i][j]=0;
		}
	}
	
	for(i=0; i<n; i++) { // Ligne
		for(j=0; j<n; j++) { // Colonne
			if(g[i][j] == 'N' && !(parcouru[i][j])) { 
				// Si on est sur un bateau qui n'est pas déjà dans la liste
				parcouru[i][j] = 1;
				if(g[i][j+1] == 'N') { // Bateau horizontal
					parcouru[i][j+1] = 1;
					j2 = j+1;
					while(j2<n && g[i][j2] == 'N') { 
						parcouru[i][j2] = 1; 
						j2++;
					}
					insertion(&liste, i, j, i, j2-1);
				} 
				else if(g[i+1][j] == 'N') { // Bateau vertical
					parcouru[i+1][j] = 1;
					i2 = i+1;
					while(i2<n && g[i2][j] == 'N') { 
						parcouru[i2][j] = 1; 
						i2++;
					}
					insertion(&liste, i, j, i2-1, j);
				}
			} 
		}
	}
	return liste;
	
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
				m->coule = 1;
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
				m->coule = 1;
				for(i=m->xDeb; i<=m->xFin;i++){
					gc[i][m->yDeb]='C';
				}
			}
			return coule;
		}
	} 
	return 0;
}

int un_navire_coule(Liste_Navires l, int ic, int jc, Grille gc){
	Maillon* tmp = l.tete;
	while(tmp != NULL && !(navire_coule(tmp,ic,jc,gc))){
		tmp = tmp->suivant;
	}
	return tmp!=NULL;
}

/** Fonction locale.
 * Renvoie vrai si le navire est touché par le tir
 * ---------------------------------------------------------------------
 * Il modifie la grille (si le bateau visé n'ets pas déjà coulé
 */
int navire_touche(Maillon *m, int ic, int jc, Grille gc){
	if(m!=NULL){
		if((m->xDeb <= ic) && (ic <= m->xFin) && (m->yDeb <= jc) && (jc <= m->yFin)){
			if(gc[ic][jc]!='C') gc[ic][jc]='T';	
			return 1;
		}		
	}
	return 0;
}

int un_navire_touche(Liste_Navires l, int ic, int jc, Grille gc){
	Maillon* tmp = l.tete;
	while(tmp != NULL && !(navire_touche(tmp,ic,jc,gc))){
		tmp = tmp->suivant;
	}
	return tmp!=NULL;
}

