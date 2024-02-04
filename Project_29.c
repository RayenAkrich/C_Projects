//Le but de cet exercice est de calculer le nombre d’occurrence de chaque caractère alphabétique présent dans le fichier sans distinction de la casse.
//Le résultat sera stocké dans un autre fichier.

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

struct Occ{
    char c;
    int nb;
};
typedef struct Occ Occ;

void Occurence(Occ *T,char *texte){
    int i=0;
    if (isalpha(texte[i])){
        switch (texte[i]) {
            case 'A':T[0].nb++;
                break;
            case 'B':T[1].nb++;
                break;
            case 'C':T[2].nb++;
                break;
            case 'D':T[3].nb++;
                break;
            case 'E':T[4].nb++;
                break;
            case 'F':T[5].nb++;
                break;
            case 'G':T[6].nb++;
                break;
            case 'H':T[7].nb++;
                break;
            case 'I':T[8].nb++;
                break;
            case 'J':T[9].nb++;
                break;
            case 'K':T[10].nb++;
                break;
            case 'L':T[11].nb++;
                break;
            case 'M':T[12].nb++;
                break;
            case 'N':T[13].nb++;
                break;
            case 'O':T[14].nb++;
                break;
            case 'P':T[15].nb++;
                break;
            case 'Q':T[16].nb++;
                break;
            case 'R':T[17].nb++;
                break;
            case 'S':T[18].nb++;
                break;
            case 'T':T[19].nb++;
                break;
            case 'U':T[20].nb++;
                break;
            case 'V':T[21].nb++;
                break;
            case 'W':T[22].nb++;
                break;
            case 'X':T[23].nb++;
                break;
            case 'Y':T[24].nb++;
                break;
            case 'Z':T[25].nb++;
                break;
            default:
                break;
        }
    }

}
void Saisie(Occ*T){
    for (int i=0;i<26;i++){
        T[i].c='A'+i;
        T[i].nb = 0;
    }
}


int main()
{
    char nom_fichier[100];
    FILE *fichier;
    FILE *fichier_2;

    // Obtenir le nom du fichier
    printf("Entrez le nom du fichier texte : ");
    scanf("%s",nom_fichier);

    // Ouvrir les fichier en mode lecture et ecriture
    fichier = fopen(nom_fichier, "r");
    fichier_2 = fopen("exp.txt", "w");
    if (fichier == NULL || fichier_2 == NULL) {
        printf("Erreur : l'un des fichiers ne peut pas être ouvert.\n");
        return 0;
    }

    // Copier le contenu du fichier dans 'texte' et le convertir en majuscule
    char texte[100];
    fgets(texte,  100, fichier);
    for (int i = 0; texte[i] != '\0'; i++) {
            if (isalpha(texte[i])) {
                texte[i] = toupper(texte[i]);
            }
    }

    // Initialisation du tableau Tableau_Occ
    Occ Tableau_Occ[26];
    Saisie(Tableau_Occ);

    // Calcul d'occurence des lettres dans texte
    Occurence(Tableau_Occ,texte);

    // Ecriture le contenu de Tableau-Occ dans fichier_2
    for(int i=0;i<26;i++){
        fprintf(fichier_2,"%c",Tableau_Occ[i].c);
        fprintf(fichier_2,"%c",' ');
        fprintf(fichier_2,"%d",Tableau_Occ[i].nb);
        fprintf(fichier_2,"%c",'\n');
    }

    //Fermeture des fichier
    fclose(fichier);
    fclose(fichier_2);
    return 0;
}
