//Le but de ce programme est de saisir Un tableau de 5<=N<=20 chaines de caractere ,puis extraiter les lettres de chaque case et les afficher.

#include<stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char T[20][10];
    char ST[10];     //ST sera le nom du variable contenant les lettres dans une Chaine T[i]
    int N;
    do {
        printf("Saisir N (entre 5 et 20) : ");
        scanf("%d", &N);
    } while (N < 5 || N > 20);
    for (int i = 0; i < N; i++) {
        ST[0] = '\0';
        printf("Saisir la %d ème case : ", i+1);
        gets(T[i]);fflush(stdout);
        for (int j = 0; T[i][j] != '\0'; j++) {
            if (isalpha(T[i][j])) {
                strncat(ST, &T[i][j], 1);
            }
        }
        printf("%d %s \n",i+1,ST);
    }
}
