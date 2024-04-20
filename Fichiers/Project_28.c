//Le but de cet exercice est demander un nom sans extension pour un fichier,rajoute l’extension « .txt », et crée ce fichier.
//Ensuite le programme prendra des chaines saisies par l’utilisateur et les écrits dans le fichier.
//La condition d’arrêt étant une chaine ne contenant pas le caractère ‘#’.

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int Verif_Hachtag(char* texte){
    int i=0;
    while (i<= strlen(texte) && texte[i]!='#'){
        i++;
    }
    return i<= strlen(texte);
};
int main()
{
    char nom_fichier[100];
    FILE *fichier;

    // Obtenir le nom du fichier
    printf("Entrez le nom du fichier texte : ");
    scanf("%s",nom_fichier);
    strcat(nom_fichier,".txt");

    // Creer le fichier en mode ecriture
    fichier = fopen(nom_fichier, "w");

    // Saisir les chaines saisies par l'utilisateur contenant les '#'
    char texte[100];
    int test=1;
    while(test==1){
        printf("Saisir votre chaine:\n");
        fflush(stdin);gets(texte);fflush(stdout);
        test=Verif_Hachtag(texte);
        fprintf(fichier, "%s\n", texte);
    }

    fclose(fichier);
    return 0;
}
