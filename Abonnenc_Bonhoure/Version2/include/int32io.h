#ifndef INT32IO_H
#define INT32IO_H

#include <stdint.h>

/**
 * Place la valeur v dans entre b_faible et b_fort de x
 * ---------------------------------------------------------------------
 * set_field(adr_x,faible,fort,v) place la valeur v dans l'entier 
 * d'adresse x, en ne modifiant pas le bits avant faible et apres fort
 */
void set_field (int32_t *adr_x, int faible, int fort, int v);


/**
 * Recupére la valeur entre b_faible et b_fort de x
 * ---------------------------------------------------------------------
 * get_field(adr_x,faible,fort) renvoie la valeur de x entre
 * b_faible et b_fort
 */
int get_field(int32_t * adr_x, int faible, int fort);

/**
 * Fonctions pour charger les différents arguments
 */
void set_i_debut(int32_t *x,int v);
void set_j_debut(int32_t *x,int v);
void set_i_fin(int32_t *x,int v);
void set_j_fin(int32_t *x,int v);
void set_coule(int32_t *x,int v);

/**
 * Fonctions pour récupérer les différents arguments
 */
int get_i_debut(int32_t *x);
int get_j_debut(int32_t *x);
int get_i_fin(int32_t *x);
int get_j_fin(int32_t *x);
int get_coule(int32_t *x);

#endif
