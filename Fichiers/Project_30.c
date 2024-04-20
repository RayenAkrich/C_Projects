//Le but de cet exercice est de dupliquer un fichier. Le nom de la copie sera formé à partir du nom du premier auquel on ajoute 2 avant l’extension.
//Par exemple de « fichier.ext » aura pour nom « fichier2.ext ».

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main()
{
    char nom_fichier[100];
    FILE *fichier;

    // Obtenir le nom du fichier
    printf("Entrez le nom du fichier texte : ");
    scanf("%s",nom_fichier);

    // Ouvrir le fichier
    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL ) {
        printf("Erreur : le fichier n'existe pas.\n");
        return 0;
    }
    
    // Creation du 2eme fichier
    FILE *fichier2;
    char nom_fichier2[100];
    strcpy(nom_fichier2,nom_fichier);
    nom_fichier2[strlen(nom_fichier2)-4]='\0';
    strcat(nom_fichier2,"2.txt");
    fichier2= fopen(nom_fichier2,"w");
    if (fichier2 == NULL ) {
        printf("Erreur.\n");
        return 0;
    }

    // Ecriture le contenu de text dans fichier2
    char texte[1000];
    while (fgets(texte, sizeof(texte), fichier) != NULL) {
        fputs(texte, fichier2);
    }

    //Fermeture des fichiers
    fclose(fichier);
    fclose(fichier2);
    return 0;
}
