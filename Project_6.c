//Le but de ce programme est de de saisir une chaine de caractères CH non vide et de supprimer toute séquence de plusieurs blancs pour ne garder qu’un seul.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char *ch;
    ch = (char *) malloc(1000 * sizeof(char));
    if(ch==NULL){
        printf("Erreur de location!");
        return 0;
    }
    printf("Saisir votre chaine: ");
    fflush(stdin);
    gets(ch);
    fflush(stdout);
    for (int i=0;i<strlen(ch)-1;){
        if((ch[i])==' '){
            if (ch[i+1]==' '){
                strcpy(ch+i+1,ch+i+2);
            }
            else{
                i++;
            }
        }
        else{i++;}
    }
    printf("Votre chaine sans répétition des espaces:\n%s",ch);
    free(ch);
    return 0;
}
