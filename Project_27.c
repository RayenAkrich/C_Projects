//Le but de cet exercice déterminer le nombre de lignes d’un fichier ainsi que la longueur de chaque ligne.
//On suppose que les lignes du fichier sont de longueur fixe(50)
#include "stdlib.h"
#include "stdio.h"

int main()
{
    char nom_fichier[100];
    FILE *fichier;

    // Obtenir le nom du fichier
    printf("Entrez le nom du fichier texte : ");
    scanf("%s",nom_fichier);

    // Ouvrir le fichier en mode lecture
    fichier = fopen(nom_fichier, "r");

    // Verification que le fichier existe
    if (fichier == NULL) {
        printf("Erreur : le fichier n'existe pas ou ne peut pas être ouvert.\n");
        return 0;
    }

    // Compter les lignes et la taille de chaque ligne
    char texte[1000];
    int nombre_des_lignes=0 ;
    int longeur_ligne = 50;
    while (fgets(texte, sizeof(texte), fichier) != NULL){
        for (int i=0; texte[i]!='\0';i++){
            if(texte[i]=='\n'){
                nombre_des_lignes++;
            }
        }
    }
    printf("Le nombre des lignes est %d , la longeur de chaque ligne est %d (suppose fixe)",nombre_des_lignes,longeur_ligne);
    fclose(fichier);
    return 0;
}
