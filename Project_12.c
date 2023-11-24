//Le but de cet exercice est de simuler le fonctionnement de la fonction strncat permettant de concaténer n caractères de la deuxième chaine en utilisant le mécanisme de pointeurs.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n1,n2,n;char *ch1; char *ch2;char *ch3;
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
    fflush(stdout);
    do{
        printf("Saisir le nombre de caractères de la 2eme chaine pour les concatener");
        scanf("%d",&n);
    }while(n> strlen(ch2));
    ch3=(char*)malloc((n1+n+1)* sizeof(char));
    if(ch3==NULL){
        printf("erreur de location");
        free(ch1);
        free(ch2);
        return 0;
    }
    for(int i=0;i<strlen(ch1);i++){
        ch3[i]=ch1[i];
    }
    for(int i=0;i<n;i++){
        ch3[i+ strlen(ch1)]=ch2[i];
    }
    printf("La chaine 1 est : %s \nLa chaine 2 est : %s\nLa chaine 3 est : %s",ch1,ch2,ch3);
    free(ch1);
    free(ch2);
    free(ch3);
    return 0;
}
