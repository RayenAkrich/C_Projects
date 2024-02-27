//PROJET 1://
//Exricture d'un programme C qui permet de :*Lire une chaine de caractère et afficher les mots qui se répétent*//

#include <stdio.h>
#include <string.h>
void main(){
    char ch[100];char T[100][50];int Nb_Occ[100];int k=0;int j=0;
    //déclaration d'une chaine de caractères//
    printf("saisir une chaine de caractères :\n");
    gets(ch);
    //insertion les mots de la chaine dans un tableau//
    for (int i=0;i<=strlen(ch);i++){
        //si le caractère numéro i n'est pas un espace ou il est le dérnier caractère on le stocke dans le Kème case du tableau T//
        if ((ch[i]!=' ')||(ch[i]=='\0')){T[k][j]=ch[i];j=j+1;}
            //sinon on passe pour la prochaine case//
        else {T[k][j]='\0';k=k+1;T[k][j]='\0';j=0;}
    }
    //cherchons le nombre d'occurence pour chacun des éléments de T//
    for (int i=0;i<=k;i++){
        Nb_Occ[i]=0;
        //comparons la Ième mot avec tous les mots qui lui précédes(les A mots)//
        for (int a= i + 1; a <=k; a++){
            if (strcmp(T[i],T[a])==0){Nb_Occ[i]=Nb_Occ[i]+1;}
        }
    }
    //affichons les mots qui se répétent//
    for (int i=0;i<=k;i++){
        if (Nb_Occ[i]!=0){printf("%s \n",T[i]);}
    }
}
