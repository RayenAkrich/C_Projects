//Le but de cet exercice est de ❖ Charger un tableau t de taille 5≤n≤100 par des entiers introduits dans un ordre croissant,
//❖ Lire une valeur v quelconque,
//❖ Insérer v dans t de telle façon que le vecteur t reste toujours trié par ordre croissant.
//❖ Afficher les éléments de t pour s’assurer que l’insertion de v dans t a été bien faite.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;int *T;int v;
    printf("Donner la taille de votre tableau: ");
    scanf("%d",&n);
    T=(int*)malloc(n*sizeof(int));
    if (T==NULL){
        printf("Erreur de location !");
        return 0;
    }
    printf("Donner la case numéro 1: ");
    scanf("%d",&T[0]);
    for (int i=1 ; i<n;i++){
        do{
            printf("Donner la case numéro %d: ",i+1);
            scanf("%d",&T[i]);
        } while (T[i-1]>T[i]);
    }
    printf("Donner un numéro V quelconque: ");
    scanf("%d",&v);
    int i=0;
    while ((i<n)&&(T[i]<v)){i++;}
    if (i<n){
        n++;
        for(int j=n;j>i;j--){
            T[j]=T[j-1];
        }
        T[i]=v;
    }
    else{
        n++;
        T[n-1]=v;
    }
    for(int j=0;j<n;j++){
        printf("%d | ",T[j]);
    }
    free(T);
}
