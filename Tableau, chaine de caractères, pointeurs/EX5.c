//Le but de ce programme est :
//❖ Saisir une chaîne de caractères CH non vide formée uniquement par des lettres alphabétiques, l’espace est aussi autorisé,
//❖ Compter les occurrences des lettres de l'alphabet en faisant abstraction à la casse.
//Exemple : Donnée : CH = Jeanne
//Résultat : La chaîne "jeanne" contient :
//1 fois la lettre 'a'
//2 fois la lettre 'e'
//1 fois la lettre 'j'
//2 fois la lettre 'n'

#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
struct No{
    int Occ;
    char c;
};
int main() {
    struct No *Nomb_occ;
    char *ch;
    int n;
    //saisir la taille de la chaine
    printf("Saisir la taille de votre chaine: ");
    scanf("%d", &n);
    ch = (char *) malloc((n + 1) * sizeof(char));
    if (ch == NULL) {
        printf("error");
        return 0;
    }
    bool test = true;
    //saisir la chaine
    do {
        printf("Saisir votre chaine :\n");
        fflush(stdin);gets(ch);fflush(stdout);
        for (int i = 0; (test) && (i < strlen(ch)); i++) {
            if ((ch[i] != ' ') || !(isalpha(ch[i]))) {
                test = false;
            }
        }
    } while (test);
    //pour faciliter le calcul on fait convertir la chaine en majuscule
    strupr(ch);
    //création et verification de Num_Occ
    Nomb_occ = (struct No *)malloc(26* sizeof(struct No));
    if (Nomb_occ == NULL) {
        printf("Erreur d'allocation de mémoire");
        free(ch);
        return 0;
    }
    //initialiastion du Nomb occ
    for (int i = 0; i < 26; i++) {
        Nomb_occ[i].c = 'A' + i;
        Nomb_occ[i].Occ = 0;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < strlen(ch); j++) {
            if (Nomb_occ[i].c == ch[j]) {
                Nomb_occ[i].Occ++;
            }
        }
    }
    //Afficher les occurrences de chaque lettre
    printf("Occurrences de chaque lettre dans la chaîne :\n");
    for (int i = 0; i < 26; i++) {
        if(Nomb_occ[i].Occ!=0){
            printf("'%c' : %d fois\n", Nomb_occ[i].c, Nomb_occ[i].Occ);
        }
    }
    //Free
    free(ch);
    free(Nomb_occ);
}
