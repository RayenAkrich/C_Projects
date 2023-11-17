// Le but de ce programme C est de saisir Un tableau de 5<=N<=20 chaines de caractere ,
// d'extraiter les enteiers contenant dans chaque chaine et les sommer//

#include<stdio.h>
#include<stdlib.h>
void main() {
    char T[20][10];
    char ST[10];          //ST sera le nom du variable contenant les numéros dans une Chaine T[i]
    int N;
    int sum = 0;
    do {
        printf("Saisir N (entre 5 et 20) : ");
        scanf("%d", &N);
    } while (N < 5 || N > 20);
    sum = 0;
    for (int i = 0; i < N; i++) {
        ST[0] = '\0';
        printf("Saisir la %d ème case : ", i);
        scanf("%s", T[i]);
        for (int j = 0; T[i][j] != '\0'; j++) {
            if (isdigit(T[i][j])) {
                strncat(ST, &T[i][j], 1);
            }
        }
        sum = sum + atoi(ST);
    }
    printf("La somme est : %d", sum);
}
