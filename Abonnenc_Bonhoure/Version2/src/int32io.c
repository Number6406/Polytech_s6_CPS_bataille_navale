/**
 * Abonnenc Bonhoure 
 * Mars 2016
 */

#include <stdio.h>
#include <stdint.h>

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
	v = v << faible;
	// Crée un masque pour mettre à 0 la valeur qui dépasse.
	for(i = 1; i<fort;i++){
		lu = (lu<<1)|1;
	}
	v &= lu;
	
	// Mettre à 0 les bits de x entre faible et fort
	// On crée un masque
	lu = 0xFFFFFFFF;
	eff = ~(1<<faible);
	for(i=faible;i<fort;i++){
		lu &= eff;
		eff = ~(1<<(i+1));
	}
	// On efface dans x
	x &= eff;
	
	// On remplace
	x |= v;
	
	// On stocke
	*adr_x = x;
}

int get_field(int32_t * adr_x, int faible, int fort){
	uint32_t lu = 1;
	unsigned int i;
	int32_t x = *adr_x; // Récupérer la valeur
	
	// Crée un masque pour mettre à 0 la valeur qui dépasse.
	lu = 1<<faible;
	for(i = 1; i<fort;i++){
		lu = (lu<<1)|1;
	}
	x = x & lu;
	x >>= faible;
	return (int)x;
}

int main(void){
	int val = 0xAA;
	int32_t x = 0;
	
	printf("x : %x\n",x);
	
	set_field(&x,0,8,val);
	
	printf("x : %x\n",x);
	
	val = get_field(&x,4,8);
	
	printf("val : %x\n",val);
	return 0;
}
