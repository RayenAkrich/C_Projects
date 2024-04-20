#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

Arbre* create(int n) {
    //Cas de base si n est 0
    if (n == 0) {
        return NULL;
    }

    //Initialisation d'une nouvelle arbre
    Arbre* nouveau = (Arbre*)malloc(sizeof(Arbre));
    if(nouveau==NULL){
      printf("Erreur d'allocation de mémoire!");
      return NULL;
    }
    
    //Initialisation les fils à NULL
    nouveau->F_d = NULL;
    nouveau->F_g = NULL;

    //Saisie de la valeur de sommet du père
    printf("Saisir la valeur du sommet du père: ");
    scanf("%d",&nouveau->a);
    
    //Création des sous-arbres récursivement
    nouveau->F_g = create(n - 1);
    nouveau->F_d = create(n - 1);
    
    return nouveau;
}

void liberer_arbre(Arbre* arbre) {
    if (arbre == NULL) {
        return;
    }

    //Libèration les sous-arbres 
    liberer_arbre(arbre->F_g);
    liberer_arbre(arbre->F_d);

    //Libèration du noeud père
    free(arbre);
}
