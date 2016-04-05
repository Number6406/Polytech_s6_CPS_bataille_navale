/**
 * Abonnenc Bonhoure 
 * Mars 2016
 */

#include <stdio.h>
#include <stdint.h>

#define IDEB_FAIBLE 	0
#define IDEB_FORT 		3
#define JDEB_FAIBLE 	7
#define JDEB_FORT 		10
#define IFIN_FAIBLE 	14
#define IFIN_FORT 		17
#define JFIN_FAIBLE 	21
#define JFIN_FORT 		24
#define COULE			31

/**
 * Place la valeur v dans entre b_faible et b_fort de x
 * ---------------------------------------------------------------------
 * set_field(adr_x,faible,fort,v) place la valeur v dans l'entier 
 * d'adresse x, en ne modifiant pas le bits avant faible et apres fort
 */
void set_field (int32_t *adr_x, int faible, int fort, int v){
	uint32_t lu = 1;
	uint32_t eff;
	unsigned int i;
	int32_t x = *adr_x; // Récupérer la valeur
	
	// Modifier x
	// Bien placer V à partir de faible
	v = (unsigned int)v << faible;
	// Crée un masque pour mettre à 0 la valeur qui dépasse.
	for(i = 0; i<fort;i++){
		lu = (lu<<1)|1;
	}
	v &= lu;
	
	// Mettre à 0 les bits de x entre faible et fort
	// On crée un masque
	lu = 0xFFFFFFFF;
	for(i=faible;i<=fort;i++){
		eff = ~(1<<(i));
		lu &= eff;
	}
	// On efface dans x
	x &= lu;
	
	
	// On remplace
	x |= v;
	
	// On stocke
	*adr_x = x;
}


/**
 * Recupére la valeur entre b_faible et b_fort de x
 * ---------------------------------------------------------------------
 * get_field(adr_x,faible,fort) renvoie la valeur de x entre
 * b_faible et b_fort
 */
int get_field(int32_t * adr_x, int faible, int fort){
	uint32_t lu = 1;
	unsigned int i;
	int32_t x = *adr_x; // Récupérer la valeur
	
	// Crée un masque pour mettre à 0 la valeur qui dépasse.
	lu = 1<<faible;
	for(i = 0; i<fort-faible;i++){
		lu = (lu<<1)|(1<<faible);
	}
	x = x & lu;
	x = (uint32_t)x >> faible;
	return (int)x;
}

void set_i_debut(int32_t *x,int v){
	set_field(x,IDEB_FAIBLE,IDEB_FORT,v);
}

void set_j_debut(int32_t *x,int v){
	set_field(x,JDEB_FAIBLE,JDEB_FORT,v);
}

void set_i_fin(int32_t *x,int v){
	set_field(x,IFIN_FAIBLE,IFIN_FORT,v);
}

void set_j_fin(int32_t *x,int v){
	set_field(x,JFIN_FAIBLE,JFIN_FORT,v);
}

void set_coule(int32_t *x,int v){
	set_field(x,COULE,COULE,v);
}

int get_i_debut(int32_t *x){
	return get_field(x,IDEB_FAIBLE,IDEB_FORT);
}

int get_j_debut(int32_t *x){
	return get_field(x,JDEB_FAIBLE,JDEB_FORT);
}

int get_i_fin(int32_t *x){
	return get_field(x,IFIN_FAIBLE,IFIN_FORT);
}

int get_j_fin(int32_t *x){
	return get_field(x,JFIN_FAIBLE,JFIN_FORT);
}

int get_coule(int32_t *x){
	return get_field(x,COULE,COULE);
}

/*
int main(void){
	int val = 0x3;
	int32_t x = 0xFFFFFFFF;
	
	printf("x : %x\n",x);
	set_i_debut(&x,val);
	printf("x : %x\n",x);
	val = get_i_debut(&x);
	printf("i_debut : %x\n",val);
	
	val = 0x8;
	printf("x : %x\n",x);
	set_j_debut(&x,val);
	printf("x : %x\n",x);
	val = get_j_debut(&x);
	printf("j_debut : %x\n",val);
	
	printf("x : %x\n",x);
	set_coule(&x,1);
	printf("x : %x\n",x);
	val = get_coule(&x);
	printf("coule : %x\n",val);
	
	return 0;
} */
