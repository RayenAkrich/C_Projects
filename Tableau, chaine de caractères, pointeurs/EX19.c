//Examen Janvier 2020 Partie B Enoncé :

//On se propose d'écrire une fonction qui permet d'effectuer un tri bulle sur un tableau d'entiers.
//Le principe du tri bulle est de comparer deux à deux les éléments e1 et e2 consécutifs d'un tableau et d'effecteur une permutation si e1 > e2.
//On continue de trier jusqu'à ce qu'il n'y ait plus de permutation.

#include <stdio.h>
#include <stdlib.h>

int* tri_bulle(int *t, int n){
    int test_permut=1;
    do{
        test_permut=0;
        for(int i=0;i<n-1;i++){
            if(t[i]>t[i+1]){//Permutation si t[i]>t[i+1]
                int temp;
                temp=t[i+1];
                t[i+1]=t[i];
                t[i]=temp;
                test_permut=1;
            }
        }
    }while(test_permut);//Arret du boucle s'il n y a aucune permutation
}

int main() {
    int n;int *t;

    //Saisie du taille du tableau
    printf("Saisir la taille de votre tableau: ");
    scanf("%d",&n);

    //Initialisation du tableau
    t=(int*) malloc(n* sizeof(int));
    if(t==NULL){
        printf("Erreur de location!");
        return 0;
    }

    //Remplissage du tableau
    for(int i=0;i<n;i++){
        printf("\nSaisir la case %d: ",i+1);
        scanf("%d",&t[i]);
    }

    //Tri du tableau
    tri_bulle(t,n);

    //Affichage du tableau après tri
    printf("Tableau apres tri:\n |");
    for(int i=0;i<n;i++){printf(" %d |",t[i]);}

    //Free Mem
    if(t!=NULL){
        free(t);
    }
    return 0;
}
