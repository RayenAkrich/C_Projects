//Le but de ce programme estp ermettant de saisir une chaine de caractères CH non vide, de supprimer tous les caractères autres que les alphabétiques, de construire une chaine RES dans laquelle on rangera toutes les consonne de CH qui sont en majuscule,
// suivies de toutes les voyelles de CH qui sont en majuscule, suivies de toutes les consonne de CH qui sont en minuscule, suivies de toutes les voyelles de CH qui sont en minuscule en conservant dans RES l’ordre d’apparition des lettres dans CH.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *ch;
    ch = (char *)malloc(1000 * sizeof(char));

    if (ch == NULL) {
        printf("Erreur d'allocation!");
        return 0;
    }

    do {
        printf("Saisir votre chaine: ");
        fflush(stdin);
        gets(ch);
        fflush(stdout);
    } while (strlen(ch) == 0);

    char consonnesMajuscules[1000] = "", voyellesMajuscules[1000] = "", consonnesMinuscules[1000] = "", voyellesMinuscules[1000] = "";

    for (int i = 0; i < strlen(ch); i++) {
        char c = ch[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    strcat(voyellesMajuscules, &c);
                } else {
                    strcat(consonnesMajuscules, &c);
                }
            } else {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    strcat(voyellesMinuscules, &c);
                } else {
                    strcat(consonnesMinuscules, &c);
                }
            }
        }
    }
    
    char resultat[4000] = "";
    strcat(resultat, consonnesMajuscules);
    strcat(resultat, voyellesMajuscules);
    strcat(resultat, consonnesMinuscules);
    strcat(resultat, voyellesMinuscules);

    printf("%s", resultat);

    free(ch);
    free(resultat);
    return 0;
}
