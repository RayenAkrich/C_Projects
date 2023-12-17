//Le but de ce programme est d'implémenter une fonction de chiffrement et de dé chiffrement de César

#include <stdio.h>
#include <ctype.h>

// Fonction de chiffrement César
void chiffrement_cesar(char *texte, int cle) {
    int i = 0;
    while (texte[i] != '\0') {
        // Vérifier si le caractère est une lettre majuscule de l'alphabet anglais (A-Z)
        if (isalpha(texte[i]) && isupper(texte[i])) {
            // Appliquer le chiffrement César
            texte[i] = (texte[i] - 'A' + cle) % 26 + 'A';
        } else {
            // Afficher un message d'erreur et terminer le programme si un caractère invalide est détecté
            printf("Erreur : Le texte ne doit contenir que des lettres majuscules de A à Z.\n");
            return;
        }
        i++;
    }
}

// Fonction de déchiffrement César
void dechiffrement_cesar(char *texte, int cle) {
    int i = 0;
    while (texte[i] != '\0') {
        // Vérifier si le caractère est une lettre majuscule de l'alphabet anglais (A-Z)
        if (isalpha(texte[i]) && isupper(texte[i])) {
            // Appliquer le déchiffrement César
            texte[i] = (texte[i] - 'A' - cle + 26) % 26 + 'A';
        } else {
            // Afficher un message d'erreur et terminer le programme si un caractère invalide est détecté
            printf("Erreur : Le texte ne doit contenir que des lettres majuscules de A à Z.\n");
            return;
        }
        i++;
    }
}

int main() {
    char texte[100];
    int cle;

    // Demander à l'utilisateur d'entrer le texte
    printf("Entrez le texte (seulement des lettres majuscules de A à Z) : ");
    scanf("%[^\n]s", texte);

    // Vérifier si la chaîne contient uniquement des lettres majuscules de A à Z
    int i = 0;
    while (texte[i] != '\0') {
        if (!isalpha(texte[i]) || !isupper(texte[i])) {
            // Afficher un message d'erreur et terminer le programme si un caractère invalide est détecté
            printf("Erreur : Le texte ne doit contenir que des lettres majuscules de A à Z.\n");
            return 1; // Terminer le programme avec un code d'erreur
        }
        i++;
    }

    // Demander à l'utilisateur d'entrer la clé de chiffrement
    printf("Entrez la cle de chiffrement (entier entre 1 et 25) : ");
    scanf("%d", &cle);

    // Chiffrement
    chiffrement_cesar(texte, cle);
    printf("Texte chiffre : %s\n", texte);

    // Déchiffrement
    dechiffrement_cesar(texte, cle);
    printf("Texte dechiffre : %s\n", texte);

    return 0;
}
