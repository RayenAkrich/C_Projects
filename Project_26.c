//Le but de ce programme est d'éliminer les répétitions d’espaces dans un fichier texte.
//Dans des traitements indépendants les uns des autres, le résultat sera :
//a- Affiché sur l’écran,
//b- Ecrit dans un autre fichier.

#include <stdio.h>
#include <stdlib.h>


// Fonction pour éliminer les répétitions d'espaces dans une chaîne
void eliminer_repetitions_espaces(char *chaine) {
    int i, j;
    int espace_precedent = 0;

    for (i = 0, j = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] != ' ') {
            chaine[j] = chaine[i];
            j++;
            espace_precedent = 0;
        } else {
            if (!espace_precedent) {
                chaine[j] = chaine[i];
                j++;
                espace_precedent = 1;
            }
        }
    }

    chaine[j] = '\0';
}

// Fonction pour afficher le contenu d'une chaîne et l'écrire dans un fichier
void afficher_et_ecrire_fichier(const char *chaine, FILE *fp) {
    // Afficher sur l'écran
    printf("Resultat :%s\n", chaine);

    // Écrire dans un autre fichier
    if (fp != NULL) {
        fprintf(fp, "%s", chaine);
        fclose(fp);
        printf("Le resultat a ete ecrit dans un autre fichier.\n");
    }
}

int main() {
    FILE *fichier_entree, *fichier_sortie;
    char nom_fichier_entree[100], nom_fichier_sortie[100];
    char ligne[1000];

    // Obtenir le nom du fichier d'entrée
    printf("Entrez le nom du fichier texte d'entree : ");
    scanf("%s", nom_fichier_entree);

    // Ouvrir le fichier d'entrée en mode lecture
    fichier_entree = fopen(nom_fichier_entree, "r");

    // Vérifier que le fichier d'entrée existe
    if (fichier_entree == NULL) {
        printf("Erreur : le fichier d'entrée n'existe pas ou ne peut pas etre ouvert.\n");
        return 1;
    }

    // Obtenir le nom du fichier de sortie
    printf("Entrez le nom du fichier texte de sortie : ");
    scanf("%s", nom_fichier_sortie);

    // Ouvrir le fichier de sortie en mode écriture
    fichier_sortie = fopen(nom_fichier_sortie, "w");

    // Vérifier que le fichier de sortie peut être ouvert
    if (fichier_sortie == NULL) {
        printf("Erreur : le fichier de sortie ne peut pas etre ouvert.\n");
        fclose(fichier_entree);
        return 1;
    }

    // Lire chaque ligne du fichier d'entrée, éliminer les répétitions d'espaces, afficher et écrire dans le fichier de sortie
    while (fgets(ligne, sizeof(ligne), fichier_entree) != NULL) {
        eliminer_repetitions_espaces(ligne);
        afficher_et_ecrire_fichier(ligne, fichier_sortie);
    }

    // Fermer les fichiers
    fclose(fichier_entree);
    fclose(fichier_sortie);

    return 0;
}
