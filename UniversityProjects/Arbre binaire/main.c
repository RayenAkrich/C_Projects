#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
int main() {
  
  int niveau=3;//Niveau est 3 pour notre test
  
  Arbre* racine = create(niveaux);//Création de l'arbre

  printf("Saisir la valeur à rechercher: ");
  scanf("%d", &x);//Lecture d'une valeur qu'on souhaite chercher
  
  resultat = recherche(racine,x);//Recherche
    if (resultat != NULL) {
        printf("La valeur %d a été trouvée dans l'arbre.\n",x);
    } else {
        printf("La valeur %d n'a pas été trouvée dans l'arbre.\n",x);
    }
  
  liberer_arbre(racine);//Libération de l'arbre
  
}
