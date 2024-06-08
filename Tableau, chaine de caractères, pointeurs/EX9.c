//Le but de ce programme est de de saisir une chaine de caractères CH non vide et de supprimer les blancs à gauche et à droite de la chaîne CH.

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int main(){
    char *ch;
    ch=(char*)malloc(200* sizeof(char));
    if(ch==NULL){
        printf("Erreur de location!");
        return 0;
    }

    printf("Donner votre chaine: ");
    fflush(stdin);gets(ch);fflush(stdout);

    while(isspace(ch[0])){
        strcpy(ch,ch+1);
    }
    while(isspace(ch[strlen(ch)-1])){
        ch[strlen(ch)-1]='\0';
    }

    printf("Votre chaine sans espaces est :%s",ch);
    free(ch);
    return 0;
}
