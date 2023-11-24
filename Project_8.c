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
