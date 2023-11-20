//Le but de cet exercice est de simuler le fonctionnement de la fonction strcat permettant de concaténer deux chaines de caractères en utilisant le mécanisme de pointeurs.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n1,n2;char *ch1; char *ch2;char *ch3;
    printf("Donner la taille de votre 1er chaine: ");
    scanf("%d",&n1);
    ch1=(char*) malloc((n1+1)* sizeof(char));
    if(ch1==NULL){
        printf("erreur de location");
        return 0;
    }
    printf("Donner votre 1er chaine");
    fflush(stdin);
    gets(ch1);
    printf("Donner la taille de votre 2eme chaine: ");
    scanf("%d",&n2);
    ch2=(char*) malloc((n2+1)* sizeof(char));
    if(ch2==NULL){
        printf("erreur de location");
        free(ch1);
        return 0;
    }
    printf("Donner votre 2eme chaine");
    fflush(stdin);
    gets(ch2);
    ch3=(char*)malloc((n1+n2+1)* sizeof(char));
    if(ch3==NULL){
        printf("erreur de location");
        free(ch1);
        free(ch2);
        return 0;
    }
    for (int i=0;i< strlen(ch1);i++){
        ch3[i]=ch1[i];
    }
    for (int i=0;i< strlen(ch2);i++){
        ch3[i+ strlen(ch1)]=ch2[i];
    }
    printf("la chaine 1 est : %s \nla chaine 2 est : %s\nla chaine concaté est : %s",ch1,ch2,ch3);
    free(ch1);
    free(ch2);
    free(ch3);
    return 0;
}
