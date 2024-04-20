//Le but de ce programme est de lire le comptenu d'un fichier text dont son nom et son adresse sont saisies par l'utilisateur

#include<stdio.h>
#include<stdlib.h>

void afficher_fichier(FILE *fp){
    char texte[1000];

    // Lire chaque ligne du fichier et l'afficher
    while (fgets(texte, sizeof(texte), fp) != NULL) {
        printf("%s", texte);
    }
}

int main() {
    FILE *fichier;
    char nom_fichier[100];

    //obtenir le nom du fichier/
    printf("Entrez le nom du fichier texte � afficher : ");
    scanf("%s", nom_fichier);

    // Ouvrir le fichier en mode lecture
    fichier = fopen(nom_fichier, "r");

    // V�rification que le fichier existe
    if (fichier == NULL) {
        printf("Erreur : le fichier n'existe pas ou ne peut pas être ouvert.\n");
    }

    // Afficher le contenu du fichier
    afficher_fichier(fichier);

    // Fermer le fichier
    fclose(fichier);

    return 0;
}
