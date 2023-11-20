//Le but de ce programme est de découper un texte en mots en utilisant le mécanisme de pointeurs ; Chaque mot sera affiché sur une ligne à part.

#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){
    int n;char *ch;
    printf("Saisir la taille de votre chaine: ");
    scanf("%d",&n);
    ch=(char*)malloc((n+1)* sizeof(char));
    if (ch==NULL){
        printf("Erreur de location");
        return 0;
    }
    printf("Donner votre chaine: ");
    fflush(stdin);
    gets(ch);
    fflush(stdout);
    int k=0;int i=0;
    do{
        if ((i==strlen(ch))||(ch[i]==' ')){
            char *ch3;
            ch3=(char*)malloc((i-k+1)* sizeof(char));
            if (ch3==NULL){
                printf("Erreur de location du chaine découpé");
                free(ch);
                return 0;
            }
            strncpy(ch3,ch+k,i);
            ch3[i-k+1]='\0';
            printf("%s\n", ch3);
            k=i;
            free(ch3);
        }
        i++;
    }while(i<strlen(ch)+1);
    free(ch);
}
