//Le but de ce programme est de saisir une chaine de taille N est de remplacer toute suite d’un même caractère par un seul.

#include <stdio.h>
#include <stdlib.h>
int main(){
    char *T;
    int N;
    printf("Donner la taille de votre chaine: ");
    scanf("%d", &N);
    T=(char *)malloc((N + 1) * sizeof(char));
    if(T==NULL){
        printf("error");
        return 0;
    }
    printf("Donner votre chaine: \n");
    fflush(stdin);
    gets(T);
    for (int i=0;i<=N-2;i++){
        if (T[i]==T[i+1]){
            for (int j=i;j<=N-1;j++){
                T[j]=T[j+1];
            }
            N=N-1;
            i=i-1;
        }
    }
    T[N]='\0';
    printf("votre chaine sans répétition est :\n %s",T);
    free(T);
}
