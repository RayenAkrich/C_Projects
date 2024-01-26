//Le but de ce programme est de lire le comptenu d'un fichier text dont son nom et son adresse sont saisies par l'utilisateur avec la supression des premiers espaces et les symboles "//"

#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

void afficher_fichier(FILE *fp) {
    char texte[1000];

    // Lire chaque ligne du fichier et l'afficher
    while (fgets(texte, sizeof(texte), fp) != NULL) {
        // Supprimer les espaces en début de ligne
        int i = 0;
        while (isspace(texte[i])) {
            i++;
        }
        // Ignorer les lignes de commentaires commençant par '//'
        if (texte[i] == '/' && texte[i + 1] == '/') {
            // La ligne est un commentaire, ne rien faire
        } else {
            // Afficher le reste de la ligne
            printf("%s", texte + i);
        }

    }}

    int main() {
        FILE *fichier;
        char nom_fichier[100];

        //obtenir le nom du fichier/
        printf("Entrez le nom du fichier texte à afficher : ");
        scanf("%s", nom_fichier);

        // Ouvrir le fichier en mode lecture
        fichier = fopen(nom_fichier, "r");

        // V�rification que le fichier existe
        if (fichier == NULL) {
            printf("Erreur : le fichier n'existe pas ou ne peut pas être ouvert.\n");
            return 0;
        }

        // Afficher le contenu du fichier
        afficher_fichier(fichier);

        // Fermer le fichier
        fclose(fichier);

        return 0;
    }
