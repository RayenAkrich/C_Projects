//Le but de ce programme est de ❖ Charger deux tableaux t1 et t2 de dimensions respectives 5≤n1≤10 et 5≤n2≤10 par des entiers introduits dans un ordre croissant,
//❖ Fusionner t1 et t2 dans un troisième tableau t3 (utiliser la technique du tri-fusion),
//❖ Afficher les éléments de t3 dans un ordre décroissant.
#include<stdlib.h>
#include <stdio.h>
int main(){
    int n1;int n2; int *T1;int *T2;int *T3;
    do{
        printf("Donner la taille du tableau 1: ");
        scanf("%d",&n1);
    }while(!((5<=n1)&&(n1<=10)));
    T1=(int*)malloc(n1*sizeof (int));
    if(T1==NULL){
        printf("erreur");
        return 0;
    }
    printf("Donner la case numéro 1 du 1er tableau: ");
    scanf("%d",&T1[0]);
    for (int i=1;i<n1;i++){
        do{
            printf("Donner la case numéro %d du 1er tableau: ",i+1);
            scanf("%d",&T1[i]);
        }while(T1[i-1]>T1[i]);
    }
    do{
        printf("Donner la taille du tableau 2: ");
        scanf("%d",&n2);
    }while(!((5<=n1)&&(n2<=10)));
    T2=(int*)malloc(n2*sizeof (int));
    if(T2==NULL){
        printf("erreur");
        free(T1);
        return 0;
    }
    printf("Donner la case numéro 1 du 2eme tableau: ");
    scanf("%d",&T2[0]);
    for (int i=1;i<n2;i++){
        do{
            printf("Donner la case numéro %d du 2eme tableau: ",i+1);
            scanf("%d",&T2[i]);
        }while(T2[i-1]>T2[i]);
    }
    T3=(int*)malloc((n1+n2)* sizeof(int));
    if (T3==NULL){
        printf("erreur");
        free(T1);
        free(T2);
        return 0;
    }
    int c1=0;int c2=0;int c3=0;
    while((c1<n1)&&(c2<n2)){
        if (T1[c1]>=T2[c2]){
            T3[c3]=T2[c2];
            c3++;
            c2++;
        }
        else{
            T3[c3]=T1[c1];
            c3++;
            c1++;
        }
        }
    if (c1>=n1){
        for(int i=c2;i<n2;i++){
            T3[c3]=T2[i];
            c3++;
        }
    }
    else {
        for(int i=c1;i<n1;i++){
            T3[c3]=T1[i];
            c3++;
        }
    }
    printf("Le tableau 3 décroissant est :\n");
    for (int j = (n1+n2)-1; j>=0; j--) {
        printf("%d , ",T3[j]);
    }
    free(T1);
    free(T2);
    free(T3);
}
