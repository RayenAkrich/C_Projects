//Le but de ce programme est d’afficher sur écran le contenu d’un fichier texte.Pour cet exemple on prendera l'adresse du fichier est C:\Games\exp.txt
#include <stdio.h>

void affiche_fichier(FILE *fp) {
    // Déplacer le curseur de fichier au début
    rewind(fp);
    // Lire et afficher le contenu du fichier
    char caractere;
    while ((caractere = fgetc(fp)) != EOF) {
        putchar(caractere);
    }

    // Fermer le fichier
    fclose(fp);
}

int main() {
    // Exemple d'utilisation
    char fp[30]="C:\Games\exp.txt";
    FILE *fichier = fopen(fp, "r");
    // Vérifier si le pointeur de fichier est valide
    if (fichier == NULL) {
        printf( "Erreur : Impossible d'ouvrir le fichier.\n");
        return 0;
    }

    affiche_fichier(fichier);

    return 0;
}
