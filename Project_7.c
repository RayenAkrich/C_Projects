//Le but de ce programme est de saisir un mot et une phrase tous les deux non vides, de les convertir en majuscule, et d’afficher si le mot existe ou non dans la phrase et si oui avec quel nombre d’occurrences.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char *ch;char *mot , *trouve;int nb=0;
    ch = (char *) malloc(1000 * sizeof(char));
    if(ch==NULL){
        printf("Erreur de location!");
        return 0;
    }

    do{
        printf("Saisir votre chaine: ");
        fflush(stdin);
        gets(ch);
        fflush(stdout);
    }while(strlen(ch)==0);
    strupr(ch);

    mot = (char *) malloc(1000 * sizeof(char));
    if(mot==NULL){
        printf("Erreur de location!");
        free(ch);
        return 0;
    }
    do{
        printf("Saisir votre mot");
        fflush(stdin);
        gets(mot);
        fflush(stdout);
    }while(strlen(mot)==0);
    strupr(mot);

    trouve=strstr(ch,mot) ;
    while(trouve != NULL)
    {
        nb++ ;
        trouve=strstr(trouve+strlen(mot), mot) ;
    }

    printf("Votre mot %s est répété %d fois.",mot,nb);
    free(ch);
    free(mot);
    return 0;
}
